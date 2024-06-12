#include "s21_string.h"

#define DEFAULT_WIDTH 50

typedef struct {
  s21_size_t pos_str;
  s21_size_t pos_format;
  int count;
  int error;
} pos_format_t;

typedef struct {
  int start;
  int end;
  int width;
  int size;
  int ignor;
  char type;
  char flags;
  int precision;
} type_label_t;

void check_format(const char *str, const char *format, va_list parm,
                  pos_format_t *pf);
type_label_t get_signature(const char *format, pos_format_t *pf);
void cmp_symbol(const char *str, const char *format, pos_format_t *pf);
int get_size_type(const char *format, s21_size_t *position);
int is_digital(char ch, int base);
int is_flag(char ch);
int is_size(char ch);
int is_end_str(char ch);
int is_spec(char ch);
int char_to_number(char ch);
int check_format_base(const char *str, s21_size_t *position);
long long int str_to_int(const char *str, s21_size_t *position, int base,
                         int width, int *error);
long double str_to_float(const char *format, pos_format_t *pf,
                         type_label_t type);
void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf,
                        va_list parm);
void make_di(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_c(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_s(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_fGgEe(void *label, const char *str, pos_format_t *pf,
                type_label_t type);
void make_n(void *label, pos_format_t *pf, type_label_t type);
void make_uoxX(void *label, const char *str, pos_format_t *pf,
               type_label_t type);
void make_p(void **label, const char *str, pos_format_t *pf, type_label_t type);

int s21_sscanf(const char *str, const char *format, ...) {
  s21_size_t len_format = s21_strlen(format);
  s21_size_t len_str = s21_strlen(str);
  pos_format_t pf = {0};
  va_list parm;
  va_start(parm, format);

  while (!pf.error && pf.pos_format < len_format && pf.pos_str < len_str) {
    check_format(str, format, parm, &pf);
  }

  va_end(parm);

  return pf.count;
}

void check_format(const char *str, const char *format, va_list parm,
                  pos_format_t *pf) {
  while (is_end_str(format[pf->pos_format])) pf->pos_format++;
  while (is_end_str(str[pf->pos_str])) pf->pos_str++;

  if (format[pf->pos_format] != '%') {
    cmp_symbol(str, format, pf);
  } else {
    type_label_t type = get_signature(format, pf);
    if (type.type != '\0') {
      find_and_set_value(type, str, pf, parm);
      if (type.type == '%') cmp_symbol(str, format, pf);
    } else {
      cmp_symbol(str, format, pf);
    }
    if (type.type != 's')
      while (is_end_str(str[pf->pos_str])) pf->pos_str++;
  }
}

void cmp_symbol(const char *str, const char *format, pos_format_t *pf) {
  if (format[pf->pos_format] != str[pf->pos_str]) {
    pf->error = 1;
  } else {
    pf->pos_str++;
    pf->pos_format++;
  }
}

type_label_t get_signature(const char *format, pos_format_t *pf) {
  type_label_t label = {0};
  label.start = pf->pos_format++;

  if (is_flag(format[pf->pos_format])) pf->pos_format++;

  if (format[pf->pos_format] == '*') {
    pf->pos_format++;
    label.ignor = 1;
  }

  if (is_digital(format[pf->pos_format], 10)) {
    label.width = str_to_int(format, &pf->pos_format, 10, 0, NULL);
  }

  if (format[pf->pos_format] == '.') {
    pf->pos_format++;
    if (is_digital(format[pf->pos_format], 10)) {
      pf->pos_format++;
    } else if (format[pf->pos_format] == '*') {
      pf->pos_format++;
      label.ignor = 1;
    }
  }

  if (is_size(format[pf->pos_format])) {
    label.size = get_size_type(format, &pf->pos_format);
  }

  if (is_spec(format[pf->pos_format])) {
    label.type = format[pf->pos_format];
  }

  label.end = pf->pos_format++;
  if (label.flags != '\0' || label.precision != 0 || label.type == '\0') {
    pf->error = 4;
  }

  return label;
}

void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf,
                        va_list parm) {
  s21_size_t start = pf->pos_str;
  if (type.type == 'p') {
    if (!type.ignor) {
      make_p(va_arg(parm, void **), str, pf, type);
    } else {
      make_p(s21_NULL, str, pf, type);
    }
  } else if (type.type == '%') {
    if (type.width == 0) pf->pos_format = type.end;
  } else {
    void *label_void = s21_NULL;
    if (!type.ignor) {
      label_void = va_arg(parm, void *);
    }

    switch (type.type) {
      case 'c':
        make_c(label_void, str, pf, type);
        break;
      case 'd':
      case 'i':
        make_di(label_void, str, pf, type);
        break;
      case 's':
        make_s(label_void, str, pf, type);
        break;
      case 'f':
      case 'G':
      case 'g':
      case 'E':
      case 'e':
        make_fGgEe(label_void, str, pf, type);
        break;
      case 'o':
      case 'u':
      case 'x':
      case 'X':
        make_uoxX(label_void, str, pf, type);
        break;
      case 'n':
        make_n(label_void, pf, type);
        break;
      default:
        pf->error = 20;
    }
    if (start == pf->pos_str && type.type != '%' && type.type != 'n')
      pf->error = 9;
    if (label_void != s21_NULL)
      if (!pf->error) pf->count++;
  }
}

void make_c(void *label, const char *str, pos_format_t *pf, type_label_t type) {
  int offset = 0;
  if (type.width == 0) type.width = 1;

  while (type.width > 0) {
    if (type.size == 0) {
      if (!type.ignor)
        *((char *)label + offset) = str[pf->pos_str++];
      else
        pf->pos_str++;
    } else if (type.size == 1) {
      wchar_t ch;
      int bytes_read = mbtowc(&ch, str + pf->pos_str, MB_CUR_MAX);
      if (bytes_read > 0) {
        if (!type.ignor) *((wchar_t *)label + offset) = ch;
        pf->pos_str += bytes_read;
      } else {
        pf->error = 7;
      }
    } else {
      pf->error = 5;
    }
    type.width--;
    offset++;
  }
}

void make_di(void *label, const char *str, pos_format_t *pf,
             type_label_t type) {
  long long int value = 0;
  int error = 0;
  if (type.type == 'd')
    value = str_to_int(str, &pf->pos_str, 10, type.width, &error);
  else if (type.type == 'i')
    value = str_to_int(str, &pf->pos_str, 0, type.width, &error);
  pf->error = error;
  if (!type.ignor) {
    if (type.size == 0)
      *((int *)label) = (int)value;
    else if (type.size == 1)
      *((long int *)label) = (long int)value;
    else if (type.size == 2)
      *((long long int *)label) = (long long int)value;
    else if (type.size == 3)
      *((short int *)label) = (short int)value;
    else if (type.size == 4)
      *((signed char *)label) = (signed char)value;
  }
}

void make_uoxX(void *label, const char *str, pos_format_t *pf,
               type_label_t type) {
  long long unsigned int value = 0;
  int error = 0;
  if (type.type == 'u') {
    value = str_to_int(str, &pf->pos_str, 10, type.width, &error);
  } else if (type.type == 'o') {
    value = str_to_int(str, &pf->pos_str, 8, type.width, &error);
  } else if (type.type == 'x' || type.type == 'X') {
    value = str_to_int(str, &pf->pos_str, 16, type.width, &error);
  }
  pf->error = error;
  if (!type.ignor) {
    if (type.size == 0)
      *((unsigned int *)label) = (unsigned int)value;
    else if (type.size == 1)
      *((long unsigned int *)label) = (long unsigned int)value;
    else if (type.size == 2)
      *((long long unsigned int *)label) = (long long unsigned int)value;
    else if (type.size == 3)
      *((short unsigned int *)label) = (short unsigned int)value;
    else if (type.size == 4)
      *((unsigned char *)label) = (unsigned char)value;
  }
}

void make_s(void *label, const char *str, pos_format_t *pf, type_label_t type) {
  s21_size_t start = pf->pos_str;
  s21_size_t bytes_read = 0;

  if (type.size == 0) {
    while (!is_end_str(str[pf->pos_str]) && str[pf->pos_str] != ' ' &&
           str[pf->pos_str] != '\t' && str[pf->pos_str] != '\n' &&
           (type.width == 0 || pf->pos_str - start < (s21_size_t)type.width)) {
      if (!type.ignor) *((char *)label + bytes_read) = str[pf->pos_str];
      pf->pos_str++;
      bytes_read++;
    }
    if (!type.ignor) *((char *)label + bytes_read) = '\0';
  } else if (type.size == 1) {
    while (!is_end_str(str[pf->pos_str]) && str[pf->pos_str] != ' ' &&
           str[pf->pos_str] != '\t' && str[pf->pos_str] != '\n' &&
           (type.width == 0 || pf->pos_str - start < (s21_size_t)type.width)) {
      wchar_t ch;
      int len = mbtowc(&ch, str + pf->pos_str, MB_CUR_MAX);
      if (len > 0) {
        if (!type.ignor) *((wchar_t *)label + bytes_read) = ch;
        pf->pos_str += len;
        bytes_read++;
      } else {
        pf->error = 7;
        break;
      }
    }
    if (!type.ignor) *((wchar_t *)label + bytes_read) = L'\0';
  }
}

void make_fGgEe(void *label, const char *str, pos_format_t *pf,
                type_label_t type) {
  long double value = str_to_float(str, pf, type);
  if (!type.ignor) {
    if (type.size == 0)
      *((float *)label) = (float)value;
    else if (type.size == 1)
      *((double *)label) = (double)value;
    else if (type.size == 2)
      *((long double *)label) = (long double)value;
  }
}

void make_p(void **label, const char *str, pos_format_t *pf,
            type_label_t type) {
  long long int value =
      str_to_int(str, &pf->pos_str, 16, type.width, &pf->error);
  if (!type.ignor) {
    *label = (void *)value;
  }
}

void make_n(void *label, pos_format_t *pf, type_label_t type) {
  s21_size_t value = 0;
  if (!pf->error) value = pf->pos_str;

  pf->count--;
  if (!type.ignor) {
    if (type.size == 0)
      *((int *)label) = (int)value;
    else if (type.size == 1)
      *((long int *)label) = (long int)value;
    else if (type.size == 2)
      *((long long int *)label) = (long long int)value;
    else if (type.size == 3)
      *((short int *)label) = (short int)value;
    else if (type.size == 4)
      *((signed char *)label) = (signed char)value;
    else if (type.size == 5)
      pf->error = 5;
  }
}

long double str_to_float(const char *format, pos_format_t *pf,
                         type_label_t type) {
  int sign = 1;
  long double result = 0.0;
  int exp_sign = 1;
  int exponent = 0;
  int decimal_part = 0;
  int decimal_digits = 0;
  s21_size_t start = pf->pos_str;
  s21_size_t *position = &pf->pos_str;
  int width = type.width == 0 ? DEFAULT_WIDTH : type.width;

  if (format[*position] == '-') {
    sign = -1;
    (*position)++;
    width--;
  } else if (format[*position] == '+') {
    (*position)++;
    width--;
  }

  if (width >= 3) {
    if (s21_strncasecmp(format + *position, "nan", 3) == 0) {
      *position += 3;
      return sign * NAN;
    } else if (s21_strncasecmp(format + *position, "inf", 3) == 0) {
      *position += 3;
      return sign * INFINITY;
    }
  }

  while (is_digital(format[*position], 10) && width > 0) {
    result = result * 10.0 + (format[*position] - '0');
    (*position)++;
    width--;
  }

  if (format[*position] == '.' && width > 0) {
    (*position)++;
    width--;
    while (is_digital(format[*position], 10) && width > 0) {
      decimal_part = decimal_part * 10 + (format[*position] - '0');
      decimal_digits++;
      (*position)++;
      width--;
    }
    result += (long double)decimal_part / powl(10, decimal_digits);
  }

  if ((format[*position] == 'E' || format[*position] == 'e') && width > 0) {
    (*position)++;
    width--;
    if (format[*position] == '-' && width > 0) {
      exp_sign = -1;
      (*position)++;
      width--;
    } else if (format[*position] == '+' && width > 0) {
      (*position)++;
      width--;
    }
    while (is_digital(format[*position], 10) && width > 0) {
      exponent = exponent * 10 + (format[*position] - '0');
      (*position)++;
      width--;
    }
    result *= powl(10, exp_sign * exponent);
  }

  return sign * result;
}

long long int str_to_int(const char *str, s21_size_t *position, int base,
                         int width, int *error) {
  long long int value = 0;
  int sign_multiplier = 1;
  int digital = 0;

  if (width == 0) width = DEFAULT_WIDTH;

  if (str[*position] == '-') {
    sign_multiplier = -1;
    (*position)++;
    width--;
  } else if (str[*position] == '+') {
    (*position)++;
    width--;
  }

  if (base == 0) base = check_format_base(str, position);

  if (base == 16 && str[*position] == '0' &&
      (str[*position + 1] == 'x' || str[*position + 1] == 'X')) {
    (*position) += 2;
    width -= 2;
    digital = 1;
  } else if (base == 8 && str[*position] == '0') {
    (*position)++;
    width--;
    digital = 1;
  }

  while (is_digital(str[*position], base) && width > 0) {
    if (value != 0) value *= base;
    value += char_to_number(str[(*position)++]);
    digital++;
    width--;
  }

  if (digital == 0 && error != s21_NULL) *error = 12;

  return value * sign_multiplier;
}

int check_format_base(const char *str, s21_size_t *position) {
  int base = 10;
  if (str[*position] == '0') {
    if (str[*position + 1] == 'x')
      base = 16;
    else
      base = 8;
  }
  return base;
}

int is_digital(char ch, int base) {
  int res = 1;
  if (base == 8)
    res = ch >= '0' && ch <= '8';
  else if (base == 10)
    res = (ch >= '0' && ch <= '9');
  else if (base == 16)
    res = (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') ||
          (ch >= 'A' && ch <= 'F');
  return res;
}

int is_flag(char ch) {
  return (ch == '-' || ch == '+' || ch == ' ' || ch == '#' || ch == '0');
}

int is_size(char ch) { return (ch == 'h' || ch == 'l' || ch == 'L'); }

int is_end_str(char ch) {
  return (ch == '\0' || ch == '\n' || ch == '\t' || ch == ' ');
}

int is_spec(char ch) {
  return (ch == 'd' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'x' ||
          ch == 'X' || ch == 'f' || ch == 'F' || ch == 'e' || ch == 'E' ||
          ch == 'g' || ch == 'G' || ch == 'a' || ch == 'A' || ch == 'c' ||
          ch == 's' || ch == 'p' || ch == 'n' || ch == '%');
}

int char_to_number(char ch) {
  int number = 0;
  if (ch >= '0' && ch <= '9')
    number = ch - '0';
  else if (ch >= 'a' && ch <= 'f')
    number = ch - 'a' + 10;
  else if (ch >= 'A' && ch <= 'F')
    number = ch - 'A' + 10;
  return number;
}

int get_size_type(const char *format, s21_size_t *position) {
  int size = 0;
  if (format[*position] == 'h') {
    (*position)++;
    size = format[*position] == 'h' ? (++(*position), 4) : 3;
  } else if (format[*position] == 'l') {
    (*position)++;
    size = format[*position] == 'l' ? (++(*position), 2) : 1;
  } else if (format[*position] == 'L') {
    (*position)++;
    size = 2;
  }
  return size;
}

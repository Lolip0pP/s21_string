#include "s21_string.h"
#include <string.h>

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
  char flags;
  int precision;
  int ignor;
  char type;
} type_label_t;

int is_digital(char ch, int base);
int read_int(const char **str);
int char_to_digit(char ch);
int is_end_str(char ch);
void cmp_symbols(const char *str, const char *format, pos_format_t *pf);
type_label_t get_signatur(const char *format, pos_format_t *pf);
void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf, va_list parm);
void make_fGgEe(void *label, const char *str, pos_format_t *pf,
               type_label_t t);
void make_s(void *label, const char *str, pos_format_t *pf, type_label_t t);
void make_di(void *i, const char *str, pos_format_t *pf, type_label_t t);
void make_uoxX(void *i, const char *str, pos_format_t *pf, type_label_t t);
void make_p(void **i, const char *str, pos_format_t *pf, type_label_t t);
void make_c(void *c, const char *str, pos_format_t *pf, type_label_t t);
void make_n(void *n, pos_format_t *pf);
long long int str_to_int(const char *format, pos_format_t *pf, type_label_t type, int base);
long double str_to_float(const char *format, pos_format_t *pf, type_label_t type);

int s21_sscanf(const char *str, const char *format, ...) {
  s21_size_t len_format = s21_strlen(format);
  s21_size_t len_str = s21_strlen(str);
  pos_format_t pf = {0};
  va_list parm;
  va_start(parm, format);

  while (!pf.error && pf.pos_format < len_format && pf.pos_str < len_str) {
    type_label_t type = {0};
    if (is_end_str(format[pf.pos_format])) {
      while (is_end_str(format[pf.pos_format])) (pf.pos_format)++;
      while (is_end_str(str[pf.pos_str])) (pf.pos_str)++;
    }
    if (format[pf.pos_format] != '%') {
      cmp_symbols(str, format, &pf);
    } else {
      type = get_signatur(format, &pf);
      if (type.type != '\0') {
        find_and_set_value(type, str, &pf, parm);
        if (type.type == '%') cmp_symbols(str, format, &pf);
      } else {
        cmp_symbols(str, format, &pf);
      }
      if (type.type != 's') {
        while (is_end_str(str[pf.pos_str])) (pf.pos_str)++;
      }
    }
  }

  va_end(parm);
  return pf.count;
}

int is_digital(char ch, int base) {
  if (base == 8)
    return ch >= '0' && ch <= '7';
  else if (base == 10)
    return ch >= '0' && ch <= '9';
  else if (base == 16)
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
  return 0;
}

int read_int(const char **str) {
    int value = 0;
    while (**str >= '0' && **str <= '9') {
        value = value * 10 + (**str - '0');
        (*str)++;
    }
    return value;
}

int is_end_str(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r' || ch == '\f' || ch == '\0';
}

void cmp_symbols(const char *str, const char *format, pos_format_t *pf) {
  if (format[pf->pos_format] != str[pf->pos_str]) {
    pf->error = 1;
  } else {
    pf->pos_str++;
    pf->pos_format++;
  }
}

type_label_t get_signatur(const char *format, pos_format_t *pf) {
  type_label_t label = {0};
  label.start = pf->pos_format++;
  if (format[pf->pos_format] == '*') {
    pf->pos_format++;
    label.ignor = 1;
  }
  if (isdigit(format[pf->pos_format])) {
    const char *temp = format + pf->pos_format;
    label.width = read_int(&temp);
    pf->pos_format += temp - (format + pf->pos_format);
  }
  if (format[pf->pos_format] == '.') {
    pf->pos_format++;
    if (isdigit(format[pf->pos_format])) {
      const char *temp = format + pf->pos_format;
      label.precision = read_int(&temp);
      pf->pos_format += temp - (format + pf->pos_format);
    } else if (format[pf->pos_format] == '*') {
      pf->pos_format++;
      label.ignor = 1;
    }
  }
  if (format[pf->pos_format] == 'h' || format[pf->pos_format] == 'l' || format[pf->pos_format] == 'L') {
    label.size = format[pf->pos_format];
    pf->pos_format++;
  }
  if (s21_strchr("cdeEfgGiouxXspn%", format[pf->pos_format])) {
    label.type = format[pf->pos_format];
    pf->pos_format++;
    label.end = pf->pos_format;
  }
  return label;
}

void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf, va_list parm) {
  switch (type.type) {
    case 'i':
    case 'd':
      if (type.size == 'h') {
        short int *pi = va_arg(parm, short int *);
        make_di(pi, str, pf, type);
      } else if (type.size == 'l') {
        long int *pi = va_arg(parm, long int *);
        make_di(pi, str, pf, type);
      } else {
        int *pi = va_arg(parm, int *);
        make_di(pi, str, pf, type);
      }
      break;
    case 'u':
    case 'o':
    case 'x':
    case 'X':
      if (type.size == 'h') {
        short unsigned int *pi = va_arg(parm, short unsigned int *);
        make_uoxX(pi, str, pf, type);
      } else if (type.size == 'l') {
        long unsigned int *pi = va_arg(parm, long unsigned int *);
        make_uoxX(pi, str, pf, type);
      } else {
        unsigned int *pi = va_arg(parm, unsigned int *);
        make_uoxX(pi, str, pf, type);
      }
      break;
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G':
      if (type.size == 'l') {
        double *pl = va_arg(parm, double *);
        make_fGgEe(pl, str, pf, type);
      } else if (type.size == 'L') {
        long double *pl = va_arg(parm, long double *);
        make_fGgEe(pl, str, pf, type);
      } else {
        float *pl = va_arg(parm, float *);
        make_fGgEe(pl, str, pf, type);
      }
      break;
    case 'c':
      if (type.size == 'l') {
        wchar_t *pc = va_arg(parm, wchar_t *);
        make_s(pc, str, pf, type);
      } else {
        char *pc = va_arg(parm, char *);
        make_s(pc, str, pf, type);
      }
      break;
    case 's':
      if (type.size == 'l') {
        wchar_t *ps = va_arg(parm, wchar_t *);
        make_s(ps, str, pf, type);
      } else {
        char *ps = va_arg(parm, char *);
        make_s(ps, str, pf, type);
      }
      break;
    case 'p':
      void **pp = va_arg(parm, void **);
      make_p(pp, str, pf, type);
      break;
    case 'n':
      if (type.size == 'h') {
        short int *pi = va_arg(parm, short int *);
        *pi = pf->pos_str;
      } else if (type.size == 'l') {
        long int *pi = va_arg(parm, long int *);
        *pi = pf->pos_str;
      } else {
        int *pi = va_arg(parm, int *);
        *pi = pf->pos_str;
      }
      break;
    default:
      pf->error = 2;
      break;
  }
}

void make_di(void *i, const char *str, pos_format_t *pf, type_label_t t) {
  *(long long int *)i = str_to_int(str, pf, t, 10);
}

void make_fGgEe(void *label, const char *str, pos_format_t *pf, type_label_t t) {
    long double value = str_to_float(str, pf, t);
    if (!t.ignor) {
        if (t.size == 0)
            *((float *)label) = (float)value;
        else if (t.size == 'l')
            *((double *)label) = (double)value;
        else if (t.size == 'L')
            *((long double *)label) = (long double)value;
        else
            pf->error = 5;  // error size type
    }
}

void make_s(void *label, const char *str, pos_format_t *pf, type_label_t t) {
  int width = t.width == 0 ? DEFAULT_WIDTH : t.width;
  while (str[pf->pos_str] != '\0' && !is_end_str(str[pf->pos_str]) && width > 0) {
    *(char *)label = str[pf->pos_str];
    pf->pos_str++;
    label = (char *)label + 1;
    width--;
  }
  *(char *)label = '\0';
}

void make_uoxX(void *i, const char *str, pos_format_t *pf, type_label_t t) {
  int base = (t.type == 'o') ? 8 : (t.type == 'x' || t.type == 'X') ? 16 : 10;
  *(long long unsigned int *)i = str_to_int(str, pf, t, base);
}

void make_p(void **i, const char *str, pos_format_t *pf, type_label_t t) {
  *(long unsigned int *)i = str_to_int(str, pf, t, 16);
}

void make_c(void *c, const char *str, pos_format_t *pf, type_label_t t) {
  if (t.size == 'l') {
    *(wchar_t *)c = (wchar_t)str[pf->pos_str];
  } else {
    *(char *)c = str[pf->pos_str];
  }
  pf->pos_str++;
  pf->count++;
}

void make_n(void *n, pos_format_t *pf) {
  *(int *)n = pf->pos_str;
  pf->count++;
}

long long int str_to_int(const char *format, pos_format_t *pf, type_label_t type, int base) {
  int sign = 1;
  long long int result = 0;
  s21_size_t start = pf->pos_str;
  s21_size_t *position = &pf->pos_str;
  int width = type.width == 0 ? DEFAULT_WIDTH : type.width;
  
  if (format[*position] == '-' || format[*position] == '+') {
    if (format[*position] == '-') sign = -1;
    (*position)++;
    width--;
  }

  while (is_digital(format[*position], base) && width > 0) {
    result = result * base + char_to_digit(format[*position]);
    (*position)++;
    width--;
  }

  if (start != *position) {
    pf->error = 11;
    pf->count++;
  }

  return sign * result;
}

long double str_to_float(const char *format, pos_format_t *pf, type_label_t type) {
  int sign = 1, exp_sign = 1, exponent = 0, decimal_digits = 0;
  long double result = 0.0;
  s21_size_t start = pf->pos_str;
  s21_size_t *position = &pf->pos_str;
  int width = type.width == 0 ? DEFAULT_WIDTH : type.width;
  
  if (format[*position] == '-' || format[*position] == '+') {
    if (format[*position] == '-') sign = -1;
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

  // Parse the integer part
  while (is_digital(format[*position], 10) && width > 0) {
    result = result * 10.0 + (format[*position] - '0');
    (*position)++;
    width--;
  }

  // Parse the decimal part
  if (format[*position] == '.' && width > 0) {
    (*position)++;
    width--;
    while (is_digital(format[*position], 10) && width > 0) {
      result = result * 10.0 + (format[*position] - '0');
      decimal_digits++;
      (*position)++;
      width--;
    }
    result /= powl(10, decimal_digits);
  }

  // Check for exponential form (E or e)
  if ((format[*position] == 'E' || format[*position] == 'e') && width > 1 && start != *position) {
    (*position)++;
    width--;
    if (format[*position] == '-' || format[*position] == '+') {
      if (format[*position] == '-') exp_sign = -1;
      (*position)++;
      width--;
    }
    while (is_digital(format[*position], 10) && width > 0) {
      exponent = exponent * 10 + (format[*position] - '0');
      (*position)++;
      width--;
    }
    result *= powl(10, exp_sign * exponent);
  } else if (start != *position) {
    pf->error = 11;  // format exp error
    pf->count++;
  }

  return sign * result;
}

int char_to_digit(char ch) {
  int number = 0;
  if (ch >= '0' && ch <= '9')
    number = ch - '0';
  else if (ch >= 'a' && ch <= 'f')
    number = ch - 'a' + 10;
  else if (ch >= 'A' && ch <= 'F')
    number = ch - 'A' + 10;
  return number;
}

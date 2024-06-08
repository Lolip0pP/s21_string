#include "s21_string.h"
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

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

// static long double str_to_float(const char *format, pos_format_t *pf, type_label_t type);
static int is_digital(char ch, int base);
static int read_int(const char **str);
int char_to_digit(char ch);
static int is_end_str(char ch);
static void cmp_symbols(const char *str, const char *format, pos_format_t *pf);
static type_label_t get_signatur(const char *format, pos_format_t *pf);
static void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf, va_list parm);
static void make_di(void *i, const char *str, pos_format_t *pf, type_label_t t);
static void make_uoxX(void *i, const char *str, pos_format_t *pf, type_label_t t);
static void make_p(void **i, const char *str, pos_format_t *pf, type_label_t t);
static long long int str_to_int(const char *format, pos_format_t *pf, type_label_t type, int base);

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

int main() {
  long long int i;
  char *form = "%o \n";
  char *var = "1239";
  s21_sscanf(var, form, &i);
  printf(form, i);
  sscanf(var, form, &i);
  printf(form, i);
  return 0;
};


// static long double str_to_float(const char *format, pos_format_t *pf, type_label_t type) {
//   int sign = 1, exp_sign = 1, exponent = 0, decimal_digits = 0;
//   long double result = 0.0;
//   s21_size_t start = pf->pos_str;
//   s21_size_t *position = &pf->pos_str;
//   int width = type.width == 0 ? DEFAULT_WIDTH : type.width;
  
//   if (format[*position] == '-' || format[*position] == '+') {
//     if (format[*position] == '-') sign = -1;
//     (*position)++;
//     width--;
//   }

//   if (width >= 3) {
//     if (s21_strncasecmp(format + *position, "nan", 3) == 0) {
//       *position += 3;
//       return sign * NAN;
//     } else if (s21_strncasecmp(format + *position, "inf", 3) == 0) {
//       *position += 3;
//       return sign * INFINITY;
//     }
//   }

//   // Parse the integer part
//   while (is_digital(format[*position], 10) && width > 0) {
//     result = result * 10.0 + (format[*position] - '0');
//     (*position)++;
//     width--;
//   }

//   // Parse the decimal part
//   if (format[*position] == '.' && width > 0) {
//     (*position)++;
//     width--;
//     while (is_digital(format[*position], 10) && width > 0) {
//       result = result * 10.0 + (format[*position] - '0');
//       decimal_digits++;
//       (*position)++;
//       width--;
//     }
//     result /= powl(10, decimal_digits);
//   }

//   // Check for exponential form (E or e)
//   if ((format[*position] == 'E' || format[*position] == 'e') && width > 1 && start != *position) {
//     (*position)++;
//     width--;
//     if (format[*position] == '-' || format[*position] == '+') {
//       if (format[*position] == '-') exp_sign = -1;
//       (*position)++;
//       width--;
//     }
//     while (is_digital(format[*position], 10) && width > 0) {
//       exponent = exponent * 10 + (format[*position] - '0');
//       (*position)++;
//       width--;
//     }
//     result *= powl(10, exp_sign * exponent);
//   } else if (start != *position) {
//     pf->error = 11;  // format exp error
//     pf->count++;
//   }

//   return sign * result;
// }

static int is_digital(char ch, int base) {
  if (base == 8)
    return ch >= '0' && ch <= '7';
  else if (base == 10)
    return ch >= '0' && ch <= '9';
  else if (base == 16)
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
  return 0;
}

static int read_int(const char **str) {
    int value = 0;
    while (**str >= '0' && **str <= '9') {
        value = value * 10 + (**str - '0');
        (*str)++;
    }
    return value;
}

static int is_end_str(char ch) {
    return isspace((unsigned char)ch);
}

static void cmp_symbols(const char *str, const char *format, pos_format_t *pf) {
  if (format[pf->pos_format] != str[pf->pos_str]) {
    pf->error = 1;
  } else {
    pf->pos_str++;
    pf->pos_format++;
  }
}

static type_label_t get_signatur(const char *format, pos_format_t *pf) {
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
    label.size = format[pf->pos_format++];
  }
  if (isalpha(format[pf->pos_format])) {
    label.type = format[pf->pos_format];
  }
  label.end = pf->pos_format++;
  return label;
}

static void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf, va_list parm) {
  s21_size_t start = pf->pos_str;
  if (type.type == 'p') {
    if (!type.ignor) {
      make_p(va_arg(parm, void **), str, pf, type);
    } else {
      make_p(NULL, str, pf, type);
    }
  } else if (type.type == '%') {
    if (type.width == 0) pf->pos_format = type.end;
  } else {
    void *label_void = NULL;
    if (!type.ignor) {
      label_void = va_arg(parm, void *);
    }
    switch (type.type) {
    //   case 'c':
    //     make_c(label_void, str, pf, type);
        // break;
      case 'd':
      case 'i':
        make_di(label_void, str, pf, type);
        break;
    //   case 's':
    //     make_s(label_void, str, pf, type);
    //     break;
    //   case 'f':
    //   case 'G':
    //   case 'g':
    //   case 'E':
    //   case 'e':
    //     make_fGgEe(label_void, str, pf, type);
    //     break;
      case 'o':
      case 'u':
      case 'x':
      case 'X':
        make_uoxX(label_void, str, pf, type);
        break;
    //   case 'n':
    //     make_n(label_void, pf, type);
    //     break;
      default:
        pf->error = 20;  // not valid type
    }
    if (start == pf->pos_str && type.type != '%' && type.type != 'n') {
      pf->error = 9;  // empty data
    }
    if (label_void != NULL && !pf->error) {
      pf->count++;
    }
  }
}

static void make_di(void *i, const char *str, pos_format_t *pf, type_label_t t) {
  long long int value = 0;
  int error = 0;
  value = str_to_int(str, pf, t, 0);
  pf->error = error;
  if (!t.ignor) {
    if (t.size == '\0')
      *((int *)i) = (int)value;
    else if (t.size == 'l')
      *((long int *)i) = (long int)value;
    else if (t.size == 'L')
      *((long long int *)i) = (long long int)value;
    else if (t.size == 'h')
      *((short int *)i) = (short int)value;
  }
}

static void make_uoxX(void *i, const char *str, pos_format_t *pf, type_label_t t) {
  long long unsigned int value = 0;
  int error = 0;
  if (t.type == 'u')
    value = str_to_int(str, pf, t, 10);
  else if (t.type == 'o')
    value = str_to_int(str, pf, t, 8);
  else if (t.type == 'x' || t.type == 'X')
    value = str_to_int(str, pf, t, 16);
  pf->error = error;
  if (!t.ignor) {
    if (t.size == '\0')
      *((unsigned int *)i) = (unsigned int)value;
    else if (t.size == 'l')
      *((long unsigned int *)i) = (long unsigned int)value;
    else if (t.size == 'L')
      *((long long unsigned int *)i) = (long long unsigned int)value;
    else if (t.size == 'h')
      *((short unsigned int *)i) = (short unsigned int)value;
  }
}

static void make_p(void **i, const char *str, pos_format_t *pf, type_label_t t) {
  s21_size_t start = pf->pos_str;
  s21_size_t address = (s21_size_t)str_to_int(str, pf, t, 16);
  if (start == pf->pos_str) pf->error = 9;
  if (!t.ignor) {
    *i = (void *)address;
    if (!pf->error) pf->count++;
  }
}

static long long int str_to_int(const char *format, pos_format_t *pf, type_label_t type, int base) {
  int sign = 1;
  long long int result = 0;
  s21_size_t *position = &pf->pos_str;
  int width = type.width == 0 ? DEFAULT_WIDTH : type.width;

  if (format[*position] == '-' || format[*position] == '+') {
    if (format[*position] == '-') sign = -1;
    (*position)++;
    width--;
  }

  if ((base == 16 || base == 0) && format[*position] == '0' && format[*position + 1] == 'x') {
    base = 16;
    (*position) += 2;
    width -= 2;
  }
  if ((base == 8 || base == 0) && format[*position] == '0') {
    base = 8;
    (*position) += 1;
    width--;
  }
  if (base == 0) base = 10;

  while (is_digital(format[*position], base) && width > 0) {
    result = result * base + char_to_digit(format[(*position)++]);
    width--;
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

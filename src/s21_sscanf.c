#include "s21_string.h"

#define DEFAULT_WIDTH 50

struct pos_format {
  s21_size_t pos_str;
  s21_size_t pos_format;
  int count;
  int error;
};
struct type_label {
  int start;
  int end;
  int width;
  int size;
  int ignor;
  char type;
};

long double str_to_float(const char *format, struct pos_format *pos_format, struct type_label type) {
  int sign = 1, exp_sign = 1, exponent = 0, decimal_digits = 0;
  long double result = 0.0;
  s21_size_t start = pos_format->pos_str;
  s21_size_t *position = &pos_format->pos_str;
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
    pos_format->error = 11;  // format exp error
    pos_format->count++;
  }

  return sign * result;
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
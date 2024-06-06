#include "s21_string.h"


int_to_string(int num, char* buffer);
double_to_string(double num, char* buffer);

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list args;
  va_start(args, format);
  int length = 0;
  
  for (int i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      spec spec = {"", INT_MIN, INT_MIN, '\0'};
      i = parse_spec(i, format, &spec, &args);
      if (format[i] == 'n') {
        *(va_arg(args, int *)) = length;
      } else {
        length += process_specifier(str + length, format[i], spec, &args);
      }
    } else {
      str[length++] = format[i];
      str[length] = '\0';
    }
  }
  
  va_end(args);
  return length;
}

int parse_spec(int i, const char *format, spec *spec, va_list *args) {
  i++;
  while (s21_strchr("-+ #0", format[i])) {
    spec->flags[s21_strlen(spec->flags)] = format[i++];
  }
  while (isdigit(format[i])) {
    spec->width = spec->width * 10 + (format[i++] - '0');
  }
  if (format[i] == '*') {
    spec->width = va_arg(*args, int);
    i++;
  }
  if (format[i] == '.') {
    i++;
    spec->precision = 0;
    while (isdigit(format[i])) {
      spec->precision = spec->precision * 10 + (format[i++] - '0');
    }
    if (format[i] == '*') {
      spec->precision = va_arg(*args, int);
      i++;
    }
  }
  if (s21_strchr("hlL", format[i])) {
    spec->length = format[i++];
  }
  return i;
}

int process_specifier(char *str, char specifier, spec spec, va_list *args) {
  int length = 0;
  char buffer[1024];
  buffer[0] = '\0';

  switch (specifier) {
    case '%':
      s21_strcat(str, "%");
      length = 1;
      break;
    case 'c':
      buffer[0] = (char) va_arg(*args, int);
      buffer[1] = '\0';
      s21_strcat(str, buffer);
      length = 1;
      break;
    case 's':
      s21_strcat(str, va_arg(*args, char *));
      length = s21_strlen(str);
      break;
    case 'd':
    case 'i':
      itoa(va_arg(*args, int), buffer, 10);
      s21_strcat(str, buffer);
      length = s21_strlen(buffer);
      break;
    // Остальные случаи для других спецификаторов
  }

  return length;
}

int base_precision(int precision, int symbol) {
  if (precision < 0) {
    s21_strchr("diouxX", symbol) ? precision = 1 : 0;
    s21_strchr("eEfgG", symbol) ? precision = 6 : 0;
    s21_strchr("p", symbol) ? precision = 16 : 0;
  }
  return precision;
}

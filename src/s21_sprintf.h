#ifndef  S21_SPRINTF_H
#define S21_SPRINTF_H

typedef struct {
  char flags[10];
  int width;
  int precision;
  char length;
} spec;

int s21_sprintf(char *str, const char *format, ...);
int_to_string(int num, char* buffer);
double_to_string(double num, char* buffer);
int base_precision(int precision, int symbol);

#endif //S21_SPRINTF_H
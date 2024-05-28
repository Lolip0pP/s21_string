#ifndef  S21_SPRINTF_H
#define S21_SPRINTF_H

typedef struct {
  char flag[10];
  int width;
  int accuracy;
  char type;
} spec;

int s21_sprintf(char *str, const char *format, ...);
int_to_string(int num, char* buffer);
double_to_string(double num, char* buffer);

#endif //S21_SPRINTF_H
#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...);
int_to_string(int num, char* buffer);
double_to_string(double num, char* buffer);

int base_accuracy(int accuracy, int symbol) {
  if (accuracy < 0) {
    s21_strchr("diouxX", symbol) ? accuracy = 1 : 0;
    s21_strchr("eEfgG", symbol) ? accuracy = 6 : 0;
    s21_strchr("p", symbol) ? accuracy = 16 : 0;
  }
  return accuracy;
}

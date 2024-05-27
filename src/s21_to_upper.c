#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *new_string = malloc(s21_strlen(str) + 1);

  for (int i = 0; i < s21_strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_string[i] = str[i] - 32;
    } else {
      new_string[i] = str[i];
    }
  }

  new_string[s21_strlen(str)] = '\0';

  return new_string;
}

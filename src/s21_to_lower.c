#include "s21_string.h"

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *new_string = malloc(len + 1);
  if (new_string == NULL) {
      return NULL; // обработка ошибки выделения памяти
  }
  
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_string[i] = str[i] + 32;
    } else {
      new_string[i] = str[i];
    }
  }

  new_string[len] = '\0';

  return new_string;
}
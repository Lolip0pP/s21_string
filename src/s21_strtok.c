#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = s21_NULL;
  char *token = s21_NULL;

  if (str) {
    next_token = str;
  }

  if (next_token) {
    token = next_token + s21_strspn(next_token, delim);

    if (*token != '\0') {
      next_token = token + s21_strcspn(token, delim);

      if (*next_token != '\0') {
        *next_token = '\0';
        next_token++;
      } else {
        next_token = s21_NULL;
      }
    } else {
      token = s21_NULL;
      next_token = s21_NULL;
    }
  }

  return token;
}

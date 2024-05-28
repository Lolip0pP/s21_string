#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *str1 = (char *)dest;
  const char *str2 = (const char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    str1[i] = str2[i];
  }

  return dest;
}

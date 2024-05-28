#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *big = (const char *)str;
  s21_size_t i = 0;

  while (i < n && big[i] != c) {
    i++;
  }

  return (i < n) ? (void *)&big[i] : s21_NULL;
}

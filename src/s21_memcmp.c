#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int count = 0;

  if (n != 0) {
    const char *p1 = str1, *p2 = str2;

    do {
      if (*p1++ != *p2++) count = (n != 0) ? (*--p1 - *--p2) : 0;
    } while (--n != 0 && !count);
  }

  return count;
}

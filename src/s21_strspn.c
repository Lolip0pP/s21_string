#include "s21_string.h"

s21_size_t s21_strspn(const char *str, const char *sym) {
  const char *ptr = str;
  while (*ptr && s21_strchr(sym, *ptr)) {
    ptr++;
  }
  return ptr - str;
}

#include "s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *sym) {
<<<<<<< HEAD
    const char *ptr = str;
    while (*ptr && !s21_strchr(sym, *ptr)) {
        ptr++;
    }
    return ptr - str;
}
=======
  const char *ptr = str;
  while (*ptr && !s21_strchr(sym, *ptr)) {
    ptr++;
  }
  return ptr - str;
}
>>>>>>> bandwidl

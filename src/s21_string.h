#ifndef CHECK_TEST_EXAMPLE_STRLEN_H
#define CHECK_TEST_EXAMPLE_STRLEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);

#endif  // CHECK_TEST_EXAMPLE_STRLEN_H
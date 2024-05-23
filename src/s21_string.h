#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

s21_size_t s21_strspn(const char *str, const char *sym);
s21_size_t s21_strcspn(const char *str, const char *sym);
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

#endif  // S21_STRING_H
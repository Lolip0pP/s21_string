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
#define S21_INF (1.0 / 0.0)
#define S21_NINF (-1.0 / 0.0)

typedef long unsigned s21_size_t;

s21_size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str, const char *sym);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strspn(const char *str, const char *sym);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
int s21_strncasecmp(const char *s1, const char *s2, s21_size_t n);

#endif  // S21_STRING_H
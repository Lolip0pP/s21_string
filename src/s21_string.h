<<<<<<< HEAD
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

=======
#ifndef CHECK_TEST_EXAMPLE_STRLEN_H
#define CHECK_TEST_EXAMPLE_STRLEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
>>>>>>> bandwidl
#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

<<<<<<< HEAD
s21_size_t s21_strspn(const char *str, const char *sym);
s21_size_t s21_strcspn(const char *str, const char *sym);
char *s21_strchr(const char *str, int c);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
=======
s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str, const char *sym);
>>>>>>> bandwidl
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
<<<<<<< HEAD

#endif  // S21_STRING_H
=======
s21_size_t s21_strspn(const char *str, const char *sym);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

#endif  // CHECK_TEST_EXAMPLE_STRLEN_H
>>>>>>> bandwidl

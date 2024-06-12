#ifndef S21_SPRINTF
#define S21_SPRINTF

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"
#include <wchar.h>

#define F_L_ALIGNMENT (1 << 0)
#define F_PLUS        (1 << 1)
#define F_SPACE       (1 << 2)
#define F_POINT       (1 << 3)
#define F_ZERO        (1 << 4)

#define F_SHORT       (1 << 5)
#define F_LONG_I      (1 << 6)
#define F_LONG_D      (1 << 7)
#define F_UNSIGNED      (1 << 8)

#define F_FLOAT       (1 << 9)
#define F_START       (1 << 10)
#define F_MINUS       (1 << 11)
#define F_COMPACT     (1 << 12)
#define F_GEN         (1 << 13)
#define F_MANTISSA    (1 << 14)
#define F_ACCURACY    (1 << 15)

#define F_OCT         (1 << 16)
#define F_HEX         (1 << 17)
#define F_UPP         (1 << 18)

typedef struct {
  unsigned int flags;
  int width;
  int accuracy;
  int type;
} setup_t;

int s21_sprintf(char *result, const char *format, ...);
int read_specifier(char *result, char spec, setup_t setup_t, va_list *params);
int read_arg(char *str, setup_t setup_t, long double arg);
int read_s(char *str, setup_t setup, va_list *params);
int read_c(char *str, setup_t setup, va_list *params);
void num_to_string(char *str, unsigned long int num, int *index, int accuracy, unsigned int flags);
int mantissa(char *str, setup_t setup, int log);
int r_log(long double arg);
setup_t get_setup(int *cur, const char *format, va_list *params);
long double get_double(va_list *params, int type);
long double get_int(va_list *params, int type);
int get_accuracy(char spec);
int format(char *str, int length, int width, int flags, char ch);

#endif

#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include "s21_string.h"

#define DEFAULT_WIDTH 50

typedef struct {
  s21_size_t pos_str;
  s21_size_t pos_format;
  int count;
  int error;
} pos_format_t;

typedef struct {
  int start;
  int end;
  int width;
  int size;
  int ignor;
  char type;
  char flags;
  int precision;
} type_label_t;

void check_format(const char *str, const char *format, va_list parm, pos_format_t *pf);
type_label_t get_signature(const char *format, pos_format_t *pf);
void cmp_symbol(const char *str, const char *format, pos_format_t *pf);
int get_size_type(const char *format, s21_size_t *position);
int is_digital(char ch, int base);
int is_flag(char ch);
int is_size(char ch);
int is_end_str(char ch);
int is_spec(char ch);
int char_to_number(char ch);
int check_format_base(const char *str, s21_size_t *position);
long long int str_to_int(const char *str, s21_size_t *position, int base, int width, int *error);
long double str_to_float(const char *format, pos_format_t *pf, type_label_t type);
void find_and_set_value(type_label_t type, const char *str, pos_format_t *pf, va_list parm);
void make_di(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_c(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_s(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_fGgEe(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_n(void *label, pos_format_t *pf, type_label_t type);
void make_uoxX(void *label, const char *str, pos_format_t *pf, type_label_t type);
void make_p(void **label, const char *str, pos_format_t *pf, type_label_t type);

#endif  // S21_SSCANF_H
#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index){
  char *new_str = s21_NULL;

  if (src != s21_NULL){
    int src_len = s21_strlen(src), sub_len = s21_strlen(str);
    int new_len = src_len + sub_len;
    new_str = (char *)malloc(new_len + 1);

    if (new_str != s21_NULL && start_index <= (size_t)src_len) {
      s21_strncpy(new_str, src, start_index);
      s21_strncpy(new_str + start_index, str, sub_len);
      s21_strcpy(new_str + start_index + sub_len, src + start_index);
    } else {
      new_str = s21_NULL;
    }
  }

  return new_str;
}

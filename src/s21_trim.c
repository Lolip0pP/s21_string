#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;

  if (src != s21_NULL) {
    if (trim_chars != s21_NULL) {
      int start_src = 0;
      int end_src = s21_strlen(src) - 1;

      while (s21_find_trim_chars(src[start_src], trim_chars)) {
        start_src++;
      }

      while (end_src > start_src &&
             s21_find_trim_chars(src[end_src], trim_chars)) {
        end_src--;
      }

      int new_len = end_src - start_src + 1;
      new_str = (char *)malloc(new_len + 1);

      if (new_str != s21_NULL) {
        s21_memcpy(new_str, &src[start_src], new_len);
        new_str[new_len] = '\0';
      }

    } else {
      new_str = (char *)malloc(s21_strlen(src) + 1);
      s21_strncpy(new_str, src, s21_strlen(src) + 1);
    }
  }

  return new_str;
}

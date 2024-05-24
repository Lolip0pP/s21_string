#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    
    while (*str1 && result == s21_NULL) {
        if (s21_strchr(str2, *str1)) {
            result = (char *)str1;
        } else {
            str1++;
        }
    }
    
    return result;
}

#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    int len = s21_strlen(str);
    const char *result = s21_NULL;

    for (int i = len; result == s21_NULL && i >= 0; i--) {
        if (str[i] == c)
            result = str + i;
    }

    return (char*) result;
}
#include "s21_string.h"

char *s21_strcat(char *dest, const char *str) {
    char *tmp = dest;

    while (*dest) dest++;

    while (*str) {
        *dest = *str;
        dest++;
        str++;
    }

    *dest = '\0';

    return tmp;
}

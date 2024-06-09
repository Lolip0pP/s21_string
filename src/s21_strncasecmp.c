#include "s21_string.h"

static inline char s21_to_lower_char(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;
    }
    return ch;
}

int s21_strncasecmp(const char *s1, const char *s2, s21_size_t n) {
    if (n == 0) return 0;

    while (n-- > 0) {
        unsigned char c1 = (unsigned char)*s1++;
        unsigned char c2 = (unsigned char)*s2++;
        char lower_c1 = s21_to_lower_char(c1);
        char lower_c2 = s21_to_lower_char(c2);

        if (lower_c1 != lower_c2) return (int)(unsigned char)lower_c1 - (int)(unsigned char)lower_c2;
        if (lower_c1 == '\0') return 0;
    }

    return 0;
}
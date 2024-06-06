#include "s21_string.h"

int s21_strncasecmp(const char *s1, const char *s2, s21_size_t n) {
    if (n == 0) return 0;

    while (n-- > 0) {
        char c1 = s21_to_lower((unsigned char)*s1);
        char c2 = s21_to_lower((unsigned char)*s2);
        
        if (c1 != c2) return c1 - c2;
        if (c1 == '\0') return 0;
        
        s1++;
        s2++;
    }
    
    return 0;
}
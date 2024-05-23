#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
    char *result = s21_NULL;

    if (*needle == '\0') {
        result = (char *)haystack;
    } else {
        while (*haystack != '\0' && result == s21_NULL) {
            const char *h = haystack;
            const char *n = needle;

            while (*h != '\0' && *n != '\0' && *h == *n) {
                h++;
                n++;
            }

            if (*n == '\0') {
                result = (char *)haystack;
            }

            haystack++;
        }
    }

    return result;
}

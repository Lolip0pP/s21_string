#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>


s21_size_t s21_strlen(const char *str)
{
    s21_size_t len = 0;
    for(; str[len]; len++);
    return len;
} 

void *s21_memchr(const void *str, int c, size_t n)
{
 const char *big = (const char *)str;
    size_t i = 0;
    
    while (i < n && big[i] != c) {
        i++;
    }

    return (i < n) ? (void *)&big[i] : NULL;
}

int s21_memcmp(const void *str1, const void *str2, size_t n){
	
int flag = 0;

	if (n != 0) {
		register const unsigned char *p1 = str1, *p2 = str2;
		do {
			if (*p1++ != *p2++){
				if (*p1 > *p2){
                    flag = 1;
                }else
                flag =-1;
            }
		} while (--n != 0);
	}
	return flag;
}

void *s21_memcpy(void *dest, const void *src, size_t n){
    char* str1 = (char*)dest;
    const char* str2 = (const char*)src;

    for (size_t i = 0; i < n; i++) {
        str1[i] = str2[i];
    }

    return dest;
}

void *s21_memset(void *str, int c, size_t n){
if (s21_strlen(str)>=n){
unsigned char* tmp = (unsigned char*)str;

for (size_t i = 0; i < n; i++) {
tmp[i] = (unsigned char)c;
}

return str;
}else
return NULL;
}

char *s21_strncat(char *dest, const char *src, size_t n){
char *dest_start = dest;
    while (*dest != '\0') {
        dest++;
    }
    size_t dest_len = dest - dest_start;
    size_t src_len = 0;
    const char *src_end = src;
    while (*src_end != '\0' && (size_t)(src_end - src) < n) {
    src_end++;
    src_len++;
}
    if (dest_len + src_len >= n) {
        return dest_start;
    }
    
    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }
    
    *dest = '\0'; 
    return dest_start;
}

char *s21_strncpy(char *dest, const char *src, size_t n){
    char* start = dest;  

    while (n != 0 && (*dest++ = *src++)) {
       n--;
    }

    *dest = '\0';

    return start;
}

char *s21_strchr(const char *str, int c){

  while (*str != c && *str != '\0') {
        str++;
    }
    return (*str == c) ? (char *)str : NULL;

}








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
	size_t i;
	for (i = 0; i < n; i++)
		if (big[i] == c)
			return (void *)&big[i];
	return NULL;
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

// char *s21_strncat(char *dest, const char *src, size_t n){

//    unsigned char len1 = s21_strlen(dest);
//     unsigned char len2 = s21_strlen(src);
    
//     if (len2 < n) {
// 	s21_strncpy(&dest[len1], src, len2);
//     } else {
// 	s21_strncpy(&dest[len1], src, n);
// 	dest[len1 + n] = '\0';
//     }
//     return dest;
// }

char *s21_strncpy(char *dest, const char *src, size_t n){
    char* start = dest;  

    while (n != 0 && (*dest++ = *src++)) {
       n--;
    }

    *dest = '\0';
    return start;
}









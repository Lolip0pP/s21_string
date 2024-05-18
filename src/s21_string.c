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








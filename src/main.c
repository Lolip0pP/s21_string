#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[100];
    int length;
    fgets(string,100,stdin);

    printf("%p\n",  memcpy(string, "",1));
    printf("%p\n",  s21_memcpy(string, "",1));
    return 0;
}
void *s21_memcpy(void *dest, const void *src, size_t n){
    char* str1 = (char*)dest;
    const char* str2 = (const char*)src;

    for (size_t i = 0; i < n; i++) {
        str1[i] = str2[i];
    }

    return dest;
}
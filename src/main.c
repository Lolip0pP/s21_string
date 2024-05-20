#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[4] = "1234";
    // int length;
    // fgets(string,100,stdin);
    char src[10] = "1234567890";
    char dest1[10] = "0000000000";
   printf("%p\n",  strncpy(dest1,src, 10));
   printf("%p\n",  s21_strncpy(dest1,src, 10));
   printf("%s\n", dest1);
    return 0;

}

char *s21_strncpy(char *dest, const char *src, size_t n){
    char* start = dest;  
    while (n != 0 && (*dest++ = *src++)) {
       n--;
    }

    *dest = '\0';
    return start;
}

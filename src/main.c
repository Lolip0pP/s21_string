#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[4] = "1234";
    // int length;
    // fgets(string,100,stdin);

  //  printf("%p\n",  memset(string,'0',5));
   printf("%p\n",  s21_memset(string,'0',5));
   printf("%s\n", string);
    return 0;

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

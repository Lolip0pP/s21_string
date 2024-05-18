#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[100];
    int length;
    fgets(string,100,stdin);

    memcmp("hello", "hell",0);
    printf("%d\n",  memcmp("hello", "hedllo",5));
    return 0;
}
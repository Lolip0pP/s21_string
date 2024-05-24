#include "s21_string.h"


int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
  
  	int result = 0;
	char u1 = *str1;
    char u2 = *str2;
    while (result == 0 && n > 0) {
        if (u1 != u2 || u1 == '\0') {
            result = (int)(u1 - u2);
        }
        
        str1++;
        str2++;
		n--;
    }
    
    return result;
}
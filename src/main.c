// #include "s21_string.h"

// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     char src[] = "1234567890";
//     char dest1[] = "1111111111";
//     //char dest2[20] = "0000000000";
//     printf("%p\n",  strncat(dest1,src, 7));
//     printf("%s\n", dest1);
//     // printf("%p\n",  s21_strncat(dest2,src, 3));
//     // printf("%s\n", dest2);
//     return 0;

// }

// char *s21_strncat(char *dest, const char *src, size_t n){

//    char *save = dest;
    
//     // Находим конец dest
//     while (*dest != '\0') {
//         dest++;
//     }

//     // Копируем src до символа '\0' или до n символов
//     while (n > 0 && *src != '\0') {
//         *dest = *src;
//         dest++;
//         src++;
//         n--;
//     }

//     *dest = '\0';  // Добавляем завершающий нуль

//     return save; // Возвращаем указатель на начало строки
// }

// char *s21_strncpy(char *dest, const char *src, size_t n){
//     char* start = dest;  

//     while (n != 0 && (*dest++ = *src++)) {
//        n--;
//     }

//     *dest = '\0';
//     return start;
// }



// s21_size_t s21_strlen(const char *str)
// {
//     s21_size_t len = 0;
//     for(; str[len]; len++);
//     return len;
// } 
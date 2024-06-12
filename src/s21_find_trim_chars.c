#include "s21_string.h"


int s21_find_trim_chars(char c, const char *trim_chars) {
int flag = 0;
while (*trim_chars && !flag) {
flag = (*trim_chars == c);
trim_chars++;
}
return flag;
}

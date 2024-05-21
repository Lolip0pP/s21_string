#ifndef CHECK_TEST_EXAMPLE_TEST_H
#define CHECK_TEST_EXAMPLE_TEST_H

/**
install check: https://libcheck.github.io/check/web/install.html

then add an environment variables as follows
export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib
**/
#include <check.h>
#include "../s21_string.h"

Suite* s21_strlen_test(void);
Suite* s21_memchr_test(void);
Suite* s21_memcmp_test(void);
Suite* s21_memcpy_test(void);
Suite* s21_memset_test(void);
Suite* s21_strncpy_test(void);
Suite* s21_strncat_test(void);
Suite* s21_strchr_test(void);


#endif //CHECK_TEST_EXAMPLE_TEST_H
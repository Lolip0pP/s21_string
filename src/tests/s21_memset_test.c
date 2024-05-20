
#include "test.h"


START_TEST(test_memset) {
    char string1[10] = "1234567890";
    char string2[6] = "hello";
    char string3[7] = "      ";
    ck_assert_str_eq(s21_memset(string1,'1', 3), memset(string1,'1', 3));
    ck_assert_str_eq(s21_memset(string2,'\n', 5), memset(string2,'\n', 5));
    ck_assert_str_eq(s21_memset(string3,'3', 2), memset(string3,'3', 2));
}

END_TEST


Suite* s21_memset_test(void) {

    Suite* suite;
    TCase* core;

    suite = suite_create("s21_memset");
    core = tcase_create("Core");

    tcase_add_test(core, test_memset);

    suite_add_tcase(suite, core);

    return (suite);
}
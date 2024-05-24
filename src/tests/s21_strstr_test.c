#include "test.h"

START_TEST(test_strstr) {
    char str1[11] = "0123456";
    char str2[11] = "123";
    char str3[11] = "321";
    char str4[11] = "345";
    ck_assert_ptr_eq(s21_strstr(str1,str2), strstr(str1,str2));
    ck_assert_ptr_eq(s21_strstr(str1,str3),strstr(str1,str3));
    ck_assert_ptr_eq(s21_strstr(str1,str4), strstr(str1,str4));
}

END_TEST


Suite* s21_strstr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strstr");
    core = tcase_create("Core");

    tcase_add_test(core, test_strstr);

    suite_add_tcase(suite, core);

    return (suite);
}



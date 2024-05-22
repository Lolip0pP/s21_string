#include "test.h"


START_TEST(test_strncmp) {
    char str1[11] = "1234567890";
    char str2[11] = "0000000000";
    char str3[11] = "0000000000";
    char str4[11] = "0000000111";
    ck_assert_int_eq(s21_strncmp(str1,str2, 7), strncmp(str1,str2, 7));
    ck_assert_int_eq(s21_strncmp(str2,str3, 11), strncmp(str2,str3, 11));
    ck_assert_int_eq(s21_strncmp(str3,str4, 5), strncmp(str3,str4, 5));
}

END_TEST


Suite* s21_strncmp_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strncmp");
    core = tcase_create("Core");

    tcase_add_test(core, test_strncmp);

    suite_add_tcase(suite, core);

    return (suite);
}

#include "test.h"

START_TEST(test_strspn) {
    char str1[11] = "123";
    char str2[11] = "124";
    char str3[11] = "321";
    char str4[11] = "324";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
    ck_assert_int_eq(s21_strspn(str2,str3),strspn(str2,str3));
    ck_assert_int_eq(s21_strspn(str3,str4), strspn(str3,str4));
}

END_TEST


Suite* s21_strspn_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strspn");
    core = tcase_create("Core");

    tcase_add_test(core, test_strspn);

    suite_add_tcase(suite, core);

    return (suite);
}
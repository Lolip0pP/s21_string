
#include "test.h"

START_TEST(test_strcspn) {
    char str1[11] = "123";
    char str2[11] = "124";
    char str3[11] = "321";
    char str4[11] = "324";
    ck_assert_int_eq(s21_strcspn(str1,str2), strcspn(str1,str2));
    ck_assert_int_eq(s21_strcspn(str2,str3),strcspn(str2,str3));
    ck_assert_int_eq(s21_strcspn(str3,str4), strcspn(str3,str4));
}

END_TEST


Suite* s21_strcspn_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strcspn");
    core = tcase_create("Core");

    tcase_add_test(core, test_strcspn);

    suite_add_tcase(suite, core);

    return (suite);
}
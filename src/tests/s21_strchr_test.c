#include "test.h"


START_TEST(test_strchr) {
    ck_assert_ptr_eq(s21_strchr("hello",'l'), strchr("hello",'l'));
    ck_assert_ptr_eq(s21_strchr("123",'3'), strchr("123",'3'));
    ck_assert_ptr_eq(s21_strchr("privet k",' '), strchr("privet k",' '));
    ck_assert_ptr_eq(s21_strchr("privet k",'d'), strchr("privet k",'d'));
}

END_TEST


Suite* s21_strchr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strchr");
    core = tcase_create("Core");

    tcase_add_test(core, test_strchr);

    suite_add_tcase(suite, core);

    return (suite);
}
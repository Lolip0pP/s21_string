#include "test.h"


START_TEST(test_memcpy) {
    char string[10];
    ck_assert_str_eq(s21_memcpy(string, "hello",6), memcpy(string,"hello", 6));
    ck_assert_str_eq(s21_memcpy(string,"123",3), memcpy(string,"123",3));
    ck_assert_str_eq(s21_memcpy(string,"privet k", 9), memcpy(string,"privet k", 9));
    ck_assert_str_eq(s21_memcpy(string,"", 0), memcpy(string,"", 0));
    ck_assert_str_eq(s21_memcpy(string,"", 1), memcpy(string,"", 1));
    ck_assert_str_eq(s21_memcpy(string,"g", 0), memcpy(string,"g", 0));
}

END_TEST


Suite* s21_memcpy_test(void) {
    Suite* suite;

    TCase* core;

    suite = suite_create("s21_memcpy");
    core = tcase_create("Core");

    tcase_add_test(core, test_memcpy);

    suite_add_tcase(suite, core);

    return (suite);
}
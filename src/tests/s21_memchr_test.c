#include "test.h"


START_TEST(test_memchr) {
    ck_assert_str_eq(s21_memchr("hello",'l', 7), memchr("hello",'l', 7));
    ck_assert_str_eq(s21_memchr("123",'3', 4), memchr("123",'3', 4));
    ck_assert_str_eq(s21_memchr("privet k",' ', 9), memchr("privet k",' ', 9));
}

END_TEST


Suite* s21_memchr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_memchr");
    core = tcase_create("Core");

    tcase_add_test(core, test_memchr);

    suite_add_tcase(suite, core);

    return (suite);
}
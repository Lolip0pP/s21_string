#include "test.h"


START_TEST(test_memcmp) {
    ck_assert_int_eq(s21_memcmp("hello","hello", 7), memcmp("hello","hello", 7));
    ck_assert_int_eq(s21_memcmp("123","23", 3), memcmp("123","23", 3));
    ck_assert_int_eq(s21_memcmp("privet k"," ", 1), memcmp("privet  k"," ", 1));
}

END_TEST


Suite* s21_memcmp_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_memcmp");
    core = tcase_create("Core");

    tcase_add_test(core, test_memcmp);

    suite_add_tcase(suite, core);

    return (suite);
}
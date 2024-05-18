#include "test.h"

START_TEST(test_strlen) {
    ck_assert_int_eq(s21_strlen("hello"), strlen("hello"));
    ck_assert_int_eq(s21_strlen("11"), strlen("11"));
    ck_assert_int_eq(s21_strlen("privet"), strlen("privet"));
}

END_TEST


Suite* s21_strlen_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strlen");
    core = tcase_create("Core");

    tcase_add_test(core, test_strlen);

    suite_add_tcase(suite, core);

    return (suite);
}
#include "test.h"


START_TEST(test_strncpy) {
    char src[10] = "1234567890";
    char dest1[10] = "0000000000";
    char dest2[10] = "1111111111";
    ck_assert_str_eq(s21_strncpy(dest1,src, 7), strncpy(dest1,src, 7));
    ck_assert_str_eq(s21_strncpy(dest1,src, 1), strncpy(dest1,src, 1));
    ck_assert_str_eq(s21_strncpy(dest2,src, 10), strncpy(dest2,src, 10));
}

END_TEST


Suite* s21_strncpy_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strncpy");
    core = tcase_create("Core");

    tcase_add_test(core, test_strncpy);

    suite_add_tcase(suite, core);

    return (suite);
}
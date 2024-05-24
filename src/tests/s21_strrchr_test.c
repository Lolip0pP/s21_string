#include "test.h"


START_TEST(test_strrchr) {
    ck_assert_ptr_eq(s21_strrchr("hello",'l'), strrchr("hello",'l'));
    ck_assert_ptr_eq(s21_strrchr("12323",'3'), strrchr("12323",'3'));
    ck_assert_ptr_eq(s21_strrchr("privet k",' '), strrchr("privet k",' '));
    ck_assert_ptr_eq(s21_strrchr("privet k",'d'), strrchr("privet k",'d'));
}

END_TEST


Suite* s21_strrchr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strrchr");
    core = tcase_create("Core");

    tcase_add_test(core, test_strrchr);

    suite_add_tcase(suite, core);

    return (suite);
}
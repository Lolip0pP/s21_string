#include "test.h"


START_TEST(test_NULL) {
    ck_assert_ptr_eq(s21_NULL,NULL);
}

END_TEST


Suite* s21_NULL_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_NULL");
    core = tcase_create("Core");

    tcase_add_test(core, test_NULL);

    suite_add_tcase(suite, core);

    return (suite);
}
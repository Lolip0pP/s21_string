#include "test.h"


START_TEST(test_size_t) {
    s21_size_t size1 = 10;
    size_t size2 = 10;
    ck_assert_uint_eq(size1, size2);
}

END_TEST


Suite* s21_size_t_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_size_t");
    core = tcase_create("Core");

    tcase_add_test(core, test_size_t);

    suite_add_tcase(suite, core);

    return (suite);
}
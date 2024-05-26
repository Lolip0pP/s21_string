#include "test.h"


START_TEST(test_size_t_1) {
    s21_size_t size1 = 10;
    size_t size2 = 10;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_2) {
    s21_size_t size1 = 0;
    size_t size2 = 0;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_3) {
    s21_size_t size1 = 2;
    size_t size2 = 2;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_4) {
    s21_size_t size1 = 999;
    size_t size2 = 999;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_5) {
    s21_size_t size1 = -4;
    size_t size2 = -4;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_6) {
    s21_size_t size1 = 22;
    size_t size2 = 22;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_7) {
    s21_size_t size1 = 1;
    size_t size2 = 1;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_8) {
    s21_size_t size1 = 01;
    size_t size2 = 01;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_9) {
    s21_size_t size1 = 14;
    size_t size2 = 14;
    ck_assert_uint_eq(size1, size2);
}
END_TEST

START_TEST(test_size_t_10) {
    s21_size_t size1 = -500;
    size_t size2 = -500;
    ck_assert_uint_eq(size1, size2);
}
END_TEST


Suite* s21_size_t_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_size_t");
    core = tcase_create("Core");

    tcase_add_test(core, test_size_t_1);
    tcase_add_test(core, test_size_t_2);
    tcase_add_test(core, test_size_t_3);
    tcase_add_test(core, test_size_t_4);
    tcase_add_test(core, test_size_t_5);
    tcase_add_test(core, test_size_t_6);
    tcase_add_test(core, test_size_t_7);
    tcase_add_test(core, test_size_t_8);
    tcase_add_test(core, test_size_t_9);
    tcase_add_test(core, test_size_t_10);

    suite_add_tcase(suite, core);

    return (suite);
}

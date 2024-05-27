#include "test.h"

START_TEST(test_memchr_1) {
  ck_assert_ptr_eq(s21_memchr("hello", 'l', 7), memchr("hello", 'l', 7));
}
END_TEST

START_TEST(test_memchr_2) {
  ck_assert_ptr_eq(s21_memchr("123", '3', 4), memchr("123", '3', 4));
}
END_TEST

START_TEST(test_memchr_3) {
  ck_assert_ptr_eq(s21_memchr("privet k", ' ', 9), memchr("privet k", ' ', 9));
}
END_TEST

START_TEST(test_memchr_4) {
  ck_assert_ptr_eq(s21_memchr("privet k", 'd', 9), memchr("privet k", 'd', 9));
}
END_TEST

START_TEST(test_memchr_5) {
  ck_assert_ptr_eq(s21_memchr("999899", '7', 7), memchr("999899", '7', 7));
}
END_TEST

START_TEST(test_memchr_6) {
  ck_assert_ptr_eq(s21_memchr("999899", '9', 3), memchr("999899", '9', 3));
}
END_TEST

START_TEST(test_memchr_7) {
  ck_assert_ptr_eq(s21_memchr(",,,...//", '/', 9), memchr(",,,...//", '/', 9));
}
END_TEST

START_TEST(test_memchr_8) {
  ck_assert_ptr_eq(s21_memchr("4815162342", '1', 11),
                   memchr("4815162342", '1', 11));
}
END_TEST

START_TEST(test_memchr_9) {
  ck_assert_ptr_eq(s21_memchr("ABDCabcd", 'c', 9), memchr("ABDCabcd", 'c', 9));
}
END_TEST

START_TEST(test_memchr_10) {
  ck_assert_ptr_eq(s21_memchr("25.05.2024", '.', 11),
                   memchr("25.05.2024", '.', 11));
}
END_TEST

Suite* s21_memchr_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_memchr");
  core = tcase_create("Core");

  tcase_add_test(core, test_memchr_1);
  tcase_add_test(core, test_memchr_2);
  tcase_add_test(core, test_memchr_3);
  tcase_add_test(core, test_memchr_4);
  tcase_add_test(core, test_memchr_5);
  tcase_add_test(core, test_memchr_6);
  tcase_add_test(core, test_memchr_7);
  tcase_add_test(core, test_memchr_8);
  tcase_add_test(core, test_memchr_9);
  tcase_add_test(core, test_memchr_10);

  suite_add_tcase(suite, core);

  return (suite);
}
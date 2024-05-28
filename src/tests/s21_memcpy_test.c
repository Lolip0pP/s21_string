#include "test.h"

START_TEST(test_memcpy_1) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "hello", 6), memcpy(string, "hello", 6));
}
END_TEST

START_TEST(test_memcpy_2) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "123", 3), memcpy(string, "123", 3));
}
END_TEST

START_TEST(test_memcpy_3) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "privet k", 9),
                   memcpy(string, "privet k", 9));
}
END_TEST

START_TEST(test_memcpy_4) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "", 0), memcpy(string, "", 0));
}
END_TEST

START_TEST(test_memcpy_5) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "", 1), memcpy(string, "", 1));
}
END_TEST

START_TEST(test_memcpy_6) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "", 0), memcpy(string, "", 0));
}
END_TEST

START_TEST(test_memcpy_7) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "g", 0), memcpy(string, "g", 0));
}
END_TEST

START_TEST(test_memcpy_8) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "adcd", 5), memcpy(string, "adcd", 5));
}
END_TEST

START_TEST(test_memcpy_9) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "4515162342", 11),
                   memcpy(string, "4515162342", 11));
}
END_TEST

START_TEST(test_memcpy_10) {
  char string[20];
  ck_assert_str_eq(s21_memcpy(string, "hahaha", 4),
                   memcpy(string, "hahaha", 4));
}
END_TEST

Suite* s21_memcpy_test(void) {
  Suite* suite;

  TCase* core;

  suite = suite_create("s21_memcpy");
  core = tcase_create("Core");

  tcase_add_test(core, test_memcpy_1);
  tcase_add_test(core, test_memcpy_2);
  tcase_add_test(core, test_memcpy_3);
  tcase_add_test(core, test_memcpy_4);
  tcase_add_test(core, test_memcpy_5);
  tcase_add_test(core, test_memcpy_6);
  tcase_add_test(core, test_memcpy_7);
  tcase_add_test(core, test_memcpy_8);
  tcase_add_test(core, test_memcpy_9);
  tcase_add_test(core, test_memcpy_10);

  suite_add_tcase(suite, core);

  return (suite);
}

#include "test.h"

START_TEST(test_memset_1) {
  char string[] = "1234567890";
  ck_assert_str_eq(s21_memset(string, '1', 3), memset(string, '1', 3));
}
END_TEST

START_TEST(test_memset_2) {
  char string[] = "hello";
  ck_assert_str_eq(s21_memset(string, '\n', 5), memset(string, '\n', 5));
}
END_TEST

START_TEST(test_memset_3) {
  char string[] = "     ";
  ck_assert_str_eq(s21_memset(string, '.', 5), memset(string, '.', 5));
}
END_TEST

START_TEST(test_memset_4) {
  char string[] = "hello world";
  ck_assert_str_eq(s21_memset(string, ' ', 12), memset(string, ' ', 12));
}
END_TEST

START_TEST(test_memset_5) {
  char string[] = "abcdABCD";
  ck_assert_str_eq(s21_memset(string, 'A', 9), memset(string, 'A', 9));
}
END_TEST

START_TEST(test_memset_6) {
  char string[] = "abcdABCD";
  ck_assert_str_eq(s21_memset(string, 'b', 5), memset(string, 'b', 5));
}
END_TEST

START_TEST(test_memset_7) {
  char string[] = "test/test";
  ck_assert_str_eq(s21_memset(string, 'e', 10), memset(string, 'e', 10));
}
END_TEST

START_TEST(test_memset_8) {
  char string[] = "hello/privet";
  ck_assert_str_eq(s21_memset(string, '/', 7), memset(string, '/', 7));
}
END_TEST

START_TEST(test_memset_9) {
  char string[] = "4515162342";
  ck_assert_str_eq(s21_memset(string, '1', 11), memset(string, '1', 11));
}
END_TEST

START_TEST(test_memset_10) {
  char string[] = "verter";
  ck_assert_str_eq(s21_memset(string, '>', 6), memset(string, '>', 6));
}
END_TEST

Suite* s21_memset_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_memset");
  core = tcase_create("Core");

  tcase_add_test(core, test_memset_1);
  tcase_add_test(core, test_memset_2);
  tcase_add_test(core, test_memset_3);
  tcase_add_test(core, test_memset_4);
  tcase_add_test(core, test_memset_5);
  tcase_add_test(core, test_memset_6);
  tcase_add_test(core, test_memset_7);
  tcase_add_test(core, test_memset_8);
  tcase_add_test(core, test_memset_9);
  tcase_add_test(core, test_memset_10);

  suite_add_tcase(suite, core);

  return (suite);
}
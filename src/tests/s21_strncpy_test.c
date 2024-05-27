#include "test.h"

START_TEST(test_strncpy_1) {
  char src[] = "1234567890";
  char dest1[] = "0000000000";
  ck_assert_str_eq(s21_strncpy(dest1, src, 7), strncpy(dest1, src, 7));
}
END_TEST

START_TEST(test_strncpy_2) {
  char src[] = "1234567890";
  char dest1[] = "0000000000";
  ck_assert_str_eq(s21_strncpy(dest1, src, 1), strncpy(dest1, src, 1));
}
END_TEST

START_TEST(test_strncpy_3) {
  char src[] = "1234567890";
  char dest1[] = "11111111111";
  ck_assert_str_eq(s21_strncpy(dest1, src, 10), strncpy(dest1, src, 10));
}
END_TEST

START_TEST(test_strncpy_4) {
  char src[] = "1234567890";
  char dest1[] = "          ";
  ck_assert_str_eq(s21_strncpy(dest1, src, 10), strncpy(dest1, src, 10));
}
END_TEST

START_TEST(test_strncpy_5) {
  char src[] = "          ";
  char dest1[] = "          ";
  ck_assert_str_eq(s21_strncpy(dest1, src, 10), strncpy(dest1, src, 10));
}
END_TEST

START_TEST(test_strncpy_6) {
  char src[] = "0000000000";
  char dest1[] = "          ";
  ck_assert_str_eq(s21_strncpy(dest1, src, 2), strncpy(dest1, src, 2));
}
END_TEST

START_TEST(test_strncpy_7) {
  char src[] = "0000000000";
  char dest1[] = "          ";
  ck_assert_str_eq(s21_strncpy(dest1, src, 6), strncpy(dest1, src, 6));
}
END_TEST

START_TEST(test_strncpy_8) {
  char src[] = "abcdABCD";
  char dest1[] = "abcdABCDE";
  ck_assert_str_eq(s21_strncpy(dest1, src, 6), strncpy(dest1, src, 6));
}
END_TEST

START_TEST(test_strncpy_9) {
  char src[] = "abcdABCD";
  char dest1[] = "abcdABCE";
  ck_assert_str_eq(s21_strncpy(dest1, src, 9), strncpy(dest1, src, 9));
}
END_TEST

START_TEST(test_strncpy_10) {
  char src[] = "1abcdABCD";
  char dest1[] = "2abcdABCE";
  ck_assert_str_eq(s21_strncpy(dest1, src, 8), strncpy(dest1, src, 8));
}
END_TEST

Suite* s21_strncpy_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strncpy");
  core = tcase_create("Core");

  tcase_add_test(core, test_strncpy_1);
  tcase_add_test(core, test_strncpy_2);
  tcase_add_test(core, test_strncpy_3);
  tcase_add_test(core, test_strncpy_4);
  tcase_add_test(core, test_strncpy_5);
  tcase_add_test(core, test_strncpy_6);
  tcase_add_test(core, test_strncpy_7);
  tcase_add_test(core, test_strncpy_8);
  tcase_add_test(core, test_strncpy_9);
  tcase_add_test(core, test_strncpy_10);

  suite_add_tcase(suite, core);

  return (suite);
}
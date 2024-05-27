#include "test.h"

START_TEST(test_strncmp_1) {
  char str1[] = "1234567890";
  char str2[] = "0000000000";
  ck_assert_int_eq(s21_strncmp(str1, str2, 7), strncmp(str1, str2, 7));
}
END_TEST

START_TEST(test_strncmp_2) {
  char str1[] = "0000000000";
  char str2[] = "0000000000";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_3) {
  char str1[] = "0000000000";
  char str2[] = "0000000111";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_4) {
  char str1[] = "1234567890";
  char str2[] = "0000000111";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_5) {
  char str1[] = "0000000000";
  char str2[] = "0000000111";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_strncmp_6) {
  char str1[] = "12345";
  char str2[] = "54321";
  ck_assert_int_eq(s21_strncmp(str1, str2, 6), strncmp(str1, str2, 6));
}
END_TEST

START_TEST(test_strncmp_7) {
  char str1[] = "          ";
  char str2[] = "          ";
  ck_assert_int_eq(s21_strncmp(str1, str2, 11), strncmp(str1, str2, 11));
}
END_TEST

START_TEST(test_strncmp_8) {
  char str1[] = "01010101010";
  char str2[] = "01010101011";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10), strncmp(str1, str2, 10));
}
END_TEST

START_TEST(test_strncmp_9) {
  char str1[] = "01012101010";
  char str2[] = "01010101011";
  ck_assert_int_eq(s21_strncmp(str1, str2, 12), strncmp(str1, str2, 12));
}
END_TEST

START_TEST(test_strncmp_10) {
  char str1[] = "01012101010";
  char str2[] = "01210101011";
  ck_assert_int_eq(s21_strncmp(str1, str2, 12), strncmp(str1, str2, 12));
}
END_TEST

Suite* s21_strncmp_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strncmp");
  core = tcase_create("Core");

  tcase_add_test(core, test_strncmp_1);
  tcase_add_test(core, test_strncmp_2);
  tcase_add_test(core, test_strncmp_3);
  tcase_add_test(core, test_strncmp_4);
  tcase_add_test(core, test_strncmp_5);
  tcase_add_test(core, test_strncmp_6);
  tcase_add_test(core, test_strncmp_7);
  tcase_add_test(core, test_strncmp_8);
  tcase_add_test(core, test_strncmp_9);
  tcase_add_test(core, test_strncmp_10);

  suite_add_tcase(suite, core);

  return (suite);
}
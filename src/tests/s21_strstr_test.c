#include "test.h"

START_TEST(test_strstr_1) {
  char str1[] = "0123456";
  char str2[] = "123";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_2) {
  char str1[] = "0123456";
  char str2[] = "321";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_3) {
  char str1[] = "0123456";
  char str2[] = "345";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_4) {
  char str1[] = "0101010101";
  char str2[] = "101";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_5) {
  char str1[] = "...///...///";
  char str2[] = "///";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_6) {
  char str1[] = "555   55  5   ";
  char str2[] = "  ";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_7) {
  char str1[] = "1+1=2";
  char str2[] = "+1";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_8) {
  char str1[] = "  n   :";
  char str2[] = "010";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_9) {
  char str1[] = "****777****";
  char str2[] = "7*";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_10) {
  char str1[] = "11 00 1100 11";
  char str2[] = "\0";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite* s21_strstr_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strstr");
  core = tcase_create("Core");

  tcase_add_test(core, test_strstr_1);
  tcase_add_test(core, test_strstr_2);
  tcase_add_test(core, test_strstr_3);
  tcase_add_test(core, test_strstr_4);
  tcase_add_test(core, test_strstr_5);
  tcase_add_test(core, test_strstr_6);
  tcase_add_test(core, test_strstr_7);
  tcase_add_test(core, test_strstr_8);
  tcase_add_test(core, test_strstr_9);
  tcase_add_test(core, test_strstr_10);

  suite_add_tcase(suite, core);

  return (suite);
}

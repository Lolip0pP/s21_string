
#include "test.h"

START_TEST(test_strcspn_1) {
  char str1[] = "123";
  char str2[] = "124";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_2) {
  char str1[] = "124";
  char str2[] = "321";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_3) {
  char str1[] = "abcdABCD";
  char str2[] = "AB";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_4) {
  char str1[] = "abcdABCD";
  char str2[] = "ab";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_5) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_6) {
  char str1[] = "05060";
  char str2[] = "060";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_7) {
  char str1[] = "ab cd";
  char str2[] = "bc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_8) {
  char str1[] = "ab cd";
  char str2[] = "b c";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_9) {
  char str1[] = "1/2/3/4";
  char str2[] = "/";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(test_strcspn_10) {
  char str1[] = "124124";
  char str2[] = "124";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite* s21_strcspn_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strcspn");
  core = tcase_create("Core");

  tcase_add_test(core, test_strcspn_1);
  tcase_add_test(core, test_strcspn_2);
  tcase_add_test(core, test_strcspn_3);
  tcase_add_test(core, test_strcspn_4);
  tcase_add_test(core, test_strcspn_5);
  tcase_add_test(core, test_strcspn_6);
  tcase_add_test(core, test_strcspn_7);
  tcase_add_test(core, test_strcspn_8);
  tcase_add_test(core, test_strcspn_9);
  tcase_add_test(core, test_strcspn_10);

  suite_add_tcase(suite, core);

  return (suite);
}
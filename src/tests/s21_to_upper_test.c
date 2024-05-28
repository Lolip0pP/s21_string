#include "test.h"

START_TEST(test_to_upper_1) {
  char *string1 = s21_to_upper("abcd");
  char string2[] = "ABCD";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_2) {
  char *string1 = s21_to_upper("ab1cd");
  char string2[] = "AB1CD";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_3) {
  char *string1 = s21_to_upper("///ab1cd");
  char string2[] = "///AB1CD";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_4) {
  char *string1 = s21_to_upper("\0");
  char string2[] = "\0";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_5) {
  char *string1 = s21_to_upper("zxcv");
  char string2[] = "ZXCV";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_6) {
  char *string1 = s21_to_upper("zxcv00++");
  char string2[] = "ZXCV00++";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *string1 = s21_to_upper("z'''xcv00++");
  char string2[] = "Z'''XCV00++";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_8) {
  char *string1 = s21_to_upper("1+1=2");
  char string2[] = "1+1=2";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_9) {
  char *string1 = s21_to_upper("/n");
  char string2[] = "/N";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_upper_10) {
  char *string1 = s21_to_upper("mmm000lll");
  char string2[] = "MMM000LLL";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

Suite *s21_to_upper_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_to_upper");
  core = tcase_create("Core");

  tcase_add_test(core, test_to_upper_1);
  tcase_add_test(core, test_to_upper_2);
  tcase_add_test(core, test_to_upper_3);
  tcase_add_test(core, test_to_upper_4);
  tcase_add_test(core, test_to_upper_5);
  tcase_add_test(core, test_to_upper_6);
  tcase_add_test(core, test_to_upper_7);
  tcase_add_test(core, test_to_upper_8);
  tcase_add_test(core, test_to_upper_9);
  tcase_add_test(core, test_to_upper_10);

  suite_add_tcase(suite, core);

  return (suite);
}
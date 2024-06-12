#include "test.h"

START_TEST(test_to_lower_1) {
  char *string1 = s21_to_lower("ABCD");
  char string2[] = "abcd";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_2) {
  char *string1 = s21_to_lower("AB1CD");
  char string2[] = "ab1cd";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_3) {
  char *string1 = s21_to_lower("///AB1CD");
  char string2[] = "///ab1cd";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_4) {
  char *string1 = s21_to_lower("\0");
  char string2[] = "\0";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_5) {
  char *string1 = s21_to_lower("ZXCV");
  char string2[] = "zxcv";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_6) {
  char *string1 = s21_to_lower("ZXCV00++");
  char string2[] = "zxcv00++";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *string1 = s21_to_lower("Z'''XCV00++");
  char string2[] = "z'''xcv00++";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_8) {
  char *string1 = s21_to_lower("1+1=2");
  char string2[] = "1+1=2";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_9) {
  char *string1 = s21_to_lower("/N");
  char string2[] = "/n";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_10) {
  char *string1 = s21_to_lower("MMM000LLL");
  char string2[] = "mmm000lll";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_to_lower_11) {
  char *string1 = s21_to_lower(s21_NULL);
  ck_assert_ptr_eq(string1, NULL);
  free(string1);
}
END_TEST

Suite *s21_to_lower_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_to_lower");
  core = tcase_create("Core");

  tcase_add_test(core, test_to_lower_1);
  tcase_add_test(core, test_to_lower_2);
  tcase_add_test(core, test_to_lower_3);
  tcase_add_test(core, test_to_lower_4);
  tcase_add_test(core, test_to_lower_5);
  tcase_add_test(core, test_to_lower_6);
  tcase_add_test(core, test_to_lower_7);
  tcase_add_test(core, test_to_lower_8);
  tcase_add_test(core, test_to_lower_9);
  tcase_add_test(core, test_to_lower_10);
  tcase_add_test(core, test_to_lower_11);

  suite_add_tcase(suite, core);

  return (suite);
}
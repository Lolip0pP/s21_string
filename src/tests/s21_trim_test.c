#include "test.h"

START_TEST(test_trim_1) {
  char *string1 = s21_trim(" 123 ", " ");
  char string2[] = "123";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_2) {
  char *string1 = s21_trim(" /123/ ", " /");
  char string2[] = "123";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_3) {
  char *string1 = s21_trim(" ", " /");
  char string2[] = "";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_4) {
  char *string1 = s21_trim("1231hello321", "123");
  char string2[] = "hello";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_5) {
  char *string1 = s21_trim("1231hello123hello321", "123");
  char string2[] = "hello123hello";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_6) {
  char *string1 = s21_trim("hello", "123");
  char string2[] = "hello";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_7) {
  char *string1 = s21_trim("hello", "");
  char string2[] = "hello";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_8) {
  char *string1 = s21_trim("", "");
  char string2[] = "";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_9) {
  char *string1 = s21_trim(" 1234321", "123");
  char string2[] = " 1234";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_trim_10) {
  char *string1 = s21_trim("hello ", " h");
  char string2[] = "ello";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

Suite *s21_trim_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_trim");
  core = tcase_create("Core");

  tcase_add_test(core, test_trim_1);
  tcase_add_test(core, test_trim_2);
  tcase_add_test(core, test_trim_3);
  tcase_add_test(core, test_trim_4);
  tcase_add_test(core, test_trim_5);
  tcase_add_test(core, test_trim_6);
  tcase_add_test(core, test_trim_7);
  tcase_add_test(core, test_trim_8);
  tcase_add_test(core, test_trim_9);
  tcase_add_test(core, test_trim_10);

  suite_add_tcase(suite, core);

  return (suite);
}
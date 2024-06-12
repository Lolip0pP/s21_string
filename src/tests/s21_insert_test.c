#include "test.h"

START_TEST(test_insert_1) {
  char *string1 = s21_insert("cat", "dog", 3);
  char string2[] = "catdog";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_2) {
  char *string1 = s21_insert("cat", "dog", 2);
  char string2[] = "cadogt";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_3) {
  char *string1 = s21_insert("cat", "dog", 0);
  char string2[] = "dogcat";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_4) {
  char *string1 = s21_insert("cat", "dog", 15);
  ck_assert_ptr_eq(string1, s21_NULL);
  free(string1);
}
END_TEST

START_TEST(test_insert_5) {
  char *string1 = s21_insert("", "dog", 0);
  char string2[] = "dog";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_6) {
  char *string1 = s21_insert("cat", "", 0);
  char string2[] = "cat";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_7) {
  char *string1 = s21_insert("123", "456", 25);
  ck_assert_ptr_eq(string1, s21_NULL);
  free(string1);
}
END_TEST

START_TEST(test_insert_8) {
  char *string1 = s21_insert("c", "at", 1);
  char string2[] = "cat";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_9) {
  char *string1 = s21_insert("1+1", "=2", 3);
  char string2[] = "1+1=2";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

START_TEST(test_insert_10) {
  char *string1 = s21_insert("12", "34", 1);
  char string2[] = "1342";
  ck_assert_str_eq(string1, string2);
  free(string1);
}
END_TEST

Suite *s21_insert_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_insert");
  core = tcase_create("Core");

  tcase_add_test(core, test_insert_1);
  tcase_add_test(core, test_insert_2);
  tcase_add_test(core, test_insert_3);
  tcase_add_test(core, test_insert_4);
  tcase_add_test(core, test_insert_5);
  tcase_add_test(core, test_insert_6);
  tcase_add_test(core, test_insert_7);
  tcase_add_test(core, test_insert_8);
  tcase_add_test(core, test_insert_9);
  tcase_add_test(core, test_insert_10);

  suite_add_tcase(suite, core);

  return (suite);
}
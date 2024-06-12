#include "test.h"

START_TEST(test_strlen_1) {
  ck_assert_int_eq(s21_strlen("hello/0"), strlen("hello/0"));
}
END_TEST

START_TEST(test_strlen_2) { ck_assert_int_eq(s21_strlen("11"), strlen("11")); }
END_TEST

START_TEST(test_strlen_3) { ck_assert_int_eq(s21_strlen("/n"), strlen("/n")); }
END_TEST

START_TEST(test_strlen_4) {
  ck_assert_int_eq(s21_strlen("     "), strlen("     "));
}
END_TEST

START_TEST(test_strlen_5) { ck_assert_int_eq(s21_strlen(""), strlen("")); }
END_TEST

START_TEST(test_strlen_6) {
  ck_assert_int_eq(s21_strlen("01001110"), strlen("01001110"));
}
END_TEST

START_TEST(test_strlen_7) {
  ck_assert_int_eq(s21_strlen("///...///"), strlen("///...///"));
}
END_TEST

START_TEST(test_strlen_8) {
  ck_assert_int_eq(s21_strlen("1+1=2"), strlen("1+1=2"));
}
END_TEST

START_TEST(test_strlen_9) {
  ck_assert_int_eq(s21_strlen("1-1-1"), strlen("1-1-1"));
}
END_TEST

START_TEST(test_strlen_10) {
  ck_assert_int_eq(s21_strlen("4815162342"), strlen("4815162342"));
}
END_TEST

Suite* s21_strlen_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strlen");
  core = tcase_create("Core");

  tcase_add_test(core, test_strlen_1);
  tcase_add_test(core, test_strlen_2);
  tcase_add_test(core, test_strlen_3);
  tcase_add_test(core, test_strlen_4);
  tcase_add_test(core, test_strlen_5);
  tcase_add_test(core, test_strlen_6);
  tcase_add_test(core, test_strlen_7);
  tcase_add_test(core, test_strlen_8);
  tcase_add_test(core, test_strlen_9);
  tcase_add_test(core, test_strlen_10);

  suite_add_tcase(suite, core);

  return (suite);
}
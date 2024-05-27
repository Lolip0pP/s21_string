#include "test.h"

START_TEST(test_strpbrk_1) {
  const char str1[] = "123";
  const char str2[] = "124";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_2) {
  const char str1[] = "123";
  const char str2[] = "000";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_3) {
  const char str1[] = "111242";
  const char str2[] = "001";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_4) {
  const char str1[] = "";
  const char str2[] = "001";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_5) {
  const char str1[] = "    ";
  const char str2[] = " ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_6) {
  const char str1[] = "    ";
  const char str2[] = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_7) {
  const char str1[] = "hello";
  const char str2[] = "hello";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_8) {
  const char str1[] = "hello";
  const char str2[] = "\0";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_9) {
  const char str1[] = "11223344";
  const char str2[] = "1234";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(test_strpbrk_10) {
  const char str1[] = "11223344";
  const char str2[] = "012340";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite* s21_strpbrk_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strpbrk");
  core = tcase_create("Core");

  tcase_add_test(core, test_strpbrk_1);
  tcase_add_test(core, test_strpbrk_2);
  tcase_add_test(core, test_strpbrk_3);
  tcase_add_test(core, test_strpbrk_4);
  tcase_add_test(core, test_strpbrk_5);
  tcase_add_test(core, test_strpbrk_6);
  tcase_add_test(core, test_strpbrk_7);
  tcase_add_test(core, test_strpbrk_8);
  tcase_add_test(core, test_strpbrk_9);
  tcase_add_test(core, test_strpbrk_10);

  suite_add_tcase(suite, core);

  return (suite);
}

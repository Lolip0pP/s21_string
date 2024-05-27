#include "test.h"

START_TEST(test_memcmp_1) {
  char str1[] = "hello";
  char str2[] = "hello";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(test_memcmp_2) {
  char str1[] = "123";
  char str2[] = "23";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(test_memcmp_3) {
  char str1[] = "privet k";
  char str2[] = " ";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

START_TEST(test_memcmp_4) {
  char str1[] = "privet k";
  char str2[] = "b";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

START_TEST(test_memcmp_5) {
  char str1[] = "4815162342";
  char str2[] = "162";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(test_memcmp_6) {
  char str1[] = "4815162342";
  char str2[] = "261";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(test_memcmp_7) {
  char str1[] = "     ";
  char str2[] = " ";
  ck_assert_int_eq(s21_memcmp(str1, str2, 2), memcmp(str1, str2, 2));
}
END_TEST

START_TEST(test_memcmp_8) {
  char str1[] = "55555";
  char str2[] = "555";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

START_TEST(test_memcmp_9) {
  char str1[] = "abcdABCD";
  char str2[] = "ab";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

START_TEST(test_memcmp_10) {
  char str1[] = "abcdABCD";
  char str2[] = "CD";
  ck_assert_int_eq(s21_memcmp(str1, str2, 3), memcmp(str1, str2, 3));
}
END_TEST

Suite* s21_memcmp_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_memcmp");
  core = tcase_create("Core");

  tcase_add_test(core, test_memcmp_1);
  tcase_add_test(core, test_memcmp_2);
  tcase_add_test(core, test_memcmp_3);
  tcase_add_test(core, test_memcmp_4);
  tcase_add_test(core, test_memcmp_5);
  tcase_add_test(core, test_memcmp_6);
  tcase_add_test(core, test_memcmp_7);
  tcase_add_test(core, test_memcmp_8);
  tcase_add_test(core, test_memcmp_9);
  tcase_add_test(core, test_memcmp_10);

  suite_add_tcase(suite, core);

  return (suite);
}
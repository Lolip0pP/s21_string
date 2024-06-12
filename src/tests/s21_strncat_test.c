#include "test.h"

START_TEST(test_strncat_1) {
  char src[] = "1234567890";
  char dest1[21] = "1111111111";
  char dest2[21] = "1111111111";
  ck_assert_str_eq(s21_strncat(dest1, src, 7), strncat(dest2, src, 7));
}
END_TEST

START_TEST(test_strncat_2) {
  char src[] = "1234567890";
  char dest1[21] = "1111111111";
  char dest2[21] = "1111111111";
  ck_assert_str_eq(s21_strncat(dest1, src, 1), strncat(dest2, src, 1));
}
END_TEST

START_TEST(test_strncat_3) {
  char src[] = "1234567890";
  char dest1[21] = "1111111111";
  char dest2[21] = "1111111111";
  ck_assert_str_eq(s21_strncat(dest1, src, 15), strncat(dest2, src, 15));
}
END_TEST

START_TEST(test_strncat_4) {
  char src[] = "1234567890";
  char dest1[21] = "          ";
  char dest2[21] = "          ";
  ck_assert_str_eq(s21_strncat(dest1, src, 4), strncat(dest2, src, 4));
}
END_TEST

START_TEST(test_strncat_5) {
  char src[] = "1234567890";
  char dest1[21] = "1234567890";
  char dest2[21] = "1234567890";
  ck_assert_str_eq(s21_strncat(dest1, src, 10), strncat(dest2, src, 10));
}
END_TEST

START_TEST(test_strncat_6) {
  char src[] = "ABCDabcd";
  char dest1[21] = "1111111111";
  char dest2[21] = "1111111111";
  ck_assert_str_eq(s21_strncat(dest1, src, 9), strncat(dest2, src, 9));
}
END_TEST

START_TEST(test_strncat_7) {
  char src[] = "hello";
  char dest1[21] = "bye";
  char dest2[21] = "bye";
  ck_assert_str_eq(s21_strncat(dest1, src, 15), strncat(dest2, src, 15));
}
END_TEST

START_TEST(test_strncat_8) {
  char src[] = "     ";
  char dest1[21] = "555666";
  char dest2[21] = "555666";
  ck_assert_str_eq(s21_strncat(dest1, src, 2), strncat(dest2, src, 2));
}
END_TEST

START_TEST(test_strncat_9) {
  char src[] = "///...///";
  char dest1[21] = "000000";
  char dest2[21] = "000000";
  ck_assert_str_eq(s21_strncat(dest1, src, 11), strncat(dest2, src, 11));
}
END_TEST

START_TEST(test_strncat_10) {
  char src[] = "1234567890";
  char dest1[25] = "1111111111";
  char dest2[25] = "1111111111";
  ck_assert_str_eq(s21_strncat(dest1, src, 15), strncat(dest2, src, 15));
}
END_TEST

Suite* s21_strncat_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strncat");
  core = tcase_create("Core");

  tcase_add_test(core, test_strncat_1);
  tcase_add_test(core, test_strncat_2);
  tcase_add_test(core, test_strncat_3);
  tcase_add_test(core, test_strncat_4);
  tcase_add_test(core, test_strncat_5);
  tcase_add_test(core, test_strncat_6);
  tcase_add_test(core, test_strncat_7);
  tcase_add_test(core, test_strncat_8);
  tcase_add_test(core, test_strncat_9);
  tcase_add_test(core, test_strncat_10);

  suite_add_tcase(suite, core);

  return (suite);
}
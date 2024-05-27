
#include <stdio.h>

#include "test.h"

#ifdef __APPLE__
#define S21_OS_MACOS
#endif

#ifdef __linux__
#define S21_OS_LINUX
#endif

START_TEST(test_strerror) {
#ifdef S21_OS_MACOS
  for (int i = 0; i < 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
#endif

#ifdef S21_OS_LINUX
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(5), strerror(5));
  ck_assert_str_eq(s21_strerror(155), strerror(155));
  ck_assert_str_eq(s21_strerror(0), strerror(0));
#endif
}
END_TEST

Suite* s21_strerror_test(void) {
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_strerror");
  core = tcase_create("Core");

  tcase_add_test(core, test_strerror);

  suite_add_tcase(suite, core);

  return (suite);
}

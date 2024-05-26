
#include "test.h"

START_TEST(test_strerror) {
  for (int i = 0;i<133;i++){
  ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
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
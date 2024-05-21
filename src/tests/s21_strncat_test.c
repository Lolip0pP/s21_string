#include "test.h"


START_TEST(test_strncat) {
    char src[10] = "1234567890";
    char dest1[20] = "0000000000";
    char dest2[20] = "1111111111";
    ck_assert_str_eq(s21_strncat(dest1,src, 7), strncat(dest1,src, 7));
    ck_assert_str_eq(s21_strncat(dest1,src, 1), strncat(dest1,src, 1));
    ck_assert_str_eq(s21_strncat(dest2,src, 10), strncat(dest2,src, 10));
}

END_TEST


Suite* s21_strncat_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strncat");
    core = tcase_create("Core");

    tcase_add_test(core, test_strncat);

    suite_add_tcase(suite, core);

    return (suite);
}
#include "test.h"


START_TEST(test_strncat_1) {
    char src[11] = "1234567890";
    char dest1[20] = "1111111111";
    char dest2[20] = "1111111111";
    ck_assert_str_eq(s21_strncat(dest1,src, 7), strncat(dest2,src, 7));
}

END_TEST

START_TEST(test_strncat_2) {
    char src[11] = "1234567890";
    char dest1[20] = "1111111111";
    char dest2[20] = "1111111111";
    ck_assert_str_eq(s21_strncat(dest1,src, 1), strncat(dest2,src, 1));
}

END_TEST

START_TEST(test_strncat_3) {
    char src[11] = "1234567890";
    char dest1[20] = "1111111111";
    char dest2[20] = "1111111111";
    ck_assert_str_eq(s21_strncat(dest1,src, 15), strncat(dest2,src, 15));
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
    
    suite_add_tcase(suite, core);

    return (suite);
}
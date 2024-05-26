
#include "test.h"

START_TEST(test_strspn_1) {
    char str1[] = "123";
    char str2[] = "124";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_2) {
    char str1[] = "123";
    char str2[] = "321";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_3) {
    char str1[] = "1321";
    char str2[] = "324";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_4) {
    char str1[] = "hello";
    char str2[] = "l";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_5) {
    char str1[] = "hello";
    char str2[] = "ll";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_6) {
    char str1[] = "4515162342";
    char str2[] = "4515162422";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_7) {
    char str1[] = "2+2=4";
    char str2[] = "2*2=4";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_8) {
    char str1[] = "ABCD";
    char str2[] = "abcd";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_9) {
    char str1[] = "ABCDabcd";
    char str2[] = "abcd";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST

START_TEST(test_strspn_10) {
    char str1[] = "abcdABCDabcd";
    char str2[] = "abcd";
    ck_assert_int_eq(s21_strspn(str1,str2), strspn(str1,str2));
}
END_TEST


Suite* s21_strspn_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strspn");
    core = tcase_create("Core");

    tcase_add_test(core, test_strspn_1);
    tcase_add_test(core, test_strspn_2);
    tcase_add_test(core, test_strspn_3);
    tcase_add_test(core, test_strspn_4);
    tcase_add_test(core, test_strspn_5);
    tcase_add_test(core, test_strspn_6);
    tcase_add_test(core, test_strspn_7);
    tcase_add_test(core, test_strspn_8);
    tcase_add_test(core, test_strspn_9);
    tcase_add_test(core, test_strspn_10);

    suite_add_tcase(suite, core);

    return (suite);
}
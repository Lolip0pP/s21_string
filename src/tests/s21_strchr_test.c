#include "test.h"


START_TEST(test_strchr_1) {
    ck_assert_ptr_eq(s21_strchr("hello",'l'), strchr("hello",'l'));
}
END_TEST

START_TEST(test_strchr_2) {
    ck_assert_ptr_eq(s21_strchr("123",'3'), strchr("123",'3'));
}
END_TEST

START_TEST(test_strchr_3) {
    ck_assert_ptr_eq(s21_strchr("privet k",' '), strchr("privet k",' '));
}
END_TEST

START_TEST(test_strchr_4) {
    ck_assert_ptr_eq(s21_strchr("privet k",'d'), strchr("privet k",'d'));
}
END_TEST

START_TEST(test_strchr_5) {
    ck_assert_ptr_eq(s21_strchr("abcdABCD",'d'), strchr("abcdABCD",'d'));
}
END_TEST

START_TEST(test_strchr_6) {
    ck_assert_ptr_eq(s21_strchr("abcdABCD",'C'), strchr("abcdABCD",'C'));
}
END_TEST

START_TEST(test_strchr_7) {
    ck_assert_ptr_eq(s21_strchr("hello",'\n'), strchr("hello",'\n'));
}
END_TEST

START_TEST(test_strchr_8) {
    ck_assert_ptr_eq(s21_strchr("123456",'6'), strchr("123456",'6'));
}
END_TEST

START_TEST(test_strchr_9) {
    ck_assert_ptr_eq(s21_strchr("1213141516",'1'), strchr("1213141516",'1'));
}
END_TEST

START_TEST(test_strchr_10) {
    ck_assert_ptr_eq(s21_strchr("00000",'0'), strchr("00000",'0'));
}
END_TEST


Suite* s21_strchr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strchr");
    core = tcase_create("Core");

    tcase_add_test(core, test_strchr_1);
    tcase_add_test(core, test_strchr_2);
    tcase_add_test(core, test_strchr_3);
    tcase_add_test(core, test_strchr_4);
    tcase_add_test(core, test_strchr_5);
    tcase_add_test(core, test_strchr_6);
    tcase_add_test(core, test_strchr_7);
    tcase_add_test(core, test_strchr_8);
    tcase_add_test(core, test_strchr_9);
    tcase_add_test(core, test_strchr_10);

    suite_add_tcase(suite, core);

    return (suite);
}
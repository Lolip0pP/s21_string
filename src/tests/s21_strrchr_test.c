#include "test.h"


START_TEST(test_strrchr_1) {
    ck_assert_ptr_eq(s21_strrchr("hello",'l'), strrchr("hello",'l'));
}
END_TEST

START_TEST(test_strrchr_2) {
    ck_assert_ptr_eq(s21_strrchr("12323",'3'), strrchr("12323",'3'));
}
END_TEST

START_TEST(test_strrchr_3) {
    ck_assert_ptr_eq(s21_strrchr("privet k",' '), strrchr("privet k",' '));
}
END_TEST

START_TEST(test_strrchr_4) {
   ck_assert_ptr_eq(s21_strrchr("privet k",'d'), strrchr("privet k",'d'));
}
END_TEST

START_TEST(test_strrchr_5) {
   ck_assert_ptr_eq(s21_strrchr("     ",' '), strrchr("     ",' '));
}
END_TEST

START_TEST(test_strrchr_6) {
   ck_assert_ptr_eq(s21_strrchr("12345983",'3'), strrchr("12345983",'3'));
}
END_TEST

START_TEST(test_strrchr_7) {
   ck_assert_ptr_eq(s21_strrchr("///...///",'.'), strrchr("///...///",'.'));
}
END_TEST

START_TEST(test_strrchr_8) {
   ck_assert_ptr_eq(s21_strrchr("4515162342",'5'), strrchr("4515162342",'5'));
}
END_TEST

START_TEST(test_strrchr_9) {
   ck_assert_ptr_eq(s21_strrchr("hello world",'o'), strrchr("hello world",'o'));
}
END_TEST

START_TEST(test_strrchr_10) {
   ck_assert_ptr_eq(s21_strrchr("privet +++11",'+'), strrchr("privet +++11",'+'));
}
END_TEST

Suite* s21_strrchr_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strrchr");
    core = tcase_create("Core");

    tcase_add_test(core, test_strrchr_1);
    tcase_add_test(core, test_strrchr_2);
    tcase_add_test(core, test_strrchr_3);
    tcase_add_test(core, test_strrchr_4);
    tcase_add_test(core, test_strrchr_5);
    tcase_add_test(core, test_strrchr_6);
    tcase_add_test(core, test_strrchr_7);
    tcase_add_test(core, test_strrchr_8);
    tcase_add_test(core, test_strrchr_9);
    tcase_add_test(core, test_strrchr_10);

    suite_add_tcase(suite, core);

    return (suite);
}
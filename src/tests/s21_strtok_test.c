
#include "test.h"


START_TEST(test_strtok_1) {
    char string[ ] = "1.2.3.4.5";
    ck_assert_str_eq(s21_strtok(string,"."), strtok(string,"."));
}
END_TEST

START_TEST(test_strtok_2) {
    char string[] = "he/ll/o";
    ck_assert_str_eq(s21_strtok(string,"/"), strtok(string,"/"));
}
END_TEST

START_TEST(test_strtok_3) {
    char string[] = "1//213//14";
    ck_assert_str_eq(s21_strtok(string,"//"), strtok(string,"//"));
}
END_TEST

START_TEST(test_strtok_4) {
    char string[] = "1//213//14";
    ck_assert_str_eq(s21_strtok(string," "), strtok(string," "));
}
END_TEST

START_TEST(test_strtok_5) {
    char string[] = "1+1=2";
    ck_assert_str_eq(s21_strtok(string,"="), strtok(string,"="));
}
END_TEST

START_TEST(test_strtok_6) {
    char string[] = "1+1=2";
    ck_assert_str_eq(s21_strtok(string,"+1"), strtok(string,"+1"));
}
END_TEST

START_TEST(test_strtok_7) {
    char string[] = "123145167189";
    ck_assert_str_eq(s21_strtok(string,"1"), strtok(string,"1"));
}
END_TEST

START_TEST(test_strtok_8) {
    char string[] = "123145167189";
    ck_assert_str_eq(s21_strtok(string,"12"), strtok(string,"12"));
}
END_TEST

START_TEST(test_strtok_9) {
    char string[] = "123145167189";
    ck_assert_str_eq(s21_strtok(string,"9"), strtok(string,"9"));
}
END_TEST

START_TEST(test_strtok_10) {
    char string[] = "///...///";
    ck_assert_str_eq(s21_strtok(string,"."), strtok(string,"."));
}
END_TEST



Suite* s21_strtok_test(void) {

    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strtok");
    core = tcase_create("Core");

    tcase_add_test(core, test_strtok_1);
    tcase_add_test(core, test_strtok_2);
    tcase_add_test(core, test_strtok_3);
    tcase_add_test(core, test_strtok_4);
    tcase_add_test(core, test_strtok_5);
    tcase_add_test(core, test_strtok_6);
    tcase_add_test(core, test_strtok_7);
    tcase_add_test(core, test_strtok_8);
    tcase_add_test(core, test_strtok_9);
    tcase_add_test(core, test_strtok_10);

    suite_add_tcase(suite, core);

    return (suite);
}
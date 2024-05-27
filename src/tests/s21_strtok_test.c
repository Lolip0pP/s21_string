
#include "test.h"


START_TEST(test_strtok_1) {
    char string1[ ] = "1.2.3.4.5";
    char string2[] = ".";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_2) {
    char string1[] = "he/ll/o";
    char string2[] = "/";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_3) {
    char string1[] = "1//213//14";
    char string2[] = "//";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_4) {
    char string1[] = "1//213//14";
    char string2[] = " ";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_5) {
    char string1[] = "1+1=2";
    char string2[] = "=";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_6) {
    char string1[] = "1+1=2";
    char string2[] = "+1";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_7) {
    char string1[] = "123145167189";
    char string2[] = "1";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_8) {
    char string1[] = "123145167189";
    char string2[] = "12";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_9) {
    char string1[] = "123145167189";
    char string2[] = "";
    ck_assert_str_eq(s21_strtok(string1,string2), strtok(string1,string2));
}
END_TEST

START_TEST(test_strtok_10) {
    char string1[] = "\0";
    char string2[] = "11";
    ck_assert_ptr_eq(s21_strtok(string1,string2), strtok(string1,string2));
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
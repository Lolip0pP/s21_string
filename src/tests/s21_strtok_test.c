
#include "test.h"


START_TEST(test_strtok) {
    char string1[11] = "1.2.3.4.5";
    char string2[11] = "he/ll/o";
    char string3[20] = "1//213//14";
    ck_assert_str_eq(s21_strtok(string1,"."), strtok(string1,"."));
    ck_assert_str_eq(s21_strtok(string2,"/"), strtok(string2,"/"));
    ck_assert_str_eq(s21_strtok(string3,"//"), strtok(string3,"//"));
    ck_assert_str_eq(s21_strtok(string3," "), strtok(string3," "));
}


END_TEST


Suite* s21_strtok_test(void) {

    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strtok");
    core = tcase_create("Core");

    tcase_add_test(core, test_strtok);

    suite_add_tcase(suite, core);

    return (suite);
}
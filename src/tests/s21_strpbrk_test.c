#include "test.h"

START_TEST(test_strpbrk) {
    const char str1[11] = "123";
    const char str2[11] = "124";
    const char str3[11] = "321";
    const char str4[11] = "324";
    ck_assert_ptr_eq(s21_strpbrk(str1,str2), strpbrk(str1,str2));
    ck_assert_ptr_eq(s21_strpbrk(str2,str3),strpbrk(str2,str3));
    ck_assert_ptr_eq(s21_strpbrk(str3,str4), strpbrk(str3,str4));
}
END_TEST


Suite* s21_strpbrk_test(void) {
    Suite* suite;
    TCase* core;

    suite = suite_create("s21_strpbrk");
    core = tcase_create("Core");

    tcase_add_test(core, test_strpbrk);

    suite_add_tcase(suite, core);

    return (suite);
}



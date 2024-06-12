#include "test.h"

START_TEST(test_sprintf_1) {
  char s1[256];
  char s2[256];
  int a = 100;
  char *format = "%d";
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_2) {
  char s1[256];
  char s2[256];
  char *format = "%c";
  char c = '\n';
  s21_sprintf(s1,format,c);
  sprintf(s2,format,c);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_3) {
  char s1[256];
  char s2[256];
  char *format = "%i";
  int a = -5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_4) {
  char s1[256];
  char s2[256];
  char *format = "%e";
  double a = 123.456;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_5) {
  char s1[256];
  char s2[256];
  char *format = "%E";
  double a = 12345.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST


START_TEST(test_sprintf_6) {
  char s1[256];
  char s2[256];
  char *format = "%f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_7) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 0.00007416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_8) {
  char s1[256];
  char s2[256];
  char *format = "%G";
  double a = 1.00007416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_9) {
  char s1[256];
  char s2[256];
  char *format = "%o";
  unsigned int a = 555;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_10) {
  char s1[256];
  char s2[256];
  char *format = "%s";
  char str[] = "hello";
  s21_sprintf(s1,format,str);
  sprintf(s2,format,str);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_11) {
  char s1[256];
  char s2[256];
  char *format = "%u";
  unsigned int a = 485;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_12) {
  char s1[256];
  char s2[256];
  char *format = "%x";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_13) {
  char s1[256];
  char s2[256];
  char *format = "%x";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_14) {
  char s1[256];
  char s2[256];
  char *format = "%p";
  int a = 10;
  int *prt = &a;
  s21_sprintf(s1,format,prt);
  sprintf(s2,format,prt);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_15) {
  char s1[256];
  char s2[256];
  int count1 = 0;
  int count2 = 0;
  char *format = "Hello, World!%n";
  s21_sprintf(s1,format,&count1);
  sprintf(s2,format,&count2);
  ck_assert_str_eq(s1,s2);
  ck_assert_int_eq(count1,count2);
}
END_TEST

START_TEST(test_sprintf_16) {
  char s1[256];
  char s2[256];
  char *format = "%d%%";
  int a = 5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_17) {
  char s1[256];
  char s2[256];
  char *format = "%5d";
  int a = 100;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_18) {
  char s1[256];
  char s2[256];
  char *format = "%10f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_19) {
  char s1[256];
  char s2[256];
  char *format = "%2f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_20) {
  char s1[256];
  char s2[256];
  char *format = "%5.2f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_21) {
  char s1[256];
  char s2[256];
  char *format = "%-5.2f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_22) {
  char s1[256];
  char s2[256];
  char *format = "%.2f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_23) {
  char s1[256];
  char s2[256];
  char *format = "%-.2f";
  double a = 4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_24) {
  char s1[256];
  char s2[256];
  char *format = "%-f";
  double a = -4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_25) {
  char s1[256];
  char s2[256];
  char *format = "% f";
  double a = 4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_26) {
  char s1[256];
  char s2[256];
  char *format = "%+f";
  double a = -4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_27) {
  char s1[256];
  char s2[256];
  char *format = "%+f";
  double a = 4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_28) {
  char s1[256];
  char s2[256];
  char *format = "%+f";
  double a = -4.856;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_29) {
  char s1[256];
  char s2[256];
  char *format = "%#x";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_30) {
  char s1[256];
  char s2[256];
  char *format = "%#X";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_31) {
  char s1[256];
  char s2[256];
  char *format = "%#o";
  unsigned int a = 555;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_32) {
  char s1[256];
  char s2[256];
  char *format = "%#e";
  double a = 123;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_33) {
  char s1[256];
  char s2[256];
  char *format = "%#E";
  double a = 12345;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_34) {
  char s1[256];
  char s2[256];
  char *format = "%#f";
  double a = 1;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_35) {
  char s1[256];
  char s2[256];
  char *format = "%#g";
  double a = 0.00007416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_36) {
  char s1[256];
  char s2[256];
  char *format = "%#G";
  double a = 1.0000741600;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_37) {
  char s1[256];
  char s2[256];
  char *format = "%05d";
  int a = 100;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_38) {
  char s1[256];
  char s2[256];
  char *format = "%010f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_39) {
  char s1[256];
  char s2[256];
  char *format = "%02f";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_40) {
  char s1[256];
  char s2[256];
  double a = 1.76;
  char *format = "%05.2f";
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_41) {
  char s1[256];
  char s2[256];
  char *format = "%*f";
  int len = 5;
  double a = 1.76;
  s21_sprintf(s1,format,len,a);
  sprintf(s2,format,len,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_42) {
  char s1[256];
  char s2[256];
  char *format = "%.*f";
  int len = 5;
  double a = 1.76;
  s21_sprintf(s1,format,len,a);
  sprintf(s2,format,len,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_43) {
  char s1[256];
  char s2[256];
  char *format = "%hi";
  int a = -5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_44) {
  char s1[256];
  char s2[256];
  char *format = "%hd";
  short int a = -5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_45) {
  char s1[256];
  char s2[256];
  char *format = "%ho";
  unsigned int a = 555;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST


START_TEST(test_sprintf_46) {
  char s1[256];
  char s2[256];
  char *format = "%hu";
  unsigned int a = 485;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_47) {
  char s1[256];
  char s2[256];
  char *format = "%hx";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_48) {
  char s1[256];
  char s2[256];
  char *format = "%hX";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_49) {
  char s1[256];
  char s2[256];
  char *format = "%li";
  int a = -5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_50) {
  char s1[256];
  char s2[256];
  char *format = "%ld";
  long int a = -5;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_51) {
  char s1[256];
  char s2[256];
  char *format = "%lo";
  long unsigned int a = 555;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST


START_TEST(test_sprintf_52) {
  char s1[256];
  char s2[256];
  char *format = "%lu";
  unsigned int a = 485;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_53) {
  char s1[256];
  char s2[256];
  char *format = "%lx";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_54) {
  char s1[256];
  char s2[256];
  char *format = "%lx";
  unsigned int a = 255;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_55) {
  char s1[256];
  char s2[256];
  char *format = "%lc";
  char c = 'a';
  s21_sprintf(s1,format,c);
  sprintf(s2,format,c);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_56) {
  char s1[256];
  char s2[256];
  char *format = "%ls";
  char *c = "abc";
  s21_sprintf(s1,format,c);
  sprintf(s2,format,c);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_57) {
  char s1[256];
  char s2[256];
  char *format = "%Le";
  double a = 123.456;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_58) {
  char s1[256];
  char s2[256];
  char *format = "%LE";
  double a = 12345.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_59) {
  char s1[256];
  char s2[256];
  char *format = "%Lf";
  double a = 1.7416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_60) {
  char s1[256];
  char s2[256];
  char *format = "%Lg";
  double a = 0.00007416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_61) {
  char s1[256];
  char s2[256];
  char *format = "%LG";
  double a = 1.00007416;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_62) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 5000000.8;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_63) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 500000.7;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_64) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 50000.06;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_65) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 5000.007;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_66) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 500.0007;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_67) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 50.00007;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_68) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 5.000007;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_69) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 0.0000007;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_70) {
  char s1[256];
  char s2[256];
  char *format = "%g";
  double a = 0.00000006;
  s21_sprintf(s1,format,a);
  sprintf(s2,format,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_71) {
  char s1[256];
  char s2[256];
  char *format = "%d %d";
  double a = 0.00000006;
  s21_sprintf(s1,format,a,a);
  sprintf(s2,format,a,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_72) {
  char s1[256];
  char s2[256];
  char *format = "%.8f %.1f";
  double a = 4.00000006;
  s21_sprintf(s1,format,a,a);
  sprintf(s2,format,a,a);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_73) {
  char s1[256];
  char s2[256];
  char *format = "%.8f %.1f";
  double a = 4.00000006;
  double b = 5.00000006;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_74) {
  char s1[256];
  char s2[256];
  char *format = "%5.4f%4.1f";
  double a = 4.00000006;
  double b = 5.00000006;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_75) {
  char s1[256];
  char s2[256];
  char *format = "%g%g";
  double a = 0.00009999999;
  double b = 999999.9 ;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_76) {
  char s1[256];
  char s2[256];
  char *format = "%d %ld";
  long int a = 2000000000000000000;
  long int b = 2000000000000000000;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_77) {
  char s1[256];
  char s2[256];
  char *format = "%d HELLO %ld";
  long int a = 200;
  long int b = 200;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_78) {
  char s1[256];
  char s2[256];
  char *format = "%d\n%ld";
  long int a = 200;
  long int b = 200;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

START_TEST(test_sprintf_79) {
  char s1[256];
  char s2[256];
  char *format = "%d\0%ld";
  long int a = 200;
  long int b = 200;
  s21_sprintf(s1,format,a,b);
  sprintf(s2,format,a,b);
  ck_assert_str_eq(s1,s2);
}
END_TEST

Suite* s21_sprintf_test(void) {
  
  Suite* suite;
  TCase* core;

  suite = suite_create("s21_sprintf");
  core = tcase_create("Core");

  tcase_add_test(core, test_sprintf_1);
  // tcase_add_test(core, test_sprintf_2);
  tcase_add_test(core, test_sprintf_3);
  tcase_add_test(core, test_sprintf_4);
  tcase_add_test(core, test_sprintf_5);
  tcase_add_test(core, test_sprintf_6);
  tcase_add_test(core, test_sprintf_7);
  tcase_add_test(core, test_sprintf_8);
  tcase_add_test(core, test_sprintf_9);
  tcase_add_test(core, test_sprintf_10);
  tcase_add_test(core, test_sprintf_11);
  tcase_add_test(core, test_sprintf_12);
  tcase_add_test(core, test_sprintf_13);
  tcase_add_test(core, test_sprintf_14);
  tcase_add_test(core, test_sprintf_15);
  tcase_add_test(core, test_sprintf_16);
  tcase_add_test(core, test_sprintf_17);
  tcase_add_test(core, test_sprintf_18);
  tcase_add_test(core, test_sprintf_19);
  tcase_add_test(core, test_sprintf_20);
  tcase_add_test(core, test_sprintf_21);
  tcase_add_test(core, test_sprintf_22);
  tcase_add_test(core, test_sprintf_23);
  tcase_add_test(core, test_sprintf_24);
  tcase_add_test(core, test_sprintf_25);
  tcase_add_test(core, test_sprintf_26);
  tcase_add_test(core, test_sprintf_27);
  tcase_add_test(core, test_sprintf_28);
  tcase_add_test(core, test_sprintf_29);
  tcase_add_test(core, test_sprintf_30);
  tcase_add_test(core, test_sprintf_31);
  tcase_add_test(core, test_sprintf_32);
  tcase_add_test(core, test_sprintf_33);
  tcase_add_test(core, test_sprintf_34);
  tcase_add_test(core, test_sprintf_35);
  tcase_add_test(core, test_sprintf_36);
  tcase_add_test(core, test_sprintf_37);
  tcase_add_test(core, test_sprintf_38);
  tcase_add_test(core, test_sprintf_39);
  tcase_add_test(core, test_sprintf_40);
  tcase_add_test(core, test_sprintf_41);
  tcase_add_test(core, test_sprintf_42);
  tcase_add_test(core, test_sprintf_43);
  tcase_add_test(core, test_sprintf_44);
  tcase_add_test(core, test_sprintf_45);
  tcase_add_test(core, test_sprintf_46);
  tcase_add_test(core, test_sprintf_47);
  tcase_add_test(core, test_sprintf_48);
  tcase_add_test(core, test_sprintf_49);
  tcase_add_test(core, test_sprintf_50);
  tcase_add_test(core, test_sprintf_51);
  tcase_add_test(core, test_sprintf_52);
  tcase_add_test(core, test_sprintf_53);
  tcase_add_test(core, test_sprintf_54);
  tcase_add_test(core, test_sprintf_55);
  tcase_add_test(core, test_sprintf_56);
  tcase_add_test(core, test_sprintf_57);
  tcase_add_test(core, test_sprintf_58);
  tcase_add_test(core, test_sprintf_59);
  tcase_add_test(core, test_sprintf_60);
  tcase_add_test(core, test_sprintf_61);
  tcase_add_test(core, test_sprintf_62);
  tcase_add_test(core, test_sprintf_63);
  tcase_add_test(core, test_sprintf_64);
  tcase_add_test(core, test_sprintf_65);
  tcase_add_test(core, test_sprintf_66);
  tcase_add_test(core, test_sprintf_67);
  tcase_add_test(core, test_sprintf_68);
  tcase_add_test(core, test_sprintf_69);
  tcase_add_test(core, test_sprintf_70);
  tcase_add_test(core, test_sprintf_71);
  tcase_add_test(core, test_sprintf_72);
  tcase_add_test(core, test_sprintf_73);
  tcase_add_test(core, test_sprintf_74);
  tcase_add_test(core, test_sprintf_75);
  tcase_add_test(core, test_sprintf_76);
  tcase_add_test(core, test_sprintf_77);
  tcase_add_test(core, test_sprintf_78);
  tcase_add_test(core, test_sprintf_79);

  suite_add_tcase(suite, core);

  return (suite);
}
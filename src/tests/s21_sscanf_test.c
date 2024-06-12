#include "test.h"

START_TEST(test_s21_sscanf_read_int_1) {
  int s21_a = 0;

  int sys_a = 0;

  int sys_count = 0;
  int s21_count = 0;
  s21_count = s21_sscanf("25", "%d", &s21_a);
  sys_count = sscanf("25", "%d", &sys_a);
  ck_assert_int_eq(s21_a, sys_a);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_read_int) {
  int s21_a = 0;
  int s21_b = 0;
  int sys_a = 0;
  int sys_b = 0;
  int sys_count = 0;
  int s21_count = 0;
  s21_count = s21_sscanf("-0012:+1500", "%d:%d", &s21_a, &s21_b);
  sys_count = sscanf("-0012:+1500", "%d:%d", &sys_a, &sys_b);
  ck_assert_int_eq(s21_a, sys_a);
  ck_assert_int_eq(s21_b, sys_b);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_read_char) {
  char sys_ch1 = 0;
  char sys_ch2 = 0;
  char sys_ch3 = 0;
  char s21_ch1 = 0;
  char s21_ch2 = 0;
  char s21_ch3 = 0;
  int sys_count = 0;
  int s21_count = 0;
  s21_count = s21_sscanf("!de             #&", "%cde %c%cre", &s21_ch1,
                         &s21_ch2, &s21_ch3);
  sys_count =
      sscanf("!de             #&", "%cde %c%cre", &sys_ch1, &sys_ch2, &sys_ch3);
  ck_assert_int_eq(s21_count, sys_count);
  ck_assert_int_eq(s21_ch1, sys_ch1);
  ck_assert_int_eq(s21_ch2, sys_ch2);
  ck_assert_int_eq(s21_ch3, sys_ch3);
}
END_TEST

START_TEST(test_s21_sscanf_float_1) {
  float f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
  int sys_count = 0;
  int s21_count = 0;
  sys_count = sscanf("-12.34\t 1.778e-10 \n nan", "%f%f%6f", &f1, &f2, &f3);
  s21_count = s21_sscanf("-12.34\t 1.778e-10 \n nan", "%f%f%6f", &f4, &f5, &f6);
  ck_assert_float_eq(f1, f4);
  ck_assert_float_eq(f2, f5);
  ck_assert_float_nan(f3);
  ck_assert_float_nan(f6);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_Gg_2) {
  float f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
  int sys_count = 0;
  int s21_count = 0;
  sys_count = sscanf("-12.34\t 1.778e-10 \n nan", "%g%g%6g", &f1, &f2, &f3);
  s21_count = s21_sscanf("-12.34\t 1.778e-10 \n nan", "%g%g%6g", &f4, &f5, &f6);
  ck_assert_float_eq(f1, f4);
  ck_assert_float_eq(f2, f5);
  ck_assert_float_nan(f3);
  ck_assert_float_nan(f6);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_Ee_2) {
  float f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0;
  int sys_count = 0;
  int s21_count = 0;
  sys_count = sscanf("-12.34\t 1.778e-10 \n nan", "%e%e%6e", &f1, &f2, &f3);
  s21_count = s21_sscanf("-12.34\t 1.778e-10 \n nan", "%e%e%6e", &f4, &f5, &f6);
  ck_assert_float_eq(f1, f4);
  ck_assert_float_eq(f2, f5);
  ck_assert_float_nan(f3);
  ck_assert_float_nan(f6);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_read_i) {
  int s21_a = 0;
  int s21_b = 0;
  int s21_c = 0;
  int sys_a = 0;
  int sys_b = 0;
  int sys_c = 0;
  int sys_count = 0;
  int s21_count = 0;
  s21_count = s21_sscanf("-0012 1500 0x123", "%i%i%i", &s21_a, &s21_b, &s21_c);
  sys_count = sscanf("-0012 1500 0x123", "%i%i%i", &sys_a, &sys_b, &sys_c);
  ck_assert_int_eq(s21_a, sys_a);
  ck_assert_int_eq(s21_b, sys_b);
  ck_assert_int_eq(s21_c, sys_c);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_error_read_sc) {
  int i = 0, i2 = 0;
  char a[40] = {'\0'}, c[40] = {'\0'}, d[40] = {'\0'};
  wchar_t b[40] = {'\0'};
  char a2[40] = {'\0'}, c2[40] = {'\0'}, d2[40] = {'\0'};
  wchar_t b2[40] = {'\0'};
  int sys_count = 0;
  int s21_count = 0;
  const char str[] = "School 21 need food for students !!!";
  sys_count = sscanf(str, "%s %ls %3d %5c %*s %*3s %s", a, b, &i, c, d);
  s21_count =
      s21_sscanf(str, "%s %ls %3d %5c %*s %*3s %s", a2, b2, &i2, c2, d2);
  ck_assert_str_eq(a, a2);
  ck_assert_int_eq(i, i2);
  ck_assert_int_eq(s21_count, sys_count);
}
END_TEST

START_TEST(test_s21_sscanf_d) {
  int a = 1, a1 = 1;
  short b = 1, b1 = 1;
  long c = 1, c1 = 1, d = 1, d1 = 1, e = 1, e1 = 1;
  int sys_count = 0;
  int s21_count = 0;
  const char str[] = "-77777 777777777 -7777 888888777";
  sys_count = sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a, &b, &c, &d, &e);
  s21_count =
      s21_sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a1, &b1, &c1, &d1, &e1);
  ck_assert_int_eq(sys_count, s21_count);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(e, e1);
}
END_TEST

START_TEST(test_s21_sscanf_n) {
  int a1 = 1, a2 = 1;
  short b1 = 1, b2 = 1;
  signed char c1 = 1, c2 = 1;
  long int e1 = 1, e2 = 1;
  long long int d1 = 1, d2 = 1;
  int sys_count = 0;
  int s21_count = 0;
  char *format = "%*s %*2s %n %*d %hn %*d %hhn %ln %lln";
  const char str[] = "-77777 777777777 -7777 888888777";
  sys_count = sscanf(str, format, &a1, &b1, &c1, &d1, &e1);
  s21_count = s21_sscanf(str, format, &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(sys_count, s21_count);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_error_d) {
  int a = 1, a1 = 1;
  short b = 1, b1 = 1;
  long c = 1, c1 = 1, d = 1, d1 = 1, e = 1, e1 = 1;
  int sys_count = 0;
  int s21_count = 0;
  const char str[] = "-77777 777777777 --7777 888888777";
  sys_count = sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a, &b, &c, &d, &e);
  s21_count =
      s21_sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a1, &b1, &c1, &d1, &e1);
  ck_assert_int_eq(sys_count, s21_count);
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(e, e1);
}
END_TEST

START_TEST(test_s21_sscanf_s_and_c) {
  char a[40] = {'\0'}, c[40] = {'\0'}, d[40] = {'\0'};
  wchar_t b[40] = {'\0'};
  char a2[40] = {'\0'}, c2[40] = {'\0'}, d2[40] = {'\0'};
  wchar_t b2[40] = {'\0'};
  const char str[] = "now big tests for big problems";
  ck_assert_int_eq(sscanf(str, "%s %ls %3c %*s %s", a, b, c, d),
                   s21_sscanf(str, "%s %ls %3c %*s %s", a2, b2, c2, d2));
  ck_assert_str_eq(a, a2);
  ck_assert_str_eq(c, c2);
  ck_assert_str_eq(d, d2);
}
END_TEST

START_TEST(test_s21_sscanf_x) {
  int a1, b1, c1, d1, a2, b2, c2, d2, e1, e2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = e1 = e2 = 1;
  const char str[] = "4242 0042 0x42AB -99 -0x42ad";
  int sys_count = sscanf(str, "%x%x%x%x%x", &a1, &b1, &c1, &d1, &e1);
  int s21_count = s21_sscanf(str, "%x%x%x%x%x", &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(sys_count, s21_count);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_s21_sscanf_error_x) {
  int a1, b1, c1, d1, a2, b2, c2, d2, e1, e2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = e1 = e2 = 1;
  const char str[] = "4242 0042 0x42GG -99 -0x42ad";
  int sys_count = sscanf(str, "%x%x%x%x%x", &a1, &b1, &c1, &d1, &e1);
  int s21_count = s21_sscanf(str, "%x%x%x%x%x", &a2, &b2, &c2, &d2, &e2);
  ck_assert_int_eq(sys_count, s21_count);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_s21_sscanf_i) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "0x11 098 98 -0998";
  int r1 = sscanf(str, "%i%i%i%i", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%i%i%i%i", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_o) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "0143 2342 -42 777";
  int r1 = sscanf(str, "%o%o%o%o", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%o%o%o%o", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sscanf_p) {
  int integer = 45;
  int *p1a = &integer;
  int *p2a;
  int *p3a;
  char temp[50] = {'\0'};
  sprintf(temp, "%p", p1a);
  sscanf(temp, "%p", &p2a);
  s21_sscanf(temp, "%p", &p3a);
  ck_assert_ptr_eq(p2a, p3a);
}
END_TEST

START_TEST(test_s21_sscanf_n_and_percent) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "-12345%    -000456000    111    0005 pisos";
  int r1 = s21_sscanf(str, "%d%% %d %n %d", &a1, &b1, &c1, &d1);
  int r2 = sscanf(str, "%d%% %d %n %d", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_f_and_e) {
  float a1, b1, a2, b2;
  double c1, c2;
  long double d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1.1;
  const char str[] = "-12345.445 12.34e+07 -0.0 1234e-07 pisos";
  s21_sscanf(str, "%f%f%lf%Lf", &a1, &b1, &c1, &d1);
  sscanf(str, "%f%f%lf%Lf", &a2, &b2, &c2, &d2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_u) {
  unsigned int a1, b1, a2, b2;
  unsigned short c1, c2;
  unsigned long d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "0 0002 -1 -1234 666 pisos";
  int r1 = sscanf(str, "%*u%u%u%hu%lu", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%*u%u%u%hu%lu", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

Suite *s21_sscanf_test(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_sscanf");
  core = tcase_create("Core");

  tcase_add_test(core, test_s21_sscanf_read_int_1);
  tcase_add_test(core, test_s21_sscanf_read_int);
  tcase_add_test(core, test_s21_sscanf_read_char);
  tcase_add_test(core, test_s21_sscanf_float_1);
  tcase_add_test(core, test_s21_sscanf_Gg_2);
  tcase_add_test(core, test_s21_sscanf_Ee_2);
  tcase_add_test(core, test_s21_sscanf_read_i);
  tcase_add_test(core, test_s21_sscanf_error_read_sc);
  tcase_add_test(core, test_s21_sscanf_d);
  tcase_add_test(core, test_s21_sscanf_n);
  tcase_add_test(core, test_s21_sscanf_error_d);
  tcase_add_test(core, test_s21_sscanf_s_and_c);
  tcase_add_test(core, test_s21_sscanf_x);
  tcase_add_test(core, test_s21_sscanf_error_x);
  tcase_add_test(core, test_s21_sscanf_i);
  tcase_add_test(core, test_s21_sscanf_o);
  tcase_add_test(core, test_s21_sscanf_p);
  tcase_add_test(core, test_s21_sscanf_n_and_percent);
  tcase_add_test(core, test_s21_sscanf_f_and_e);
  tcase_add_test(core, test_s21_sscanf_u);

  suite_add_tcase(suite, core);

  return (suite);
}
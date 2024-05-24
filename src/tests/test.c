#include "test.h"


int main(void) {
  int failed = 0;
  Suite* tests[] = {s21_strlen_test(),s21_memchr_test(),
                    s21_memcmp_test(), s21_memcpy_test(),
                    s21_memset_test(),s21_strncpy_test(),
                    s21_strncat_test(), s21_strchr_test(),
                    s21_strncmp_test(), s21_strcspn_test(),
                    s21_strpbrk_test(), s21_strrchr_test(),
                    s21_strstr_test(),s21_strtok_test(),
                    s21_strspn_test(), s21_NULL_test(),
                    s21_size_t_test()};
  for (int i = 0; i < 17; i++) {
    SRunner* runner = srunner_create(tests[i]);
    srunner_run_all(runner, CK_NORMAL);
    if (srunner_ntests_failed(runner) != 0){
      failed = srunner_ntests_failed(runner);
    }
    srunner_free(runner);
  }
  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
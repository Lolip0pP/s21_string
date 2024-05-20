#include "test.h"


int main(void) {
  int failed = 0;
  Suite* tests[] = {s21_strlen_test(),s21_memchr_test(),
                    s21_memcmp_test(), s21_memcpy_test(),
                    s21_memset_test()};
  for (int i = 0; i < 5; i++) {
    SRunner* runner = srunner_create(tests[i]);
    srunner_run_all(runner, CK_NORMAL);
    if (srunner_ntests_failed(runner) != 0){
      failed = srunner_ntests_failed(runner);
    }
    srunner_free(runner);
  }
  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
#include "tests.h"

int main(void) {
  Suite *test_suites[] = {suite_test_sub(),
                          suite_test_add(),
                          suite_test_div(),
                          suite_test_mul(),
                          suite_from_float_to_decimal(),
                          suite_from_int_to_decimal(),
                          suite_from_decimal_to_int(),
                          suite_from_decimal_to_float(),
                          suite_less(),
                          suite_less_equal(),
                          suite_greater(),
                          suite_greater_equal(),
                          suite_equal(),
                          suite_not_equal(),
                          suite_trunc(),
                          suite_round(),
                          suite_negate(),
                          suite_floor(),
                          NULL};

  for (Suite **current_suite = test_suites; *current_suite != NULL;
       current_suite++) {
    run_suite(*current_suite);
  }
  return 0;
}

void run_suite(Suite *test_suite) {
  SRunner *runner = srunner_create(test_suite);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

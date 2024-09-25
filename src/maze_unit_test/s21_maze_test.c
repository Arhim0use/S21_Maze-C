
#include "s21_maze_test.h"



void run_set(Suite *current_set) {
  SRunner *all_test = srunner_create(current_set);

  srunner_set_fork_status(all_test, CK_NOFORK);
  srunner_run_all(all_test, CK_NORMAL);

  srunner_free(all_test);
}

void test_sets(void) {
  Suite *sets[] = {suite_create_maze(),
                   suite_generate_maze(),
                   suite_solve_maze(),
                   suite_parse_maze(),
                   NULL};

  for (Suite **current_set = sets; *current_set != NULL; current_set++) {
    run_set(*current_set);
  }
}

int main(void) {
  test_sets();
  return 0;
}

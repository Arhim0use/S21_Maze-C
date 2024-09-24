
#include "s21_maze_test.h"

//--------------GENERATE--------------//

START_TEST(s21_generate_maze_1) {
  rectangular_maze check = null_maze();

  int row = 5, column = 5;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, OK);

    // generate test
    printf("\033[1;30;47m TODO generate test \033[0;0;0m\n");

  delete_maze(&check);
  
}
END_TEST


//--------------SUITE--------------//


Suite *suite_generate_maze(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_GENERATE_MAZE \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_generate_maze \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_generate_maze_1);

  suite_add_tcase(suite, test_case);
  return suite;
}

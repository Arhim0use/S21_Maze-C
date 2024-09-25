#include "s21_maze_test.h"

//--------------GENERATE--------------//

START_TEST(s21_parse_maze_1) {
  rectangular_maze check = null_maze();

  int row = 5, column = 5;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, OK);

    // parse test
printf("\033[1;30;47m TODO parse test \033[0;0;0m\n");
  delete_maze(&check);
  
}
END_TEST


//--------------SUITE--------------//


Suite *suite_parse_maze(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_PARSE_MAZE \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_parse_maze \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_parse_maze_1);

  suite_add_tcase(suite, test_case);
  return suite;
}

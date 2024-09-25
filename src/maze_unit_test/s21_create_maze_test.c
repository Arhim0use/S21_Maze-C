#include "s21_maze_test.h"

//--------------CREATE--------------//

START_TEST(s21_create_maze_null) {

  rectangular_maze check = null_maze();

  ck_assert_int_eq(check.rows, 0);
  ck_assert_int_eq(check.cols, 0);

  ck_assert_int_eq(check.right_walls.columns, 0);
  ck_assert_int_eq(check.right_walls.rows, 0);
  ck_assert_ptr_eq(check.right_walls.matrix, NULL);

  ck_assert_int_eq(check.lower_walls.columns, 0);
  ck_assert_int_eq(check.lower_walls.rows, 0);
  ck_assert_ptr_eq(check.lower_walls.matrix, NULL);

  ck_assert_ptr_eq(check.num_set, NULL);
}
END_TEST

START_TEST(s21_create_maze_1) {

  rectangular_maze check = null_maze();

  int row = 2, column = 2;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, OK);
  ck_assert_int_eq(check.rows, row);
  ck_assert_int_eq(check.cols, column);

  if (create_res == OK) {
    delete_maze(&check);
  }

  ck_assert_int_eq(check.rows, 0);
  ck_assert_int_eq(check.cols, 0);
  ck_assert_ptr_eq(check.num_set, NULL);
  ck_assert_ptr_eq(check.lower_walls.matrix, NULL);
  ck_assert_ptr_eq(check.right_walls.matrix, NULL);
}
END_TEST

START_TEST(s21_create_maze_2) {

  rectangular_maze check = null_maze();

  int row = 55, column = 51;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, OK);
  ck_assert_int_eq(check.rows, row);
  ck_assert_int_eq(check.cols, column);

  ck_assert_int_eq(check.right_walls.columns, column);
  ck_assert_int_eq(check.right_walls.rows, row);

  ck_assert_int_eq(check.lower_walls.columns, column);
  ck_assert_int_eq(check.lower_walls.rows, row);

  if (create_res == OK) {
    delete_maze(&check);
  }

  ck_assert_int_eq(check.rows, 0);
  ck_assert_int_eq(check.cols, 0);
  ck_assert_ptr_eq(check.num_set, NULL);
  ck_assert_ptr_eq(check.lower_walls.matrix, NULL);
  ck_assert_ptr_eq(check.right_walls.matrix, NULL);
}
END_TEST

START_TEST(s21_create_maze_err_1) {

  rectangular_maze check = null_maze();

  int row = 1, column = 2;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, ERROR);

  ck_assert_int_eq(check.rows, 0);
  ck_assert_int_eq(check.cols, 0);
  ck_assert_ptr_eq(check.num_set, NULL);
  ck_assert_ptr_eq(check.lower_walls.matrix, NULL);
  ck_assert_ptr_eq(check.right_walls.matrix, NULL);
}
END_TEST

START_TEST(s21_create_maze_err_2) {

  rectangular_maze check = null_maze();

  int row = 2, column = 0;
  maze_errors create_res = create_maze(row, column, &check);

  ck_assert_int_eq(create_res, ERROR);

  ck_assert_int_eq(check.rows, 0);
  ck_assert_int_eq(check.cols, 0);
  ck_assert_ptr_eq(check.num_set, NULL);
  ck_assert_ptr_eq(check.lower_walls.matrix, NULL);
  ck_assert_ptr_eq(check.right_walls.matrix, NULL);
}
END_TEST


Suite *suite_create_maze(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_CREATE_MATRIX \033[0;0;0m");
  TCase *test_case =
      tcase_create("\033[1;30;47m s21_create_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_create_maze_null);
  tcase_add_test(test_case, s21_create_maze_1);
  tcase_add_test(test_case, s21_create_maze_2);
  tcase_add_test(test_case, s21_create_maze_err_1);
  tcase_add_test(test_case, s21_create_maze_err_2);

  suite_add_tcase(suite, test_case);
  return suite;
}
#ifndef S21_MAZE_TEST_H
#define S21_MAZE_TEST_H

#include <check.h>

#include "../s21_Maze_Model/maze_model.h"

Suite *suite_create_maze(void);
Suite *suite_generate_maze(void);
Suite *suite_solve_maze(void);
Suite *suite_parse_maze(void);

void test_sets(void);
void run_set(Suite *current_set);

#endif // S21_MAZE_TEST_H
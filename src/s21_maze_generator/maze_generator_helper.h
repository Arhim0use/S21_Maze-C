#ifndef MAZE_GENERATOR_HELPER_H
#define MAZE_GENERATOR_HELPER_H

#include "../s21_maze_model/maze_model.h"

void generate_maze(rectangular_maze *maze);

void gen_lower_walls(rectangular_maze *A, int row);
void gen_right_walls(rectangular_maze *A, int row);
void last_row(rectangular_maze *A);
void merge_num_set(int *num_set, int cols, int pos);
void next_row_set(rectangular_maze *A, int row);
int is_have_vertical_door(rectangular_maze *A, int row, int pos);
void reset_matrix(rectangular_maze *maze, int rows, int cols);
int randomBool();

#endif  //  MAZE_GENERATOR_HELPER_H

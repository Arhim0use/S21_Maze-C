#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "../C_Matrix/s21_matrix.h"

typedef enum {
    OK,
    ERROR,
    SIZE_ERROR
} maze_errors;

/// @brief Init struct with `rectangular_maze null_maze()`
typedef struct {
    matrix_t right_walls;
    matrix_t lower_walls; 
    int rows;
    int cols;
    int *num_set;
} rectangular_maze;

maze_errors create_maze(int rows, int cols, rectangular_maze *A);
rectangular_maze null_maze();
void delete_maze(rectangular_maze *A);
int is_created_maze(rectangular_maze *A);
void print_two_matrix(rectangular_maze *A);
void print_maze(rectangular_maze *A);

maze_errors init_matrix(rectangular_maze *A);
maze_errors first_num_set(rectangular_maze *A);

#endif // MAZE_MODEL_H
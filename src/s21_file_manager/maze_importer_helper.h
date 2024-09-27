#ifndef MAZE_IMPORTER_HELPER_H
#define MAZE_IMPORTER_HELPER_H

#include "../s21_maze_model/maze_model.h"

maze_errors open_file(FILE **fp, char *filename);
maze_errors get_data(FILE **fp, rectangular_maze *maze, maze_errors *err_code);
void walls_recording(matrix_t *walls, char* str, unsigned short row, maze_errors *perr_code);
void pars_size_create_matrix(rectangular_maze *maze, char *str, maze_errors *perr_code);
int is_digit(char ch);
int is_bool(char ch);
int fill_cell(matrix_t *A, int row, int col, short unsigned int data);
int atob(char ch);

#endif // MAZE_IMPORTER_HELPER_H
#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "../s21_maze_model/maze_model.h"

// Не забыть почистить rectangular_maze на выходе из программы, между итерациями не обязательно
maze_errors generate_ideal_maze(int rows, int cols, rectangular_maze *maze);

#endif // MAZE_GENERATOR_H
#ifndef MAZE_EXPORTER_H
#define MAZE_EXPORTER_H

#include "string.h"

#include "../s21_maze_model/maze_model.h"

maze_errors export_maze(char *filename, rectangular_maze *maze);

#endif // MAZE_EXPORTER_H
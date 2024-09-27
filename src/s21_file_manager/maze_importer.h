#ifndef MAZE_IMPORTER_H
#define MAZE_IMPORTER_H

#include "string.h"

#include "../s21_maze_model/maze_model.h"

maze_errors import_maze(char *filename, rectangular_maze *maze);

#endif // MAZE_IMPORTER_H
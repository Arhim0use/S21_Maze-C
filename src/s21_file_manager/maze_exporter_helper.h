#ifndef MAZE_EXPORTER_HELPER_H
#define MAZE_EXPORTER_HELPER_H

maze_errors create_file(FILE **fp, char *filename);
void set_data(FILE **fp, rectangular_maze *maze, maze_errors *err_code);
void matrix_to_file(FILE **fp, matrix_t *walls, maze_errors *err_code);

#endif // MAZE_EXPORTER_HELPER_H
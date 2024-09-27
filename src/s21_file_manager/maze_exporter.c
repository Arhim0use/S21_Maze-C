#include "maze_exporter.h"
#include "maze_exporter_helper.h"

maze_errors export_maze(char *filename, rectangular_maze *maze) {
  if (maze == NULL || filename == NULL) return ERROR_FILE;
  if (!strlen(filename)) return ERROR_FILE;

  FILE *fp;
  maze_errors err_code = ERROR;

  if ((err_code = create_file(&fp, filename)) == OK) {
    set_data(&fp, maze, &err_code);

    fclose(fp);
  }

  return err_code;
}

maze_errors create_file(FILE **fp, char *filename) {
  if ((*fp = fopen(filename, "w")) == NULL) return ERROR_FILE;
  return OK;
}

void set_data(FILE **fp, rectangular_maze *maze, maze_errors *err_code) {
    if ((*err_code = is_valid_size(maze->rows, maze->cols)) != OK) { return; }

    char *str;
    if ((str = (char *)calloc(6, sizeof(char))) != NULL) {
        sprintf(str, "%d %d\n", maze->rows, maze->cols);
        fputs(str, *fp);
        free(str);
    } else {
        *err_code = ERROR;
    }
    matrix_to_file(fp, &maze->right_walls, err_code);
    fputs("\n", *fp);
    matrix_to_file(fp, &maze->lower_walls, err_code);

}

void matrix_to_file(FILE **fp, matrix_t *walls, maze_errors *err_code) {
    if (*err_code != OK) { return; }

    char *str;
    for (int i = 0; i < walls->rows; i++) {
      if ((str = (char *)calloc(walls->columns * 2 + 1, sizeof(char))) != NULL) {
        for (int j = 0; j < walls->columns; j++) {
          char wall[3] = {0};
          sprintf(wall, "%hd ", walls->matrix[i][j]);
          strcat(str, wall);
        }
        strcat(str, "\n");
        fputs(str, *fp);
        free(str);
      } else {
        *err_code = ERROR;
      }
    }
}
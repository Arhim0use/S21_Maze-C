#include "maze_importer.h"
#include "maze_importer_helper.h"

maze_errors import_maze(char *filename, rectangular_maze *maze) {
  if (maze == NULL || filename == NULL) return ERROR_FILE;
  if (!strlen(filename)) return ERROR_FILE;

  FILE *fp;
  maze_errors err_code = ERROR;

  if ((err_code = open_file(&fp, filename)) == OK) {
    get_data(&fp, maze, &err_code);

    fclose(fp);
  }

  return err_code;
}

maze_errors open_file(FILE **fp, char *filename) {
  if ((*fp = fopen(filename, "r")) == NULL) return ERROR_FILE;
  return OK;
}

maze_errors get_data(FILE **fp, rectangular_maze *maze, maze_errors *err_code) {
  char str[4096] = {0};
  short first_str = 1, first_matrix = 1;
  unsigned short row = 0;

  while (fgets(str, 4096, *fp) != NULL && *err_code == OK) {
    if (first_str) {
        first_str = 0;
        pars_size_create_matrix(maze, str, err_code);
    } else {
        if (first_matrix) {
          walls_recording(&maze->right_walls, str, row, err_code);
          if (row == maze->rows) {
            row = -1;
            first_matrix = 0;
          }
        } else {
          walls_recording(&maze->lower_walls, str, row, err_code);
        }
        row++;
    }
  }

  return *err_code;
}

void walls_recording(matrix_t *walls, char* str, unsigned short row, maze_errors *perr_code) {
  if (row >= walls->rows) return;

  char *token = strtok(str, " ");
  short unsigned col = 0;
  short cell = 0;
  while (token && *perr_code == OK && col < walls->columns) {
    unsigned long long length_token = strlen(token);
    if ((cell = atob(token[0])) < 0 || length_token > 2) { 
      *perr_code = ERROR_FILE; 
    }

    if (*perr_code == OK && fill_cell(walls, row, col, cell)) {
      col++;
      token = strtok(NULL, " ");  
    } else {
      *perr_code = ERROR_FILE;      
    }
  }

  if (col < walls->columns) {
    *perr_code = ERROR_SIZE;      
  }
}

void pars_size_create_matrix(rectangular_maze *maze, char *str, maze_errors *perr_code) {
    char *token = strtok(str, " ");
    int rows = 0, cols = 0, count = 0;
    int scanf_res = 0;
    while (token && count < 2 && *perr_code == OK) {
        // if (strlen(token) > 1 && token[strlen(token) - 1] == '\n') {
        //     token[strlen(token) - 1] = '\0';
        // }
        scanf_res = count ? sscanf(token, "%d", &cols) : sscanf(token, "%d", &rows);
        token = strtok(NULL, " ");
        count++;
        if (scanf_res < 1) *perr_code = ERROR_FILE;
    }
    
    if (*perr_code == OK && (*perr_code = is_valid_size(rows, cols)) == OK) {
        if (maze->cols > 0 || maze->rows > 0) {
            delete_maze(maze);
        }
        *perr_code = create_maze(rows, cols, maze);
    }
}

int is_bool(char ch) {
    if (ch >= '0' || ch <= '1') { 
        return 1; 
    }
    return 0;
}


/// @return 0 - '0'; 1 - '1'; -1 - other
int atob(char ch) {
    if (ch == '0') {
        return 0;
    } else if (ch == '1') { 
        return 1; 
    }
    return -1;
}

int fill_cell(matrix_t *A, int row, int col, short unsigned int data) {
    if (data > 1 || data < 0) { return 0; }
    if (row > A->rows || col > A->columns) { return 0; }

    A->matrix[row][col] = data;
    return 1;
}

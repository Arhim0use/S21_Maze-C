#include "maze_generator.h"
#include "maze_generator_helper.h"

void print_num_set(rectangular_maze *A) {
    for (int i = 0; i < A->cols; i++) {
       printf("%3d", A->num_set[i]);
    }
    printf("\n");
}

maze_errors generate_ideal_maze(int rows, int cols, rectangular_maze *maze) {
    
    maze_errors err_code = is_valid_size(rows, cols);
    if (err_code == ERROR) { return ERROR; }

    if (is_created_maze(maze)) {
        if (maze->cols != cols || maze->rows != rows) {
            delete_maze(maze);
            err_code = create_maze(rows, cols, maze);
        } 
    } else {
        err_code = create_maze(rows, cols, maze);
    }

    if (err_code == OK) {
        reset_matrix(maze, rows, cols);
        generate_maze(maze);
    } 

    return err_code;
}

void generate_maze(rectangular_maze *A) {
    if (!is_created_maze(A)) { return; }
    if (A->rows < 2) { return; }

    for (int row = 0; row < A->rows - 1; row++) {
        gen_right_walls(A, row);
        gen_lower_walls(A, row);
        if (row != A->rows - 1) next_row_set(A, row);
    }
    last_row(A);
}

void gen_lower_walls(rectangular_maze *A, int row) {
    if (row > A->rows - 1) { return; }

    for (int col = 0; col < A->cols; col++) {
        if (randomBool()) {
            A->lower_walls.matrix[row][col] = 0;
        }
        if (A->right_walls.matrix[row][col] && 
            !is_have_vertical_door(A, row, col)) {
            A->lower_walls.matrix[row][col] = 0;
        }
    }
}

void gen_right_walls(rectangular_maze *A, int row) {
    if (row >= A->rows) { return; }

    for (int col = 0; col < A->cols - 1; col++) {
        if (randomBool() && A->num_set[col + 1] != A->num_set[col]) {
            A->right_walls.matrix[row][col] = 0;
            merge_num_set(A->num_set, A->cols, col);
        }        
    }
}

void last_row(rectangular_maze *A) {
    int last_row = A->rows - 1;
    for (int col = 0; col < A->cols - 1; col++) {
        if (A->right_walls.matrix[last_row][col] && 
                A->num_set[col] != A->num_set[col + 1]) {
            A->right_walls.matrix[last_row][col] = 0;
            merge_num_set(A->num_set, A->cols, col);
        }
    }
}

void next_row_set(rectangular_maze *A, int row) {
    if (row > A->rows - 1) { return; }

    int next_num = A->num_set[A->cols - 1] + rand() % 9999;
 
    for (int i = 0; i < A->cols; i++) {
        if (A->lower_walls.matrix[row][i] == 1) {
            A->num_set[i] = next_num++;
        }
    }
}

void merge_num_set(int *num_set, int cols, int pos) {
    if (pos >= cols) { return; }

    int next_num = num_set[pos + 1];
    for (int i = 0; i < cols; i++) {
        int num = num_set[i];
        if (num == next_num) 
            num_set[i] = num_set[pos];
    }
}

int is_have_vertical_door(rectangular_maze *A, int row, int pos) {
    if (pos == 0) { return !A->lower_walls.matrix[row][0]; }

    int is_door = 0;
    for (int i = pos; i >= 0 && !is_door; i--) {
        if (A->num_set[i] == A->num_set[pos]) {
            is_door = !A->lower_walls.matrix[row][i];
        }
    }

    return is_door;
}

void reset_matrix(rectangular_maze *maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    init_matrix(maze);
    first_num_set(maze);
}

int randomBool() { 
    return rand() % 2; 
}
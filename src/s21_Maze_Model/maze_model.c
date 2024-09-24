#include "maze_model.h"

/// @brief Init empty maze struct
rectangular_maze null_maze() {
    rectangular_maze maze;
    maze.rows = 0;
    maze.cols = 0;
    maze.lower_walls.matrix = NULL;
    maze.lower_walls.columns = 0;
    maze.lower_walls.rows = 0;
    maze.right_walls.matrix = NULL;
    maze.right_walls.columns = 0;
    maze.right_walls.rows = 0;
    maze.num_set = NULL;
    return maze;
}

/// @brief min maze size 2x2 else return enum maze_errors ERROR
/// @return  enum maze_errors ERROR if invalid size or cant calloc memory and OK if always good
maze_errors create_maze(int rows, int cols, rectangular_maze *A) {
    if (rows < 2 || cols < 2) { return ERROR; }

    maze_errors err_code = ERROR;
    A->rows = rows;
    A->cols = cols;

    if(!s21_create_matrix(rows, cols, &A->right_walls) && !s21_create_matrix(rows, cols, &A->lower_walls)) {
        A->num_set = (int *)calloc(cols, sizeof(int));
        if (!A->num_set) {
            s21_remove_matrix(&A->lower_walls);
            s21_remove_matrix(&A->right_walls);
            A->rows = 0;
            A->cols = 0;
        } else {
            next_num_set(A);
            err_code = OK;
        }
    }
    return err_code;
}

void delete_maze(rectangular_maze *A) {
    A->rows = 0;
    A->cols = 0;
    s21_remove_matrix(&A->right_walls);
    s21_remove_matrix(&A->lower_walls);
    if(A->num_set != NULL) {
        free(A->num_set);
        *A = null_maze();
    }
}

maze_errors init_random_matrix(rectangular_maze *A) {
    if (!is_created_maze(A)) {
        return ERROR;
    }

    srand(time(NULL));   // Initialization, should only be called once.

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            A->right_walls.matrix[i][j] = rand() % 2;
            A->lower_walls.matrix[i][j] = rand() % 2;
        }
    }

    return OK;
}

maze_errors next_num_set(rectangular_maze *A) {
    if (!is_created_maze(A)) { return ERROR; }

    int num = A->num_set[A->cols - 1];
    for (int i = 0; i < A->cols; i++) {
        A->num_set[i] = ++num;
    }

    return OK;
}


void print_two_matrix(rectangular_maze *A) {
    if(!is_created_maze(A)) { 
        printf("Print err rectangular_maze or matrix is NULL\n");
        return;
    } 
    printf("%d %d", A->rows, A->cols);
    print_matrix(&A->right_walls);
    print_matrix(&A->lower_walls);
}

void print_maze(rectangular_maze *A) {
    if(!is_created_maze(A)) { 
        printf("Print err rectangular_maze or matrix is NULL\n");
        return;
    } 
    printf("%d %d\n", A->rows, A->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
            char lower_wall = A->lower_walls.matrix[i][j] ? '_' : ' ';
            char right_wall = A->right_walls.matrix[i][j] ? '|' : ' ';
            printf("%c%c", lower_wall, right_wall);
        }
        printf("\n");
    }
}

/// @brief check memory alloceted for matrix
/// @return 1 - is ok; 0 - is error
int is_created_maze(rectangular_maze *A) {
    maze_errors res = 1;
    if(A == NULL || A->right_walls.matrix == NULL ||
         A->lower_walls.matrix == NULL || A->num_set == NULL) {
        res = 0;
    }
    return res;
}
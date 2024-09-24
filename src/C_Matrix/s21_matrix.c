#include "s21_matrix.h"

int s21_mtx_minor(matrix_t *A, int minor_row, int minor_column,
                  matrix_t *result);
int correct_matrix(matrix_t *matrix);

/// @brief Создание матрицы
/// @param rows Количество строк матрицы
/// @param columns Количество столбцов матрицы
/// @param result Структура со всеми определителями и содержимым матрицы
/// @return // SUCCESS 0; INCORRECT_MATRIX 1;
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_code = INCORRECT_MATRIX;
  result->columns = 0;
  result->rows = 0;
  if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++)
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      err_code = SUCCESS;
    }
  }
  return err_code;
}

/// @brief Почиcтить память
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  if (A->rows) A->rows = 0;
  if (A->columns) A->columns = 0;
}

/// @brief Сравнение двух матриц
/// @return // EQUAL 1; NOT_EQUAL 0
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows != B->rows || A->columns != B->columns) return NOT_EQUAL;
  int result = EQUAL;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) result = NOT_EQUAL;
    }
  }
  return result;
}

/// @brief Сложение двух матриц
/// @param result Матрица с записанным результатом сложения
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (correct_matrix(A) || correct_matrix(B)) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  int err_code = s21_create_matrix(A->rows, A->columns, result);
  if (!err_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return err_code;
}

/// @brief Вычитание двух матриц
/// @param result Матрица с записанным результатом вычитания
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (correct_matrix(A) || correct_matrix(B)) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  int err_code = s21_create_matrix(A->rows, A->columns, result);
  if (!err_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return err_code;
}

/// @brief Умножение матрицы на число
/// @param result Матрица с записанным результатом умножения
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (correct_matrix(A)) return INCORRECT_MATRIX;
  int err_code = s21_create_matrix(A->rows, A->columns, result);
  if (!err_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return err_code;
}

/// @brief Умножение двух матриц
/// @param result Матрица с записанным результатом умножения
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (correct_matrix(A) || correct_matrix(B)) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;
  int err_code = s21_create_matrix(A->rows, B->columns, result);
  if (!err_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++)
        for (int k = 0; k < A->columns; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }

  return err_code;
}

/// @brief Разворот матрицы вокруг главной оси (столбцы и строки меняются
/// местами)
/// @param result Матрица с записанным результатом разворота
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (correct_matrix(A)) return INCORRECT_MATRIX;
  int err_code = s21_create_matrix(A->columns, A->rows, result);
  if (!err_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return err_code;
}

/// @brief Матрица алгебраических дополнений
/// @param A Исходная матрица
/// @param result Возвращаемая матрица
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows || A->columns == 1) return CALCULATION_ERROR;
  int err_code = s21_create_matrix(A->rows, A->columns, result);
  if (!err_code) {
    double mtx_complement;
    matrix_t minor_temp;
    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &minor_temp)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_mtx_minor(A, i, j, &minor_temp);
          s21_determinant(&minor_temp, &mtx_complement);
          result->matrix[i][j] = pow(-1, (i + 1) + (j + 1)) * mtx_complement;
        }
      }
    }
    s21_remove_matrix(&minor_temp);
  }
  return err_code;
}

/// @brief Поиск определителя матрицы
/// @param result Записанный определитель
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_determinant(matrix_t *A, double *result) {
  if (correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  *result = 0.;
  int err_code = SUCCESS;

  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->rows > 2) {
    matrix_t minor_temp;
    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &minor_temp)) {
      int k = 1;
      double temp_res = 0.0;
      for (int i = 0; i < A->rows; i++) {
        s21_mtx_minor(A, i, 0, &minor_temp);
        s21_determinant(&minor_temp, &temp_res);
        *result += k * A->matrix[i][0] * temp_res;
        k = -k;
      }
      s21_remove_matrix(&minor_temp);
    }
  }

  return err_code;
}

/// @brief Матрица А^(-1) (при умножении на исходную матрицу получаем еденичную
/// матрицу(еденицы на главной диагонали матрицы))
/// @param A Исходная матрица
/// @param result Записанная обратная матрица
/// @return // SUCCESS 0; INCORRECT_MATRIX 1; CALCULATION_ERROR 2
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (correct_matrix(A)) return INCORRECT_MATRIX;
  if (A->columns != A->rows || A->columns == 1) return CALCULATION_ERROR;

  double determinant = 0.0;
  s21_determinant(A, &determinant);
  if (determinant) {
    matrix_t temp_mtx_1, temp_mtx_2;
    // err_code = ;
    if (!s21_calc_complements(A, &temp_mtx_1)) {
      // err_code = ;
      if (!s21_transpose(&temp_mtx_1, &temp_mtx_2)) {
        s21_mult_number(&temp_mtx_2, 1 / determinant, result);
        s21_remove_matrix(&temp_mtx_2);
      }
      s21_remove_matrix(&temp_mtx_1);
    }
  }

  return SUCCESS;
}

//------HELP_FUNC------//

/// @brief Найти минор матрицы
/// @param A Исходная матрица
/// @param minor_row Индекс строки минора
/// @param minor_column Индекс столбца минора
/// @param result Минор матрицы
int s21_mtx_minor(matrix_t *A, int minor_row, int minor_column,
                  matrix_t *result) {
  int x = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i != minor_row) {
      int y = 0;
      for (int j = 0; j < A->columns; j++) {
        if (j != minor_column) {
          result->matrix[x][y] = A->matrix[i][j];
          y++;
        }
      }
      x++;
    }
  }
  return 0;
}

/// @brief Проверка входных значений матрицы
/// @param matrix Подаваtмая матрица
/// @return // SUCCESS 0; INCORRECT_MATRIX 1;
int correct_matrix(matrix_t *matrix) {
  int ret_status = SUCCESS;
  if (matrix == NULL || matrix->matrix == NULL || (matrix->rows) <= 0 ||
      matrix->columns <= 0) {
    ret_status = INCORRECT_MATRIX;
  }
  return ret_status;
}

/// @brief Напечатать матрицу
void print_matrix(matrix_t *mtx) {
  if (mtx != NULL)
    for (int i = 0; i < mtx->rows; i++) {
      printf("\n");
      for (int j = 0; j < mtx->columns; j++) {
        // printf("i[%d]j[%d] ", i, j);
        // printf("%10.9lf ", mtx->matrix[i][j]);
        printf("%2.lf ", mtx->matrix[i][j]);
      }
    }
      printf("\n");
}

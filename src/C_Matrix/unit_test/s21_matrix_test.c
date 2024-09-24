
#include "../s21_matrix.h"

#include <check.h>

//--------------CREATE--------------//

START_TEST(s21_create_matrix_err_1) {
  matrix_t check;
  int row = 1, column = 1;
  int check_res = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res, SUCCESS);
  ck_assert_int_eq(check.rows, 1);
  ck_assert_int_eq(check.columns, 1);

  if (!check_res) {
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_2) {
  matrix_t check;
  int row = 4, column = 4;
  int check_res = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res, SUCCESS);
  ck_assert_int_eq(check.rows, 4);
  ck_assert_int_eq(check.columns, 4);

  if (!check_res) {
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_3) {
  matrix_t check;
  int row = 4, column = 1;
  int check_res = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res, SUCCESS);
  ck_assert_int_eq(check.rows, 4);
  ck_assert_int_eq(check.columns, 1);

  if (!check_res) {
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_4) {
  matrix_t check;
  int row = 1, column = 4;
  int check_res = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res, SUCCESS);
  ck_assert_int_eq(check.rows, 1);
  ck_assert_int_eq(check.columns, 4);

  if (!check_res) {
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_5) {
  matrix_t check;
  int row = 900, column = 900;
  int check_res = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res, SUCCESS);

  if (!check_res) {
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_6) {
  matrix_t check;
  int row = 0, column = 0;
  int check_res = s21_create_matrix(row, column, &check);
  if (check_res) {
    ck_assert_int_eq(check_res, INCORRECT_MATRIX);

    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_7) {
  matrix_t check;
  int row = 0, column = -1;
  int check_res = s21_create_matrix(row, column, &check);
  if (check_res) {
    ck_assert_int_eq(check_res, INCORRECT_MATRIX);

    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
  }
}
END_TEST

START_TEST(s21_create_matrix_err_8) {
  matrix_t check;
  int row = 1, column = -1;
  int check_res = s21_create_matrix(row, column, &check);
  if (check_res) {
    ck_assert_int_eq(check_res, INCORRECT_MATRIX);

    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
  }
}
END_TEST

//--------------EQUAL--------------//

START_TEST(s21_equal_1) {
  matrix_t check, origin;
  int row = 2, column = 1;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(column, row, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, NOT_EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_2) {
  matrix_t check, origin;
  int row = 50, column = 51;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(column, row, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, NOT_EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_3) {
  matrix_t check, origin;
  int row = 2, column = 2;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(row, column, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check.matrix[0][0] = 1.0001230, check.matrix[0][1] = 2.0004440;
      check.matrix[1][0] = 3.0003210, check.matrix[1][1] = 4.0005556;

      origin.matrix[0][0] = 1.0001230, origin.matrix[0][1] = 2.0004440;
      origin.matrix[1][0] = 3.0003210, origin.matrix[1][1] = 4.0005550;
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, NOT_EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_4) {
  matrix_t check, origin;
  int row = 2, column = 2;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(row, column, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check.matrix[0][0] = 1., check.matrix[0][1] = 2.;
      check.matrix[1][0] = 3., check.matrix[1][1] = 4.;

      origin.matrix[0][0] = 1.0, origin.matrix[0][1] = 2.00;
      origin.matrix[1][0] = 3.000, origin.matrix[1][1] = 4.0000;
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_5) {
  matrix_t check, origin;
  int row = 3, column = 3;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(row, column, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check.matrix[0][0] = 1., check.matrix[0][1] = 2.,
      check.matrix[0][2] = 12.;
      check.matrix[1][0] = 3., check.matrix[1][1] = 4.,
      check.matrix[1][2] = 34.;
      check.matrix[2][0] = 5., check.matrix[2][1] = 6.,
      check.matrix[2][2] = 56.0000001;

      origin.matrix[0][0] = 1.0, origin.matrix[0][1] = 2.00,
      origin.matrix[0][2] = 12.;
      origin.matrix[1][0] = 3.000, origin.matrix[1][1] = 4.0000,
      origin.matrix[1][2] = 34.;
      origin.matrix[2][0] = 5.00000, origin.matrix[2][1] = 6.000000,
      origin.matrix[2][2] = 56.0000001;
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_6) {
  matrix_t check, origin;
  int row = 3, column = 3;
  int check_res_1 = s21_create_matrix(row, column, &check);
  if (!check_res_1) {
    ck_assert_int_eq(check_res_1, SUCCESS);
    int check_res_2 = s21_create_matrix(row, column, &origin);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check.matrix[0][0] = 1., check.matrix[0][1] = 2.,
      check.matrix[0][2] = 12.;
      check.matrix[1][0] = 3., check.matrix[1][1] = 4.,
      check.matrix[1][2] = 34.;
      check.matrix[2][0] = 5., check.matrix[2][1] = 6.,
      check.matrix[2][2] = 56.0000008;

      origin.matrix[0][0] = 1.0, origin.matrix[0][1] = 2.00,
      origin.matrix[0][2] = 12.;
      origin.matrix[1][0] = 3.000, origin.matrix[1][1] = 4.0000,
      origin.matrix[1][2] = 34.;
      origin.matrix[2][0] = 5.00000, origin.matrix[2][1] = 6.000000,
      origin.matrix[2][2] = 56.0000008;
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

START_TEST(s21_equal_7) {
  matrix_t check, origin;
  int row = 3, column = 3;
  int check_res_1 = s21_create_matrix(row, column, &check);
  ck_assert_int_eq(check_res_1, SUCCESS);
  if (!check_res_1) {
    int check_res_2 = s21_create_matrix(row, column, &origin);
    ck_assert_int_eq(check_res_2, SUCCESS);
    if (!check_res_2) {
      check.matrix[0][0] = 1.0000000001, check.matrix[0][1] = 2.00000000002,
      check.matrix[0][2] = 12.000000000000000003;
      check.matrix[1][0] = 3., check.matrix[1][1] = 4.,
      check.matrix[1][2] = 34.;
      check.matrix[2][0] = 5., check.matrix[2][1] = 6.,
      check.matrix[2][2] = 56.00000083;

      origin.matrix[0][0] = 1.0000000001, origin.matrix[0][1] = 2.00000000002,
      origin.matrix[0][2] = 12.000000000000000003;
      origin.matrix[1][0] = 3.000, origin.matrix[1][1] = 4.0000,
      origin.matrix[1][2] = 34.;
      origin.matrix[2][0] = 5.00000, origin.matrix[2][1] = 6.000000,
      origin.matrix[2][2] = 56.00000083;
      int check_eq = s21_eq_matrix(&check, &origin);
      ck_assert_int_eq(check_eq, EQUAL);

      s21_remove_matrix(&origin);
    }
    s21_remove_matrix(&check);
    ck_assert_int_eq(check.rows, 0);
    ck_assert_int_eq(check.columns, 0);
    ck_assert_ptr_eq(check.matrix, NULL);
  }
}
END_TEST

//--------------SUM--------------//

START_TEST(s21_sum_matrix_1) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;

  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_1 = s21_create_matrix(row, column, &val_1);
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);
      check_res_2 = s21_create_matrix(1, column, &val_2);  // разные матрицы
      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);
        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, CALCULATION_ERROR);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 2.,
        origin.matrix[0][2] = 12.;
        origin.matrix[1][0] = 3., origin.matrix[1][1] = 4.,
        origin.matrix[1][2] = 34.;
        origin.matrix[2][0] = 5., origin.matrix[2][1] = 6.,
        origin.matrix[2][2] = 56.;

        s21_remove_matrix(&val_2);
        if (!check_sum) s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_1 = s21_create_matrix(row, column, &val_2);
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);
      check_res_2 = s21_create_matrix(1, column, &val_1);  // разные матрицы
      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);
        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, CALCULATION_ERROR);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 2.,
        origin.matrix[0][2] = 12.;
        origin.matrix[1][0] = 3., origin.matrix[1][1] = 4.,
        origin.matrix[1][2] = 34.;
        origin.matrix[2][0] = 5., origin.matrix[2][1] = 6.,
        origin.matrix[2][2] = 56.;

        s21_remove_matrix(&val_1);
        if (!check_sum) s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_2);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t val_1, val_2, check, origin;
  int row = 1, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_2 = s21_create_matrix(row, column, &val_1);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check_res_1 = s21_create_matrix(row, column, &val_2);
      if (!check_res_1) {
        ck_assert_int_eq(check_res_1, SUCCESS);

        val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 1.,
        val_1.matrix[0][2] = 3.;

        val_2.matrix[0][0] = 0., val_2.matrix[0][1] = 1.,
        val_2.matrix[0][2] = 9.;

        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, SUCCESS);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 2.,
        origin.matrix[0][2] = 12.;

        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        if (!check_sum) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_2 = s21_create_matrix(row, column, &val_1);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check_res_1 = s21_create_matrix(row, column, &val_2);
      if (!check_res_1) {
        ck_assert_int_eq(check_res_1, SUCCESS);

        val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 1.,
        val_1.matrix[0][2] = 3.;
        val_1.matrix[1][0] = 1.01, val_1.matrix[1][1] = 1.001,
        val_1.matrix[1][2] = 3.000004;
        val_1.matrix[2][0] = 1.151, val_1.matrix[2][1] = 1.000222,
        val_1.matrix[2][2] = 3.808010;

        val_2.matrix[0][0] = 0., val_2.matrix[0][1] = 1.,
        val_2.matrix[0][2] = 9.;
        val_2.matrix[1][0] = 0.1, val_2.matrix[1][1] = 1.0001,
        val_2.matrix[1][2] = 9.00008;
        val_2.matrix[2][0] = 0.515, val_2.matrix[2][1] = 1.765248,
        val_2.matrix[2][2] = 9.6842951;

        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, SUCCESS);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 2.,
        origin.matrix[0][2] = 12.;
        origin.matrix[1][0] = 1.11, origin.matrix[1][1] = 2.0011,
        origin.matrix[1][2] = 12.000084;
        origin.matrix[2][0] = 1.666, origin.matrix[2][1] = 2.765470,
        origin.matrix[2][2] = 13.492305100;

        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        if (!check_sum) s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_2);
    }
    s21_remove_matrix(&val_1);
  }
  s21_remove_matrix(&origin);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t val_1, val_2, check, origin;
  int row = 1, column = 1;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_2 = s21_create_matrix(row, column, &val_1);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check_res_1 = s21_create_matrix(row, column, &val_2);
      if (!check_res_1) {
        ck_assert_int_eq(check_res_1, SUCCESS);

        val_1.matrix[0][0] = 1.00001;

        val_2.matrix[0][0] = 999.35789;

        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, SUCCESS);

        origin.matrix[0][0] = 1000.3579;

        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        if (!check_sum) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t val_1, val_2, check, origin;
  int row = 2, column = 1;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_2 = s21_create_matrix(row, column, &val_1);
    if (!check_res_2) {
      ck_assert_int_eq(check_res_2, SUCCESS);
      check_res_1 = s21_create_matrix(row, column, &val_2);
      if (!check_res_1) {
        ck_assert_int_eq(check_res_1, SUCCESS);

        val_1.matrix[0][0] = 1.;
        val_1.matrix[1][0] = 1.01;

        val_2.matrix[0][0] = 0.;
        val_2.matrix[1][0] = 0.2;

        int check_sum = s21_sum_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sum, SUCCESS);

        origin.matrix[0][0] = 1.;
        origin.matrix[1][0] = 1.21;

        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        if (!check_sum) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------SUB--------------//

START_TEST(s21_sub_matrix_1) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);

      check_res_2 = s21_create_matrix(1, column, &val_2);  // разные матрицы
      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);
        int check_sub = s21_sub_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sub, CALCULATION_ERROR);

        if (!check_sub) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(1, column, &val_1);  // разные матрицы
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);
      check_res_2 = s21_create_matrix(row, column, &val_2);

      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);

        int check_sub = s21_sub_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sub, CALCULATION_ERROR);

        if (!check_sub) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t val_1, val_2, check, origin;
  int row = 1, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);

  ck_assert_int_eq(check_res_2, SUCCESS);

  check_res_1 = s21_create_matrix(row, column, &val_1);
  check_res_2 = s21_create_matrix(row, column, &val_2);
  ck_assert_int_eq(check_res_1, SUCCESS);
  ck_assert_int_eq(check_res_2, SUCCESS);
  if (origin.matrix != NULL && val_1.matrix != NULL && val_2.matrix != NULL) {
    val_1.matrix[0][0] = 123., val_1.matrix[0][1] = 456.,
    val_1.matrix[0][2] = 789.;

    val_2.matrix[0][0] = 23., val_2.matrix[0][1] = 450.,
    val_2.matrix[0][2] = 8.991135;

    int check_sub = s21_sub_matrix(&val_1, &val_2, &check);
    ck_assert_int_eq(check_sub, SUCCESS);

    origin.matrix[0][0] = 100., origin.matrix[0][1] = 6.,
    origin.matrix[0][2] = 780.0088650;

    int check_eq = s21_eq_matrix(&check, &origin);
    ck_assert_int_eq(check_eq, EQUAL);

    s21_remove_matrix(&check);
    s21_remove_matrix(&origin);
    s21_remove_matrix(&val_1);
    s21_remove_matrix(&val_2);
  }
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 1;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);

  ck_assert_int_eq(check_res_2, SUCCESS);

  if (!check_res_2) {
    check_res_1 = s21_create_matrix(row, column, &val_1);

    if (!check_res_1) {
      check_res_2 = s21_create_matrix(row, column, &val_2);
      ck_assert_int_eq(check_res_1, SUCCESS);
      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);
        val_1.matrix[0][0] = 123., val_1.matrix[1][0] = 456.,
        val_1.matrix[2][0] = 789.;

        val_2.matrix[0][0] = 23., val_2.matrix[1][0] = 450.,
        val_2.matrix[2][0] = 8.991135;

        int check_sub = s21_sub_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sub, SUCCESS);

        origin.matrix[0][0] = 100., origin.matrix[1][0] = 6.,
        origin.matrix[2][0] = 780.0088650;
        if (!check_sub) {
          int check_eq = s21_eq_matrix(&check, &origin);
          ck_assert_int_eq(check_eq, EQUAL);
        }

        if (!check_sub) s21_remove_matrix(&check);
        s21_remove_matrix(&val_1);
      }
      s21_remove_matrix(&val_2);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);

  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    if (!check_res_1) {
      check_res_2 = s21_create_matrix(row, column, &val_2);
      if (!check_res_2) {
        ck_assert_int_eq(check_res_1, SUCCESS);
        ck_assert_int_eq(check_res_2, SUCCESS);

        val_1.matrix[0][0] = 0., val_1.matrix[0][1] = -2.,
        val_1.matrix[0][2] = 8.;
        val_1.matrix[1][0] = -3., val_1.matrix[1][1] = 0.,
        val_1.matrix[1][2] = 9.;
        val_1.matrix[2][0] = -5., val_1.matrix[2][1] = 6.,
        val_1.matrix[2][2] = 1000.987654321;

        val_2.matrix[0][0] = 1., val_2.matrix[0][1] = 2.,
        val_2.matrix[0][2] = -8.;
        val_2.matrix[1][0] = -3., val_2.matrix[1][1] = -4.,
        val_2.matrix[1][2] = 9.;
        val_2.matrix[2][0] = 5., val_2.matrix[2][1] = 6.,
        val_2.matrix[2][2] = -50.12345678;

        int check_sub = s21_sub_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_sub, SUCCESS);

        origin.matrix[0][0] = -1., origin.matrix[0][1] = -4.,
        origin.matrix[0][2] = 16.;
        origin.matrix[1][0] = 0., origin.matrix[1][1] = 4.,
        origin.matrix[1][2] = 0.;
        origin.matrix[2][0] = -10., origin.matrix[2][1] = 0.,
        origin.matrix[2][2] = 1051.11111101;

        if (!check_sub) {
          int check_eq = s21_eq_matrix(&check, &origin);
          ck_assert_int_eq(check_eq, EQUAL);
        }

        if (!check_sub) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------MULT_MTX--------------//

START_TEST(s21_mult_matrix_1) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);
      check_res_2 =
          s21_create_matrix(1, column, &val_2);  // неподходящие матрицы
      if (!check_res_2) {
        ck_assert_int_eq(check_res_2, SUCCESS);
        int check_mul = s21_mult_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_mul, CALCULATION_ERROR);

        if (!check_mul) s21_remove_matrix(&check);
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 2;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(3, 1, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      check_res_2 = s21_create_matrix(1, 2, &val_2);
      ck_assert_int_eq(check_res_2, SUCCESS);
      if (!check_res_2) {
        val_1.matrix[0][0] = 10., val_1.matrix[1][0] = -0.1,
        val_1.matrix[2][0] = -789.001;

        val_2.matrix[0][0] = 23., val_2.matrix[0][1] = -450.005;

        int check_mul = s21_mult_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_mul, SUCCESS);

        origin.matrix[0][0] = 230.0000000, origin.matrix[0][1] = -4500.0500000,
        origin.matrix[1][0] = -2.3000000, origin.matrix[1][1] = 45.0005000,
        origin.matrix[2][0] = -18147.0230000,
        origin.matrix[2][1] = 355054.3950050;

        if (!check_mul) {
          int check_eq = s21_eq_matrix(&check, &origin);
          ck_assert_int_eq(check_eq, EQUAL);
          s21_remove_matrix(&check);
          ck_assert_int_eq(check.rows, 0);
          ck_assert_int_eq(check.columns, 0);
          ck_assert_ptr_eq(check.matrix, NULL);
        }
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t val_1, val_2, check, origin;
  int row = 3, column = 2;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, 4, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      check_res_2 = s21_create_matrix(4, 2, &val_2);
      ck_assert_int_eq(check_res_2, SUCCESS);
      if (!check_res_2) {
        val_1.matrix[0][0] = 1., val_1.matrix[0][1] = -2.,
        val_1.matrix[0][2] = 3, val_1.matrix[0][3] = 4;
        val_1.matrix[1][0] = 5., val_1.matrix[1][1] = 6.,
        val_1.matrix[1][2] = -7., val_1.matrix[1][3] = 8.;
        val_1.matrix[2][0] = 9., val_1.matrix[2][1] = 10.,
        val_1.matrix[2][2] = 11., val_1.matrix[2][3] = -12.0;

        val_2.matrix[0][0] = 1000000., val_2.matrix[0][1] = 9.;
        val_2.matrix[1][0] = 7., val_2.matrix[1][1] = -6.;
        val_2.matrix[2][0] = -4., val_2.matrix[2][1] = 0.000003;
        val_2.matrix[3][0] = 0.000002, val_2.matrix[3][1] = 0.;

        int check_mul = s21_mult_matrix(&val_1, &val_2, &check);
        ck_assert_int_eq(check_mul, SUCCESS);

        origin.matrix[0][0] = 999974.000008, origin.matrix[0][1] = 21.000009,
        origin.matrix[1][0] = 5000070.000016, origin.matrix[1][1] = 8.999979,
        origin.matrix[2][0] = 9000025.999976, origin.matrix[2][1] = 21.000033;

        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);
        if (!check_mul) {
          s21_remove_matrix(&check);
          ck_assert_int_eq(check.rows, 0);
          ck_assert_int_eq(check.columns, 0);
          ck_assert_ptr_eq(check.matrix, NULL);
        }
        s21_remove_matrix(&val_2);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------MULT_NUM_MTX--------------//

// Битая матрица
START_TEST(s21_mult_number_1) {
  matrix_t val_1, check, origin;
  double val_2 = 1.23456;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (check_res_1) {
      val_1.rows = 0;
      val_1.columns = 0;

      int check_mul = s21_mult_number(&val_1, val_2, &check);
      ck_assert_int_eq(check_mul, INCORRECT_MATRIX);

      if (!check_mul) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, NOT_EQUAL);
        s21_remove_matrix(&check);
      }
    }
    s21_remove_matrix(&val_1);
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t val_1, check, origin;
  double val_2 = 1.23456;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      int check_mul = s21_mult_number(&val_1, val_2, &check);
      ck_assert_int_eq(check_mul, SUCCESS);

      origin.matrix[0][0] = 0., origin.matrix[0][1] = 0.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = 0., origin.matrix[1][1] = 0.,
      origin.matrix[1][2] = 0.;
      origin.matrix[2][0] = 0., origin.matrix[2][1] = 0.,
      origin.matrix[2][2] = 0.;

      if (!check_mul) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t val_1, check, origin;
  double val_2 = 1.23456;
  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = -2.,
      val_1.matrix[0][2] = 3.;
      val_1.matrix[1][0] = 5., val_1.matrix[1][1] = 6.,
      val_1.matrix[1][2] = -7.;
      val_1.matrix[2][0] = 9., val_1.matrix[2][1] = 10.,
      val_1.matrix[2][2] = 11.;

      int check_mul = s21_mult_number(&val_1, val_2, &check);
      ck_assert_int_eq(check_mul, SUCCESS);

      origin.matrix[0][0] = 1.23456, origin.matrix[0][1] = -2.46912,
      origin.matrix[0][2] = 3.70368;
      origin.matrix[1][0] = 6.1728, origin.matrix[1][1] = 7.40736,
      origin.matrix[1][2] = -8.64192;
      origin.matrix[2][0] = 11.11104, origin.matrix[2][1] = 12.3456,
      origin.matrix[2][2] = 13.58016;
      if (!check_mul) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t val_1, check, origin;
  double val_2 = -0.845;
  int row = 1, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = -1., val_1.matrix[0][1] = -2.,
      val_1.matrix[0][2] = 0.156;

      int check_mul = s21_mult_number(&val_1, val_2, &check);
      ck_assert_int_eq(check_mul, SUCCESS);

      origin.matrix[0][0] = 0.845, origin.matrix[0][1] = 1.69,
      origin.matrix[0][2] = -0.13182;
      if (!check_mul) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------TRANSPOSE_MTX--------------//

START_TEST(s21_transpose_1) {
  matrix_t val_1, check, origin;

  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    if (!check_res_1) {
      ck_assert_int_eq(check_res_1, SUCCESS);
      val_1.matrix[0][0] = 1.;
      val_1.matrix[1][1] = 1.;
      val_1.matrix[2][2] = 1.;

      int check_tr = s21_transpose(&val_1, &check);
      ck_assert_int_eq(check_tr, SUCCESS);

      origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = 0., origin.matrix[1][1] = 1.,
      origin.matrix[1][2] = 0.;
      origin.matrix[2][0] = 0., origin.matrix[2][1] = 0.,
      origin.matrix[2][2] = 1.;
      if (!check_tr) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t val_1, check, origin;

  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);
    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 2., val_1.matrix[0][2] = 3.;
      val_1.matrix[1][0] = 4., val_1.matrix[1][1] = 5., val_1.matrix[1][2] = 6.;
      val_1.matrix[2][0] = 0., val_1.matrix[2][1] = 8., val_1.matrix[2][2] = 9.;

      int check_tr = s21_transpose(&val_1, &check);
      ck_assert_int_eq(check_tr, SUCCESS);

      origin.matrix[0][0] = 1., origin.matrix[0][1] = 4.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = 2., origin.matrix[1][1] = 5.,
      origin.matrix[1][2] = 8.;
      origin.matrix[2][0] = 3., origin.matrix[2][1] = 6.,
      origin.matrix[2][2] = 9.;
      if (!check_tr) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t val_1, check, origin;

  int row = 4, column = 1;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(column, row, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 4., val_1.matrix[0][2] = 0.,
      val_1.matrix[0][3] = 8.;

      int check_tr = s21_transpose(&val_1, &check);
      ck_assert_int_eq(check_tr, SUCCESS);

      origin.matrix[0][0] = 1., origin.matrix[1][0] = 4.,
      origin.matrix[2][0] = 0., origin.matrix[3][0] = 8.;
      if (!check_tr) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------CALC_COMPLEMENTS--------------//

START_TEST(s21_calc_complements_1) {
  matrix_t val_1, check, origin;

  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1.;
      val_1.matrix[1][1] = 1.;
      val_1.matrix[2][2] = 1.;

      int check_calc_com = s21_calc_complements(&val_1, &check);
      ck_assert_int_eq(check_calc_com, SUCCESS);

      origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = 0., origin.matrix[1][1] = 1.,
      origin.matrix[1][2] = 0.;
      origin.matrix[2][0] = 0., origin.matrix[2][1] = 0.,
      origin.matrix[2][2] = 1.;
      if (!check_calc_com) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t val_1, check, origin;

  int row = 2, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 8.,
      val_1.matrix[0][2] = 15.;
      val_1.matrix[1][0] = 0., val_1.matrix[1][1] = 1., val_1.matrix[1][2] = 0.;

      int check_calc_com = s21_calc_complements(&val_1, &check);
      ck_assert_int_eq(check_calc_com, CALCULATION_ERROR);

      origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = -44.5, origin.matrix[1][1] = 1.,
      origin.matrix[1][2] = 3.5;
      if (!check_calc_com) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, NOT_EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t val_1, check, origin;

  int row = 4, column = 4;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 8.,
      val_1.matrix[0][2] = 15., val_1.matrix[0][3] = 1.5;
      val_1.matrix[1][0] = 0., val_1.matrix[1][1] = 1., val_1.matrix[1][2] = 0.,
      val_1.matrix[1][3] = 115.;
      val_1.matrix[2][0] = 0., val_1.matrix[2][1] = 3.5,
      val_1.matrix[2][2] = 100., val_1.matrix[2][3] = 125.;
      val_1.matrix[3][0] = 0., val_1.matrix[3][1] = 303.5,
      val_1.matrix[3][2] = 1., val_1.matrix[3][3] = 155.;

      int check_calc_com = s21_calc_complements(&val_1, &check);
      ck_assert_int_eq(check_calc_com, SUCCESS);

      origin.matrix[0][0] = -3474472.5, origin.matrix[0][1] = 0.00000,
      origin.matrix[0][2] = 0.000000, origin.matrix[0][3] = 0;
      origin.matrix[1][0] = -638405.250, origin.matrix[1][1] = 15375.0,
      origin.matrix[1][2] = 37395.0, origin.matrix[1][3] = -30346.5;
      origin.matrix[2][0] = 520294.000, origin.matrix[2][1] = 115.00,
      origin.matrix[2][2] = -34747.5, origin.matrix[2][3] = -1.;
      origin.matrix[3][0] = 87687.500, origin.matrix[3][1] = -11500.,
      origin.matrix[3][2] = 277.500, origin.matrix[3][3] = 100.;
      if (!check_calc_com) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_calc_complements_4) {
  matrix_t val_1, check, origin;

  int row = 2, column = 2;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 8.;
      val_1.matrix[1][0] = 15., val_1.matrix[1][1] = 4.;

      int check_calc_com = s21_calc_complements(&val_1, &check);
      ck_assert_int_eq(check_calc_com, SUCCESS);

      origin.matrix[0][0] = 4., origin.matrix[0][1] = -15.,
      origin.matrix[1][0] = -8., origin.matrix[1][1] = 1.;
      if (!check_calc_com) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------DETERMINANT--------------//

START_TEST(s21_determinant_1) {
  matrix_t val_1;
  double origin_det = 0., check_determinant = 0.;
  int row = 3, column = 2;

  int check_res_1 = s21_create_matrix(row, column, &val_1);
  ck_assert_int_eq(check_res_1, SUCCESS);
  if (!check_res_1) {
    val_1.matrix[0][0] = 1.;
    val_1.matrix[1][1] = 1.;

    int check_det_err = s21_determinant(&val_1, &check_determinant);
    ck_assert_int_eq(check_det_err, CALCULATION_ERROR);

    ck_assert_ldouble_eq(check_determinant, origin_det);

    s21_remove_matrix(&val_1);
  }
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t val_1;
  double check_determinant = 0.;
  int row = 3, column = 3;
  int check_res_1 = s21_create_matrix(row, column, &val_1);
  ck_assert_int_eq(check_res_1, SUCCESS);
  if (!check_res_1) {
    val_1.matrix[0][0] = 1.9821, val_1.matrix[0][1] = 2.,
    val_1.matrix[0][2] = 3.;
    val_1.matrix[1][0] = 4., val_1.matrix[1][1] = 576.346,
    val_1.matrix[1][2] = 605.7863;
    val_1.matrix[2][0] = 789.24, val_1.matrix[2][1] = 8.,
    val_1.matrix[2][2] = 9.;

    int check_det_err = s21_determinant(&val_1, &check_determinant);
    ck_assert_int_eq(check_det_err, SUCCESS);
    double origin_det = -407704.84583844;
    ck_assert_ldouble_eq_tol(check_determinant, origin_det, 1e-07);

    s21_remove_matrix(&val_1);
  }
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t val_1;
  double check_determinant = 0.;
  int row = 4, column = 4;
  int check_res_1 = s21_create_matrix(row, column, &val_1);
  ck_assert_int_eq(check_res_1, SUCCESS);
  if (!check_res_1) {
    val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 8., val_1.matrix[0][2] = 15.,
    val_1.matrix[0][3] = 1.5;
    val_1.matrix[1][0] = 0., val_1.matrix[1][1] = 1.,
    val_1.matrix[1][2] = 0.76481, val_1.matrix[1][3] = 115.;
    val_1.matrix[2][0] = 0., val_1.matrix[2][1] = 3.5,
    val_1.matrix[2][2] = 100., val_1.matrix[2][3] = 125.;
    val_1.matrix[3][0] = 0.987552, val_1.matrix[3][1] = 303.5,
    val_1.matrix[3][2] = 1., val_1.matrix[3][3] = 155.;

    int check_det_err = s21_determinant(&val_1, &check_determinant);
    ck_assert_int_eq(check_det_err, SUCCESS);
    double origin_det = -3360027.78842448;
    ck_assert_ldouble_eq_tol(check_determinant, origin_det, 1e-07);

    s21_remove_matrix(&val_1);
  }
}
END_TEST

//--------------INVERSE_MTX--------------//

START_TEST(s21_inverse_matrix_1) {
  matrix_t val_1, check, origin;

  int row = 2, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 8.,
      val_1.matrix[0][2] = 15.;
      val_1.matrix[1][0] = 0., val_1.matrix[1][1] = 1., val_1.matrix[1][2] = 0.;

      int check_inv = s21_inverse_matrix(&val_1, &check);
      ck_assert_int_eq(check_inv, CALCULATION_ERROR);

      origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
      origin.matrix[0][2] = 0.;
      origin.matrix[1][0] = -44.5, origin.matrix[1][1] = 1.,
      origin.matrix[1][2] = 3.5;

      if (!check_inv) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, NOT_EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t val_1, check, origin;

  int row = 3, column = 3;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 101.1001, val_1.matrix[0][1] = 128.,
      val_1.matrix[0][2] = 256.512;
      val_1.matrix[1][0] = 4096., val_1.matrix[1][1] = 10.24,
      val_1.matrix[1][2] = 111000.1;
      val_1.matrix[2][0] = 2056.123, val_1.matrix[2][1] = 987.654,
      val_1.matrix[2][2] = 0.010101;

      int check_inv = s21_inverse_matrix(&val_1, &check);
      ck_assert_int_eq(check_inv, SUCCESS);

      origin.matrix[0][0] = -0.00572115, origin.matrix[0][1] = 0.00001322,
      origin.matrix[0][2] = 0.00074132;
      origin.matrix[1][0] = 0.011910452, origin.matrix[1][1] = -0.00002752,
      origin.matrix[1][2] = -0.000530809;
      origin.matrix[2][0] = 0.000210016, origin.matrix[2][1] = 0.000008552,
      origin.matrix[2][2] = -0.0000273065;

      if (!check_inv) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
        origin.matrix[0][2] = 0., origin.matrix[1][0] = 0.,
        origin.matrix[1][1] = 1., origin.matrix[1][2] = 0.,
        origin.matrix[2][0] = 0., origin.matrix[2][1] = 0.,
        origin.matrix[2][2] = 1.;
        matrix_t val_2;
        if (!s21_mult_matrix(&val_1, &check, &val_2)) {
          s21_eq_matrix(&val_2, &origin);
          ck_assert_int_eq(check_eq, EQUAL);
          s21_remove_matrix(&val_2);
        }
        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t val_1, check, origin;

  int row = 4, column = 4;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 1., val_1.matrix[0][1] = 5.,
      val_1.matrix[0][2] = 10., val_1.matrix[0][3] = 10.;
      val_1.matrix[1][0] = 3., val_1.matrix[1][1] = 8., val_1.matrix[1][2] = 4.,
      val_1.matrix[1][3] = 15.;
      val_1.matrix[2][0] = 7., val_1.matrix[2][1] = 0.,
      val_1.matrix[2][2] = 0.5, val_1.matrix[2][3] = 1.;
      val_1.matrix[3][0] = 9., val_1.matrix[3][1] = 1.,
      val_1.matrix[3][2] = 0.25, val_1.matrix[3][3] = 4.;

      int check_inv = s21_inverse_matrix(&val_1, &check);
      ck_assert_int_eq(check_inv, SUCCESS);

      origin.matrix[0][0] = -0.025331724, origin.matrix[0][1] = 0.03317249,
      origin.matrix[0][2] = 0.310615199, origin.matrix[0][3] = -0.13872135,
      origin.matrix[1][0] = -0.270205066, origin.matrix[1][1] = 0.52050663,
      origin.matrix[1][2] = 2.146562123, origin.matrix[1][3] = -1.81302774,
      origin.matrix[2][0] = 0.120627261, origin.matrix[2][1] = -0.06272617,
      origin.matrix[2][2] = 0.139927623, origin.matrix[2][3] = -0.10132689,
      origin.matrix[3][0] = 0.117008443, origin.matrix[3][1] = -0.20084439,
      origin.matrix[3][2] = -1.244270205, origin.matrix[3][3] = 1.02171290;

      if (!check_inv) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, EQUAL);

        origin.matrix[0][0] = 1., origin.matrix[0][1] = 0.,
        origin.matrix[0][2] = 0., origin.matrix[0][3] = 0.,
        origin.matrix[1][0] = 0., origin.matrix[1][1] = 1.,
        origin.matrix[1][2] = 0., origin.matrix[1][3] = 0.,
        origin.matrix[2][0] = 0., origin.matrix[2][1] = 0.,
        origin.matrix[2][2] = 1., origin.matrix[2][3] = 0.,
        origin.matrix[3][0] = 0., origin.matrix[3][1] = 0.,
        origin.matrix[3][2] = 0., origin.matrix[3][3] = 1.;
        matrix_t val_2;
        if (!s21_mult_matrix(&val_1, &check, &val_2)) {
          s21_eq_matrix(&val_2, &origin);
          ck_assert_int_eq(check_eq, EQUAL);
          s21_remove_matrix(&val_2);
        }
        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t val_1, check, origin;

  int row = 1, column = 1;
  int check_res_1 = 0;
  int check_res_2 = s21_create_matrix(row, column, &origin);
  if (!check_res_2) {
    ck_assert_int_eq(check_res_2, SUCCESS);

    check_res_1 = s21_create_matrix(row, column, &val_1);
    ck_assert_int_eq(check_res_1, SUCCESS);
    if (!check_res_1) {
      val_1.matrix[0][0] = 4.;

      int check_inv = s21_inverse_matrix(&val_1, &check);
      ck_assert_int_eq(check_inv, CALCULATION_ERROR);

      origin.matrix[0][0] = 4684.;

      if (!check_inv) {
        int check_eq = s21_eq_matrix(&check, &origin);
        ck_assert_int_eq(check_eq, NOT_EQUAL);

        s21_remove_matrix(&check);
      }
      s21_remove_matrix(&val_1);
    }
    s21_remove_matrix(&origin);
  }
}
END_TEST

//--------------SUITE--------------//

Suite *suite_create_mtx(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_CREATE_MATRIX \033[0;0;0m");
  TCase *test_case =
      tcase_create("\033[1;30;47m s21_create_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_create_matrix_err_1);
  tcase_add_test(test_case, s21_create_matrix_err_2);
  tcase_add_test(test_case, s21_create_matrix_err_3);
  tcase_add_test(test_case, s21_create_matrix_err_4);
  tcase_add_test(test_case, s21_create_matrix_err_5);
  tcase_add_test(test_case, s21_create_matrix_err_6);
  tcase_add_test(test_case, s21_create_matrix_err_7);
  tcase_add_test(test_case, s21_create_matrix_err_8);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_eq_mtx(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_EQ_MATRIX \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_eq_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_equal_1);
  tcase_add_test(test_case, s21_equal_2);
  tcase_add_test(test_case, s21_equal_3);
  tcase_add_test(test_case, s21_equal_4);
  tcase_add_test(test_case, s21_equal_5);
  tcase_add_test(test_case, s21_equal_6);
  tcase_add_test(test_case, s21_equal_7);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_sum_matrix(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_SUM_MATRIX \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_sum_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_sum_matrix_1);
  tcase_add_test(test_case, s21_sum_matrix_2);
  tcase_add_test(test_case, s21_sum_matrix_3);
  tcase_add_test(test_case, s21_sum_matrix_4);
  tcase_add_test(test_case, s21_sum_matrix_5);
  tcase_add_test(test_case, s21_sum_matrix_6);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_sub_matrix(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_SUB_MATRIX \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_sub_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_sub_matrix_1);
  tcase_add_test(test_case, s21_sub_matrix_2);
  tcase_add_test(test_case, s21_sub_matrix_3);
  tcase_add_test(test_case, s21_sub_matrix_4);
  tcase_add_test(test_case, s21_sub_matrix_5);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_mult_matrix(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_MULT_MATRIX \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_mult_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_mult_matrix_1);
  tcase_add_test(test_case, s21_mult_matrix_2);
  tcase_add_test(test_case, s21_mult_matrix_3);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_mult_number(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_MULT_NUMBER \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_mult_number \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_mult_number_1);
  tcase_add_test(test_case, s21_mult_number_2);
  tcase_add_test(test_case, s21_mult_number_3);
  tcase_add_test(test_case, s21_mult_number_4);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_transpose(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_TRANSPOSE \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_transpose \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_transpose_1);
  tcase_add_test(test_case, s21_transpose_2);
  tcase_add_test(test_case, s21_transpose_3);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_calc_complements(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_CALC_COMPLEMENTS \033[0;0;0m");
  TCase *test_case =
      tcase_create("\033[1;30;47m s21_calc_complements \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_calc_complements_1);
  tcase_add_test(test_case, s21_calc_complements_2);
  tcase_add_test(test_case, s21_calc_complements_3);
  tcase_add_test(test_case, s21_calc_complements_4);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_determinant(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_DETERMINANT \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_determinant \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_determinant_1);
  tcase_add_test(test_case, s21_determinant_2);
  tcase_add_test(test_case, s21_determinant_3);

  suite_add_tcase(suite, test_case);
  return suite;
}

Suite *suite_inverse_matrix(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_INVERSE_MATRIX \033[0;0;0m");
  TCase *test_case =
      tcase_create("\033[1;30;47m s21_inverse_matrix \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_inverse_matrix_1);
  tcase_add_test(test_case, s21_inverse_matrix_2);
  tcase_add_test(test_case, s21_inverse_matrix_3);
  tcase_add_test(test_case, s21_inverse_matrix_4);

  suite_add_tcase(suite, test_case);
  return suite;
}

void run_set(Suite *current_set) {
  SRunner *all_test = srunner_create(current_set);

  srunner_set_fork_status(all_test, CK_NOFORK);
  srunner_run_all(all_test, CK_NORMAL);

  srunner_free(all_test);
}

void test_sets(void) {
  Suite *sets[] = {suite_create_mtx(),
                   suite_eq_mtx(),
                   suite_sum_matrix(),
                   suite_sub_matrix(),
                   suite_mult_matrix(),
                   suite_mult_number(),
                   suite_transpose(),
                   suite_calc_complements(),
                   suite_determinant(),
                   suite_inverse_matrix(),
                   NULL};

  for (Suite **current_set = sets; *current_set != NULL; current_set++) {
    run_set(*current_set);
  }
}

int main(void) {
  test_sets();
  return 0;
}

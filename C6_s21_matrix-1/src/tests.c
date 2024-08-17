#include <check.h>
#include <stdlib.h>  //для rand

#include "s21_matrix.h"

double get_rand(double min, double max);

START_TEST(create_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST
START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(create_4) {
  const int rows = -1;
  const int columns = 2;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, columns, &m),
                   ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(create_null_result) {
  const int rows = 1;
  const int columns = 2;
  ck_assert_int_eq(s21_create_matrix(rows, columns, NULL),
                   ERROR_UNCORRECT_MATRIX);
}
END_TEST

START_TEST(remove_1) {
  const int rows = 4;
  const int columns = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  s21_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
  ck_assert_int_eq(m.rows, 0);
  ck_assert_int_eq(m.columns, 0);
}
END_TEST
START_TEST(remove_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(eq_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST
START_TEST(eq_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, FAILURE);
}
END_TEST
START_TEST(eq_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, FAILURE);
}
END_TEST
START_TEST(eq_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, FAILURE);
}
END_TEST
START_TEST(eq_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  int return_value;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  return_value = s21_eq_matrix(&matrix1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, FAILURE);
}
END_TEST
START_TEST(eq_casual_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_casual_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_casual_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_casual_matrix_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_casual_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.00000000234;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(eq_casual_matrix_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(zero_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
}
END_TEST

START_TEST(sum_1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, columns, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] + mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_2) {
  matrix_t m = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int columns1 = rand() % 100 + 1;
  s21_create_matrix(rows1, columns1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res),
                   ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST
START_TEST(sum_3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  rows = -rows;
  columns = -columns;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, columns, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);

  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  matrix_t matrix_test;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 5;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 6;
  // matrix2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 0;
  matrix2.matrix[0][2] = 0;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 0;
  matrix2.matrix[1][2] = 0;
  matrix2.matrix[2][0] = 3;
  matrix2.matrix[2][1] = 4;
  matrix2.matrix[2][2] = 1;
  // matrix_test
  matrix_test.matrix[0][0] = 2;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 2;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 5;
  matrix_test.matrix[2][0] = 3;
  matrix_test.matrix[2][1] = 4;
  matrix_test.matrix[2][2] = 7;

  return_value = s21_sum_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, FAILURE);
  return_value = s21_eq_matrix(&matrix_test, &matrix_result);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(sum_5) {
  int rows = 0;
  int columns = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, columns, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      check.matrix[i][j] = m.matrix[i][j] + mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), ERROR_UNCORRECT_MATRIX);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), FAILURE);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sum_6) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result),
                   ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(sum_7) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST
START_TEST(sum_8) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(sub_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  matrix_t matrix_test;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 5;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 6;
  // matrix2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = 0;
  matrix2.matrix[0][2] = 0;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 0;
  matrix2.matrix[1][2] = 0;
  matrix2.matrix[2][0] = 3;
  matrix2.matrix[2][1] = 4;
  matrix2.matrix[2][2] = 1;
  // matrix_test
  matrix_test.matrix[0][0] = 0;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = -2;
  matrix_test.matrix[1][1] = 4;
  matrix_test.matrix[1][2] = 5;
  matrix_test.matrix[2][0] = -3;
  matrix_test.matrix[2][1] = -4;
  matrix_test.matrix[2][2] = 5;

  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  s21_remove_matrix(&matrix_test);
}
END_TEST
START_TEST(sub_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(sub_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
}
END_TEST
START_TEST(sub_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  s21_create_matrix(3, 3, &matrix_result);
  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
}
END_TEST
START_TEST(sub_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value = 0;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_create_matrix(3, 3, &matrix_result);
  return_value = s21_sub_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
}
END_TEST
START_TEST(sub_1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, columns, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] - mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sub_2) {
  matrix_t m = {0};
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int columns1 = rand() % 100 + 1;
  s21_create_matrix(rows1, columns1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < columns1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res),
                   ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST
START_TEST(sub_3) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  rows = -rows;
  columns = -columns;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, columns, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);
  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res), ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sub_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] - mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sub_matrix1) {
  matrix_t m = {0};
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  s21_create_matrix(rows1, cols1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res),
                   ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
}
END_TEST
START_TEST(sub_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_sub_matrix(&m, &mtx, &res), ERROR_UNCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(sub_matrix_last_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result),
                   ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(sub_matrix_last_2) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST
START_TEST(sub_matrix_last_3) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;
  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = -2, eq_matrix.matrix[1][1] = 4,
  eq_matrix.matrix[1][2] = 5;
  eq_matrix.matrix[2][0] = -3, eq_matrix.matrix[2][1] = -4,
  eq_matrix.matrix[2][2] = 5;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(mult_num_1) {
  matrix_t matrix1;
  matrix_t matrix_result;
  double number = 1;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix1.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(mult_num_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  matrix_t matrix_test;
  double number = 2;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  // matrix_test
  matrix_test.matrix[0][0] = 2;
  matrix_test.matrix[0][1] = 4;
  matrix_test.matrix[0][2] = 6;
  matrix_test.matrix[1][0] = 8;
  matrix_test.matrix[1][1] = 10;
  matrix_test.matrix[1][2] = 12;
  matrix_test.matrix[2][0] = 14;
  matrix_test.matrix[2][1] = 16;
  matrix_test.matrix[2][2] = 18;

  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
  s21_remove_matrix(&matrix_test);
}
END_TEST
START_TEST(mult_num_3) {
  matrix_t matrix1;
  matrix_t matrix_result;
  matrix_t matrix_test;
  double number = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_create_matrix(rows, cols, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  // matrix_test
  matrix_test.matrix[0][0] = 0;
  matrix_test.matrix[0][1] = 0;
  matrix_test.matrix[0][2] = 0;
  matrix_test.matrix[1][0] = 0;
  matrix_test.matrix[1][1] = 0;
  matrix_test.matrix[1][2] = 0;
  matrix_test.matrix[2][0] = 0;
  matrix_test.matrix[2][1] = 0;
  matrix_test.matrix[2][2] = 0;

  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
  s21_remove_matrix(&matrix_test);
}
END_TEST
START_TEST(mult_num_4) {
  matrix_t matrix1;
  matrix_t matrix_result;
  double number = 1;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // s21_create_matrix(rows, cols, &matrix_result);
  s21_remove_matrix(&matrix1);
  return_value = s21_mult_number(&matrix1, number, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
  // s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(mult_number_1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);
  double mult_number = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_number_2) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  rows = -rows;
  columns = -columns;
  matrix_t m = {0};
  s21_create_matrix(rows, columns, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &check);
  double mult_number = get_rand(-10e5, 10e5);
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, mult_number, &res),
                   ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_number_3) {
  double number = (rand() % 100 + 1) / 3;
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, columns, &A);
  int ret = s21_mult_number(&A, number, &R);
  ck_assert_int_eq(1, ret);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(mult_number_4) {
  double number = (rand() % 100 + 1) / 3;
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double t = rand();
      A.matrix[i][j] = t / 2;
      C.matrix[i][j] = number * A.matrix[i][j] * 2;
    }
  }
  int ret = s21_mult_number(&A, number, &R);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(0, ret);
  ck_assert_int_eq(FAILURE, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST
START_TEST(mult_number_5) {
  double number = (rand() % 100 + 1) / 3;
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double t = rand();
      A.matrix[i][j] = t / 2;
      C.matrix[i][j] = number * A.matrix[i][j];
    }
  }
  int ret = s21_mult_number(&A, number, &R);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(0, ret);
  ck_assert_int_eq(SUCCESS, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST
START_TEST(mult_number_6) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST
START_TEST(mult_number_7) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, OK);
}
END_TEST
START_TEST(mult_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  matrix_t matrix_test;
  int return_value;
  s21_create_matrix(3, 2, &matrix1);
  s21_create_matrix(2, 3, &matrix2);
  s21_create_matrix(3, 3, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 4;
  matrix1.matrix[1][0] = 2;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 6;
  // matrix2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = -1;
  matrix2.matrix[0][2] = 1;
  matrix2.matrix[1][0] = 2;
  matrix2.matrix[1][1] = 3;
  matrix2.matrix[1][2] = 4;
  // matrix_test
  matrix_test.matrix[0][0] = 9;
  matrix_test.matrix[0][1] = 11;
  matrix_test.matrix[0][2] = 17;
  matrix_test.matrix[1][0] = 12;
  matrix_test.matrix[1][1] = 13;
  matrix_test.matrix[1][2] = 22;
  matrix_test.matrix[2][0] = 15;
  matrix_test.matrix[2][1] = 15;
  matrix_test.matrix[2][2] = 27;

  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      ck_assert_double_eq(matrix_result.matrix[i][j], matrix_test.matrix[i][j]);
  }
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
  ck_assert_int_eq(return_value, OK);
}
END_TEST
START_TEST(mult_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix2);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(mult_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix2);
  return_value = s21_mult_matrix(&matrix1, &matrix2, &matrix_result);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(mult_matrix1) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 10, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST
START_TEST(mult_matrix2) {
  matrix_t m = {0};
  int rows = 2;
  int cols = 3;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  int rows1 = 4;
  int cols1 = 5;
  s21_create_matrix(rows1, cols1, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res),
                   ERROR_MATHEMATICS_OPERATIONS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix3) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 3, &B);
  int result = s21_mult_matrix(&A, &B, &C);
  ck_assert_int_eq(result, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST
START_TEST(mult_matrix4) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = get_rand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = get_rand(-10e10, 10e10);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < mtx.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < m.columns; k++)
        check.matrix[i][j] += m.matrix[i][k] * mtx.matrix[k][j];
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix5) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix6) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = get_rand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = get_rand(-10e10, 10e10);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < mtx.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < m.columns; k++)
        check.matrix[i][j] += m.matrix[i][k] * mtx.matrix[k][j];
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix7) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(mult_matrix8) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), ERROR_UNCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t matrix1;
  matrix_t matrix_test;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(2, 3, &matrix_test);
  return_value = s21_transpose(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 0);
  return_value = s21_eq_matrix(&matrix_result, &matrix_test);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(transpose_2) {
  matrix_t matrix1;
  matrix_t matrix_test;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(2, 3, &matrix_test);
  // matrix1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 4;
  matrix1.matrix[1][0] = 2;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[2][0] = 3;
  matrix1.matrix[2][1] = 6;
  // matrix_test
  matrix_test.matrix[0][0] = 1;
  matrix_test.matrix[0][1] = 2;
  matrix_test.matrix[0][2] = 3;
  matrix_test.matrix[1][0] = 4;
  matrix_test.matrix[1][1] = 5;
  matrix_test.matrix[1][2] = 6;

  return_value = s21_transpose(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, FAILURE);
  return_value = s21_eq_matrix(&matrix_result, &matrix_test);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_test);
  s21_remove_matrix(&matrix_result);
}
END_TEST
START_TEST(transpose_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      m.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(transpose_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), ERROR_UNCORRECT_MATRIX);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST
START_TEST(transpose_matrix3) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(3, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST
START_TEST(transpose_matrix4) {
  matrix_t A;
  matrix_t result;
  s21_create_matrix(2, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST
START_TEST(transpose_matrix5) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 4;
  A.matrix[1][0] = 2, A.matrix[1][1] = 5;
  A.matrix[2][0] = 3, A.matrix[2][1] = 6;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = 2,
  eq_matrix.matrix[0][2] = 3;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = 5,
  eq_matrix.matrix[1][2] = 6;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&eq_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, OK);
  ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST
START_TEST(determinant_2) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  // matrix1.matrix[0][0] = 1;
  // matrix1.matrix[0][1] = 2;
  // matrix1.matrix[0][2] = 3;
  // matrix1.matrix[1][0] = 4;
  // matrix1.matrix[1][1] = 5;
  // matrix1.matrix[1][2] = 6;
  // matrix1.matrix[2][0] = 7;
  // matrix1.matrix[2][1] = 8;
  // matrix1.matrix[2][2] = 9;

  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
  // // ck_assert_double_eq(determinant, 0);
  s21_remove_matrix(&matrix1);
}
END_TEST
START_TEST(determinant_3) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 0;
  matrix1.matrix[0][2] = 0;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 0;
  matrix1.matrix[1][2] = 0;
  matrix1.matrix[2][0] = 0;
  matrix1.matrix[2][1] = 0;
  matrix1.matrix[2][2] = 0;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, OK);
  ck_assert_double_eq(determinant, 0);
}
END_TEST
START_TEST(determinant_4) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  matrix1.matrix[0][0] = 0;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 4;
  matrix1.matrix[1][0] = 1;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 3;
  matrix1.matrix[2][0] = 2;
  matrix1.matrix[2][1] = 3;
  matrix1.matrix[2][2] = 1;
  return_value = s21_determinant(&matrix1, &determinant);
  s21_remove_matrix(&matrix1);
  ck_assert_int_eq(return_value, OK);
  ck_assert_double_eq(determinant, -2);
}
END_TEST
START_TEST(determinant_5) {
  matrix_t matrix1;
  double determinant = 0;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);
  // matrix1.matrix[0][0] = 0;
  // matrix1.matrix[0][1] = 0;
  // matrix1.matrix[0][2] = 0;
  // matrix1.matrix[1][0] = 0;
  // matrix1.matrix[1][1] = 0;
  // matrix1.matrix[1][2] = 0;
  // matrix1.matrix[2][0] = 0;
  // matrix1.matrix[2][1] = 0;
  // matrix1.matrix[2][2] = 0;
  return_value = s21_determinant(&matrix1, &determinant);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
  // ck_assert_double_eq(determinant, 0);
}
END_TEST
START_TEST(deter_1) {
  int result = s21_determinant(NULL, NULL);
  ck_assert_int_eq(result, ERROR_UNCORRECT_MATRIX);
}
END_TEST
START_TEST(deter_3) {
  matrix_t A;
  double deter;
  s21_create_matrix(10, 9, &A);
  int res = s21_determinant(&A, &deter);
  ck_assert_int_eq(res, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(deter_4) {
  matrix_t A;
  double deter;
  double det_true = 984.1238;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 984.1238;
  int res = s21_determinant(&A, &deter);
  ck_assert_double_eq_tol(deter, det_true, 1e+08);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(deter_5) {
  matrix_t A;
  double deter;
  double det_true = 0;
  double const A_nums[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                             14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
  s21_create_matrix(5, 5, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  int res = s21_determinant(&A, &deter);
  ck_assert_double_eq_tol(deter, det_true, 1e-08);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(deter_6) {
  matrix_t A;
  double deter;
  double det_true = -40;
  double const A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  s21_create_matrix(3, 3, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  int res = s21_determinant(&A, &deter);
  ck_assert_double_eq_tol(deter, det_true, 1e-08);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(deter_7) {
  matrix_t A;
  double deter;
  double det_true = -1369800;
  double const A_nums[25] = {1,  2,  3,   4, 5,  6,  7,  8,  9,  10, 11, 12, 49,
                             14, 15, 161, 7, 18, 19, 20, 64, 48, 1,  2,  3};
  s21_create_matrix(5, 5, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  int res = s21_determinant(&A, &deter);
  ck_assert_double_eq_tol(deter, det_true, 1e+08);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
// END_TEST
START_TEST(deter_8) {
  matrix_t A;
  double deter;
  double det_true = 17187;
  double const A_nums[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  int res = s21_determinant(&A, &deter);
  ck_assert_double_eq_tol(deter, det_true, 1e+08);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(determinant1) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant2) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant3) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant4) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant5) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant6) {
  const int size = 1;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant7) {
  matrix_t m = {0};
  int rows = rand() % 100 + 1;
  rows = -rows;
  s21_create_matrix(rows, rows, &m);
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, ERROR_UNCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant8) {
  matrix_t m = {0};
  int rows = 4;
  int cols = 5;
  s21_create_matrix(rows, cols, &m);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);

  s21_remove_matrix(&m);
}
END_TEST
START_TEST(determinant9) {
  matrix_t A;
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant10) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  double det = 5;
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(OK, ret);
  ck_assert_double_eq(res, det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant11) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 7;
  double det = 31;
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(OK, ret);
  ck_assert_double_eq(res, det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant12) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;
  double det = 55;
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(OK, ret);
  ck_assert_double_eq(res, det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant13) {
  int rows = 4;
  int columns = 4;
  matrix_t A = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 8;
  A.matrix[1][3] = 6;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;
  A.matrix[2][3] = 3;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 2;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 2;
  double det = -44;
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(OK, ret);
  ck_assert_double_eq(res, det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant14) {
  int rows = rand() % 10 + 1;
  matrix_t A = {0};
  s21_create_matrix(rows, rows, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      A.matrix[i][j] = 4;
    }
  }
  double det = 5;
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(OK, ret);
  ck_assert_double_ne(res, det);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant15) {
  int rows = rand() % 100 + 1;
  matrix_t A = {0};
  s21_create_matrix(rows, rows + 1, &A);
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(ERROR_MATHEMATICS_OPERATIONS, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant16) {
  int rows = rand() % 100 + 1;
  matrix_t A = {0};
  s21_create_matrix(rows, 0, &A);
  double res = 0;
  int ret = s21_determinant(&A, &res);
  ck_assert_int_eq(ERROR_UNCORRECT_MATRIX, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant17) {
  matrix_t matrix;
  s21_create_matrix(3, 3, &matrix);
  int count = 1;
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = count++;
    }
  }
  matrix.matrix[2][2] = 10;
  double res, ref = -3.0;
  int ret = s21_determinant(&matrix, &res);
  ck_assert_double_eq(res, ref);
  ck_assert_int_eq(ret, OK);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;
  // matrix_result
  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 10;
  matrix2.matrix[0][2] = -20;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = -14;
  matrix2.matrix[1][2] = 8;
  matrix2.matrix[2][0] = -8;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = 4;
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 0;
  matrix1.matrix[1][1] = 4;
  matrix1.matrix[1][2] = 2;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = 2;
  matrix1.matrix[2][2] = 1;
  // matrix_result
  matrix2.matrix[0][0] = 0;
  matrix2.matrix[0][1] = 10;
  matrix2.matrix[0][2] = -20;
  matrix2.matrix[1][0] = 4;
  matrix2.matrix[1][1] = -14;
  matrix2.matrix[1][2] = 8;
  matrix2.matrix[2][0] = -8;
  matrix2.matrix[2][1] = -2;
  matrix2.matrix[2][2] = 4;
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 1, cols = 1;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 1, cols = 1;
  s21_create_matrix(rows, cols, &matrix1);
  s21_remove_matrix(&matrix1);
  return_value = s21_calc_complements(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, 1);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(complements_1) {
  int result = s21_calc_complements(NULL, NULL);
  ck_assert_int_eq(result, ERROR_UNCORRECT_MATRIX);
}
END_TEST

// START_TEST(complements_2)
// {
//     matrix_t A;
//     matrix_t B;
//     s21_create_matrix(0, 10, &A);
//     A.rows = 0;
//     int res = s21_calc_complements(&A, &B);
//     ck_assert_int_eq(res, ERROR_UNCORRECT_MATRIX);
//     s21_remove_matrix(&A);
// }
// END_TEST

START_TEST(complements_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_4) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &C);
  A.matrix[0][0] = 984.1238;
  C.matrix[0][0] = 984.1238;
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(complements_5) {
  matrix_t A;
  matrix_t B;
  matrix_t C;
  double const A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double const result_nums[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }
  count = 0;
  for (int i = 0; i < C.rows; i++) {
    for (int j = 0; j < C.columns; j++) {
      C.matrix[i][j] = result_nums[count];
      count++;
    }
  }
  int res = s21_calc_complements(&A, &B);
  // for (int i = 0; i < B.rows; i++) {
  //   for (int j = 0; j < B.columns; j++) {
  //     printf("%lf\n",  B.matrix[i][j]);
  //   }
  // }
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, ERROR_UNCORRECT_MATRIX);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 && code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&result);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(complements_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_7) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 && code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    s21_calc_complements(&m, &result);

    s21_eq_matrix(&result, &expected);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(complements_8) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(complements_9) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 7;
  C.matrix[0][0] = 7;
  C.matrix[0][1] = -4;
  C.matrix[1][0] = -1;
  C.matrix[1][1] = 5;

  int ret = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, ret);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(SUCCESS, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(complements_10) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 4;

  C.matrix[0][0] = 0;
  C.matrix[0][1] = -10;
  C.matrix[0][2] = 5;
  C.matrix[1][0] = -2;
  C.matrix[1][1] = 21;
  C.matrix[1][2] = -9;
  C.matrix[2][0] = 1;
  C.matrix[2][1] = -8;
  C.matrix[2][2] = 2;
  int ret = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, ret);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(SUCCESS, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(complements_11) {
  int rows = rand() % 10 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, rows, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      double t = rand();
      A.matrix[i][j] = t / 7;
    }
  }
  int ret = s21_calc_complements(&A, &R);
  ck_assert_int_eq(0, ret);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(complements_12) {
  int rows = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, rows + 1, &A);
  int ret = s21_calc_complements(&A, &R);
  ck_assert_int_eq(2, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_13) {
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, columns, &A);
  int ret = s21_calc_complements(&A, &R);
  ck_assert_int_eq(1, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_14) {
  double m[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
  double r[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_calc_complements(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_org);
  s21_remove_matrix(&res_my);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  // matrix 1
  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 5;
  matrix1.matrix[0][2] = 7;
  matrix1.matrix[1][0] = 6;
  matrix1.matrix[1][1] = 3;
  matrix1.matrix[1][2] = 4;
  matrix1.matrix[2][0] = 5;
  matrix1.matrix[2][1] = -2;
  matrix1.matrix[2][2] = -3;
  // matrix 2
  matrix2.matrix[0][0] = 1;
  matrix2.matrix[0][1] = -1;
  matrix2.matrix[0][2] = 1;
  matrix2.matrix[1][0] = -38;
  matrix2.matrix[1][1] = 41;
  matrix2.matrix[1][2] = -34;
  matrix2.matrix[2][0] = 27;
  matrix2.matrix[2][1] = -29;
  matrix2.matrix[2][2] = 24;
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, OK);
  return_value = s21_eq_matrix(&matrix2, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  s21_remove_matrix(&matrix1);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_UNCORRECT_MATRIX);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 2, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 2;
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &matrix2);
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t matrix1;
  matrix_t matrix_result;
  int return_value, rows = 3, cols = 3;
  s21_create_matrix(rows, cols, &matrix1);
  // matrix 1
  matrix1.matrix[0][0] = 1;
  matrix1.matrix[0][1] = 2;
  matrix1.matrix[0][2] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 5;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 7;
  matrix1.matrix[2][1] = 8;
  matrix1.matrix[2][2] = 9;
  return_value = s21_inverse_matrix(&matrix1, &matrix_result);
  ck_assert_int_eq(return_value, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&matrix1);
  // s21_remove_matrix(&matrix_result);
}
END_TEST

START_TEST(inverse_1) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, OK);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_3) {
  int res = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(res, ERROR_UNCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(10, 9, &A);
  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_6) {
  matrix_t A;
  matrix_t B;
  double const A_nums[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                             14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

  s21_create_matrix(5, 5, &A);
  int count = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A_nums[count];
      count++;
    }
  }

  int res = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(res, ERROR_MATHEMATICS_OPERATIONS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_1_inverse) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one_inverse) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, OK);
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_zero_det_inverse) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect_inverse) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, ERROR_UNCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_inverse) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_not_sqare_inverse) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, ERROR_MATHEMATICS_OPERATIONS);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_normal_inverse) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (codec1 && codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_inverse) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_7) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 21;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(inverse_8) {
  matrix_t A;
  matrix_t result;
  matrix_t eq_matrix;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  eq_matrix.matrix[0][0] = 1, eq_matrix.matrix[0][1] = -1,
  eq_matrix.matrix[0][2] = 1;
  eq_matrix.matrix[1][0] = -38, eq_matrix.matrix[1][1] = 41,
  eq_matrix.matrix[1][2] = -34;
  eq_matrix.matrix[2][0] = 27, eq_matrix.matrix[2][1] = -29,
  eq_matrix.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(inverse_9) {
  int rows = 1;
  int columns = 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 5;
  int ret = s21_inverse_matrix(&A, &R);
  double inv = 0.2;
  ck_assert_int_eq(0, ret);
  ck_assert_double_eq(inv, R.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_10) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 1;

  C.matrix[0][0] = -0.2;
  C.matrix[0][1] = 0.4;
  C.matrix[1][0] = 0.8;
  C.matrix[1][1] = -0.6;
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(0, ret);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(SUCCESS, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_11) {
  int rows = 3;
  int columns = 3;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 4;
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0.4;
  C.matrix[0][2] = -0.2;
  C.matrix[1][0] = 2;
  C.matrix[1][1] = -4.2;
  C.matrix[1][2] = 1.6;
  C.matrix[2][0] = -1;
  C.matrix[2][1] = 1.8;
  C.matrix[2][2] = -0.4;
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(0, ret);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(SUCCESS, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_12) {
  int rows = 2;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, rows, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      A.matrix[i][j] = 7;
    }
  }
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(2, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_13) {
  int rows = 2;
  int columns = 2;
  matrix_t A = {0};
  matrix_t R = {0};
  matrix_t C = {0};
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 1;
  C.matrix[0][0] = 0;
  C.matrix[0][1] = 0;
  C.matrix[1][0] = 0.8;
  C.matrix[1][1] = -0.6;
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(0, ret);
  int res = s21_eq_matrix(&C, &R);
  ck_assert_int_eq(FAILURE, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_14) {
  int rows = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, rows + 1, &A);
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(2, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_15) {
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t R = {0};
  s21_create_matrix(rows, columns, &A);
  int ret = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(1, ret);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_16) {
  double m[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double r[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  matrix_t matrix, res_org, res_my;
  s21_create_matrix(3, 3, &matrix);
  s21_create_matrix(3, 3, &res_org);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = m[i][j];
    }
  }
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      res_org.matrix[i][j] = r[i][j];
    }
  }
  int ret = s21_inverse_matrix(&matrix, &res_my);
  ck_assert_int_eq(ret, 0);
  ret = s21_eq_matrix(&res_org, &res_my);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&res_my);
  s21_remove_matrix(&res_org);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Create matrix tests");
  TCase *tc1 = tcase_create("Create matrix tests");

  Suite *s2 = suite_create("Remove matrix tests");
  TCase *tc2 = tcase_create("Remove matrix tests");

  Suite *s3 = suite_create("Matrix comparison tests");
  TCase *tc3 = tcase_create("Matrix comparison tests");

  Suite *s4 = suite_create("Sum matrix tests");
  TCase *tc4 = tcase_create("Sum matrix tests");

  Suite *s5 = suite_create("Sub matrix tests");
  TCase *tc5 = tcase_create("Sub matrix tests");

  Suite *s6 = suite_create("Mult matrix to number tests");
  TCase *tc6 = tcase_create("Mult matrix to number tests");

  Suite *s7 = suite_create("Mult matrix tests");
  TCase *tc7 = tcase_create("Mult matrix tests");

  Suite *s8 = suite_create("Transpose matrix tests");
  TCase *tc8 = tcase_create("Transpose matrix tests");

  Suite *s10 = suite_create("Matrix determinant tests");
  TCase *tc10 = tcase_create("Matrix determinant tests");

  Suite *s9 = suite_create("Matrix of algebraic complements  tests");
  TCase *tc9 = tcase_create("Matrix of algebraic complements  tests");

  Suite *s11 = suite_create("Matrix inverse tests");
  TCase *tc11 = tcase_create("Matrix inverse tests");

  int nf = 0;

  suite_add_tcase(s1, tc1);
  tcase_add_test(tc1, create_1);
  tcase_add_test(tc1, create_2);
  tcase_add_test(tc1, create_3);
  tcase_add_test(tc1, create_4);
  tcase_add_test(tc1, create_null_result);

  suite_add_tcase(s2, tc2);
  tcase_add_test(tc2, remove_1);
  tcase_add_test(tc2, remove_2);

  suite_add_tcase(s3, tc3);
  tcase_add_test(tc3, eq_matrix_1);
  tcase_add_test(tc3, eq_matrix_2);
  tcase_add_test(tc3, eq_matrix_3);
  tcase_add_test(tc3, eq_matrix_4);
  tcase_add_test(tc3, eq_matrix_5);
  tcase_add_test(tc3, eq_casual_matrix_6);
  tcase_add_test(tc3, eq_casual_matrix_7);
  tcase_add_test(tc3, eq_casual_matrix_8);
  tcase_add_test(tc3, eq_casual_matrix_9);
  tcase_add_test(tc3, eq_casual_matrix_10);
  tcase_add_test(tc3, eq_casual_matrix_11);
  tcase_add_test(tc3, zero_matrix);

  suite_add_tcase(s4, tc4);
  tcase_add_test(tc4, sum_1);
  tcase_add_test(tc4, sum_2);
  tcase_add_test(tc4, sum_3);
  tcase_add_test(tc4, sum_4);
  tcase_add_test(tc4, sum_5);
  tcase_add_test(tc4, sum_6);
  tcase_add_test(tc4, sum_7);
  tcase_add_test(tc4, sum_8);

  suite_add_tcase(s5, tc5);
  tcase_add_test(tc5, sub_matrix_1);
  tcase_add_test(tc5, sub_matrix_2);
  tcase_add_test(tc5, sub_matrix_3);
  tcase_add_test(tc5, sub_matrix_4);
  tcase_add_test(tc5, sub_matrix_5);
  tcase_add_test(tc5, sub_matrix_6);
  tcase_add_test(tc5, sub_1);
  tcase_add_test(tc5, sub_2);
  tcase_add_test(tc5, sub_3);
  tcase_add_test(tc5, sub_matrix);
  tcase_add_test(tc5, sub_matrix1);
  tcase_add_test(tc5, sub_matrix2);
  tcase_add_test(tc5, sub_matrix_last_1);
  tcase_add_test(tc5, sub_matrix_last_2);
  tcase_add_test(tc5, sub_matrix_last_3);

  suite_add_tcase(s6, tc6);
  tcase_add_test(tc6, mult_num_1);
  tcase_add_test(tc6, mult_num_2);
  tcase_add_test(tc6, mult_num_3);
  tcase_add_test(tc6, mult_num_4);
  tcase_add_test(tc6, mult_number_1);
  tcase_add_test(tc6, mult_number_2);
  tcase_add_test(tc6, mult_number_3);
  tcase_add_test(tc6, mult_number_4);
  tcase_add_test(tc6, mult_number_5);
  tcase_add_test(tc6, mult_number_6);
  tcase_add_test(tc6, mult_number_7);

  suite_add_tcase(s7, tc7);
  tcase_add_test(tc7, mult_matrix_1);
  tcase_add_test(tc7, mult_matrix_2);
  tcase_add_test(tc7, mult_matrix_3);
  tcase_add_test(tc7, mult_matrix_4);
  tcase_add_test(tc7, mult_matrix1);
  tcase_add_test(tc7, mult_matrix2);
  tcase_add_test(tc7, mult_matrix3);
  tcase_add_test(tc7, mult_matrix4);
  tcase_add_test(tc7, mult_matrix5);
  tcase_add_test(tc7, mult_matrix6);
  tcase_add_test(tc7, mult_matrix7);
  tcase_add_test(tc7, mult_matrix8);

  suite_add_tcase(s8, tc8);
  tcase_add_test(tc8, transpose_1);
  tcase_add_test(tc8, transpose_2);
  tcase_add_test(tc8, transpose_matrix);
  tcase_add_test(tc8, transpose_matrix2);
  tcase_add_test(tc8, transpose_matrix3);
  tcase_add_test(tc8, transpose_matrix4);
  tcase_add_test(tc8, transpose_matrix5);

  suite_add_tcase(s10, tc10);
  tcase_add_test(tc10, determinant_1);
  tcase_add_test(tc10, determinant_2);
  tcase_add_test(tc10, determinant_3);
  tcase_add_test(tc10, determinant_4);
  tcase_add_test(tc10, determinant_5);
  tcase_add_test(tc10, deter_1);
  tcase_add_test(tc10, deter_3);
  tcase_add_test(tc10, deter_4);
  tcase_add_test(tc10, deter_5);
  tcase_add_test(tc10, deter_6);
  tcase_add_test(tc10, deter_7);
  tcase_add_test(tc10, deter_8);
  tcase_add_test(tc10, determinant1);
  tcase_add_test(tc10, determinant2);
  tcase_add_test(tc10, determinant3);
  tcase_add_test(tc10, determinant4);
  tcase_add_test(tc10, determinant5);
  tcase_add_test(tc10, determinant6);
  tcase_add_test(tc10, determinant7);
  tcase_add_test(tc10, determinant8);
  tcase_add_test(tc10, determinant9);
  tcase_add_test(tc10, determinant10);
  tcase_add_test(tc10, determinant11);
  tcase_add_test(tc10, determinant12);
  tcase_add_test(tc10, determinant13);
  tcase_add_test(tc10, determinant14);
  tcase_add_test(tc10, determinant15);
  tcase_add_test(tc10, determinant16);
  tcase_add_test(tc10, determinant17);

  suite_add_tcase(s9, tc9);
  tcase_add_test(tc9, calc_complements_1);
  tcase_add_test(tc9, calc_complements_2);
  tcase_add_test(tc9, calc_complements_3);
  tcase_add_test(tc9, calc_complements_4);
  tcase_add_test(tc9, calc_complements_5);
  tcase_add_test(tc9, complements_1);
  // tcase_add_test(tc9, complements_2);
  tcase_add_test(tc9, complements_3);
  tcase_add_test(tc9, complements_4);
  tcase_add_test(tc9, complements_5);
  tcase_add_test(tc9, test_normal);
  tcase_add_test(tc9, test_not_sqare);
  tcase_add_test(tc9, test_incorrect);
  tcase_add_test(tc9, test_one_by_one);
  tcase_add_test(tc9, complements_6);
  tcase_add_test(tc9, complements_7);
  tcase_add_test(tc9, complements_8);
  tcase_add_test(tc9, complements_9);
  tcase_add_test(tc9, complements_10);
  tcase_add_test(tc9, complements_11);
  tcase_add_test(tc9, complements_12);
  tcase_add_test(tc9, complements_13);
  tcase_add_test(tc9, complements_14);

  suite_add_tcase(s11, tc11);
  tcase_add_test(tc11, inverse_matrix_1);
  tcase_add_test(tc11, inverse_matrix_2);
  tcase_add_test(tc11, inverse_matrix_3);
  tcase_add_test(tc11, inverse_matrix_4);
  tcase_add_test(tc11, inverse_matrix_5);
  tcase_add_test(tc11, inverse_matrix_6);
  tcase_add_test(tc11, inverse_1);
  tcase_add_test(tc11, inverse_2);
  tcase_add_test(tc11, inverse_3);
  tcase_add_test(tc11, inverse_5);
  tcase_add_test(tc11, inverse_6);
  tcase_add_test(tc11, test_normal_inverse);
  tcase_add_test(tc11, test_not_sqare_inverse);
  tcase_add_test(tc11, test_zero_det_inverse);
  tcase_add_test(tc11, test_incorrect_inverse);
  tcase_add_test(tc11, test_one_by_one_inverse);
  tcase_add_test(tc11, inverse_inverse);
  tcase_add_test(tc11, s21_inverse_1_inverse);
  tcase_add_test(tc11, determinant_inverse);
  tcase_add_test(tc11, inverse_7);
  tcase_add_test(tc11, inverse_8);
  tcase_add_test(tc11, inverse_9);
  tcase_add_test(tc11, inverse_10);
  tcase_add_test(tc11, inverse_11);
  tcase_add_test(tc11, inverse_12);
  tcase_add_test(tc11, inverse_13);
  tcase_add_test(tc11, inverse_14);
  tcase_add_test(tc11, inverse_15);
  tcase_add_test(tc11, inverse_16);

  SRunner *sr = srunner_create(s1);
  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);
  srunner_add_suite(sr, s7);
  srunner_add_suite(sr, s8);
  srunner_add_suite(sr, s10);
  srunner_add_suite(sr, s9);
  srunner_add_suite(sr, s11);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

/* скомунижжено отсюда https://learnc.info/c/random.html */
double get_rand(double min, double max) {
  double val = (double)rand() / RAND_MAX;
  return min + val * (max - min);
}
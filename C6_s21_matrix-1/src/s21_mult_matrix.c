#include "s21_matrix.h"

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_matrix_return flag = OK;
  // printf("A->rows = %d, A->columns = %d, B->rows = %d, B->columns = %d,
  // result->rows = %d, result->columns = %d\n", A->rows, A->columns, B->rows,
  // B->columns, result->rows, result->columns);

  if (A != NULL && B != NULL && result != NULL && A->columns >= 1 &&
      A->rows >= 1 && B->columns >= 1 && B->rows >= 1 &&
      A->columns == B->rows) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int r = 0; r < B->rows; r++) {
          result->matrix[i][j] += (A->matrix[i][r] * B->matrix[r][j]);
        }
      }
    }
  } else if (A->columns != B->rows && A != NULL && B != NULL &&
             result != NULL && A->matrix != NULL && B->matrix != NULL) {
    flag = ERROR_MATHEMATICS_OPERATIONS;
  } else {
    flag = ERROR_UNCORRECT_MATRIX;
  }

  return flag;
}

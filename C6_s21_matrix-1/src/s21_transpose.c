#include "s21_matrix.h"

// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result) {
  s21_matrix_return flag = OK;  // OK
  if (A != NULL) {
    if (A->rows >= 1 && A->columns >= 1 && result != NULL) {
      s21_create_matrix(A->columns, A->rows, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else
      flag = ERROR_UNCORRECT_MATRIX;
  } else
    flag = ERROR_UNCORRECT_MATRIX;

  return flag;
}
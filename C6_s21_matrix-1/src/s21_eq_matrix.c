#include "s21_matrix.h"

// сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  s21_matrix_return_eq flag = SUCCESS;
  if (A != NULL && B != NULL) {
    if (A->rows == B->rows && A->columns == B->columns && A->rows >= 1 &&
        A->columns >= 1) {
      // сравниваем поэлементно
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (round(A->matrix[i][j] * pow(10, 7)) !=
              round(B->matrix[i][j] * pow(10, 7))) {
            flag = FAILURE;
            break;
          }
        }
      }
    } else
      flag = FAILURE;
  } else
    flag = FAILURE;

  return flag;
}
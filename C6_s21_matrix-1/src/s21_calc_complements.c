#include "s21_matrix.h"

// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  s21_matrix_return flag = OK;  // OK
  if (A != NULL) {
    if (A->rows >= 1 && A->columns >= 1 && result != NULL) {
      s21_create_matrix(A->rows, A->columns, result);
      // start
      if (A->rows == A->columns && A->rows >= 2) {
        // матрица корректна и больше 2
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t minor = s21_cut_matrix(*A, i, j);

            double det_minor = pow(-1, i + 1 + j + 1) * s21_det(&minor);
            result->matrix[i][j] = det_minor;
            s21_remove_matrix(&minor);  // Освобождение памяти
          }
        }
      } else if (A->rows == A->columns && A->rows == 1)
        result->matrix[0][0] = A->matrix[0][0];
      else {
        s21_remove_matrix(result);  // Освобождение памяти
        flag = ERROR_MATHEMATICS_OPERATIONS;
      }
      // finish
    } else {
      flag = ERROR_UNCORRECT_MATRIX;
    }
  } else {
    flag = ERROR_UNCORRECT_MATRIX;
  }

  return flag;
}
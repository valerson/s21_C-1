#include "s21_matrix.h"

// определитель корректной (уже проверили на правильность) матрицы
double s21_det(matrix_t *A) {
  // выход из рекурсии 2
  if (A->columns == A->rows && A->columns == 2) {
    return A->matrix[0][0] * A->matrix[1][1] -
           A->matrix[1][0] * A->matrix[0][1];
  }
  // выход из рекурсии 1
  if (A->columns == A->rows && A->columns == 1) {
    return A->matrix[0][0];
  }
  double det = 0;
  int i = 0;  // по первой строке ведем расчеты
  for (int j = 0; j < A->columns; j++) {
    matrix_t new_matrix = s21_cut_matrix(*A, i, j);
    det += pow(-1, i + 1 + j + 1) * A->matrix[i][j] * s21_det(&new_matrix);
    s21_remove_matrix(&new_matrix);  // Освобождение памяти
  }
  return det;
}

// уменьшаем матрицу (минус столбец и минус строка)
matrix_t s21_cut_matrix(matrix_t A, int i, int j) {
  matrix_t result_matrix;
  s21_create_matrix(A.rows - 1, A.columns - 1, &result_matrix);
  for (int i_old_matrix = 0, new_i = 0; i_old_matrix < A.rows; i_old_matrix++) {
    if (i_old_matrix != i) {
      for (int j_old_matrix = 0, new_j = 0; j_old_matrix < A.columns;
           j_old_matrix++) {
        if (j_old_matrix != j) {
          // printf("vot - %lf\n", A.matrix[new_i][new_j]);
          result_matrix.matrix[new_i][new_j] =
              A.matrix[i_old_matrix][j_old_matrix];
          new_j++;
        }
      }
      new_i++;
    }
  }
  return result_matrix;
}

// определитель матрицы в формате задания
int s21_determinant(matrix_t *A, double *result) {
  s21_matrix_return flag = OK;  // OK
  if (A != NULL) {
    if (A->rows >= 1 && A->columns >= 1 && result != NULL) {
      if (A->rows == A->columns && A->rows >= 2)
        // матрица корректна и больше 1
        *result = s21_det(A);
      else if (A->rows == A->columns && A->rows == 1)
        *result = A->matrix[0][0];
      else
        flag = ERROR_MATHEMATICS_OPERATIONS;
    } else
      flag = ERROR_UNCORRECT_MATRIX;
  } else
    flag = ERROR_UNCORRECT_MATRIX;

  return flag;
}
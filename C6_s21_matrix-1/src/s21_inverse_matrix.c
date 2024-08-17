#include "s21_matrix.h"

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  s21_matrix_return flag = OK;  // OK
  if (A != NULL) {
    if (A->rows >= 1 && A->columns >= 1 && result != NULL) {
      // матрица коректна
      // делал вот по такой логике -
      // https://www.youtube.com/watch?v=b8QpUkByA5A
      double determinant = 0;
      int det = s21_determinant(A, &determinant);
      if (determinant != 0 && det == 0 && A->rows >= 2) {
        // 1. получем матрица алгебгаических дополнений
        matrix_t matrix_temp_0;
        s21_calc_complements(A, &matrix_temp_0);

        // 2. транспонируем матрицу алгебраических дополниений
        matrix_t matrix_temp_1;
        s21_transpose(&matrix_temp_0, &matrix_temp_1);

        // 3. умножаем матрица на 1/определитель изначальной матрицы
        s21_mult_number(&matrix_temp_1, 1 / determinant, result);

        s21_remove_matrix(&matrix_temp_0);
        s21_remove_matrix(&matrix_temp_1);
      } else if (determinant != 0 && det == 0 && A->rows == 1) {
        s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else
        flag = ERROR_MATHEMATICS_OPERATIONS;
    } else
      flag = ERROR_UNCORRECT_MATRIX;
  } else
    flag = ERROR_UNCORRECT_MATRIX;

  return flag;
}

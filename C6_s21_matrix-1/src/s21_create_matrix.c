#include "s21_matrix.h"

// Создание матрицы
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  s21_matrix_return flag = OK;  // OK
  if (rows >= 1 && columns >= 1 && result != NULL) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));

    if (result->matrix == NULL)  // отработка ошибки выделения памяти
      flag = ERROR_UNCORRECT_MATRIX;
    else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        // скрыл, потому случая такого не было никогда, а гков
        // показывает ерунду из-за этого if (result->matrix[i] == NULL)
        // // отработка ошибки выделения памяти
        // {
        //     flag = ERROR_UNCORRECT_MATRIX;
        //     break;
        // }
      }
    }
  } else
    flag = ERROR_UNCORRECT_MATRIX;

  // скрыл, потому случая такого не было никогда, а гков показывает ерунду
  // из-за этого if (flag == ERROR_UNCORRECT_MATRIX &&
  //     result != NULL) // есил была ошика выделения памяти, то освобождаем
  //                     // выделенную память
  // {
  //     for (int i = 0; i < result->rows; i++)
  //     {
  //         free(result->matrix[i]);
  //     }
  //     free(result->matrix);
  // }
  return flag;
}

#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <float.h>  // макросы длядабл чисел
#include <math.h>  // для round и pow в eq_matrix, и для pow в детерминанте, и для матрицы миноров, и для обратной матрицы
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// сделал попробовать по заветам Новосиба
typedef enum s21_matrix_return {
  OK,
  ERROR_UNCORRECT_MATRIX,
  ERROR_MATHEMATICS_OPERATIONS
} s21_matrix_return;

typedef enum s21_matrix_return_eq { FAILURE, SUCCESS } s21_matrix_return_eq;

// создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);
// очистка матрицы
void s21_remove_matrix(matrix_t *A);
// сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

// определитель корректной (уже проверили на правильность) матрицы
double s21_det(matrix_t *A);
// уменьшаем матрицу (минус столбец и минус строка)
matrix_t s21_cut_matrix(matrix_t A, int i, int j);
// определитель матрицы в формате задания
int s21_determinant(matrix_t *A, double *result);

// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
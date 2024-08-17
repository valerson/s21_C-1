#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>  // для работы с переменным количенством аргументов
#include <stdint.h>  // библиотка для платформонезависимых размеров интов и лонгов
#include <stdlib.h>  // для фукнции size_t wcstombs
#include <wchar.h>  // библиотека для символов и строк под типы wint_t wchar_t

typedef struct {
  int minus;

  int plus;
  int space;
  int zero;
  int grill;  // решетка

  int precision;
  int is_precision_set;  // нужно для спецификаторов (можно уйти проверяя если
                         // presicion не ноль)

  int width;

  char length;

  char specificator;
} flags;

// void flag_print(flags *fl);  // для отладки

// парсинг формата
const char *parsing_all(const char *format, flags *fl, va_list *args);
const char *get_flags(const char *format, flags *fl);
const char *get_widht(const char *format, flags *fl, va_list *args);
const char *get_precision(const char *format, flags *fl, va_list *args);
const char *get_lenght(const char *format, flags *fl);

// сопутствующие функции для декомпозиции

void switch_specificator_sprintf(flags fl, char *temp, va_list *args,
                                 int *null_factor);
int64_t text_to_number(char *text);
void flag_to_null(flags *fl);
void precision_apply(flags fl, char *temp);
void flags_apply(flags fl, char *temp);
void double_add_text(double number, char *text, flags fl);
int double_up_half(char *text, long long int *temp, long long *i,
                   long long int *znak, flags fl, long long int *n,
                   double *number);
void flags_apply_pointer(flags fl, char *temp);
void u_number_add_text(long long int number, char *text);
void rounding_up(int m, char *temp);
void decomposicion_g_reduction_part1(flags fl, long double result, char *temp,
                                     int znak, int pow, int sign);
void decomposicion_g_reduction_part2(flags fl, long double result_G, char *temp,
                                     int pow, int sign);
void double_add_text_g_reduction(double number, char *text, flags fl, int *pow);
int double_up_half_g_reduction(char *text, long long int *temp, long long *i,
                               long long int *znak, flags fl, long long int *n,
                               double *number, int *pow);

// для декомпозии дублируется в science notation и g reduction
void e_notation(flags fl, char *temp, char znak, int pow);
void find_pow_and_sign(char *znak, int *pow, long double *result);
void remove_zero_for_g_reduction(char *temp);  //, flags fl);
void format_char(char c, char *temp, flags fl);
void format_char_long(wchar_t c, char *temp, flags fl);
long long int hex_half_minus_to_absolut(long long int result);

// разбор спецификаторов
void s21_int(flags fl, char *temp, va_list *args);
void s21_char(flags fl, char *temp, va_list *args, int *null_factor);
void s21_float(flags fl, char *temp, va_list *args);
void s21_string(flags fl, char *temp, va_list *args);
void s21_unsigned(flags fl, char *temp, va_list *args);
void s21_science_notation(flags fl, char *temp, va_list *args);
void s21_hex(flags fl, char *temp, va_list *args);
void s21_hex_half(flags fl, char *temp, va_list *args);
void s21_pointer(flags fl, char *temp, va_list *args);
// void s21_pointer(char *temp, va_list *args);
void s21_g_reduction(flags fl, char *temp, va_list *args);

#endif  // S21_SPRINTF_H
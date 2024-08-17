#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>  // для работы с переменным количенством аргументов
#include <stdint.h>  // библиотка для платформонезависимых размеров интов и лонгов
#include <wchar.h>  // библиотека для символов и строк под типы wint_t wchar_t

// Определение INFINITY
#define INFINITY (1.0 / 0.0)

// Определение NAN
#define NAN (0.0 / 0.0)

typedef struct {
  int hz_star;        // звездочка
  int width;          // ширина значение
  char len;           // длина тип h-l-L
  char len2;          // длина тип h-l-L
  char specificator;  // спецификатор тип
  int minus;          // добавил для 8 и 16 систем
} sscanf_flags;

int s21_sscanf(const char *str, const char *format, ...);

char *parsing_p_format(char *p_format, sscanf_flags *fl);

// всякие второстипенные функции для декомпозиции и повторяющейся мелочевки
// void print_fl(sscanf_flags *fl);
void sscanf_flags_to_null(sscanf_flags *fl);
char *parse_sign(int *sign, int *plus, char *p_str, sscanf_flags *fl);
void decomposicion_1(const char *str, char *p_format, int *output_result);
int check_specificator(sscanf_flags *fl, int *output_result);
char *decomposicion_2(char *p_format, int *output_result);

// основные функции для ссканф и их декомпозиции
void switch_specificator(sscanf_flags *fl, va_list *args, char **p_str,
                         int **output_result, char *start_str);
char *s21_sscanf_char(sscanf_flags *fl, va_list *args, char *p_str,
                      int *output_result);
char *s21_sscanf_int(sscanf_flags *fl, va_list *args, char *p_str,
                     int *output_result);
void apply_len_for_int(sscanf_flags *fl, int i, int minus, int **output_result,
                       char temp[], va_list *args);
char *s21_sscanf_i(sscanf_flags *fl, va_list *args, char *p_str,
                   int *output_result);
char *s21_sscanf_hex_half(sscanf_flags *fl, va_list *args, char *p_str,
                          int *output_result, int sign);
void apply_len_for_hex_half(sscanf_flags *fl, int **output_result,
                            long long int res_8, va_list *args, char temp[]);
char *s21_sscanf_hex(sscanf_flags *fl, va_list *args, char *p_str,
                     int *output_result, int sign);
void apply_len_for_hex(sscanf_flags *fl, int **output_result,
                       long long int res_16, va_list *args, char temp[]);
char *s21_sscanf_string(sscanf_flags *fl, va_list *args, char *p_str,
                        int *output_result);
char *s21_sscanf_float(sscanf_flags *fl, va_list *args, char *p_str,
                       int *output_result);
void e_pow_apply(char temp_float_down[], char temp_float_up[],
                 long double *result_float, int e_pow, sscanf_flags *fl,
                 int flag_nan_inf, long double result_number);
char *nan_inf_and_e_notacion_apply(char *p_str, float *result_number,
                                   int *e_pow, int *k, int *flag_nan_inf,
                                   char e_pow_bufer[]);
void apply_len_for_float(sscanf_flags *fl, int **output_result,
                         long double result_float, va_list *args,
                         char temp_float_up[], int flag_nan_inf);

#endif
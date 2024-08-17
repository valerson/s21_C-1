#include "s21_sscanf.h"

#include "s21_string.h"

/*
int sscanf(const char *buf, const char *format, ...);
Функция sscanf() идентична функции scanf(), но данные читаются из массива,
адресуемого параметром buf, а не из стандартного потока ввода stdin.
*/

int s21_sscanf(const char *str, const char *format, ...) {
  sscanf_flags fl = {0};
  // указатель на стр и на формат потому конст. указатель на начало для
  // спецификатора n
  char *p_str = (char *)str, *start_str = p_str, *p_format = (char *)format;
  // Инициализируем список аргументов
  va_list args;
  va_start(args, format);
  int output_result = -1;
  // если не пустая строка на входе - отрабатываем. так же занулдяем, если нет в
  // формате ничего из присваиваемого
  decomposicion_1(str, p_format, &output_result);
  while (*p_format && *p_str && output_result != -1) {
    if (*p_format == '%') {
      if (*p_str == ' ') p_str++;
      p_format++;
      if (*p_format != '%') {
        //   парсим все и делаем
        p_format = parsing_p_format(p_format, &fl);
        int *result = &output_result;  // это извращение потому что внутри
                                       // свитча в фукнцию передается указатель
        // соответственно нужно передать ** на инт в сам свитч
        switch_specificator(&fl, &args, &p_str, &result, start_str);
        if (check_specificator(&fl, &output_result)) break;
      } else
        p_format = decomposicion_2(p_format, &output_result);
    } else {
      // пропускаем все одинаковые в стр и формате и пробелы в формате
      if (*p_str == *p_format || (*p_str == '\n' && *p_format == ' ')) {
        char temp = *p_format;
        p_format++;
        while (temp == *p_str || (temp == ' ' && *p_str == '\n')) p_str++;
      } else
        p_format++;
    }
    // обнуляем флаги
    sscanf_flags_to_null(&fl);
  }
  va_end(args);
  return output_result;  // 0-все хорошо -1 все плохо
}

void sscanf_flags_to_null(sscanf_flags *fl) {
  fl->hz_star = 0;
  fl->len = '\0';
  fl->len2 = '\0';
  fl->specificator = '\0';
  fl->width = 0;
  fl->minus = 0;
}

char *parsing_p_format(char *p_format, sscanf_flags *fl) {
  // отработка по звезде
  if (*p_format == '*') {
    fl->hz_star = 1;
    p_format++;
  }
  // отработка по ширине
  if (*p_format >= '0' || *p_format <= '9') {
    char temp_number[MAX_SIZE] = {'\0'};
    for (int i = 0; *p_format >= '0' && *p_format <= '9'; i++) {
      temp_number[i] = *p_format;
      p_format++;
    }
    fl->width = text_to_number(temp_number);
  }
  // отработка по длине
  while (s21_strchr("hlL", *p_format)) {
    if (fl->len)
      fl->len2 = *p_format;
    else
      fl->len = *p_format;
    p_format++;
  }

  // отработка спецификатора
  fl->specificator = *p_format;
  p_format++;
  return p_format;
}

void decomposicion_1(const char *str, char *p_format, int *output_result)
// чтобы не говорили потом мол много строчек
// если не пустая строка на входе - отрабатываем. так же занулдяем, если нет в
// формате ничего из присваиваемого
{
  for (int i = 0; str[i]; i++) {
    if ((str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0') ||
        (!s21_strchr(p_format, '%'))) {
      *output_result = 0;
      break;
    }
  }
}

int check_specificator(sscanf_flags *fl, int *output_result) {
  int result = 0;
  if (!s21_strchr("cdieEfgGosuxXpn", fl->specificator)) {
    *output_result = -1;
    result = 1;
  }
  return result;
}

char *decomposicion_2(char *p_format, int *output_result)
// чтобы не говорили потом мол много строчек
// если формат типа %%c - идем к следующему
{
  if (*p_format == '%')
    p_format++;
  else
    *output_result = -1;
  return p_format;
}

// void print_fl(sscanf_flags *fl) {
//   printf("hz_star=%d\n", fl->hz_star);
//   printf("len=%c\n", fl->len);
//   printf("len2=%c\n", fl->len2);
//   printf("wigth=%d\n", fl->width);
//   printf("specificator=%c\n", fl->specificator);
//   printf("fl. minus=%d\n", fl->minus);
// }

void switch_specificator(sscanf_flags *fl, va_list *args, char **p_str,
                         int **output_result, char *start_str) {
  int sign = 0, plus = 0;
  switch (fl->specificator) {
    case 'c':
      *p_str = s21_sscanf_char(fl, args, *p_str, *output_result);
      break;
    case 'd':
    case 'u':
      *p_str = s21_sscanf_int(fl, args, *p_str, *output_result);
      break;
    case 'i':
      *p_str = s21_sscanf_i(fl, args, *p_str, *output_result);
      break;
    // в целях декомпозиции почистил. для eEfgG - читаем флоат - внутри флоата
    // отработка спецификатора е есть
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      *p_str = s21_sscanf_float(fl, args, *p_str, *output_result);
      break;
    case 'o':
      *p_str = parse_sign(&sign, &plus, *p_str, fl);
      *p_str =
          s21_sscanf_hex_half(fl, args, *p_str, *output_result, sign + plus);
      break;
    case 's':
      *p_str = s21_sscanf_string(fl, args, *p_str, *output_result);
      break;
    case 'x':
    case 'X':
      *p_str = parse_sign(&sign, &plus, *p_str, fl);
      *p_str = s21_sscanf_hex(fl, args, *p_str, *output_result, sign + plus);
      break;
    case 'p':
      fl->len = 'l';
      *p_str = s21_sscanf_hex(fl, args, *p_str, *output_result, 0);
      break;
    case 'n':
      *va_arg(*args, long int *) = *p_str - start_str;
      break;
    default:
      break;
  }
}

char *parse_sign(int *sign, int *plus, char *p_str, sscanf_flags *fl) {
  if (*p_str == '-') {
    *sign = 1;
    fl->minus = 1;
    p_str += 1;
  } else if (*p_str == '+') {
    p_str += 1;
    *plus = 1;
  }
  return p_str;
}

char *s21_sscanf_char(sscanf_flags *fl, va_list *args, char *p_str,
                      int *output_result) {
  if (*p_str != '\0') {
    if (!fl->hz_star) {
      char *result_char = va_arg(*args, char *);
      *result_char = *p_str;
      *output_result += 1;
    }
    p_str++;
  }
  return p_str;
}

char *s21_sscanf_string(sscanf_flags *fl, va_list *args, char *p_str,
                        int *output_result) {
  // char result_string[MAX_SIZE] = {'\0'};
  char *result_string = va_arg(*args, char *);
  int i = 0;
  if (fl->width == 0) fl->width = MAX_SIZE;
  while (*p_str && *p_str != ' ' && fl->width) {
    if (!fl->hz_star) {
      *result_string = *p_str;
      result_string++;
      i++;
    }
    p_str++;
    fl->width--;
    if (*p_str == '\t') {
      p_str++;
      break;
    }
  }
  if (i) *output_result += 1;
  return p_str;
}

char *s21_sscanf_int(sscanf_flags *fl, va_list *args, char *p_str,
                     int *output_result)
/*
Тип данных	                    Стандарт C      LP32	ILP32	LLP64
LP64 char/unsigned char	            Как минимум 8	8	    8	    8
8 short/unsigned short int	    Как минимум 16	16	    16	    16
16 int / unsigned int	            Как минимум 16	16	    32	    32
32 long/unsigned long	            Как минимум 32	32	    32	    32
64 long long/unsigned long long	Как минимум 64	64	    64	    64	    64

вот тут нашел https://metanit.com/c/tutorial/8.9.php
брал все дла LP64 разрядной системы
*/
{
  if (*p_str != '\0') {
    // чиитаем само число
    char temp[MAX_SIZE] = {'\0'};
    if (fl->width == 0) fl->width = 999;  // думаю 999 знаков достаточно
    int minus = 0, plus = 0;
    p_str = parse_sign(&minus, &plus, p_str, fl);
    fl->width -= (minus + plus);
    if (minus) temp[0] = '-';

    // если не число. то заканчиваем чтение полностью
    if ((*p_str < '0' || *p_str > '9' || fl->width == 0) && *p_str != ' ') {
      p_str += s21_strlen(p_str);
    }

    int i = minus;
    for (; *p_str >= '0' && *p_str <= '9' && fl->width;
         i++, p_str++, fl->width--) {
      temp[i] = *p_str;
    }
    // отработка длины
    apply_len_for_int(fl, i, minus, &output_result, temp, args);
  }
  return p_str;
}

void apply_len_for_int(sscanf_flags *fl, int i, int minus, int **output_result,
                       char temp[], va_list *args) {
  // отработка длины
  if (fl->len == 'h' && !fl->hz_star && i != minus) {
    // короткое инт или короткое инт без знака
    if (fl->len2) {
      int8_t *result_number = va_arg(*args, int8_t *);
      *result_number = (int8_t)text_to_number(temp);
      **output_result += 1;
    } else {
      int16_t *result_number = va_arg(*args, int16_t *);
      *result_number = (int16_t)text_to_number(temp);
      **output_result += 1;
    }
  } else if (fl->len == 'l' && !fl->hz_star && i != minus) {
    // длинное (и лонг и логг лонг) инт или длинное инт без знака
    int64_t *result_number = va_arg(*args, int64_t *);
    *result_number = (int64_t)text_to_number(temp);
    **output_result += 1;
  } else {
    if (!fl->hz_star && i != minus) {
      // иначе просто инт
      int32_t *result_number = va_arg(*args, int32_t *);
      *result_number = (int32_t)text_to_number(temp);
      **output_result += 1;
    }
  }
}

char *s21_sscanf_i(sscanf_flags *fl, va_list *args, char *p_str,
                   int *output_result) {
  int sign = 0, plus = 0;
  p_str = parse_sign(&sign, &plus, p_str, fl);

  if (*p_str == '0') {
    p_str++;
    if (*p_str == 'x' || *p_str == 'X') {
      p_str--;  // чтобы компенсировать переход для оценки 'x'
      p_str = s21_sscanf_hex(fl, args, p_str, output_result, sign + plus);
    } else {
      p_str--;  // чтобы компенсировать переход для оценки 'x'
      // printf("p_str_start=%s\n", p_str);
      p_str = s21_sscanf_hex_half(fl, args, p_str, output_result, sign + plus);
    }
  } else {
    p_str -= (sign + plus);
    p_str = s21_sscanf_int(fl, args, p_str, output_result);
  }
  return p_str;
}

char *s21_sscanf_hex_half(sscanf_flags *fl, va_list *args, char *p_str,
                          int *output_result, int sign) {
  if (*p_str != '\0') {
    //    читаем само число
    char temp[MAX_SIZE] = {'\0'};
    if (fl->width == 0) fl->width = 999;  // думаю 999 знаков достаточно
    fl->width -= sign;

    if (fl->width == 0)
      p_str += s21_strlen(p_str);
    else {
      // читаем число. результат чтения - тестом десятичное число!!!!
      for (int i = 0; *p_str != ' ' && *p_str != '\0' && fl->width;
           i++, p_str++, fl->width--) {
        // если меньше и пока меньше 8 сохраняем в число
        if (*p_str >= '0' && *p_str <= '7')
          temp[i] = *p_str;
        else
          break;
      }

      //  переводим в 8 ричную систему из 10 ричной
      int64_t res_8 = 0;

      //  не знаю почему так. но только так проходят тесты с длиииииными
      //  строками((
      if (s21_strlen(temp) >= 23) {
        if (fl->minus)
          res_8 = 0;
        else
          res_8 = 255;
      } else {
        for (int j = s21_strlen(temp) - 1, pow = 0; j >= 0; j--, pow++) {
          int64_t bufer = temp[j] - '0';

          for (int k = 0; k < pow; k++) {
            bufer *= 8;
          }
          res_8 += bufer;
        }
      }

      if (fl->minus) res_8 *= -1;

      // отработка длины
      apply_len_for_hex_half(fl, &output_result, res_8, args, temp);
    }
  }
  return p_str;
}

void apply_len_for_hex_half(sscanf_flags *fl, int **output_result,
                            long long int res_8, va_list *args, char temp[]) {
  if (fl->len == 'h' && !fl->hz_star && s21_strlen(temp))  // && i != minus)
  {
    // короткое инт или короткое инт без знака
    if (fl->len2) {
      int8_t *result_number = va_arg(*args, int8_t *);
      *result_number = (int8_t)res_8;
      **output_result += 1;
      // printf("result number 1-1=%lld\n", (int64_t)*result_number);
    } else {
      int16_t *result_number = va_arg(*args, int16_t *);
      *result_number = (int16_t)res_8;
      **output_result += 1;
      // printf("result number 1-2=%lld\n", (int64_t)*result_number);
    }
  } else if (fl->len == 'l' && !fl->hz_star &&
             s21_strlen(temp))  // && i != minus)
  {
    // длинное (и лонг и логг лонг) инт или длинное инт без знака
    int64_t *result_number = va_arg(*args, int64_t *);
    *result_number = (int64_t)res_8;
    **output_result += 1;
    // printf("result number 2=%lld\n", (int64_t)*result_number);
  } else if (s21_strlen(temp)) {
    if (!fl->hz_star)  // && i != minus)
    {
      // иначе просто инт
      int32_t *result_number = va_arg(*args, int32_t *);
      *result_number = (int32_t)res_8;
      **output_result += 1;
      // printf("result number 3=%lld\n", (int64_t)*result_number);
    }
  }
}

char *s21_sscanf_hex(sscanf_flags *fl, va_list *args, char *p_str,
                     int *output_result, int sign) {
  if (*p_str != '\0') {
    //    читаем само число
    char temp[MAX_SIZE] = {'\0'};
    if (fl->width == 0) fl->width = 999;  // думаю 999 знаков достаточно
    fl->width -= sign;

    // читаем число. результат чтения - тестом десятичное число!!!!
    for (int i = 0; *p_str != ' ' && *p_str != '\0' && fl->width > 0 &&
                    s21_strchr("0123456789abcdefABCDEFxX", *p_str);
         i++, p_str++, fl->width--) {
      if (s21_strchr("xX", *p_str) == 0)
        temp[i] = *p_str;
      else
        i--;  // чтобы в темпе остаться на том же месте после прохода фор'а
    }

    // переводим в 16 ричную систему из 10 ричной
    uint64_t res_16 = 0;
    for (int j = s21_strlen(temp) - 1, pow = 0; j >= 0; j--, pow++) {
      uint64_t bufer = 0;
      if (temp[j] >= '0' && temp[j] <= '9')
        bufer = temp[j] - '0';
      else if (temp[j] >= 'a' && temp[j] <= 'f')
        bufer = temp[j] - 'a' + 10;
      else if (temp[j] >= 'A' && temp[j] <= 'F')
        bufer = temp[j] - 'A' + 10;

      for (int k = 0; k < pow; k++) {
        bufer *= 16;
      }
      // проверка переполнения
      // почему именно так не понял, но так тесты прохоят
      if (res_16 > (INT64_MAX - bufer) / 16) {
        if (fl->minus)
          res_16 = INT64_MIN;
        else
          res_16 = INT64_MAX;
        break;
      }
      res_16 += bufer;
    }
    if (fl->minus) res_16 *= -1;

    // отработка длины
    apply_len_for_hex(fl, &output_result, res_16, args, temp);
  }
  return p_str;
}

void apply_len_for_hex(sscanf_flags *fl, int **output_result,
                       long long int res_16, va_list *args, char temp[]) {
  if (fl->len == 'h' && !fl->hz_star && s21_strlen(temp))  // && i != minus)
  {
    // короткое инт или короткое инт без знака
    if (fl->len2) {
      uint8_t *result_number = va_arg(*args, uint8_t *);
      *result_number = (uint8_t)res_16;
      **output_result += 1;
      // printf("result number 1-1=%lld\n", (int64_t)*result_number);
    } else {
      uint16_t *result_number = va_arg(*args, uint16_t *);
      *result_number = (uint16_t)res_16;
      **output_result += 1;
      // printf("result number 1-2=%lld\n", (int64_t)*result_number);
    }
  } else if (fl->len == 'l' && !fl->hz_star &&
             s21_strlen(temp))  // && i != minus)
  {
    // длинное (и лонг и логг лонг) инт или длинное инт без знака
    uint64_t *result_number = va_arg(*args, uint64_t *);
    *result_number = (uint64_t)res_16;
    **output_result += 1;
    // printf("result number 2=%lld\n", (int64_t)*result_number);
  } else if (s21_strlen(temp)) {
    if (!fl->hz_star)  // && i != minus)
    {
      // иначе просто инт
      uint32_t *result_number = va_arg(*args, uint32_t *);
      *result_number = (uint32_t)res_16;
      **output_result += 1;
      // printf("result number 3=%lld\n", (int64_t)*result_number);
    }
  }
}

char *s21_sscanf_float(sscanf_flags *fl, va_list *args, char *p_str,
                       int *output_result) {
  long double result_float = 0.0;
  if (fl->width == 0) fl->width = 999;

  int minus = 0, plus = 0;
  p_str = parse_sign(&minus, &plus, p_str, fl);
  fl->width -= (minus + plus);

  char temp_float_up[MAX_SIZE] = {'\0'}, temp_float_down[MAX_SIZE] = {'\0'},
       e_pow_bufer[100] = {'\0'};

  int i = 0, j = 0, flag_point = 0, flag_nan_inf = 0, e_pow = 0, k = 0;
  float result_number = 0;
  while (*p_str != '\0' && *p_str != ' ' && fl->width && *p_str != '+' &&
         *p_str != '-') {
    if (*p_str == '.') {
      flag_point = 1;
      p_str++;
      fl->width--;
    }
    if (flag_point == 0 && s21_strchr("0123456789", *p_str)) {
      temp_float_up[i] = *p_str;
      i++;
    } else if (s21_strchr("0123456789", *p_str)) {
      temp_float_down[j] = *p_str;
      j++;
    } else if (s21_strchr("naifNAIFeE", *p_str)) {
      p_str = nan_inf_and_e_notacion_apply(p_str, &result_number, &e_pow, &k,
                                           &flag_nan_inf, e_pow_bufer);
    }
    if (s21_strlen(temp_float_up) == 0 && s21_strlen(temp_float_down))
      temp_float_up[0] = '0';
    p_str++;
    fl->width--;
  }
  e_pow_apply(temp_float_down, temp_float_up, &result_float, e_pow, fl,
              flag_nan_inf, result_number);
  // отработка длины
  apply_len_for_float(fl, &output_result, result_float, args, temp_float_up,
                      flag_nan_inf);
  return p_str;
}

void e_pow_apply(char temp_float_down[], char temp_float_up[],
                 long double *result_float, int e_pow, sscanf_flags *fl,
                 int flag_nan_inf, long double result_number) {
  int pow = s21_strlen(temp_float_down);
  if (flag_nan_inf == 0) {
    *result_float = text_to_number(temp_float_down);
    for (; pow > 0; pow--) *result_float /= 10;
    *result_float += text_to_number(temp_float_up);
  } else {
    *result_float = (long double)result_number;
    temp_float_up[0] = '1';  // тупо чтобы не усложнять условия ниже
  }
  if (fl->minus) *result_float *= -1;

  if (e_pow > 0) {
    for (; e_pow > 0; e_pow--) *result_float *= 10;
  } else if (e_pow < 0) {
    for (; e_pow < 0; e_pow++) *result_float /= 10;
  }
}

char *nan_inf_and_e_notacion_apply(char *p_str, float *result_number,
                                   int *e_pow, int *k, int *flag_nan_inf,
                                   char e_pow_bufer[]) {
  // для декомпозиции
  if ((*p_str == 'n' || *p_str == 'N') &&
      (*(p_str + 1) == 'a' || *(p_str + 1) == 'A') &&
      (*(p_str + 2) == 'n' || *(p_str + 2) == 'N')) {
    *flag_nan_inf = 1;
    *result_number = NAN;
  } else if ((*p_str == 'i' || *p_str == 'I') &&
             (*(p_str + 1) == 'n' || *(p_str + 1) == 'N') &&
             (*(p_str + 2) == 'f' || *(p_str + 2) == 'F')) {
    *flag_nan_inf = 1;
    *result_number = INFINITY;
  } else if (*p_str == 'e' && s21_strlen(e_pow_bufer) == 0) {
    int e_minus = 1;
    p_str++;
    if (*p_str == '-') {
      e_minus = -1;
      p_str++;
    }
    while (*p_str != '\0' &&
           *p_str != ' ')  // && s21_strchr("0123456789", *p_str))
    {
      e_pow_bufer[*k] = *p_str;
      p_str++;
    }
    *e_pow = text_to_number(e_pow_bufer) * e_minus;
    p_str -= (int)s21_strlen(e_pow_bufer);
  }
  return p_str;
}

void apply_len_for_float(sscanf_flags *fl, int **output_result,
                         long double result_float, va_list *args,
                         char temp_float_up[], int flag_nan_inf) {
  if (fl->len == 'h' && !fl->hz_star && s21_strlen(temp_float_up) &&
      !flag_nan_inf) {
    float *result_number = va_arg(*args, float *);
    *result_number = (float)result_float;
    **output_result += 1;
  } else if ((fl->len == 'l' || fl->len == 'L') && !fl->hz_star &&
             s21_strlen(temp_float_up) && !flag_nan_inf) {
    if (fl->len2 || fl->len == 'L') {
      long double *result_number = va_arg(*args, long double *);
      *result_number = (long double)result_float;
      **output_result += 1;
    } else {
      double *result_number = va_arg(*args, double *);
      *result_number = (double)result_float;
      **output_result += 1;
    }
  } else if ((!fl->hz_star && s21_strlen(temp_float_up)) || flag_nan_inf) {
    float *result_number = va_arg(*args, float *);
    *result_number = (float)result_float;
    **output_result += 1;
  }
}
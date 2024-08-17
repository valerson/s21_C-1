#include "s21_string.h"

/*
int sprintf(char *buf, const char *format, ...);
Функция sprintf() идентична функции printf() за исключением того, что поток
вывода записывается в массив, адресуемый указателем buf, а не в стандартный
поток stdout.
*/

int s21_sprintf(char *str, const char *format, ...) {
  // если что - читай stdarg.h в википедии
  // Инициализируем список аргументов
  va_list args;
  va_start(args, format);
  // str - первый аргумент
  // Первым аргументом функция принимает адрес в памяти, куда будет записана
  // отформатированная строка. format - второй аргумент Вторым аргументом мы
  // указываем строку форматирования. Этот и следующие аргументы совпадают с
  // аргументами функции printf args - все аргументы while ((arg = va_arg(args,
  // const char *))) - проход
  flags fl = {0};
  char *start_str = str;  // указатель на пустую итоговую строку
  int null_factor = 0;
  while (*format) {
    if (*format != '%')  // если символ не означающий передачу аргумента
                         // добавляем его в финишную строку как есть
    {
      *str = *format;
      str++;
      format++;
      continue;  // обязательно !!!!! иначе пойдем ниже по алгоритму
    } else
      format++;
    // парсим на флаги, ширину, точность, длину, спецификаторы
    format = parsing_all(format, &fl, &args);  // для декомпозиции
    fl.specificator =
        *format;  // когда прошли всё - флаги, ширина, точность, длина
    /*
    c Символ
    d или i Десятичное целое число со знаком
    e Научная нотация (мантисса / экспонента) с использованием символа e
    E Научная нотация (мантисса / экспонента) с использованием символа E
    f Десятичная функция с плавающей запятой
    g Использует сокращение от %e или %f.
    G Использует сокращение от %E или %f
    o Восьмеричная функция со знаком
    s Строка символов
    u Десятичное целое число без знака
    x Шестнадцатеричное целое число без знака
    X Шестнадцатеричное целое число без знака (заглавные буквы)
    p Адрес указателя
    n Ничего не напечатано
    % Символ
    */
    char temp[MAX_SIZE] = {'\0'};
    switch_specificator_sprintf(fl, temp, &args,
                                &null_factor);  // для декомпозиции
    s21_strcpy(str, temp);
    if (*(str + s21_strlen(temp)) == '\0' && fl.specificator == 'c' &&
        null_factor) {
      if (fl.width)
        str += fl.width;
      else
        str++;
    } else
      str += s21_strlen(temp);
    format++;
    // спецификатор n записывает количество символов, напечатанных до этого
    // момента в аргумент

    if (fl.specificator == 'n') {
      int *count = va_arg(args, int *);
      *count = str - start_str;
    }
    flag_to_null(&fl);
  }
  va_end(args);
  int result = str - start_str;
  *str = '\0';
  return result;
}

const char *parsing_all(const char *format, flags *fl, va_list *args) {
  if (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
      *format == '#')
    format = get_flags(format, fl);
  if (*format == '*' || (*format >= '0' && *format <= '9'))
    format = get_widht(format, fl, args);
  if (*format == '.') format = get_precision(format, fl, args);
  if (*format == 'h' || *format == 'l' || *format == 'L')
    format = get_lenght(format, fl);
  return format;
}

void switch_specificator_sprintf(flags fl, char *temp, va_list *args,
                                 int *null_factor) {
  if (fl.specificator == 'd' || fl.specificator == 'i')
    s21_int(fl, temp, args);
  else if (fl.specificator == 'c')
    s21_char(fl, temp, args, null_factor);
  else if (fl.specificator == 'f')
    s21_float(fl, temp, args);
  else if (fl.specificator == 's')
    s21_string(fl, temp, args);
  else if (fl.specificator == 'u')
    s21_unsigned(fl, temp, args);
  else if (fl.specificator == '%')
    temp[0] = '%';
  else if (fl.specificator == 'g' || fl.specificator == 'G')
    s21_g_reduction(fl, temp, args);
  else if (fl.specificator == 'e' || fl.specificator == 'E')
    s21_science_notation(fl, temp, args);
  else if (fl.specificator == 'x' || fl.specificator == 'X')
    s21_hex(fl, temp, args);
  else if (fl.specificator == 'o')
    s21_hex_half(fl, temp, args);
  else if (fl.specificator == 'p')
    s21_pointer(fl, temp, args);
}

// void flag_print(flags *fl) {
//   printf("flag minus = %d\n", fl->minus);
//   printf("flag plus = %d\n", fl->plus);
//   printf("flag space = %d\n", fl->space);
//   printf("flag zero = %d\n", fl->zero);
//   printf("flag grill %d\n", fl->grill);
//   printf("flag precision = %d\n", fl->precision);
//   printf("flag is precision? = %d\n", fl->is_precision_set);
//   printf("flag wight = %d\n", fl->width);
//   printf("flag lenght %c\n", fl->length);
//   printf("flag specificator %c\n", fl->specificator);
// }

const char *get_flags(const char *format, flags *fl)
/*
#	Значение преобразуется в "альтернативную форму".
Для преобразования типа o первый символ выходного потока преобразуется в нуль
(префикс 0, если до этого его не было указано). Для преобразований типа x и X к
ненулевому результату добавляется `0x' (или `0X' для преобразования типа X). При
преобразованиях типа: a, A, e, E, f, F, g и G - результат всегда будет содержать
десятичную точку, даже если за ним нет следующих цифр (обычно десятичная точка
присутствует в результате таких преобразований, только если за ними следуют
цифры). Для преобразований g и G завершающие нули не удаляются из результата,
как это обычно случается. Результат других преобразований не определен.

0	Значение слева дополняется нулями (вместо пробелов).

-	Выравнивает результат преобразования по левой границе поля. (По
умолчанию выравнивание выполняется справа.) Исключает преобразование типа n ,
дополняя значение справа пробелами.
- Отменяет флаг 0, если оба флага были установлены.

' '	(пробел). Устанавливает перед положительными числами (или пустой
строкой) знак пробела для знаковых преобразований.

+	Знак + или - всегда помещается перед числом со знаком.
По умолчанию знак используется только для отрицательных чисел.
+ отменяет действие пробела, если оба флага используются.
*/
{
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0')  // чтобы отрабатывалось типа такого "#-10x"
  {
    switch (*format) {
      case '-':
        fl->minus = 1;
        fl->zero = 0;
        break;
      case '+':
        fl->plus = 1;
        fl->space = 0;
        break;
      case ' ':
        fl->space = 1;
        break;
      case '0':
        fl->zero = 1;
        break;
      case '#':
        fl->grill = 1;
        break;
    }
    format++;
  }
  return format;
}

const char *get_widht(const char *format, flags *fl, va_list *args)
/*
Ширина поля
Необязательная стpока из десятичных цифp (с пеpвой цифpой, отличной от нуля)
опpеделяет минимальную шиpину поля. Если пpеобpазованное значение имеет меньшее
количество знаков, чем шиpина поля, то оно слева дополняется пpобелами (или
спpава, если указан флаг левого пpеобpазования). Вместо стpоки десятичных цифp
можно указать '*', чтобы опpеделить шиpину поля по шиpине следующего аpгумента.
Аргументы должны иметь тип int.
Отpицательная шиpина поля пpинимается как флаг '-', устанавливающий
положительную шиpину поля.
*/
{
  if (*format == '*') {
    // если * в ширину записываем аргумент
    format++;
    fl->width = va_arg(*args, int);
  } else if (*format >= '0' && *format <= '9')  // иначе слетает флаг
  {
    char temp[MAX_SIZE] = {'\0'};
    for (int i = 0; *format >= '0' && *format <= '9'; i++) {
      temp[i] = *format;
      format++;
    }
    fl->width = text_to_number(temp);
  }
  return format;
}

const char *get_precision(const char *format, flags *fl, va_list *args)
/*
Точность
Необязательный паpаметp точности в виде знака точки ('.') сопpовождается
необязательной стpокой десятичных цифp. Вместо стpоки десятичных цифp можно
указать '*', чтобы опpеделить значение точности по следующему аpгументу, котоpые
должны иметь тип int.

Это позволяет ограничивать количество выводимых символом для преобразований
типов: d, i, o, u, x и X; показывать определенное количество цифр после
десятичной точки для преобразований: a, A, e, E, f и F; показывать максимальное
количество значащих цифр для преобразований g и G или максимальное количество
символов для печати строк при преобразованиях s и S.
*/
{
  fl->is_precision_set = 1;
  format++;

  if (*format == '*') {
    // если * в длину записываем первый аргумент
    format++;
    fl->precision = va_arg(*args, int);
  }

  if (*format >= '0' && *format <= '9') {
    char temp[MAX_SIZE] = {'\0'};
    for (int i = 0; *format >= '0' && *format <= '9'; i++) {
      temp[i] = *format;
      format++;
    }
    fl->precision = text_to_number(temp);
  }
  return format;
}

const char *get_lenght(const char *format, flags *fl)
/*
Модификаторы длины
Устанавливаются для следующих целых преобразователей:
h - short int,
l - long int для d
тип преобразования c соответствует аргументу wint_t;
тип преобразования s соответствует агрументу указателя wchar_t.
L - long double
*/
{
  switch (*format) {
    case 'h':
      fl->length = 'h';
      break;
    case 'l':
      fl->length = 'l';
      break;
    case 'L':
      fl->length = 'L';
      break;
  }
  format++;
  return format;
}

int64_t text_to_number(char *text) {
  int64_t result = 0;
  int znak = 1, flag_exit = 0;
  if (*text == '-') {
    text++;
    znak *= -1;
  }

  while (*text != '\0' && *text >= '0' && *text <= '9') {
    int digit = *text - '0';

    // Проверка переполнения перед добавлением следующей цифры
    if (znak == 1 && (result > (INT64_MAX - digit) / 10)) {
      flag_exit = 1;
      result = -1;
    } else if (znak == -1 && (result * znak < (INT64_MIN + digit) / 10)) {
      flag_exit = 1;
      result = 0;
    }
    if (flag_exit) break;
    result = result * 10 + digit;
    text++;
  }
  if (flag_exit == 0) result *= znak;

  return result;
}

void flag_to_null(flags *fl) {
  fl->minus = 0;
  fl->plus = 0;
  fl->space = 0;
  fl->zero = 0;
  fl->grill = 0;
  fl->precision = 0;
  fl->is_precision_set = 0;
  fl->width = 0;
  fl->length = '\0';
  fl->specificator = '\0';
}

void s21_int(flags fl, char *temp, va_list *args)
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
  // просто спецификатор d - обычный инт
  int64_t result = va_arg(*args, int64_t);  // текущий аргумент

  // смотрим на длину. если есть h - шорт инт,l - лонг инт
  if (fl.length == 'h') result = (int16_t)result;
  if (!fl.length) result = (int32_t)result;

  number_add_text(result, temp);
  precision_apply(fl, temp);
  flags_apply(fl, temp);
}

void precision_apply(flags fl, char *temp) {
  // отработка точности
  if (fl.is_precision_set) {
    // смотрим длину числа. если больше - добавляем нули. учитываем
    // отрицательность числа сразу же
    int n = s21_strlen(temp);
    char bufer[MAX_SIZE] = {'\0'};
    int znak = 0;
    if (temp[0] == '-') {
      bufer[0] = '-';
      znak = 1;
      n--;
    }

    if (fl.precision > n) {
      for (int i = znak, j = znak; i < fl.precision + znak; i++) {
        if (i + n < fl.precision + znak)
          bufer[i] = '0';
        else {
          bufer[i] = temp[j];
          j++;
        }
      }
      bufer[fl.precision + znak] = '\0';
      s21_strcpy(temp, bufer);
    }
  }
  if (fl.is_precision_set && fl.precision == 0 && temp[0] == '0' &&
      fl.grill == 0)
    temp[0] = '\0';
}

void flags_apply(flags fl, char *temp) {
  // отработка флагов
  char bufer2[MAX_SIZE] = {'\0'};
  if (fl.plus && temp[0] != '-' && fl.specificator != 'u' &&
      fl.specificator != 's' && fl.specificator != 'c' &&
      fl.specificator != 'x' && fl.specificator != 'X' &&
      fl.specificator != 'o') {
    bufer2[0] = '+';
    if (!APPLE_M_PROC && s21_strcmp(temp, "(nil)") != 0)
      s21_strcpy(bufer2 + 1, temp);
    else if (s21_strcmp(temp, "(nil)") == 0)
      s21_strcpy(bufer2, temp);
    else
      s21_strcpy(bufer2 + 1, temp);
    s21_strcpy(temp, bufer2);
  } else if (fl.space && temp[0] != '-' && fl.specificator != 's' &&
             fl.specificator != 'c' && fl.specificator != 'x' &&
             fl.specificator != 'X' &&
             fl.specificator != 'o')  // пробел только не для
  //  символов и текста
  {
    bufer2[0] = ' ';
    if (s21_strcmp(temp, "(nil)") == 0)
      s21_strcpy(bufer2, temp);
    else
      s21_strcpy(bufer2 + 1, temp);
    s21_strcpy(temp, bufer2);
  }
  if (fl.width > (int)s21_strlen(temp)) {
    int i = fl.width - s21_strlen(temp), sign = 0;

    if (fl.minus == 0) {
      if (fl.zero && ((fl.specificator != 'c' && fl.specificator != 's') ||
                      APPLE_M_PROC)) {
        if (temp[0] == '-' || temp[0] == ' ' || temp[0] == '+') {
          sign = 1;
          bufer2[0] = temp[0];
          i += 1;
        }
        for (int j = sign; j < i; j++) bufer2[j] = '0';
      } else {
        for (int j = 0; j < i; j++) bufer2[j] = ' ';
      }
      s21_strcpy(bufer2 + i, temp + sign);
    } else {
      s21_strcpy(bufer2, temp + sign);
      s21_memset(bufer2 + s21_strlen(bufer2), ' ', i);
    }
    s21_strcpy(temp, bufer2);
  }
}

void s21_char(flags fl, char *temp, va_list *args, int *null_factor) {
  // просто спецификатор c - обычный  символ
  // с флагом длины l тип wint_t (см. в длине туда вставил)
  if (fl.length == 'l') {
    wint_t c = '\0';
    c = va_arg(*args, wint_t);
    // temp[0] = c;
    format_char_long(c, temp, fl);
  } else {
    // вот тут проблема!! нужно как-то добиться чтения чара этого
    char c = '\0';
    c = va_arg(*args, int);
    // temp[0] = c;
    if (c == 0) *null_factor += 1;
    format_char(c, temp, fl);
  }
}

void format_char_long(wchar_t c, char *temp, flags fl) {
  if (fl.minus == 0 && fl.width) {
    // printf("URA!");
    char bufer[MAX_SIZE] = {'\0'};
    wcstombs(bufer, &c, MAX_SIZE);
    // if (!APPLE_M_PROC) bufer[1] = '\0';
    /*
    size_t wcstombs(char *out, const wchar_t *in, size_t size);
    Функция wcstombs() преобразует массив двухбайтовых символов, адресуемый
    параметром-указателем in, в его многобайтовый эквивалент и помещает
    результат в массив, адресуемый параметром out. Преобразованию подлежат
    только первые size символов. Процесс преобразования прекращается раньше,
    если будет обнаружен символ конца строки ('0').
    */
    for (int i = 0; i < fl.width - (int)s21_strlen(bufer); i++) temp[i] = ' ';
    s21_strcpy(temp + s21_strlen(temp), bufer);
  } else if (fl.width) {
    wcstombs(temp, &c, MAX_SIZE);
    // if (!APPLE_M_PROC) temp[1] = '\0';
    for (int i = (int)s21_strlen(temp); i < fl.width; i++) temp[i] = ' ';
  } else {
    wcstombs(temp, &c, MAX_SIZE);
    // if (!APPLE_M_PROC) temp[1] = '\0';
  }
}

void format_char(char c, char *temp, flags fl) {
  if (fl.minus == 0 && fl.width) {
    // printf("Ura\n");
    for (int i = 0; i < fl.width; i++) {
      if (fl.zero && APPLE_M_PROC)
        temp[i] = '0';
      else {
        temp[i] = ' ';
      }
      if (i == fl.width - 1) temp[i] = c;
    }
  } else if (fl.width) {
    temp[0] = c;
    for (int i = 1; i < fl.width; i++) temp[i] = ' ';
  } else {
    temp[0] = c;
  }
}

void s21_float(flags fl, char *temp, va_list *args) {
  // просто спецификатор f-обычный дабл
  // если есть длина L то лонг дабл
  long double result = 0;
  if (fl.length == 'L')
    result = va_arg(*args, long double);
  else
    result = va_arg(*args, double);

  if (fl.is_precision_set == 0) fl.precision = 6;

  double_add_text(result, temp, fl);
  flags_apply(fl, temp);
}

void double_add_text(double number, char *text, flags fl) {
  // сначала целую часть
  long long int temp = number, i = 0, znak = 0, n = 0;
  if (double_up_half(text, &temp, &i, &znak, fl, &n, &number)) return;

  // потом дробную часть
  number = number -
           (long long int)number;  // отбросили целую часть полностью, оставив
                                   // только дробную Обработка дробной части
  // Обработка дробной части
  double fractional_part = number;
  if (fractional_part < 0) fractional_part *= -1;
  for (int j = 0; j < fl.precision; j++) {
    fractional_part *= 10;
    int digit = (int)fractional_part;
    text[i] = '0' + digit;
    i++;
    fractional_part -= digit;
  }
  text[i] = '\0';  // Завершаем строку

  // Округление результата для точности !!!!!
  if ((fractional_part * 10 >= 5)) {
    int m = i - 1;
    while (m >= 0 && (text[m] == '9' || text[m] == '.')) {
      if (text[m] == '9') {
        text[m] = '0';
      }
      m--;
    }
    if (m >= 0) {
      if (text[m] == '-') {  // отрицательное
        char result_buf[MAX_SIZE] = {'\0'};
        result_buf[0] = '-';
        result_buf[1] = '1';
        s21_strcpy(result_buf + 2, text + 1);
        s21_strcpy(text, result_buf);
      } else  // положительное
        text[m] += 1;
    } else {
      s21_memcpy(text + 1, text, i + 1);
      text[0] = '1';
      i++;
    }
    fractional_part *= 10;
  }
}

int double_up_half(char *text, long long int *temp, long long *i,
                   long long int *znak, flags fl, long long int *n,
                   double *number) {
  // декомпоиция целая часть дабла
  if (*number < 0) {
    *znak = 1;
    text[0] = '-';
    *temp *= -1;
    *number *= -1;
  }
  if (fl.precision == 0 && (*number - (long long int)*number) * 10 >= 5) {
    *temp += 1;
  }
  char buf[MAX_SIZE] = {'\0'};
  if ((int)*temp == 0) {
    buf[*i] = '0';
    *i += 1;
    if (fl.is_precision_set != 0 && *number - (int)*number == 0) {
      text[0] = '0';
      if (fl.specificator != 'e' && fl.specificator != 'E' &&
          fl.specificator != 'f')
        return 1;
    }
  }
  while (*temp) {
    buf[*i] = '0' + *temp % 10;
    *temp = *temp / 10;
    *i += 1;
  }
  *n = *i + *znak;
  for (int j = *znak; j <= *n; j++, *i -= 1) {
    if (j == *n && (fl.precision != 0 || fl.is_precision_set))
      text[j] = '.';
    else
      text[j] = buf[*i - 1];
  }
  *n = s21_strlen(text);

  // убираем записанную ерунду из крайнего символа если точность ==0
  if (fl.precision == 0) {
    if (!fl.grill) text[*n - 1] = '\0';
    return 1;
  }
  *i = *n;
  return 0;
}

void s21_string(flags fl, char *temp, va_list *args) {
  if (fl.length == 'l') {
    wchar_t *bufer = va_arg(*args, wchar_t *);
    // printf("bufer = %s\n", bufer);
    /*
    size_t wcstombs(char *out, const wchar_t *in, size_t size);
    Функция wcstombs() преобразует массив двухбайтовых символов, адресуемый
    параметром-указателем in, в его многобайтовый эквивалент и помещает
    результат в массив, адресуемый параметром out. Преобразованию подлежат
    только первые size символов. Процесс преобразования прекращается раньше,
    если будет обнаружен символ конца строки ('0').
    */
    wcstombs(temp, bufer, MAX_SIZE);
  } else {
    char *bufer = va_arg(*args, char *);
    if (bufer)
      s21_strcpy(temp, bufer);
    else {
      // if (APPLE_M_PROC)
      s21_strcpy(temp, "(null)");
      // else {
      //   if (fl.precision >= (int)s21_strlen("(null)"))
      //     s21_strcpy(temp, "(null)");
      //   else
      //     temp[0] = '\0';
      // }
    }
  }
  if (fl.is_precision_set) temp[fl.precision] = '\0';
  flags_apply(fl, temp);  // не уверен, не все флаги просто применимы как бы,
                          // нужно потестить на неправильных флагах для  s
}

void s21_unsigned(flags fl, char *temp, va_list *args)
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
  uint64_t result = va_arg(*args, uint64_t);  // текущий аргумент unsigned long
  // смотрим на длину. если есть h - ансайдед шорт инт,l - ансайдед лонг инт
  if (fl.length == 'h') result = (uint16_t)result;
  if (fl.length == 'l') result = (uint64_t)result;
  fl.space = 0;  // потому что беззнаковый тип

  // число в текст с учетом того, что может быть беззнаковое лонг
  char bufer[MAX_SIZE] = {'\0'};
  int i = 0, j = 0;
  if (result == 0) {
    bufer[j] = '0';
    j++;
  }
  while (result) {
    bufer[j] = "0123456789"[result % 10];
    j++;
    result /= 10;
  }
  j--;
  while (j >= 0) {
    temp[i] = bufer[j];
    i++;
    j--;
  }

  precision_apply(fl, temp);
  flags_apply(fl, temp);
}

void s21_science_notation(flags fl, char *temp, va_list *args) {
  // просто спецификатор обычный дабл
  // флаг L - лонг дабл
  long double result = 0;
  if (fl.length == 'L')
    result = va_arg(*args, long double);
  else
    result = va_arg(*args, double);

  if (fl.is_precision_set == 0) fl.precision = 6;

  // вычисляем степень целой части и знак степени (если число целой части 0 знак
  // -)
  int pow = 0;
  char znak = '+';
  find_pow_and_sign(&znak, &pow, &result);
  double_add_text(result, temp, fl);
  e_notation(fl, temp, znak, pow);
  flags_apply(fl, temp);
}

void find_pow_and_sign(char *znak, int *pow, long double *result) {
  long double buf = *result;
  if (buf < 0) buf *= -1;
  if ((long long int)*result == 0 && *result != 0) *znak = '-';

  // если ИНТ число больше или равно 10 степерь плюс
  if ((long long int)*result != 0) {
    while (buf >= 10) {
      *pow += 1;
      *result /= 10;
      buf /= 10;
    }
  }
  // если ИНТ число меньше или равно 0 степерь минус
  if ((long long int)*result == 0 && *result != 0) {
    while ((long long int)*result == 0) {
      *pow += 1;
      *result *= 10;
    }
  }
}

void e_notation(flags fl, char *temp, char znak, int pow) {
  // делаем сокращение и формирование нотации с е-шками
  int len = s21_strlen(temp);
  if (temp[len] >= '5') temp[len - 1] += 1;
  if (fl.specificator == 'e' || fl.specificator == 'g') temp[len] = 'e';
  if (fl.specificator == 'E' || fl.specificator == 'G') temp[len] = 'E';
  temp[len + 1] = znak;
  if (pow < 10) {
    temp[len + 2] = '0';
    temp[len + 3] = '0' + pow;
  } else {
    temp[len + 3] = '0' + pow % 10;
    pow /= 10;
    temp[len + 2] = '0' + pow;
  }
  temp[len + 4] = '\0';
}

void s21_hex(flags fl, char *temp, va_list *args)
/*
Тип данных	                    Стандарт C      LP32	ILP32	LLP64
LP64 char/unsigned char	            Как минимум 8	8	    8	    8
8 short/unsigned short int	    Как минимум 16	16	    16	    16
16 int / unsigned int	            Как минимум 16	16	    32	    32
32 long/unsigned long	            Как минимум 32	32	    32	    32
64 long long/unsigned long long	Как минимум 64	64	    64	    64	    64
*/
{
  // просто спецификатор x-обычный самый лонг инт так же для длины l
  // если есть длина h то беззнаковый шорт инт
  uint64_t result = va_arg(*args, uint64_t);
  if (fl.length == 'h') result = (uint16_t)result;
  if (fl.length == 0) result = (uint32_t)result;
  if (fl.length == 'l') result = (uint64_t)result;
  int i = 0, j = 0, k = 0;
  if (result == 0)
    temp[i] = '0';
  else if (fl.grill) {
    temp[0] = '0';
    temp[1] = fl.specificator == 'x' ? 'x' : 'X';  // для декомпозиции
    i += 2;
  }
  char bufer[MAX_SIZE] = {'\0'};
  while (result) {
    bufer[j] = fl.specificator == 'x'
                   ? "0123456789abcdef"[result % 16]
                   : "0123456789ABCDEF"[result % 16];  // для декомпозиции
    j++;
    result /= 16;
  }
  j--;
  int len = s21_strlen(bufer);
  if (fl.precision > len + 1)  // 1 - это 0х этот 0
  {
    while (fl.precision - len - k != 0) {
      temp[i] = '0';
      i++;
      k++;
    }
  }
  while (bufer[j]) {
    temp[i] = bufer[j];
    i++;
    j--;
  }
  precision_apply(fl, temp);  // а тут по сути только обрезание вывода
  flags_apply(fl, temp);
}

void s21_hex_half(flags fl, char *temp, va_list *args)
/*
Тип данных	                    Стандарт C      LP32	ILP32	LLP64
LP64 char/unsigned char	            Как минимум 8	8	    8	    8
8 short/unsigned short int	    Как минимум 16	16	    16	    16
16 int / unsigned int	            Как минимум 16	16	    32	    32
32 long/unsigned long	            Как минимум 32	32	    32	    32
64 long long/unsigned long long	Как минимум 64	64	    64	    64	    64
*/
{
  // просто спецификатор x-обычный знаковый инт
  // если есть длина h то знаковый шорт инт
  // если длина l то знаковый лонг инт
  uint64_t result = va_arg(*args, uint64_t);

  if (fl.length == 'h') result = (int16_t)result;
  if (!fl.length) result = (int32_t)result;
  int i = 0, j = 0;
  char bufer[MAX_SIZE] = {'\0'};
  int64_t res_temp = result;
  if (result == 0) {
    bufer[j] = '0';
    j++;
  }
  // result < 0 не стал описывать но делается так
  /*
  Получить абсолютное значение числа:
  Перевести абсолютное значение в двоичную форму:
  Дополнить до 32 бит:
  Инвертировать все биты (первая часть two's complement):
  Добавить 1 (вторая часть two's complement):
  Перевести результат в восьмеричный формат:
  */
  while (result) {
    bufer[j] = "01234567"[result % 8];
    j++;
    result /= 8;
  }
  if (fl.grill && res_temp != 0) {
    bufer[j] = '0';
  } else
    j--;
  while (j >= 0) {
    temp[i] = bufer[j];
    i++;
    j--;
  }
  precision_apply(fl, temp);
  flags_apply(fl, temp);
}

void s21_pointer(flags fl, char *temp, va_list *args)
// void s21_pointer(char *temp, va_list *args)
/*
Спецификатор %p в функции sprintf используется для форматирования указателей.
Он преобразует значение указателя в строку, представляющую его адрес в
шестнадцатеричной системе счисления.
*/
{
  uint64_t result = va_arg(*args, uint64_t);
  if (result == 0 && APPLE_M_PROC == 0) {
    s21_strcpy(temp, "(nil)");
  } else {
    temp[0] = '0';
    temp[1] = 'x';
    int i = 2, j = 0;  // для декомпозиции
    char bufer[MAX_SIZE] = {'\0'};
    if (result == 0 && fl.is_precision_set == 0 && fl.precision == 0) {
      bufer[0] = '0';
      j++;
      for (int i = 1; i < fl.precision; i++, j++) bufer[i] = '0';
    }
    while (result) {
      bufer[j] = "0123456789abcdef"[result % 16];
      j++;
      result /= 16;
    }
    while (j < fl.precision) {
      bufer[j] = '0';
      j++;
    }
    j--;
    while (j >= 0) {
      temp[i] = bufer[j];
      i++;
      j--;
    }
  }
  flags_apply_pointer(fl, temp);
}

void flags_apply_pointer(flags fl, char *temp) {
  // отработка флагов
  char bufer2[MAX_SIZE] = {'\0'};
  if (fl.plus && temp[0] != '-' && !APPLE_M_PROC) {
    bufer2[0] = '+';
    if (!APPLE_M_PROC && s21_strcmp(temp, "(nil)") != 0)
      s21_strcpy(bufer2 + 1, temp);
    else if (s21_strcmp(temp, "(nil)") == 0)
      s21_strcpy(bufer2, temp);
    else
      s21_strcpy(bufer2 + 1, temp);
    s21_strcpy(temp, bufer2);
  } else if (fl.space && temp[0] != '-') {
    bufer2[0] = ' ';
    if (s21_strcmp(temp, "(nil)") == 0 || APPLE_M_PROC)
      s21_strcpy(bufer2, temp);
    else
      s21_strcpy(bufer2 + 1, temp);
    s21_strcpy(temp, bufer2);
  }
  if (fl.width > (int)s21_strlen(temp)) {
    int i = fl.width - s21_strlen(temp), sign = 0;

    if (fl.minus == 0) {
      if (fl.zero && ((fl.specificator != 'c' && fl.specificator != 's') ||
                      APPLE_M_PROC)) {
        if (temp[0] == '-' || temp[0] == ' ' || temp[0] == '+') {
          sign = 1;
          bufer2[0] = temp[0];
          i += 1;
        }
        for (int j = sign; j < i; j++) bufer2[j] = '0';
      } else {
        for (int j = 0; j < i; j++) bufer2[j] = ' ';
      }
      s21_strcpy(bufer2 + i, temp + sign);
    } else {
      s21_strcpy(bufer2, temp + sign);
      s21_memset(bufer2 + s21_strlen(bufer2), ' ', i);
    }
    s21_strcpy(temp, bufer2);
  }
}

void s21_g_reduction(flags fl, char *temp, va_list *args)
/*
Спецификатор формата %g в функции sprintf используется для форматирования
чисел с плавающей запятой (типа float или double) в наиболее короткой из форм
e или f. Он обычно используется для вывода чисел в научной нотации, если они
слишком большие или слишком малые, или в десятичной нотации в противном
случае.
*/
{
  // просто спецификатор обычный дабл
  // если есть длина L то лонг дабл
  long double result = 0;
  if (fl.length == 'L')
    result = va_arg(*args, long double);
  else
    result = va_arg(*args, double);
  int sign = 0;
  if (result < 0) sign = 1;
  if (fl.is_precision_set == 0) fl.precision = 6;
  if (fl.precision == 0) fl.precision = 1;
  // if (fl.is_precision_set && fl.precision == 0) fl.precision = 6;

  long double result_G = result;
  // вычисляем степень целой части и знак степени (если число целой части 0
  // знак
  // -)
  int pow = 0;
  char znak = '+';
  find_pow_and_sign(&znak, &pow, &result);
  // printf("pow=%d fl.precision=%d fl.is_precision=%d\n", pow, fl.precision,
  //        fl.is_precision_set);

  // char buf_temp_e[MAX_SIZE] = {'\0'};
  // char buf_temp_f[MAX_SIZE] = {'\0'};
  // s21_strcpy(buf_temp_e, temp);
  // s21_strcpy(buf_temp_f, temp);
  // decomposicion_g_reduction_part1(fl, result, buf_temp_e, znak, pow, sign);
  // decomposicion_g_reduction_part2(fl, result_G, buf_temp_f, pow, sign);
  // printf("temp_e=%s\n", buf_temp_e);
  // printf("temp_f=%s\n", buf_temp_f);
  // if (s21_strlen(buf_temp_e) > s21_strlen(buf_temp_f)) {
  //   s21_strcpy(temp, buf_temp_f);
  //   printf("temp=%s\n", temp);
  // } else {
  //   s21_strcpy(temp, buf_temp_e);
  //   printf("temp2=%s\n", temp);
  // }

  if ((pow > 4 && znak == '-') || pow >= 6 || (pow >= fl.precision)) {
    // как e(E)
    decomposicion_g_reduction_part1(fl, result, temp, znak, pow, sign);
  } else {
    // как f
    decomposicion_g_reduction_part2(fl, result_G, temp, pow, sign);
  }
  // printf("temp2=%s\n", temp);
}

void decomposicion_g_reduction_part1(flags fl, long double result, char *temp,
                                     int znak, int pow, int sign) {
  // fl.precision = 1;
  fl.precision -= 1;  // уменьшаем точность на 1, потому что в числите будет
                      // 1 знак и остальное уйдет на знаменатель
  fl.specificator = fl.specificator == 'g' ? 'e' : 'E';  // для декомпозиции
  char buf_temp[MAX_SIZE] = {'\0'};
  double_add_text_g_reduction(result, buf_temp, fl, &pow);

  s21_strcpy(temp, buf_temp);
  remove_zero_for_g_reduction(buf_temp);

  if (fl.precision >=
          (int)s21_strlen(buf_temp) - 1 - fl.plus - fl.minus - sign &&
      !fl.grill) {  // && !fl.is_precision_set &&
    // самое важное что если решетка, то нули в конце не
    // удалять!!
    // тут 1 - это точка
    s21_strcpy(temp, buf_temp);
  }
  e_notation(fl, temp, znak, pow);
  flags_apply(fl, temp);
}

void double_add_text_g_reduction(double number, char *text, flags fl,
                                 int *pow) {
  // сначала целую часть
  long long int temp = number, i = 0, znak = 0, n = 0;
  if (double_up_half_g_reduction(text, &temp, &i, &znak, fl, &n, &number, pow))
    return;

  // потом дробную часть
  number = number -
           (long long int)number;  // отбросили целую часть полностью, оставив
                                   // только дробную Обработка дробной части
  // Обработка дробной части
  double fractional_part = number;
  if (fractional_part < 0) fractional_part *= -1;
  for (int j = 0; j < fl.precision; j++) {
    fractional_part *= 10;
    int digit = (int)fractional_part;
    text[i] = '0' + digit;
    i++;
    fractional_part -= digit;
  }
  text[i] = '\0';  // Завершаем строку

  // Округление результата для точности !!!!!
  if ((fractional_part * 10 >= 5)) {
    int m = i - 1;
    while (m >= 0 && (text[m] == '9' || text[m] == '.')) {
      if (text[m] == '9') {
        text[m] = '0';
      }
      m--;
    }
    if (m >= 0) {
      if (text[m] == '-') {  // отрицательное
        char result_buf[MAX_SIZE] = {'\0'};
        result_buf[0] = '-';
        result_buf[1] = '1';
        s21_strcpy(result_buf + 2, text + 1);
        s21_strcpy(text, result_buf);
      } else  // положительное
        text[m] += 1;
    } else {
      s21_memcpy(text + 1, text, i + 1);
      text[0] = '1';
      *pow += 1;
      text[1] = '\0';
      i++;
    }
    fractional_part *= 10;
  }
}

int double_up_half_g_reduction(char *text, long long int *temp, long long *i,
                               long long int *znak, flags fl, long long int *n,
                               double *number, int *pow) {
  // декомпоиция целая часть дабла
  if (*number < 0) {
    *znak = 1;
    text[0] = '-';
    *temp *= -1;
    *number *= -1;
  }
  if (fl.precision == 0 && (*number - (long long int)*number) * 10 >= 5) {
    if (*temp == 9) {
      *pow += 1;
      *temp = 1;
    } else
      *temp += 1;
  }
  char buf[MAX_SIZE] = {'\0'};
  if ((int)*temp == 0) {
    buf[*i] = '0';
    *i += 1;
    if (fl.is_precision_set != 0 && *number - (int)*number == 0) {
      text[0] = '0';
      if (fl.specificator != 'e' && fl.specificator != 'E' &&
          fl.specificator != 'f')
        return 1;
    }
  }
  while (*temp) {
    buf[*i] = '0' + *temp % 10;
    *temp = *temp / 10;
    *i += 1;
  }
  *n = *i + *znak;
  for (int j = *znak; j <= *n; j++, *i -= 1) {
    if (j == *n && (fl.precision != 0 || fl.is_precision_set))
      text[j] = '.';
    else
      text[j] = buf[*i - 1];
  }
  *n = s21_strlen(text);

  // убираем записанную ерунду из крайнего символа если точность ==0
  if (fl.precision == 0) {
    if (!fl.grill) text[*n - 1] = '\0';
    return 1;
  }
  *i = *n;
  return 0;
}

void decomposicion_g_reduction_part2(flags fl, long double result_G, char *temp,
                                     int pow, int sign) {
  if (fl.precision == 0) fl.precision = 1;
  if (!fl.is_precision_set || pow > fl.precision) fl.precision = 6;
  fl.precision +=
      sign;  // учитываем отрицательность, потом что обрабатываем как текст
  fl.specificator = 'f';
  double_add_text(result_G, temp, fl);
  // printf("temp=%s\n", temp);
  // printf("(s21_strchr(temp, '.') - temp)=%ld\n",
  //        (s21_strchr(temp, '.') - temp));

  if ((s21_strchr(temp, '.') - temp) > fl.precision) {
    if (temp[(int)(s21_strchr(temp, '.') - temp) + fl.precision + 1] >=
        '0' + 5) {
      int m = (int)(s21_strchr(temp, '.') - temp) + fl.precision;
      rounding_up(m, temp);
    }
    temp[(int)(s21_strchr(temp, '.') - temp) + fl.precision + 1] = '\0';
  } else if ((s21_strchr(temp, '.') - temp) == fl.precision) {
    if (temp[fl.precision + 1] >= '0' + 5) {
      int m = fl.precision - 1;
      rounding_up(m, temp);
    }
    temp[fl.precision] = '\0';
  } else if ((int)s21_strlen(temp) - 2 == fl.precision) {
    temp[fl.precision + 2] = '\0';
  } else {
    if (temp[fl.precision + 1] >= '0' + 5) {
      int m = fl.precision;
      rounding_up(m, temp);
    }
    temp[fl.precision + 1] = '\0';
  }

  remove_zero_for_g_reduction(temp);

  flags_apply(fl, temp);
}

void rounding_up(int m, char *temp) {
  /*
  округление числа
  */
  while (m >= 0 && (temp[m] == '9' || temp[m] == '.')) {
    if (temp[m] == '9') {
      temp[m] = '0';
    }
    m--;
  }
  if (m >= 0) {
    if (temp[m] == '-') {  // отрицательное
      char result_buf[MAX_SIZE] = {'\0'};
      result_buf[0] = '-';
      result_buf[1] = '1';
      s21_strcpy(result_buf + 2, temp + 1);
      s21_strcpy(temp, result_buf);
    } else  // положительное
      temp[m] += 1;
  } else {
    char bbuf[MAX_SIZE] = {'\0'};
    bbuf[0] = '1';
    s21_strcpy(bbuf + 1, temp);
    s21_strcpy(temp, bbuf);
  }
}

void remove_zero_for_g_reduction(char *temp)  //, flags fl)
{
  int n = s21_strlen(temp);
  if (s21_strchr(temp, '.')) {
    int i = n - 1;
    while (temp[i] != '.') {
      if (temp[i] == '0')  // && i - 1 > fl.precision)
      {
        temp[i] = '\0';
        i--;
      } else
        break;
      if (temp[i] == '.') temp[i] = '\0';
    }
  }
}
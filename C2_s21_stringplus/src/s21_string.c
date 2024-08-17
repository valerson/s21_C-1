#include "s21_string.h"

s21_size_t s21_strlen(const char *str)
/*
    возвращает длину строки
*/
{
  s21_size_t result = 0;
  while (str[result]) {
    result++;
  }
  return result;
}

int s21_strcmp(const char *str1, const char *str2)
/*
    лексикографическое сравнение первых n байтов строк
*/
{
  int n1 = s21_strlen(str1), n2 = s21_strlen(str2);
  int result = 0;
  for (int i = 0; i < (n1 > n2 ? n1 : n2); i++) {
    result = str1[i] - str2[i];
    if (result != 0) break;
  }
  return result;
}

int s21_strncmp(const char *dest, const char *src, s21_size_t n)
/*
    лексикографическое сравнение первых n байтов строк
*/
{
  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    result = dest[i] - src[i];
    if (result != 0) break;
  }
  return result;
}

char *s21_strcpy(char *toHere, const char *fromHere)
/*
    копирует строку из одного места в другое
*/
{
  int n = s21_strlen(fromHere);
  for (int i = 0; i < n; i++) {
    toHere[i] = fromHere[i];
  }
  toHere[n] = '\0';
  return toHere;
}

char *s21_strncpy(char *toHere, const char *fromHere, s21_size_t n)
/*
    копирует до n байт строки из одного места в другое
*/
{
  for (s21_size_t i = 0; i < n; i++) {
    toHere[i] = fromHere[i];
  }
  return toHere;
}

// char *s21_strcat(char *dest, const char *src)
// /*
//     дописывает строку src в конец dest
// */
// {
//   int m = s21_strlen(dest);
//   int i = 0;
//   for (; src[i]; i++) {
//     dest[m + i] = src[i];
//   }
//   dest[m + i] = '\0';
//   return dest;
// }

char *s21_strncat(char *dest, const char *src, s21_size_t n)
/*
    дописывает строку src в конец dest
*/
{
  int m = s21_strlen(dest);
  unsigned long i = m, j = 0;
  while (src[j] != '\0' && j < n) {
    dest[i] = src[j];
    i++;
    j++;
  }

  return dest;
}

char *s21_strchr(const char *str, int c)
/*
    возвращает адрес символа c в строке s, начиная с головы, или NULL, если
   строка s не содержит символ c
*/
{
  char *p = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++)
  // while (*str != '\0')
  {
    if (str[i] == c) {
      p = (char *)str + i;
      break;
    }
    // str++;
  }

  return p;
}

char *s21_strrchr(const char *str, int c)
/*
    возвращает адрес символа c в строке str, начиная с хвоста, или s21_NULL,
   если строка str не содержит символ c
*/
{
  char *p = s21_NULL;
  s21_size_t n = s21_strlen(str);
  str = str + n;
  int count = n;
  while (count >= 0) {
    if ((int)*str == c) {
      p = (char *)str;
      break;
    }
    str--;
    count--;
  }
  return p;
}

char *s21_strstr(const char *haystack, const char *needle)
/*
    находит первое вхождение строки needle в haystack
*/
{
  char *res = s21_NULL;
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = 0;
          break;
        }
      }
      if (found) {
        res = (char *)haystack + i;
        break;
      }
    }
  }
  return res;
}

char *s21_strtok(char *str, const char *delim)
/*
    преобразует строку в последовательность токенов - wiki

    реализовал по этому описанию.
    char* strtok(char* str, const char* delim)
    Эта функция выполняет поиск в строке str подстроки, обрамленной с обеих
   сторон любым символом-разделителем из строки delim. В случае успешного поиска
   данная функция обрезает строку str. помещая символ '\0' в месте, где
   заканчивается найденная лексема. Таким образом, при повторном поиске лексемы
   в указанной строке str первым параметром следует указывать null. Так как
   strtok () модифицирует строку-оригинал, рекомендуется предварительно
   сохранять копию последней. источник -
   https://studfile.net/preview/5315455/page:6/

*/
{
  static char *next_token = s21_NULL;
  char *start_token = s21_NULL;
  int flag = 1;
  // int count = 0;

  if (str != s21_NULL) {
    //  Устанавливаем указатель на начало если str не равно NULL. Начальный
    //  элемент не должен быть в delim
    next_token = str;
  } else if (next_token == s21_NULL || *next_token == '\0')
    flag = 0;  // Если строка пустая или next_token равен NULL, возвращаем NULL

  if (flag) {
    // Пропускаем любые начальные разделители
    while (*next_token != '\0' && s21_strchr(delim, *next_token) != s21_NULL) {
      next_token++;
    }

    // Если достигли конца строки, возвращаем NULL
    if (*next_token == '\0') return s21_NULL;

    // Запоминаем начало токена
    start_token = next_token;
    //  Находим конец токена
    while (*next_token != '\0' && s21_strchr(delim, *next_token) == s21_NULL) {
      next_token++;
    }

    // Если мы не достигли конца строки, заменяем текущий разделитель на '\0' и
    // смещаем next_token
    if (*next_token != '\0') {
      *next_token = '\0';
      next_token++;
    } else {
      // Если мы достигли конца строки, устанавливаем next_token в NULL
      next_token = s21_NULL;
    }
  }

  return start_token;
}

char *s21_strpbrk(const char *str1, const char *str2)
/*
Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.
*/
{
  char *res = s21_NULL;
  while (*str1 != '\0') {
    if (s21_strchr(str2, *str1) != s21_NULL) {
      res = (char *)str1;
      break;
    }
    str1++;
  }
  return res;
}

char *s21_strerror(int errnum)
/*
    возвращает строковое представление сообщения об ошибке errno
*/
{
  static char result[100] = {0};  // статик - чтобы можно было вернуть указатель
                                  // на переменную внутри функции
  ARRAY;  // вставляк=ем массив ошибок (см. хе файл)
  if (errnum < ERROR_COUNT_MAX && errnum >= 0)
    s21_strcpy(result, s21_sys_errlist[errnum]);
  else {
    char temp[100] = ERROR_UNKNOWN;
    number_add_text(errnum, temp);
    s21_strcpy(result, temp);
  }
  return result;
}

void number_add_text(long long int number, char *text)
/*
    добавляет к тексту число в символьном виде с учетом знака
    нужно для функции стреррор в части отражение анкноу еррор номер...
*/
{
  int n = s21_strlen(text);
  char *result = text;
  result += n;
  // если число минимальное, то сращзу его и сохраняем в текст, потому что
  // миниму -.....08, а максимум ..... 07 лень переписывать всю функцию
  if (number == INT64_MIN) {
    s21_strcpy(text, "-9223372036854775808");
  } else {
    if (number < 0) {
      *result = '-';
      result++;
      number *= -1;
      n++;  // потом вернуть на начало чтобы text[]
    }
    //   двигаем указатель на число разрядов числа в уонец
    long long int i = number;
    do {
      result++;
      i = i / 10;
    } while (i);
    *result = '\0';

    // добавляем к строке число пораздядно
    do {
      result--;
      *result = '0' + number % 10;
      number = number / 10;
    } while (number);
    result -= n;
  }
}

void *s21_memchr(void *str, int c, s21_size_t n)
/*
    возвращает указатель на первое вхождение значения c среди первых n байтов s
   или NULL, если не найдено
*/
{
  char *p = s21_NULL;
  s21_size_t i = 0;
  while (i != n) {
    if (*(char *)str == (char)c)  // все привели к чар
    {
      p = (void *)str;
      break;
    }
    if (i == n) {
      break;
    }
    i++;
    str++;
  }
  return p;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n)
/*
    сравнивает первые n символов в областях памяти
*/
{
  int result = 0;
  unsigned char *ps1 = (unsigned char *)str1;
  unsigned char *ps2 = (unsigned char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (*(ps1 + i) != *(ps2 + i)) {
      result = *(ps1 + i) - *(ps2 + i);
      break;
    }
  }
  return result;
}

void *s21_memset(void *str, int c, s21_size_t n)
/*
    заполняет область памяти длинй size байт байтом value
    memset(str,'_',12); // заполнить первые 12 байт символом '_'
*/
{
  char *p = (char *)str;
  for (s21_size_t i = 0; i < n; i++) p[i] = c;

  return p;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n)
/*
    копирует n байт из области памяти src в dest, которые не должны
   пересекаться, в противном случае результат не определён (возможно как
   правильное копирование, так и нет)
*/
{
  char *pdest = dest;
  char *psrc = (char *)src;
  for (s21_size_t i = 0; i < n; i++, pdest++, psrc++) {
    *pdest = *psrc;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2)
/*
    Вычисляет длину начального сегмента str1, который полностью состоит из
   символов, не входящих в str2.
*/
{
  s21_size_t count = 0, n = s21_strlen(str1), i = 0;
  while (i < n) {
    if (s21_strchr(str2, str1[i]) == 0)
      count++;
    else
      break;
    i++;
  }
  return count;
}

void *s21_to_upper(const char *str)
/*
Возвращает копию строки (str), преобразованной в верхний регистр. В случае
какой-либо ошибки следует вернуть значение NULL.
*/
{
  int flag = 0;
  static char str_copy[MAX_SIZE] = {
      '\0'};  // статик потому что иначе выдает варнинг warning: address of
              // stack memory associated with local variable 'str_copy' returned
              // [-Wreturn-stack-address]
  if (str) {
    s21_size_t i = s21_strlen(str);
    while ((int)i >= 0) {
      if (str[i] >= 'a' && str[i] <= 'z')
        str_copy[i] = str[i] - 32;
      else
        str_copy[i] = str[i];
      i--;
    }
    flag = 1;
  }
  return flag ? str_copy : s21_NULL;
}

void *s21_to_lower(const char *str)
/*
Возвращает копию строки (str), преобразованной в нижний регистр. В случае
какой-либо ошибки следует вернуть значение NULL.
*/
{
  int flag = 0;
  static char str_copy[MAX_SIZE] = {
      '\0'};  // статик потому что иначе выдает варнинг warning: address of
              // stack memory associated with local variable 'str_copy' returned
              // [-Wreturn-stack-address]
  if (str) {
    s21_size_t i = s21_strlen(str);
    while ((int)i >= 0) {
      if (str[i] >= 'A' && str[i] <= 'Z')
        str_copy[i] = str[i] + 32;
      else
        str_copy[i] = str[i];
      i--;
    }
    flag = 1;
  }
  return flag ? str_copy : s21_NULL;
}

// эта версия работает на м-процессорах и не требует каллок/маллок и фри
// соответственно, но не работае на линухе void *s21_insert(const char *src,
// const char *str, size_t start_index)
// /*
// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src). В случае какой-либо
// ошибки следует вернуть значение NULL.
// */
// {
//   s21_size_t src_len = 0;
//   s21_size_t str_len = 0;
//   char *result = s21_NULL;
//   if (src != s21_NULL) {
//     src_len = s21_strlen(src);
//   }
//   if (str != s21_NULL) {
//     str_len = s21_strlen(str);
//   }
//   if (start_index <= src_len) {
//     char temp[MAX_SIZE] = {'\0'};
//     result = temp;
//     for (s21_size_t i = 0; i < start_index; i++) {
//       result[i] = src[i];
//     }
//     for (s21_size_t i = start_index; i < start_index + str_len; i++) {
//       result[i] = str[i - start_index];
//     }
//     for (s21_size_t i = start_index + str_len; i < src_len + str_len; i++) {
//       result[i] = src[i - str_len];
//     }
//   }
//   return (void *)result;
// }

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_src = s21_NULL;
  s21_size_t src_len = 0;
  s21_size_t str_len = 0;
  if (src != s21_NULL) {
    src_len = s21_strlen(src);
  }
  if (str != s21_NULL) {
    str_len = s21_strlen(str);
  }
  if (start_index <= src_len) {
    s21_size_t new_len = src_len + str_len;
    new_src = calloc(new_len + 1, sizeof(char));

    for (s21_size_t i = 0; i < start_index; i++) {
      new_src[i] = src[i];
    }
    for (s21_size_t i = start_index; i < start_index + str_len; i++) {
      new_src[i] = str[i - start_index];
    }
    for (s21_size_t i = start_index + str_len; i < src_len + str_len; i++) {
      new_src[i] = src[i - str_len];
    }
  }
  return new_src;
}

// эта версия работает на м-процессорах и не требует каллок/маллок и фри
// соответственно, но не работае на линухе
// void *s21_trim(const char *src, const char *trim_chars)
// /*
// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src). В
// случае какой-либо ошибки следует вернуть значение NULL.
// */
// {
//   char *src_new = s21_NULL;
//   if (src) {
//     char temp[MAX_SIZE] = {'\0'};
//     src_new = temp;
//     s21_size_t len = s21_strlen(src);

//     // убираем символы вначале строки
//     while ((s21_strchr(trim_chars, *src) && s21_strlen(src)) ||
//            (trim_chars && *src == ' '))
//       src++;
//     for (s21_size_t i = 0; i < len; i++) src_new[i] = src[i];

//     // убираем символы в конце строки
//     s21_size_t i = s21_strlen(src_new);
//     while ((s21_strchr(trim_chars, src_new[i]) && s21_strlen(src)) ||
//            (trim_chars && src_new[i] == ' '))
//       i--;
//     src_new[i + 1] = '\0';
//   }
//   return src_new;
// }

void *s21_trim(const char *src, const char *trim_chars) {
  /*
   Возвращает новую строку, в которой удаляются все начальные и конечные
   вхождения набора заданных символов (trim_chars) из данной строки (src).
   В случае какой-либо ошибки следует вернуть значение NULL.
  */

  if (src == s21_NULL || trim_chars == s21_NULL) {
    return s21_NULL;
  }

  const char *start = src;
  const char *end = src + s21_strlen(src) - 1;

  while (*start && s21_strchr(trim_chars, *start)) {
    start++;
  }

  while (end > start && s21_strchr(trim_chars, *end)) {
    end--;
  }

  s21_size_t trimmed_len = end - start + 1;
  char *trimmed = (char *)malloc(trimmed_len + 1);
  if (trimmed) {
    s21_strncpy(trimmed, start, trimmed_len);
    trimmed[trimmed_len] = '\0';
  }

  return trimmed;
}

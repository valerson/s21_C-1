#ifndef S21_TESTS_STRING_H
#define S21_TESTS_STRING_H
/*
тут смотрел
https://ru.wikipedia.org/wiki/Check_(библиотека_модульного_тестирования)
*/
#include <limits.h>  // для работы с константами различных типов (для тестов тиа INT_MIN, SHORT_MAX и тп)
#include <locale.h>  // для тестирования стринг и чар далее 127 номера по аскии
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// Подключаем заголовочный файл библиотеки.
#include <check.h>
#include <stdint.h>  // для коретного отажения размера интов

Suite *s21_memchr_test(void);
Suite *s21_memcmp_test(void);
Suite *s21_memcpy_test(void);
Suite *s21_memset_test(void);
Suite *s21_strncat_test(void);
Suite *s21_strchr_test(void);
Suite *s21_strncmp_test(void);
Suite *s21_strncpy_test(void);
Suite *s21_strcspn_test(void);
Suite *s21_strerror_test(void);
Suite *s21_strlen_test(void);
Suite *s21_strpbrk_test(void);
Suite *s21_strrchr_test(void);
Suite *s21_strstr_test(void);
Suite *s21_strtok_test(void);
Suite *s21_to_upper_test(void);
Suite *s21_to_lower_test(void);
Suite *s21_insert_test(void);
Suite *s21_trim_test(void);
Suite *s21_sprintf_test(void);
Suite *s21_sscanf_test(void);

#endif
#include "s21_tests_string.h"
// #include "s21_tests_quest_1_functions.h"
// #include "s21_tests_sprintf.h"

// Функция создания набора тестов.

/* ********************************************* MAIN HERE
 * ************************************ */
int main(void) {
  setlocale(LC_ALL, "en_US.UTF-8");

  Suite *list_suite[] = {
      s21_memchr_test(),   s21_memcmp_test(),   s21_memcpy_test(),
      s21_memset_test(),   s21_strncat_test(),  s21_strchr_test(),
      s21_strncmp_test(),  s21_strncpy_test(),  s21_strcspn_test(),
      s21_strerror_test(), s21_strlen_test(),   s21_strpbrk_test(),
      s21_strrchr_test(),  s21_strstr_test(),   s21_strtok_test(),
      s21_to_upper_test(), s21_to_lower_test(), s21_insert_test(),
      s21_trim_test(),     s21_sprintf_test(),  s21_sscanf_test()};

  int failed_count = 0;
  printf("\033[31m***************  START  TEST  ***************\033[0m\n");

  for (unsigned long i = 0; i < sizeof(list_suite) / sizeof(list_suite[0]);
       i++) {
    Suite *suite = list_suite[i];
    SRunner *suite_runner = srunner_create(suite);

    srunner_set_fork_status(suite_runner, CK_NOFORK);  // тестирование на утечки

    srunner_run_all(suite_runner, CK_NORMAL);

    failed_count += srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
  }

  printf("\033[31m***************   END  TEST   ***************\033[0m\n");
  printf("All test is finish. Result %d failed tests.\n", failed_count);
  return (failed_count == 0) ? 0 : 1;
}
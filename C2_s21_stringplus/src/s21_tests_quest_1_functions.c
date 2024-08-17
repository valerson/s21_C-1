#include "s21_sprintf.h"
#include "s21_tests_string.h"

// Функция тестирования какой-либо задачи.
START_TEST(test_memchr_1) {
  /* Исходный код теста. */
  char text_1[1024] = "aabbccddee";
  char c = 'c';
  int n = 2;
  ck_assert_ptr_eq(s21_memchr(text_1, c, n), memchr(text_1, c, n));
}
END_TEST
START_TEST(test_memchr_2) {
  char text_1[1024] = "aabbccddee";
  char c = 'c';
  size_t n = 5;
  ck_assert_ptr_eq(s21_memchr(text_1, c, n), memchr(text_1, c, n));
}
END_TEST
START_TEST(test_memchr_3) {
  char text_1[1024] = "aabbccddee";
  char c = 'z';
  size_t n = 10;
  ck_assert_ptr_eq(s21_memchr(text_1, c, n), memchr(text_1, c, n));
}
END_TEST
START_TEST(test_memchr_4) {
  char text_1[1024] = "aabbccddee";
  char c = 'e';
  size_t n = 10;
  ck_assert_ptr_eq(s21_memchr(text_1, c, n), memchr(text_1, c, n));
}
END_TEST
START_TEST(test_memchr_5) {
  char text_1[1024] = "aabbccddee";
  char c = 'a';
  size_t n = 2;
  ck_assert_ptr_eq(s21_memchr(text_1, c, n), memchr(text_1, c, n));
}
END_TEST
START_TEST(test_memchr_from_another_users) {
  char str1[10] = "Hello";
  ck_assert_mem_eq(s21_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);
  ck_assert_msg(s21_memchr(str1, 'h', 5) == s21_NULL,
                "Failed: Str == s21_NULL");
  char str2[10] = "Hellosdsfq";
  ck_assert_mem_eq(s21_memchr(str2, 'l', 5), memchr(str2, 'l', 5), 3);
  ck_assert_mem_eq(s21_memchr(str1, 'l', 0), memchr(str1, 'l', 0), 0);
}
END_TEST
START_TEST(empty_str) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(find_zero_in_string) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(find_simbol_in_string_in_start) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(find_simbol_in_string_in_end) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(find_num_in_string_in_mid) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(find_num_in_array_num) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST
START_TEST(find_float_in_array) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;

  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST
START_TEST(easy_test_string) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
START_TEST(memchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_4) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_7) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_8) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_9) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST
START_TEST(memchr_10) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_memcmp_1) {
  const char text_1[1024] = "aabbccddee";
  const char text_2[1024] = "abcde";
  size_t n = 3;
  ck_assert_int_lt(memcmp(text_1, text_2, n), 0);
  ck_assert_int_lt(s21_memcmp(text_1, text_2, n), 0);
}
END_TEST
START_TEST(test_memcmp_2) {
  const char text_1[1024] = "aabbccddee";
  const char text_2[1024] = "aabbzzzz";
  size_t n = 4;
  ck_assert_int_eq(s21_memcmp(text_1, text_2, n), memcmp(text_1, text_2, n));
}
END_TEST
START_TEST(test_memcmp_3) {
  const char text_1[1024] = "aabbccddee";
  const char text_2[1024] = "ffhhjj";
  size_t n = 3;
  ck_assert_int_lt(memcmp(text_1, text_2, n), 0);
  ck_assert_int_lt(s21_memcmp(text_1, text_2, n), 0);
}
END_TEST
START_TEST(test_memcmp_4) {
  const char text_1[1024] = "Ronaldo";
  const char text_2[1024] = "Messi";
  size_t n = 10;
  ck_assert_int_gt(memcmp(text_1, text_2, n), 0);
  ck_assert_int_gt(s21_memcmp(text_1, text_2, n), 0);
}
END_TEST
START_TEST(test_memcmp_5) {
  const char text_1[1024] = "A12";
  const char text_2[1024] = "A2";
  size_t n = 2;
  ck_assert_int_lt(memcmp(text_1, text_2, n), 0);
  ck_assert_int_lt(s21_memcmp(text_1, text_2, n), 0);
}
END_TEST
START_TEST(test_memcmp_from_another_users) {
  const char str1[2048] = "test";
  const char str2[2048] = "teSt";
  int n = 4;
  ck_assert_int_gt(memcmp(str1, str2, n), 0);
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);

  const char str1_1[2048] = "Hello";
  const char str2_1[2048] = "Hello";
  n = 6;
  ck_assert_int_eq(s21_memcmp(str1_1, str2_1, n), memcmp(str1_1, str2_1, n));

  const char str1_2[2048] = "Hello";
  const char str2_2[2048] = "Help";
  n = 4;
  ck_assert_int_lt(memcmp(str1_2, str2_2, n), 0);
  ck_assert_int_lt(s21_memcmp(str1_2, str2_2, n), 0);

  const char str1_3[2048] = "Help";
  const char str2_3[2048] = "Hello";
  n = 4;
  ck_assert_int_gt(memcmp(str1_3, str2_3, n), 0);
  ck_assert_int_gt(s21_memcmp(str1_3, str2_3, n), 0);

  const char str1_4[2048] = "Help";
  const char str2_4[2048] = "Hello";
  n = 3;
  ck_assert_int_eq(s21_memcmp(str1_4, str2_4, n), memcmp(str1_4, str2_4, n));

  const char str1_5[2048] = "Hello";
  const char str2_5[2048] = "";
  n = 4;
  ck_assert_int_gt(memcmp(str1_5, str2_5, n), 0);
  ck_assert_int_gt(s21_memcmp(str1_5, str2_5, n), 0);

  const char str1_6[2048] = "";
  const char str2_6[2048] = "";
  n = 1;
  ck_assert_int_eq(s21_memcmp(str1_6, str2_6, n), memcmp(str1_6, str2_6, n));

  const char str1_7[2048] = "gsafh";
  const char str2_7[2048] = "dhkjfhs";
  n = 0;
  ck_assert_int_eq(s21_memcmp(str1_7, str2_7, n), memcmp(str1_7, str2_7, n));

  const char str1_8[2048] = "test\0test";
  const char str2_8[2048] = "test";
  n = 10;
  ck_assert_int_gt(memcmp(str1_8, str2_8, n), 0);
  ck_assert_int_gt(s21_memcmp(str1_8, str2_8, n), 0);

  const char str1_10[2048] = "t\200";
  const char str2_10[2048] = "t\0";
  n = 2;
  ck_assert_int_gt(memcmp(str1_10, str2_10, n), 0);
  ck_assert_int_gt(s21_memcmp(str1_10, str2_10, n), 0);
}
END_TEST
START_TEST(zero_byte) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(first_byte_in_string) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(register_test) {
  char str1[] = "aboba";
  char str2[] = "Aboba";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(zero_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(first_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1234";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(two_byte_in_num) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(two_byte_long_two_num) {
  char str1[] = "13";
  char str2[] = "1234";
  int n = 2;

  ck_assert_int_gt(memcmp(str1, str2, n), 0);
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST
START_TEST(two_byte_long_first_num) {
  char str1[] = "134567";
  char str2[] = "1234";
  int n = 2;

  ck_assert_int_gt(memcmp(str1, str2, n), 0);
  ck_assert_int_gt(s21_memcmp(str1, str2, n), 0);
}
END_TEST
START_TEST(eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(not_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
  int n = 71;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
START_TEST(memcmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 13;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_6) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 2;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_10) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_11) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 4;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_13) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_14) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_15) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(memcmp_16) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_memcpy_1) {
  const char *text = "Spartak-champion";
  int n = s21_strlen(text);
  char res_1[2048] = {0};
  char res_2[2048] = {0};
  s21_memcpy(res_1, text, n + 1);
  memcpy(res_2, text, n + 1);
  ck_assert_str_eq(res_1, res_2);
}
END_TEST
START_TEST(test_memcpy_2) {
  const char *text = "asdfghjkl;'";
  s21_size_t n = 3;
  char res_1[2048] = {0};
  char res_2[2048] = {0};
  s21_memcpy(res_1, text, n);
  memcpy(res_2, text, n);
  ck_assert_str_eq(res_1, res_2);
}
END_TEST
START_TEST(test_memcpy_3) {
  const char *text = "0123456789-+";
  s21_size_t n = 10;
  char res_1[2048] = {0};
  char res_2[2048] = {0};
  s21_memcpy(res_1, text, n);
  memcpy(res_2, text, n);
  ck_assert_str_eq(res_1, res_2);
}
END_TEST
START_TEST(test_memcpy_4) {
  const char *text = "qwertyuiop";
  s21_size_t n = 2;
  char res_1[100] = {0};
  char res_2[100] = {0};
  ck_assert_str_eq(s21_memcpy(res_1, text, n), memcpy(res_2, text, n));
}
END_TEST
START_TEST(test_memcpy_5) {
  const char *text = ";'[]{}||";
  s21_size_t n = 4;
  char res_1[100] = {0};
  char res_2[100] = {0};
  ck_assert_str_eq(s21_memcpy(res_1, text, n), memcpy(res_2, text, n));
}
END_TEST
START_TEST(hate_test) {
  char src[] = "i hate memcmp";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];

  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);

  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
START_TEST(memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST
START_TEST(memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memset_1) {
  char text_1[1024] = "This is string for test s21_memset function.";
  char text_2[1024] = "This is string for test s21_memset function.";
  char c = 'Q';
  size_t n = 5;
  s21_memset(text_1, c, n);
  memset(text_2, c, n);
  ck_assert_int_eq(strcmp(text_1, text_2), 0);
}
END_TEST
START_TEST(test_memset_2) {
  char text_1[1024] = "This is string for test s21_memset function.";
  char text_2[1024] = "This is string for test s21_memset function.";
  char c = 'Q';
  size_t n = 15;
  s21_memset(text_1, c, n);
  memset(text_2, c, n);
  ck_assert_int_eq(strcmp(text_1, text_2), 0);
}
END_TEST
START_TEST(test_memset_3) {
  char text_1[1024] = "This is string for test s21_memset function.";
  char text_2[1024] = "This is string for test s21_memset function.";
  char c = 'Q';
  size_t n = 100;
  s21_memset(text_1, c, n);
  memset(text_2, c, n);
  ck_assert_int_eq(strcmp(text_1, text_2), 0);
}
END_TEST
START_TEST(test_memset_4) {
  char text_1[1024] = "This is string for test s21_memset function.";
  char text_2[1024] = "This is string for test s21_memset function.";
  char c = '_';
  size_t n = 10;
  s21_memset(text_1, c, n);
  memset(text_2, c, n);
  ck_assert_int_eq(strcmp(text_1, text_2), 0);
}
END_TEST
START_TEST(test_memset_5) {
  char text_1[1024] = "This is string for test s21_memset function.";
  char text_2[1024] = "This is string for test s21_memset function.";
  int c = '5';
  size_t n = 15;
  s21_memset(text_1, c, n);
  memset(text_2, c, n);
  ck_assert_int_eq(strcmp(text_1, text_2), 0);
}
END_TEST
START_TEST(aboba_test) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(empty) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(replace_on_register_sim) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'A';
  s21_size_t n_byte = 3;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(replace_on_register_num) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(long_string) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;

  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  memset(s1, ch, n);
  s21_memset(s2, ch, n);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST
START_TEST(memset_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST
START_TEST(memset_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST
START_TEST(memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST
START_TEST(memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST
START_TEST(memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_strncat_1) {
  char text_1[1024] = "Test";
  const char text_2[1024] = " - is good!";
  size_t n = 5;
  s21_strncat(text_1, text_2, n);
  char text_3[1024] = "Test";
  const char text_4[1024] = " - is good!";
  strncat(text_3, text_4, n);
  ck_assert_int_eq(strcmp(text_1, text_3), 0);
}
END_TEST
START_TEST(test_strncat_2) {
  char text_1[1024] = "Test";
  const char text_2[1024] = " - is good!";
  size_t n = 15;
  s21_strncat(text_1, text_2, n);
  char text_3[1024] = "Test";
  const char text_4[1024] = " - is good!";
  strncat(text_3, text_4, n);
  ck_assert_int_eq(strcmp(text_1, text_3), 0);
}
END_TEST
START_TEST(test_strncat_3) {
  char text_1[1024] = "Test";
  const char text_2[1024] = " - is good!";
  size_t n = 1;
  s21_strncat(text_1, text_2, n);
  char text_3[1024] = "Test";
  const char text_4[1024] = " - is good!";
  strncat(text_3, text_4, n);
  ck_assert_int_eq(strcmp(text_1, text_3), 0);
}
END_TEST
START_TEST(test_strncat_4) {
  char text_1[1024] = "Test";
  const char text_2[1024] = " - is good!";
  size_t n = 0;
  s21_strncat(text_1, text_2, n);
  char text_3[1024] = "Test";
  const char text_4[1024] = " - is good!";
  strncat(text_3, text_4, n);
  ck_assert_int_eq(strcmp(text_1, text_3), 0);
}
END_TEST
START_TEST(test_strncat_5) {
  char text_1[1024] = "Test";
  const char text_2[1024] = " - is good!";
  size_t n = 3;
  s21_strncat(text_1, text_2, n);
  char text_3[1024] = "Test";
  const char text_4[1024] = " - is good!";
  strncat(text_3, text_4, n);
  ck_assert_int_eq(strcmp(text_1, text_3), 0);
}
END_TEST
START_TEST(Hello_aboba) {
  char src[] = " aboba!!!";
  char res[5 + 10] = "Hello";
  char expected[5 + 10] = "Hello";

  s21_strncat(res, src, 5);
  strncat(expected, src, 5);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(zero_first) {
  char src[] = " aboba!!!";
  char res[0 + 10] = "";
  char expected[0 + 10] = "";

  s21_strncat(res, src, 2);
  strncat(expected, src, 2);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(zero_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";

  s21_strncat(res, src, 4);
  strncat(expected, src, 4);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(any_letters_with_register) {
  char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
  char res[5 + 53] = "Hello";
  char expected[5 + 53] = "Hello";

  s21_strncat(res, src, 30);
  strncat(expected, src, 30);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(any_letters_with_register_and_num) {
  char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
  char res[5 + 59] = "Hello";
  char expected[5 + 59] = "Hello";

  s21_strncat(res, src, 28);
  strncat(expected, src, 28);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(any_letters_with_register_and_num_and_sim) {
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
  char res[5 + 65] = "Hello";
  char expected[5 + 65] = "Hello";

  s21_strncat(res, src, 31);
  strncat(expected, src, 31);

  ck_assert_str_eq(res, expected);
}
END_TEST
START_TEST(strncat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "My name is Polina.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST
START_TEST(strncat_15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "My name is Polina.";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(test_strchr_1) {
  const char text_1[1024] = "Test";
  char c = 'e';
  ck_assert_ptr_eq(s21_strchr(text_1, c), strchr(text_1, c));
}
END_TEST
START_TEST(test_strchr_2) {
  const char text_1[1024] = "TeTst";
  char c = 'T';
  ck_assert_ptr_eq(s21_strchr(text_1, c), strchr(text_1, c));
}
END_TEST
START_TEST(test_strchr_3) {
  const char text_1[1024] = "Test";
  char c = 't';
  ck_assert_str_eq(s21_strchr(text_1, c), strchr(text_1, c));
}
END_TEST
START_TEST(test_strchr_4) {
  const char text_1[1024] = "Test";
  char c = 'z';
  ck_assert_ptr_eq(s21_strchr(text_1, c), strchr(text_1, c));
}
END_TEST
START_TEST(test_strchr_5) {
  const char text_1[1024] = "TeSSSt";
  char c = 'S';
  ck_assert_str_eq(s21_strchr(text_1, c), strchr(text_1, c));
}
END_TEST
START_TEST(abobasnutsa_find_a) {
  char src[] = "abobasnutsa";
  char find = 'a';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
START_TEST(abobasnutAsa_find_A) {
  char src[] = "abobasnutAsa";
  char find = 'A';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
START_TEST(abobasnutA1sa_find_1) {
  char src[] = "abobasnutA1sa";
  char find = '1';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
START_TEST(abobasnutAsa_find_Z) {
  char src[] = "abobasnutAsa";
  char find = 'Z';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
START_TEST(abobasnutAsa_find_3) {
  char src[] = "abobasnutAsa";
  char find = '3';

  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
// START_TEST(empty_src)
// {
//     char src[] = "";
//     char find = '3';
//     ck_assert_pstr_eq(s21_strchr(src, find),
//                       strchr(src, find));
// }
// END_TEST
START_TEST(strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST
START_TEST(strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strncmp_1) {
  const char text_1[1024] = "Text1. First word.";
  const char text_2[1024] = "Text2. First word.";
  size_t n = 4;
  ck_assert_int_eq(s21_strncmp(text_1, text_2, n), strncmp(text_1, text_2, n));
}
END_TEST
START_TEST(test_strncmp_2) {
  const char text_1[1024] = "Text1. First word.";
  const char text_2[1024] = "Text2. First word.";
  size_t n = 10;
  ck_assert_int_eq(s21_strncmp(text_1, text_2, n), strncmp(text_1, text_2, n));
}
END_TEST
START_TEST(test_strncmp_3) {
  const char text_1[1024] = "Text1. First word.";
  const char text_2[1024] = "Text2. First word.";
  size_t n = 2;
  ck_assert_int_eq(s21_strncmp(text_1, text_2, n), strncmp(text_1, text_2, n));
}
END_TEST
START_TEST(test_strncmp_4) {
  const char text_1[1024] = "Text1. First word.";
  const char text_2[1024] = "Text2. First word.";
  size_t n = 1;
  ck_assert_int_eq(s21_strncmp(text_1, text_2, n), strncmp(text_1, text_2, n));
}
END_TEST
START_TEST(test_strncmp_5) {
  const char text_1[1024] = "Text1. First word.";
  const char text_2[1024] = "Text2. First word.";
  size_t n = 0;
  ck_assert_int_eq(s21_strncmp(text_1, text_2, n), strncmp(text_1, text_2, n));
}
END_TEST
START_TEST(floppa_) {
  char str1[] = "floppa";
  char str2[] = "";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(_floppa) {
  char str1[] = "";
  char str2[] = "floppa";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(floppa_floppa) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 6;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(floppa_floppa_zero_byte) {
  char str1[] = "floppabazbazkotya";
  char str2[] = "floppabaz";
  s21_size_t n_byte = 10;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(floppa_floppa_one_byte) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 1;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  ck_assert_int_eq(got, expected);
}
END_TEST
START_TEST(strncmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, worldj";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_3) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_4) {
  char s1[] = "f";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_5) {
  char s1[] = "";
  char s2[] = "j";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 19;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_7) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_8) {
  char s1[] = "g124243425";
  char s2[] = "124243424";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_strncpy_1) {
  const char text_1[1024] = "Text1. First word.";
  char text_2[1024] = "";
  const char text_3[1024] = "Text1. First word.";
  char text_4[1024] = "";
  size_t n = 6;
  s21_strncpy(text_2, text_1, n);
  strncpy(text_4, text_3, n);
  ck_assert_int_eq(strcmp(text_2, text_4), 0);
}
END_TEST
START_TEST(test_strncpy_2) {
  const char text_1[1024] = "Text1. First word.";
  char text_2[1024] = "";
  const char text_3[1024] = "Text1. First word.";
  char text_4[1024] = "";
  size_t n = 2;
  s21_strncpy(text_2, text_1, n);
  strncpy(text_4, text_3, n);
  ck_assert_int_eq(strcmp(text_2, text_4), 0);
}
END_TEST
START_TEST(test_strncpy_3) {
  const char text_1[1024] = "Text1. First word.";
  char text_2[1024] = "AA";
  const char text_3[1024] = "Text1. First word.";
  char text_4[1024] = "AA";
  size_t n = 6;
  s21_strncpy(text_2, text_1, n);
  strncpy(text_4, text_3, n);
  ck_assert_int_eq(strcmp(text_2, text_4), 0);
}
END_TEST
START_TEST(test_strncpy_4) {
  const char text_1[1024] = "Text1. First word.";
  char text_2[1024] = "";
  const char text_3[1024] = "Text1. First word.";
  char text_4[1024] = "";
  size_t n = 30;
  s21_strncpy(text_2, text_1, n);
  strncpy(text_4, text_3, n);
  ck_assert_int_eq(strcmp(text_2, text_4), 0);
}
END_TEST
START_TEST(test_strncpy_5) {
  const char text_1[1024] = "Text1. First word.";
  char text_2[1024] = "";
  const char text_3[1024] = "Text1. First word.";
  char text_4[1024] = "";
  size_t n = 0;
  s21_strncpy(text_2, text_1, n);
  strncpy(text_4, text_3, n);
  ck_assert_int_eq(strcmp(text_2, text_4), 0);
}
END_TEST
START_TEST(empty_strncpy) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_int_eq(strcmp(res, exp), 0);
}
END_TEST
START_TEST(zero_byte_strncpy) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(empty_src_strncpy) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(string_strncpy) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;

  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);

  ck_assert_str_eq(res, exp);
}
END_TEST
START_TEST(strncpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST
START_TEST(strncpy_2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST
START_TEST(strncpy_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST
START_TEST(strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST
START_TEST(strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST
START_TEST(strncpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strcspn_1) {
  const char text_1[1024] = "qwerty";
  const char text_2[1024] = "rt";
  ck_assert_int_eq(s21_strcspn(text_1, text_2), strcspn(text_1, text_2));
}
END_TEST
START_TEST(test_strcspn_2) {
  const char text_1[1024] = "qwerty";
  const char text_2[1024] = "zz";
  ck_assert_int_eq(s21_strcspn(text_1, text_2), strcspn(text_1, text_2));
}
END_TEST
START_TEST(test_strcspn_3) {
  const char text_1[1024] = "";
  const char text_2[1024] = "b";
  ck_assert_int_eq(s21_strcspn(text_1, text_2), strcspn(text_1, text_2));
}
END_TEST
START_TEST(test_strcspn_4) {
  const char text_1[1024] = "aaaaaaaaaaaaab";
  const char text_2[1024] = "a";
  ck_assert_int_eq(s21_strcspn(text_1, text_2), strcspn(text_1, text_2));
}
END_TEST
START_TEST(test_strcspn_5) {
  const char text_1[1024] = "qwerty";
  const char text_2[1024] = "";
  ck_assert_int_eq(s21_strcspn(text_1, text_2), strcspn(text_1, text_2));
}
END_TEST
START_TEST(empty_strcspn) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(gora_) {
  char src[] = "gora";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(_gora) {
  char src[] = "";
  char res[] = "gora";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(any_register) {
  char src[] = "gora";
  char res[] = "gOra";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(num_num) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(long_num_num) {
  char src[] = "12345";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(num_long_num) {
  char src[] = "123";
  char res[] = "12345";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(basic_test) {
  char src[] = "absD";
  char res[] = "aD";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
START_TEST(strcspn_1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST
START_TEST(strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_strerror_1) {
  int n = 0;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
}
END_TEST
START_TEST(test_strerror_2) {
  int n = 107;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
}
END_TEST
START_TEST(test_strerror_3) {
  int n = 130;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
}
END_TEST
START_TEST(test_strerror_4) {
  int n = 150;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
}
END_TEST
START_TEST(test_strerror_5) {
  int n = 15;
  ck_assert_str_eq(s21_strerror(n), strerror(n));
}
END_TEST
START_TEST(all_std_errors) {
  for (int i = -1000; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST
START_TEST(negative_err_code) {
  const char *got = s21_strerror(-1);
  char *expected = strerror(-1);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(test_strlen_1) {
  const char text_1[1024] = "qwerty";
  ck_assert_int_eq(s21_strlen(text_1), strlen(text_1));
}
END_TEST
START_TEST(test_strlen_2) {
  const char text_1[1024] = "qwerty";
  ck_assert_int_eq(s21_strlen(text_1), strlen(text_1));
}
END_TEST
START_TEST(test_strlen_3) {
  const char text_1[1024] = "qw";
  ck_assert_int_eq(s21_strlen(text_1), strlen(text_1));
}
END_TEST
START_TEST(test_strlen_4) {
  const char text_1[1024] = "";
  ck_assert_int_eq(s21_strlen(text_1), strlen(text_1));
}
END_TEST
START_TEST(test_strlen_5) {
  const char text_1[1024] = "q w e r t y ";
  ck_assert_int_eq(s21_strlen(text_1), strlen(text_1));
}
END_TEST
START_TEST(empty_strlen) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(abosal) {
  char src[] = "abosal";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(num) {
  char src[] = "987623456124678";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(string_strlen) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(abosal_no_dal) {
  char src[] = "abosal\0no_dal";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(dai_mne_pen) {
  char src[] = "dai_mne_pen(321321)...123...123";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(Floppy_disk) {
  char src[] = "Floppy_disk";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(Russky_kot_Shlepa) {
  char src[] = "Russky_kot_Shlepa";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(kot_Vasily) {
  char src[] = "kot Vasily";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(floppa) {
  char src[] = "floppa";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_2) {
  char str[] =
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_5) {
  char str[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_7) {
  char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_8) {
  char str[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST
START_TEST(strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_strpbrk_1) {
  const char str1[2048] = "hello";
  const char str2[2048] = "hel";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(test_strpbrk_2) {
  const char str1[2048] = "hello";
  const char str2[2048] = "elo";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(test_strpbrk_3) {
  const char str1[2048] = "hello";
  const char str2[2048] = "z";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(test_strpbrk_4) {
  const char str1[2048] = "hello";
  const char str2[2048] = "ll";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(test_strpbrk_5) {
  const char str1[2048] = "hello";
  const char str2[2048] = "o";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(empty_strpbrk) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(floppy_) {
  char str1[] = "floppy";
  char str2[] = "";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(_floppy) {
  char str1[] = "";
  char str2[] = "floppy";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(poki_doki_o) {
  char str1[] = "poki doki";
  char str2[] = "o";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(poki_doki_i) {
  char str1[] = "poki doki";
  char str2[] = "i";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(poki_doki_p) {
  char str1[] = "poki doki";
  char str2[] = "p";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(find_big_P) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(find_zero) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST
START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_strrchr_1) {
  const char str1[2048] = "hello";
  char c = 'l';
  ck_assert_str_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_strrchr_2) {
  const char str1[2048] = "hello";
  char c = 'h';
  ck_assert_str_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_strrchr_3) {
  const char str1[2048] = "hello";
  char c = 'z';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_strrchr_4) {
  const char str1[2048] = "hello";
  char c = 'e';
  ck_assert_str_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_strrchr_5) {
  const char str1[2048] = "hello";
  char c = 'e';
  ck_assert_ptr_eq(s21_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(empty_strrchr) {
  char str1[] = "";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(floppy__strrchr) {
  char str1[] = "floppy";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(_floppy_strrchr) {
  char str1[] = "";
  char str2 = 'f';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(poki_doki_o_strrchr) {
  char str1[] = "poki doki";
  char str2 = 'o';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(poki_doki_i_strrchr) {
  char str1[] = "poki doki";
  char str2 = 'i';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(poki_doki_p_strrchr) {
  char str1[] = "poki p dokip";
  char str2 = 'p';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(find_big_P_strrchr) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(find_zero_strrchr) {
  char str1[] = "123456789";
  char str2 = '0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
START_TEST(strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST
START_TEST(strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strstr_1) {
  char str1[2048] = "hello";
  const char str2[2048] = "hel";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(test_strstr_2) {
  char str1[2048] = "hello";
  const char str2[2048] = "llo";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(test_strstr_3) {
  char str1[2048] = "hello";
  const char str2[2048] = "zlo";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(test_strstr_4) {
  char str1[2048] = "hello";
  const char str2[2048] = "hel";
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(test_strstr_5) {
  char str1[2048] = "hello";
  const char str2[2048] = "o";
  ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(empty_string_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(empty_string_haystack) {
  char haystack[] = "";
  char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(empty_string_needle) {
  char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char needle[] = "";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(toxic_test) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(not_word_in_haystack) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(words_with_any_register) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(repeated_words) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(word_at_end) {
  char haystack[] = "22 321 123";
  char needle[] = "123";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(one_simbol_in_needle_and_haystack) {
  char haystack[] = "1";
  char needle[] = "1";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(one_simbol_in_needle) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(one_simbol_in_haystack) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
START_TEST(strstr_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_7) {
  char s1[] = "";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_8) {
  char s1[] = "69917020";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_9) {
  char s1[] = "69917020";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_12) {
  char s1[] = "sususususpicioussusususpicious";
  char s2[] = "susp";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST
START_TEST(strstr_13) {
  char s1[] = "sus";
  char s2[] = "suspi";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(test_strtok_1) {
  char str_fot_strtok[1024] = "test1/test2*test3/tes*t4";
  char str_fot_s21_strtok[1024] = "test1/test2*test3/tes*t4";
  const char sep[1024] = "/*";  // разделитель для стрток / и/или *
  char *res_strtok = strtok(str_fot_strtok, sep);
  char *res_s21_strtok = s21_strtok(str_fot_s21_strtok, sep);
  ck_assert_str_eq(res_s21_strtok, res_strtok);
  while (res_strtok != s21_NULL) {
    ck_assert_str_eq(res_s21_strtok, res_strtok);
    res_strtok = strtok(s21_NULL, sep);
    res_s21_strtok = s21_strtok(s21_NULL, sep);
  }
  ck_assert_ptr_eq(res_s21_strtok, res_strtok);
}
END_TEST
START_TEST(test_strtok_2) {
  char str_fot_strtok[1024] = "test1/test2*test3/tes*t4";
  char str_fot_s21_strtok[1024] = "test1/test2*test3/tes*t4";
  const char sep[1024] = "test";  // разделитель для стрток
  char *res_strtok = strtok(str_fot_strtok, sep);
  char *res_s21_strtok = s21_strtok(str_fot_s21_strtok, sep);
  ck_assert_str_eq(res_s21_strtok, res_strtok);
  while (res_strtok != s21_NULL) {
    ck_assert_str_eq(res_s21_strtok, res_strtok);
    res_strtok = strtok(s21_NULL, sep);
    res_s21_strtok = s21_strtok(s21_NULL, sep);
  }
  ck_assert_ptr_eq(res_s21_strtok, res_strtok);
}
END_TEST
START_TEST(test_strtok_3) {
  char str_fot_strtok[1024] = "test1/test2*test3/tes*t4";
  char str_fot_s21_strtok[1024] = "test1/test2*test3/tes*t4";
  const char sep[1024] = "*";  // разделитель для стрток
  char *res_strtok = strtok(str_fot_strtok, sep);
  char *res_s21_strtok = s21_strtok(str_fot_s21_strtok, sep);
  ck_assert_str_eq(res_s21_strtok, res_strtok);
  while (res_strtok != s21_NULL) {
    ck_assert_str_eq(res_s21_strtok, res_strtok);
    res_strtok = strtok(s21_NULL, sep);
    res_s21_strtok = s21_strtok(s21_NULL, sep);
  }
  ck_assert_ptr_eq(res_s21_strtok, res_strtok);
}
END_TEST
START_TEST(test_strtok_4) {
  char str_fot_strtok[1024] = "test1/test2*test3/tes*t4";
  char str_fot_s21_strtok[1024] = "test1/test2*test3/tes*t4";
  const char sep[1024] = "z";  // разделитель для стрток
  char *res_strtok = strtok(str_fot_strtok, sep);
  char *res_s21_strtok = s21_strtok(str_fot_s21_strtok, sep);
  ck_assert_str_eq(res_s21_strtok, res_strtok);
  while (res_strtok != s21_NULL) {
    ck_assert_str_eq(res_s21_strtok, res_strtok);
    res_strtok = strtok(s21_NULL, sep);
    res_s21_strtok = s21_strtok(s21_NULL, sep);
  }
  ck_assert_ptr_eq(res_s21_strtok, res_strtok);
}
END_TEST
START_TEST(test_strtok_5) {
  char str_fot_strtok[1024] = "test1/test2*test3/tes*t4";
  char str_fot_s21_strtok[1024] = "test1/test2*test3/tes*t4";
  const char sep[1024] = "/";  // разделитель для стрток
  char *res_strtok = strtok(str_fot_strtok, sep);
  char *res_s21_strtok = s21_strtok(str_fot_s21_strtok, sep);
  ck_assert_str_eq(res_s21_strtok, res_strtok);
  while (res_strtok != s21_NULL) {
    ck_assert_str_eq(res_s21_strtok, res_strtok);
    res_strtok = strtok(s21_NULL, sep);
    res_s21_strtok = s21_strtok(s21_NULL, sep);
  }
  ck_assert_ptr_eq(res_s21_strtok, res_strtok);
}
END_TEST
START_TEST(correct_token_string) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_int_eq((int)s21_strlen(got), (int)s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(hard_token_string) {
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(unary_delimiters) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(no_delims) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    ck_assert_ptr_null(got);
    ck_assert_ptr_null(expected);
  }
}
END_TEST
START_TEST(only_delims) {
  char str1[] = "++++++++";
  char str2[] = "++++++++";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_ptr_null(got);
  ck_assert_ptr_null(expected);
}
END_TEST
START_TEST(too_many_uses_non_segfault) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  int i = 5;
  while (i) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);
    i--;

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(even_n_of_delims) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(odd_n_of_delims) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(mixed_n_of_delims) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got && expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(hard_mixed) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(mixed_hard_incorrect) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    // ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));

    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";

  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);

  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);

  while (got || expected) {
    got = s21_strtok(NULL, delims);
    expected = strtok(NULL, delims);

    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
START_TEST(strtok_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
// START_TEST(strtok_11) {
//   char *s1 = s21_NULL;
//   char *s2 = s21_NULL;
//   char s3[] = "";
//   ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
// }
// END_TEST
START_TEST(strtok_12) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST
START_TEST(strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST
START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST
START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST
START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  // char s3[] = "Come here";
  // char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  // for (int i = 0; i < 5; i++)
  // {
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  // }
  // ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  // ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  // ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
}
END_TEST
START_TEST(strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST
START_TEST(strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_lower_test3) {
  char str[] = "Space created";
  char expected[] = "space created";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_3) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST
START_TEST(test_to_lower_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
}
END_TEST
START_TEST(test_to_upper_1) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_2) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_3) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
}
END_TEST
START_TEST(test_to_upper_7) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
}
END_TEST

START_TEST(insert_test1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(insert_test2) {
  char str2[] = "Hello, ";
  char src2[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src2, str2, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// START_TEST(insert_test3)
// {
//     char str[] = "";
//     char src[] = "";
//     s21_size_t index = 100;
//     char *expected = s21_NULL;
//     char *got = (char *)s21_insert(src, str, index);
//     ck_assert_str_eq(got, expected);
// }
// END_TEST
START_TEST(insert_test4) {
  char *src = NULL;
  char *str = NULL;
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(insert_test5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(insert_str_null) {
  char *str = NULL;
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space  ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(test_insert_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_str_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST
// START_TEST(test_insert_9)
// {
//     char s1[] = "wtf";
//     char *s3 = s21_NULL;
//     char *s4 = s21_NULL;
//     s21_size_t num = 0;
//     char *s2 = s21_insert(s1, s3, num);
//     ck_assert_pstr_eq(s4, s2);
// }
// END_TEST
// START_TEST(test_insert_10)
// {
//     char s1[] = "";
//     char *s3 = s21_NULL;
//     char *s4 = s21_NULL;
//     s21_size_t num = 0;
//     char *s2 = s21_insert(s1, s3, num);
//     ck_assert_pstr_eq(s2, s4);
// }
// END_TEST

START_TEST(all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = " ";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_memchr_test(void) {
  Suite *s21_suite_1 = suite_create("s21_memchr tests");

  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase *s21_memchr_tests = tcase_create("s21_memchr_test");

  // Добавление теста в тестовый набор.
  suite_add_tcase(s21_suite_1, s21_memchr_tests);
  // Добавление теста в группу тестов.
  tcase_add_test(s21_memchr_tests, test_memchr_1);
  tcase_add_test(s21_memchr_tests, test_memchr_2);
  tcase_add_test(s21_memchr_tests, test_memchr_3);
  tcase_add_test(s21_memchr_tests, test_memchr_4);
  tcase_add_test(s21_memchr_tests, test_memchr_5);
  tcase_add_test(s21_memchr_tests, test_memchr_from_another_users);
  tcase_add_test(s21_memchr_tests, empty_str);
  tcase_add_test(s21_memchr_tests, find_zero_in_string);
  tcase_add_test(s21_memchr_tests, find_simbol_in_string_in_start);
  tcase_add_test(s21_memchr_tests, find_simbol_in_string_in_end);
  tcase_add_test(s21_memchr_tests, find_num_in_string_in_mid);
  tcase_add_test(s21_memchr_tests, find_num_in_array_num);
  tcase_add_test(s21_memchr_tests, find_float_in_array);
  tcase_add_test(s21_memchr_tests, easy_test_string);
  tcase_add_test(s21_memchr_tests, memchr_1);
  tcase_add_test(s21_memchr_tests, memchr_2);
  tcase_add_test(s21_memchr_tests, memchr_3);
  tcase_add_test(s21_memchr_tests, memchr_4);
  tcase_add_test(s21_memchr_tests, memchr_5);
  tcase_add_test(s21_memchr_tests, memchr_6);
  tcase_add_test(s21_memchr_tests, memchr_7);
  tcase_add_test(s21_memchr_tests, memchr_8);
  tcase_add_test(s21_memchr_tests, memchr_9);
  tcase_add_test(s21_memchr_tests, memchr_10);

  return s21_suite_1;
}

Suite *s21_memcmp_test(void) {
  Suite *s21_suite_1 = suite_create("s21_memcmp tests");
  TCase *s21_memcmp_tests = tcase_create("s21_memcmp_test");

  suite_add_tcase(s21_suite_1, s21_memcmp_tests);
  tcase_add_test(s21_memcmp_tests, test_memcmp_1);
  tcase_add_test(s21_memcmp_tests, test_memcmp_2);
  tcase_add_test(s21_memcmp_tests, test_memcmp_3);
  tcase_add_test(s21_memcmp_tests, test_memcmp_4);
  tcase_add_test(s21_memcmp_tests, test_memcmp_5);
  tcase_add_test(s21_memcmp_tests, test_memcmp_from_another_users);
  tcase_add_test(s21_memcmp_tests, zero_byte);
  tcase_add_test(s21_memcmp_tests, first_byte_in_string);
  tcase_add_test(s21_memcmp_tests, register_test);
  tcase_add_test(s21_memcmp_tests, zero_byte_in_num);
  tcase_add_test(s21_memcmp_tests, first_byte_in_num);
  tcase_add_test(s21_memcmp_tests, two_byte_in_num);
  tcase_add_test(s21_memcmp_tests, two_byte_long_two_num);
  tcase_add_test(s21_memcmp_tests, two_byte_long_first_num);
  tcase_add_test(s21_memcmp_tests, eq_long_string);
  tcase_add_test(s21_memcmp_tests, not_eq_long_string);
  tcase_add_test(s21_memcmp_tests, memcmp_1);
  tcase_add_test(s21_memcmp_tests, memcmp_2);
  tcase_add_test(s21_memcmp_tests, memcmp_3);
  tcase_add_test(s21_memcmp_tests, memcmp_4);
  tcase_add_test(s21_memcmp_tests, memcmp_5);
  tcase_add_test(s21_memcmp_tests, memcmp_6);
  tcase_add_test(s21_memcmp_tests, memcmp_7);
  tcase_add_test(s21_memcmp_tests, memcmp_8);
  tcase_add_test(s21_memcmp_tests, memcmp_9);
  tcase_add_test(s21_memcmp_tests, memcmp_10);
  tcase_add_test(s21_memcmp_tests, memcmp_11);
  tcase_add_test(s21_memcmp_tests, memcmp_12);
  tcase_add_test(s21_memcmp_tests, memcmp_13);
  tcase_add_test(s21_memcmp_tests, memcmp_14);
  tcase_add_test(s21_memcmp_tests, memcmp_15);
  tcase_add_test(s21_memcmp_tests, memcmp_16);

  return s21_suite_1;
}

Suite *s21_memcpy_test(void) {
  Suite *s21_suite_1 = suite_create("s21_memcpy tests");
  TCase *s21_memcpy_tests = tcase_create("s21_memcpy_test");
  suite_add_tcase(s21_suite_1, s21_memcpy_tests);
  tcase_add_test(s21_memcpy_tests, test_memcpy_1);
  tcase_add_test(s21_memcpy_tests, test_memcpy_2);
  tcase_add_test(s21_memcpy_tests, test_memcpy_3);
  tcase_add_test(s21_memcpy_tests, test_memcpy_4);
  tcase_add_test(s21_memcpy_tests, test_memcpy_5);
  tcase_add_test(s21_memcpy_tests, hate_test);
  tcase_add_test(s21_memcpy_tests, zero_test_string);
  tcase_add_test(s21_memcpy_tests, any_empty);
  tcase_add_test(s21_memcpy_tests, zero_test_string_with_register);
  tcase_add_test(s21_memcpy_tests, zero_test_num);
  tcase_add_test(s21_memcpy_tests, one_byte_string);
  tcase_add_test(s21_memcpy_tests, one_byte_string_with_register);
  tcase_add_test(s21_memcpy_tests, one_byte_num);
  tcase_add_test(s21_memcpy_tests, basic_long_string);
  tcase_add_test(s21_memcpy_tests, long_string_with_register);
  tcase_add_test(s21_memcpy_tests, long_string_with_register_and_num);
  tcase_add_test(s21_memcpy_tests,
                 long_string_with_register_and_num_and_simbol);
  tcase_add_test(s21_memcpy_tests, memcpy_1);
  tcase_add_test(s21_memcpy_tests, memcpy_2);
  tcase_add_test(s21_memcpy_tests, memcpy_3);
  tcase_add_test(s21_memcpy_tests, memcpy_4);
  tcase_add_test(s21_memcpy_tests, memcpy_5);
  tcase_add_test(s21_memcpy_tests, memcpy_6);
  tcase_add_test(s21_memcpy_tests, memcpy_7);
  tcase_add_test(s21_memcpy_tests, memcpy_8);
  tcase_add_test(s21_memcpy_tests, memcpy_9);
  tcase_add_test(s21_memcpy_tests, memcpy_10);

  return s21_suite_1;
}

Suite *s21_memset_test(void) {
  Suite *s21_suite_1 = suite_create("s21_memset tests");
  TCase *s21_memset_tests = tcase_create("s21_memset_test");
  suite_add_tcase(s21_suite_1, s21_memset_tests);
  tcase_add_test(s21_memset_tests, test_memset_1);
  tcase_add_test(s21_memset_tests, test_memset_2);
  tcase_add_test(s21_memset_tests, test_memset_3);
  tcase_add_test(s21_memset_tests, test_memset_4);
  tcase_add_test(s21_memset_tests, test_memset_5);
  tcase_add_test(s21_memset_tests, aboba_test);
  tcase_add_test(s21_memset_tests, empty);
  tcase_add_test(s21_memset_tests, replace_on_register_sim);
  tcase_add_test(s21_memset_tests, replace_on_register_num);
  tcase_add_test(s21_memset_tests, long_string);
  tcase_add_test(s21_memset_tests, memset_1);
  tcase_add_test(s21_memset_tests, memset_2);
  tcase_add_test(s21_memset_tests, memset_3);
  tcase_add_test(s21_memset_tests, memset_4);
  tcase_add_test(s21_memset_tests, memset_5);
  tcase_add_test(s21_memset_tests, memset_6);

  return s21_suite_1;
}

Suite *s21_strncat_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strncat tests");
  TCase *s21_strncat_tests = tcase_create("s21_strncat_test");
  suite_add_tcase(s21_suite_1, s21_strncat_tests);
  tcase_add_test(s21_strncat_tests, test_strncat_1);
  tcase_add_test(s21_strncat_tests, test_strncat_2);
  tcase_add_test(s21_strncat_tests, test_strncat_3);
  tcase_add_test(s21_strncat_tests, test_strncat_4);
  tcase_add_test(s21_strncat_tests, test_strncat_5);
  tcase_add_test(s21_strncat_tests, Hello_aboba);
  tcase_add_test(s21_strncat_tests, zero_first);
  tcase_add_test(s21_strncat_tests, zero_last);
  tcase_add_test(s21_strncat_tests, any_letters_with_register);
  tcase_add_test(s21_strncat_tests, any_letters_with_register_and_num);
  tcase_add_test(s21_strncat_tests, any_letters_with_register_and_num_and_sim);
  tcase_add_test(s21_strncat_tests, strncat_1);
  tcase_add_test(s21_strncat_tests, strncat_2);
  tcase_add_test(s21_strncat_tests, strncat_3);
  tcase_add_test(s21_strncat_tests, strncat_4);
  tcase_add_test(s21_strncat_tests, strncat_5);
  tcase_add_test(s21_strncat_tests, strncat_6);
  tcase_add_test(s21_strncat_tests, strncat_7);
  tcase_add_test(s21_strncat_tests, strncat_8);
  tcase_add_test(s21_strncat_tests, strncat_9);
  tcase_add_test(s21_strncat_tests, strncat_10);
  tcase_add_test(s21_strncat_tests, strncat_11);
  tcase_add_test(s21_strncat_tests, strncat_12);
  tcase_add_test(s21_strncat_tests, strncat_13);
  tcase_add_test(s21_strncat_tests, strncat_14);
  tcase_add_test(s21_strncat_tests, strncat_15);

  return s21_suite_1;
}

Suite *s21_strchr_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strchr tests");
  TCase *s21_strchr_tests = tcase_create("s21_strchr_test");
  suite_add_tcase(s21_suite_1, s21_strchr_tests);
  tcase_add_test(s21_strchr_tests, test_strchr_1);
  tcase_add_test(s21_strchr_tests, test_strchr_2);
  tcase_add_test(s21_strchr_tests, test_strchr_3);
  tcase_add_test(s21_strchr_tests, test_strchr_4);
  tcase_add_test(s21_strchr_tests, test_strchr_5);
  tcase_add_test(s21_strchr_tests, abobasnutsa_find_a);
  tcase_add_test(s21_strchr_tests, abobasnutAsa_find_A);
  tcase_add_test(s21_strchr_tests, abobasnutA1sa_find_1);
  tcase_add_test(s21_strchr_tests, abobasnutAsa_find_Z);
  tcase_add_test(s21_strchr_tests, abobasnutAsa_find_3);
  tcase_add_test(s21_strchr_tests, strchr_1);
  tcase_add_test(s21_strchr_tests, strchr_2);
  tcase_add_test(s21_strchr_tests, strchr_3);
  tcase_add_test(s21_strchr_tests, strchr_4);
  tcase_add_test(s21_strchr_tests, strchr_5);
  tcase_add_test(s21_strchr_tests, strchr_6);
  tcase_add_test(s21_strchr_tests, strchr_7);
  tcase_add_test(s21_strchr_tests, strchr_8);

  return s21_suite_1;
}

Suite *s21_strncmp_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strncmp tests");
  TCase *s21_strncmp_tests = tcase_create("s21_strncmp_test");
  suite_add_tcase(s21_suite_1, s21_strncmp_tests);
  tcase_add_test(s21_strncmp_tests, test_strncmp_1);
  tcase_add_test(s21_strncmp_tests, test_strncmp_2);
  tcase_add_test(s21_strncmp_tests, test_strncmp_3);
  tcase_add_test(s21_strncmp_tests, test_strncmp_4);
  tcase_add_test(s21_strncmp_tests, test_strncmp_5);
  tcase_add_test(s21_strncmp_tests, floppa_);
  tcase_add_test(s21_strncmp_tests, _floppa);
  tcase_add_test(s21_strncmp_tests, floppa_floppa);
  tcase_add_test(s21_strncmp_tests, floppa_floppa_zero_byte);
  tcase_add_test(s21_strncmp_tests, floppa_floppa_one_byte);
  tcase_add_test(s21_strncmp_tests, strncmp_1);
  tcase_add_test(s21_strncmp_tests, strncmp_2);
  tcase_add_test(s21_strncmp_tests, strncmp_3);
  tcase_add_test(s21_strncmp_tests, strncmp_4);
  tcase_add_test(s21_strncmp_tests, strncmp_5);
  tcase_add_test(s21_strncmp_tests, strncmp_6);
  tcase_add_test(s21_strncmp_tests, strncmp_7);
  tcase_add_test(s21_strncmp_tests, strncmp_8);
  tcase_add_test(s21_strncmp_tests, strncmp_9);

  return s21_suite_1;
}

Suite *s21_strncpy_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strncpy tests");
  TCase *s21_strncpy_tests = tcase_create("s21_strncpy_test");
  suite_add_tcase(s21_suite_1, s21_strncpy_tests);
  tcase_add_test(s21_strncpy_tests, test_strncpy_1);
  tcase_add_test(s21_strncpy_tests, test_strncpy_2);
  tcase_add_test(s21_strncpy_tests, test_strncpy_3);
  tcase_add_test(s21_strncpy_tests, test_strncpy_4);
  tcase_add_test(s21_strncpy_tests, test_strncpy_5);
  tcase_add_test(s21_strncpy_tests, empty_strncpy);
  tcase_add_test(s21_strncpy_tests, zero_byte_strncpy);
  tcase_add_test(s21_strncpy_tests, empty_src_strncpy);
  tcase_add_test(s21_strncpy_tests, one_byte);
  tcase_add_test(s21_strncpy_tests, two_byte);
  tcase_add_test(s21_strncpy_tests, string_strncpy);
  tcase_add_test(s21_strncpy_tests, strncpy_1);
  tcase_add_test(s21_strncpy_tests, strncpy_2);
  tcase_add_test(s21_strncpy_tests, strncpy_3);
  tcase_add_test(s21_strncpy_tests, strncpy_4);
  tcase_add_test(s21_strncpy_tests, strncpy_5);
  tcase_add_test(s21_strncpy_tests, strncpy_6);

  return s21_suite_1;
}

Suite *s21_strcspn_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strcspn tests");
  TCase *s21_strcspn_tests = tcase_create("s21_strcspn_test");
  suite_add_tcase(s21_suite_1, s21_strcspn_tests);
  tcase_add_test(s21_strcspn_tests, test_strcspn_1);
  tcase_add_test(s21_strcspn_tests, test_strcspn_2);
  tcase_add_test(s21_strcspn_tests, test_strcspn_3);
  tcase_add_test(s21_strcspn_tests, test_strcspn_4);
  tcase_add_test(s21_strcspn_tests, test_strcspn_5);
  tcase_add_test(s21_strcspn_tests, empty_strcspn);
  tcase_add_test(s21_strcspn_tests, gora_);
  tcase_add_test(s21_strcspn_tests, _gora);
  tcase_add_test(s21_strcspn_tests, any_register);
  tcase_add_test(s21_strcspn_tests, num_num);
  tcase_add_test(s21_strcspn_tests, long_num_num);
  tcase_add_test(s21_strcspn_tests, num_long_num);
  tcase_add_test(s21_strcspn_tests, any_num);
  tcase_add_test(s21_strcspn_tests, num_with_letter);
  tcase_add_test(s21_strcspn_tests, num_with_letter2);
  tcase_add_test(s21_strcspn_tests, basic_test);
  tcase_add_test(s21_strcspn_tests, any_sim);
  tcase_add_test(s21_strcspn_tests, upper_letter);
  tcase_add_test(s21_strcspn_tests, lower_letter);
  tcase_add_test(s21_strcspn_tests, not_uniq_sim);
  tcase_add_test(s21_strcspn_tests, strcspn_1);
  tcase_add_test(s21_strcspn_tests, strcspn_2);
  tcase_add_test(s21_strcspn_tests, strcspn_3);
  tcase_add_test(s21_strcspn_tests, strcspn_4);
  tcase_add_test(s21_strcspn_tests, strcspn_5);
  tcase_add_test(s21_strcspn_tests, strcspn_6);
  tcase_add_test(s21_strcspn_tests, strcspn_7);
  tcase_add_test(s21_strcspn_tests, strcspn_8);
  tcase_add_test(s21_strcspn_tests, strcspn_9);
  tcase_add_test(s21_strcspn_tests, strcspn_10);
  tcase_add_test(s21_strcspn_tests, strcspn_11);
  tcase_add_test(s21_strcspn_tests, strcspn_12);

  return s21_suite_1;
}

Suite *s21_strerror_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strerror tests");
  TCase *s21_strerror_tests = tcase_create("s21_strerror_test");
  suite_add_tcase(s21_suite_1, s21_strerror_tests);
  tcase_add_test(s21_strerror_tests, test_strerror_1);
  tcase_add_test(s21_strerror_tests, test_strerror_2);
  tcase_add_test(s21_strerror_tests, test_strerror_3);
  tcase_add_test(s21_strerror_tests, test_strerror_4);
  tcase_add_test(s21_strerror_tests, test_strerror_5);
  tcase_add_test(s21_strerror_tests, all_std_errors);
  tcase_add_test(s21_strerror_tests, negative_err_code);

  return s21_suite_1;
}

Suite *s21_strlen_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strlen tests");
  TCase *s21_strlen_tests = tcase_create("s21_strlen_test");
  suite_add_tcase(s21_suite_1, s21_strlen_tests);
  tcase_add_test(s21_strlen_tests, test_strlen_1);
  tcase_add_test(s21_strlen_tests, test_strlen_2);
  tcase_add_test(s21_strlen_tests, test_strlen_3);
  tcase_add_test(s21_strlen_tests, test_strlen_4);
  tcase_add_test(s21_strlen_tests, test_strlen_5);
  tcase_add_test(s21_strlen_tests, empty_strlen);
  tcase_add_test(s21_strlen_tests, abosal);
  tcase_add_test(s21_strlen_tests, num);
  tcase_add_test(s21_strlen_tests, string_strlen);
  tcase_add_test(s21_strlen_tests, abosal_no_dal);
  tcase_add_test(s21_strlen_tests, dai_mne_pen);
  tcase_add_test(s21_strlen_tests, Floppy_disk);
  tcase_add_test(s21_strlen_tests, floppa);
  tcase_add_test(s21_strlen_tests, kot_Vasily);
  tcase_add_test(s21_strlen_tests, Russky_kot_Shlepa);
  tcase_add_test(s21_strlen_tests, strlen_1);
  tcase_add_test(s21_strlen_tests, strlen_2);
  tcase_add_test(s21_strlen_tests, strlen_3);
  tcase_add_test(s21_strlen_tests, strlen_4);
  tcase_add_test(s21_strlen_tests, strlen_5);
  tcase_add_test(s21_strlen_tests, strlen_6);
  tcase_add_test(s21_strlen_tests, strlen_7);
  tcase_add_test(s21_strlen_tests, strlen_8);
  tcase_add_test(s21_strlen_tests, strlen_9);
  tcase_add_test(s21_strlen_tests, strlen_10);
  tcase_add_test(s21_strlen_tests, strlen_11);
  tcase_add_test(s21_strlen_tests, strlen_12);
  tcase_add_test(s21_strlen_tests, strlen_13);
  tcase_add_test(s21_strlen_tests, strlen_14);

  return s21_suite_1;
}

Suite *s21_strpbrk_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strpbrk tests");
  TCase *s21_strpbrk_tests = tcase_create("s21_strpbrk_test");
  suite_add_tcase(s21_suite_1, s21_strpbrk_tests);
  tcase_add_test(s21_strpbrk_tests, test_strpbrk_1);
  tcase_add_test(s21_strpbrk_tests, test_strpbrk_2);
  tcase_add_test(s21_strpbrk_tests, test_strpbrk_3);
  tcase_add_test(s21_strpbrk_tests, test_strpbrk_4);
  tcase_add_test(s21_strpbrk_tests, test_strpbrk_5);
  tcase_add_test(s21_strpbrk_tests, empty_strpbrk);
  tcase_add_test(s21_strpbrk_tests, floppy_);
  tcase_add_test(s21_strpbrk_tests, _floppy);
  tcase_add_test(s21_strpbrk_tests, poki_doki_o);
  tcase_add_test(s21_strpbrk_tests, poki_doki_i);
  tcase_add_test(s21_strpbrk_tests, poki_doki_p);
  tcase_add_test(s21_strpbrk_tests, find_big_P);
  tcase_add_test(s21_strpbrk_tests, find_zero);
  tcase_add_test(s21_strpbrk_tests, strpbrk_1);
  tcase_add_test(s21_strpbrk_tests, strpbrk_2);
  tcase_add_test(s21_strpbrk_tests, strpbrk_3);
  tcase_add_test(s21_strpbrk_tests, strpbrk_4);
  tcase_add_test(s21_strpbrk_tests, strpbrk_5);
  tcase_add_test(s21_strpbrk_tests, strpbrk_6);

  return s21_suite_1;
}

Suite *s21_strrchr_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strrchr tests");
  TCase *s21_strrchr_tests = tcase_create("s21_strchr_test");
  suite_add_tcase(s21_suite_1, s21_strrchr_tests);
  tcase_add_test(s21_strrchr_tests, test_strrchr_1);
  tcase_add_test(s21_strrchr_tests, test_strrchr_2);
  tcase_add_test(s21_strrchr_tests, test_strrchr_3);
  tcase_add_test(s21_strrchr_tests, test_strrchr_4);
  tcase_add_test(s21_strrchr_tests, test_strrchr_5);
  tcase_add_test(s21_strrchr_tests, empty_strrchr);
  tcase_add_test(s21_strrchr_tests, floppy__strrchr);
  tcase_add_test(s21_strrchr_tests, _floppy_strrchr);
  tcase_add_test(s21_strrchr_tests, poki_doki_o_strrchr);
  tcase_add_test(s21_strrchr_tests, poki_doki_i_strrchr);
  tcase_add_test(s21_strrchr_tests, poki_doki_p_strrchr);
  tcase_add_test(s21_strrchr_tests, find_big_P_strrchr);
  tcase_add_test(s21_strrchr_tests, find_zero_strrchr);
  tcase_add_test(s21_strrchr_tests, strrchr_1);
  tcase_add_test(s21_strrchr_tests, strrchr_2);
  tcase_add_test(s21_strrchr_tests, strrchr_3);
  tcase_add_test(s21_strrchr_tests, strrchr_4);
  tcase_add_test(s21_strrchr_tests, strrchr_5);
  tcase_add_test(s21_strrchr_tests, strrchr_6);
  tcase_add_test(s21_strrchr_tests, strrchr_7);
  tcase_add_test(s21_strrchr_tests, strrchr_8);

  return s21_suite_1;
}

Suite *s21_strstr_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strstr tests");
  TCase *s21_strstr_tests = tcase_create("s21_strstr_test");
  suite_add_tcase(s21_suite_1, s21_strstr_tests);
  tcase_add_test(s21_strstr_tests, test_strstr_1);
  tcase_add_test(s21_strstr_tests, test_strstr_2);
  tcase_add_test(s21_strstr_tests, test_strstr_3);
  tcase_add_test(s21_strstr_tests, test_strstr_4);
  tcase_add_test(s21_strstr_tests, test_strstr_5);
  tcase_add_test(s21_strstr_tests, empty_string_haystack_and_needle);
  tcase_add_test(s21_strstr_tests, empty_string_haystack);
  tcase_add_test(s21_strstr_tests, empty_string_needle);
  tcase_add_test(s21_strstr_tests, toxic_test);
  tcase_add_test(s21_strstr_tests, not_word_in_haystack);
  tcase_add_test(s21_strstr_tests, words_with_any_register);
  tcase_add_test(s21_strstr_tests, repeated_words);
  tcase_add_test(s21_strstr_tests, word_at_end);
  tcase_add_test(s21_strstr_tests, one_simbol_in_needle_and_haystack);
  tcase_add_test(s21_strstr_tests, one_simbol_in_needle);
  tcase_add_test(s21_strstr_tests, one_simbol_in_haystack);
  tcase_add_test(s21_strstr_tests, strstr_1);
  tcase_add_test(s21_strstr_tests, strstr_2);
  tcase_add_test(s21_strstr_tests, strstr_3);
  tcase_add_test(s21_strstr_tests, strstr_4);
  tcase_add_test(s21_strstr_tests, strstr_5);
  tcase_add_test(s21_strstr_tests, strstr_6);
  tcase_add_test(s21_strstr_tests, strstr_7);
  tcase_add_test(s21_strstr_tests, strstr_8);
  tcase_add_test(s21_strstr_tests, strstr_9);
  tcase_add_test(s21_strstr_tests, strstr_10);
  tcase_add_test(s21_strstr_tests, strstr_11);
  tcase_add_test(s21_strstr_tests, strstr_12);
  tcase_add_test(s21_strstr_tests, strstr_13);

  return s21_suite_1;
}

Suite *s21_strtok_test(void) {
  Suite *s21_suite_1 = suite_create("s21_strtok tests");
  TCase *s21_strtok_tests = tcase_create("s21_strtok_test");
  suite_add_tcase(s21_suite_1, s21_strtok_tests);
  tcase_add_test(s21_strtok_tests, test_strtok_1);
  tcase_add_test(s21_strtok_tests, test_strtok_2);
  tcase_add_test(s21_strtok_tests, test_strtok_3);
  tcase_add_test(s21_strtok_tests, test_strtok_4);
  tcase_add_test(s21_strtok_tests, test_strtok_5);
  tcase_add_test(s21_strtok_tests, correct_token_string);
  tcase_add_test(s21_strtok_tests, hard_token_string);
  tcase_add_test(s21_strtok_tests, only_delims);
  tcase_add_test(s21_strtok_tests, even_n_of_delims);
  tcase_add_test(s21_strtok_tests, odd_n_of_delims);
  tcase_add_test(s21_strtok_tests, mixed_n_of_delims);
  tcase_add_test(s21_strtok_tests, too_many_uses_non_segfault);
  tcase_add_test(s21_strtok_tests, hard_mixed);
  tcase_add_test(s21_strtok_tests, mixed_hard_incorrect);
  tcase_add_test(s21_strtok_tests, very_hard_mixed);
  tcase_add_test(s21_strtok_tests, unary_delimiters);
  tcase_add_test(s21_strtok_tests, no_delims);
  tcase_add_test(s21_strtok_tests, strtok_1);
  tcase_add_test(s21_strtok_tests, strtok_2);
  tcase_add_test(s21_strtok_tests, strtok_3);
  tcase_add_test(s21_strtok_tests, strtok_4);
  tcase_add_test(s21_strtok_tests, strtok_5);
  tcase_add_test(s21_strtok_tests, strtok_6);
  tcase_add_test(s21_strtok_tests, strtok_7);
  tcase_add_test(s21_strtok_tests, strtok_8);
  tcase_add_test(s21_strtok_tests, strtok_9);
  tcase_add_test(s21_strtok_tests, strtok_10);
  // tcase_add_test(s21_strtok_tests, strtok_11);
  tcase_add_test(s21_strtok_tests, strtok_12);
  tcase_add_test(s21_strtok_tests, strtok_13);
  tcase_add_test(s21_strtok_tests, strtok_14);
  tcase_add_test(s21_strtok_tests, strtok_15);
  tcase_add_test(s21_strtok_tests, strtok_16);
  tcase_add_test(s21_strtok_tests, strtok_17);
  tcase_add_test(s21_strtok_tests, strtok_18);
  tcase_add_test(s21_strtok_tests, strtok_19);
  tcase_add_test(s21_strtok_tests, strtok_20);

  return s21_suite_1;
}

Suite *s21_to_lower_test(void) {
  Suite *s21_suite_1 = suite_create("s21_to_lower tests");
  TCase *s21_to_lower_tests = tcase_create("s21_to_lower_test");
  suite_add_tcase(s21_suite_1, s21_to_lower_tests);
  tcase_add_test(s21_to_lower_tests, to_lower_test1);
  tcase_add_test(s21_to_lower_tests, to_lower_test2);
  tcase_add_test(s21_to_lower_tests, to_lower_test3);
  tcase_add_test(s21_to_lower_tests, to_lower_test4);
  tcase_add_test(s21_to_lower_tests, to_lower_test5);
  tcase_add_test(s21_to_lower_tests, test_to_lower_1);
  tcase_add_test(s21_to_lower_tests, test_to_lower_2);
  tcase_add_test(s21_to_lower_tests, test_to_lower_3);
  tcase_add_test(s21_to_lower_tests, test_to_lower_4);
  tcase_add_test(s21_to_lower_tests, test_to_lower_5);
  tcase_add_test(s21_to_lower_tests, test_to_lower_6);
  tcase_add_test(s21_to_lower_tests, test_to_lower_7);

  return s21_suite_1;
}

Suite *s21_to_upper_test(void) {
  Suite *s21_suite_1 = suite_create("s21_to_upper tests");
  TCase *s21_to_upper_tests = tcase_create("s21_to_upper_test");
  suite_add_tcase(s21_suite_1, s21_to_upper_tests);
  tcase_add_test(s21_to_upper_tests, to_upper_test1);
  tcase_add_test(s21_to_upper_tests, to_upper_test2);
  tcase_add_test(s21_to_upper_tests, to_upper_test3);
  tcase_add_test(s21_to_upper_tests, to_upper_test4);
  tcase_add_test(s21_to_upper_tests, to_upper_test5);
  tcase_add_test(s21_to_upper_tests, test_to_upper_1);
  tcase_add_test(s21_to_upper_tests, test_to_upper_2);
  tcase_add_test(s21_to_upper_tests, test_to_upper_3);
  tcase_add_test(s21_to_upper_tests, test_to_upper_4);
  tcase_add_test(s21_to_upper_tests, test_to_upper_5);
  tcase_add_test(s21_to_upper_tests, test_to_upper_6);
  tcase_add_test(s21_to_upper_tests, test_to_upper_7);

  return s21_suite_1;
}

Suite *s21_insert_test(void) {
  Suite *s21_suite_1 = suite_create("s21_insert tests");
  TCase *s21_insert_tests = tcase_create("s21_insert_test");
  suite_add_tcase(s21_suite_1, s21_insert_tests);
  tcase_add_test(s21_insert_tests, insert_test1);
  tcase_add_test(s21_insert_tests, insert_test2);
  // tcase_add_test(s21_insert_tests, insert_test3);
  tcase_add_test(s21_insert_tests, insert_test4);
  tcase_add_test(s21_insert_tests, insert_test5);
  tcase_add_test(s21_insert_tests, insert_str_null);
  tcase_add_test(s21_insert_tests, test_insert_1);
  tcase_add_test(s21_insert_tests, test_insert_2);
  tcase_add_test(s21_insert_tests, test_insert_3);
  tcase_add_test(s21_insert_tests, test_insert_4);
  tcase_add_test(s21_insert_tests, test_insert_5);
  tcase_add_test(s21_insert_tests, test_insert_6);
  tcase_add_test(s21_insert_tests, test_insert_7);
  tcase_add_test(s21_insert_tests, test_insert_8);
  // tcase_add_test(s21_insert_tests, test_insert_9);
  // tcase_add_test(s21_insert_tests, test_insert_10);

  return s21_suite_1;
}

Suite *s21_trim_test(void) {
  Suite *s21_suite_1 = suite_create("s21_trim tests");
  TCase *s21_trim_tests = tcase_create("s21_trim_test");
  suite_add_tcase(s21_suite_1, s21_trim_tests);
  tcase_add_test(s21_trim_tests, all_empty);
  tcase_add_test(s21_trim_tests, str_empty);
  tcase_add_test(s21_trim_tests, trim_empty);
  tcase_add_test(s21_trim_tests, trim_and_str_eq);
  tcase_add_test(s21_trim_tests, trim_test1);
  tcase_add_test(s21_trim_tests, trim_test2);
  tcase_add_test(s21_trim_tests, trim_test3);
  tcase_add_test(s21_trim_tests, trim_test4);
  tcase_add_test(s21_trim_tests, trim_test5);
  tcase_add_test(s21_trim_tests, empty_spaces);

  return s21_suite_1;
}

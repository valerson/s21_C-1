#include "s21_sprintf.h"
#include "s21_tests_string.h"

#define BUFF_SIZE 2048

START_TEST(simple_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(precise_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(width_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(minus_width_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(plus_width_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(padding_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(star_width_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(star_precision_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(many_flags_many_ints) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(flags_long_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(flags_short_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.0d";
  int val = 0;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(space_flag_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_hash) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_long) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#-10x";
  unsigned val = 858158158;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val),
  //                  sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_two_longer_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_char) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_many_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_long) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(null_ptr) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge_negative) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.10Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.15Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_empty) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_huge_negative) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_huge) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(E_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char *format = "%.1LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(all_empty) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_char) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_char) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_string) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_string) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_dec) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_dec) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_int) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_float) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_float) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_char_with_alignment) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX TEST
START_TEST(test_one_hex_lower) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%x", 0), sprintf(str2_1, "%x", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_3[BUFF_SIZE] = {'\0'};
  char str2_3[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_3, "%x", INT32_MAX),
                   sprintf(str2_3, "%x", INT32_MAX));
  ck_assert_str_eq(str1_3, str2_3);
}
END_TEST
START_TEST(test_one_hex_upper) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%X", 0), sprintf(str2_1, "%x", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%X", INT32_MAX),
                   sprintf(str2_2, "%X", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_many_hex_lower) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_upper) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST
// START HEX WITH ALIGNMENT
START_TEST(test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%-3x", 0), sprintf(str2_1, "%-3x", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%-3x", INT32_MAX),
                   sprintf(str2_2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%13x", 0), sprintf(str2_1, "%13x", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%13x", INT32_MAX),
                   sprintf(str2_2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%-60X", 0),
                   sprintf(str2_1, "%-60X", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%-60X", INT32_MAX),
                   sprintf(str2_2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%7X", 0), sprintf(str2_1, "%7X", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%7X", INT32_MAX),
                   sprintf(str2_2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT
// START HEX TEST WITH #
START_TEST(test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%#x", 0), sprintf(str2_1, "%#x", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%#x", INT32_MAX),
                   sprintf(str2_2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%#X", 0), sprintf(str2_1, "%#X", 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%#X", INT32_MAX),
                   sprintf(str2_2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #
// START HEX TEST with width *
START_TEST(test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%*x", 11, 0),
                   sprintf(str2_1, "%*x", 11, 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%*x", 11, INT32_MAX),
                   sprintf(str2_2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%*X", 11, 0),
                   sprintf(str2_1, "%*X", 11, 0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%*X", 11, INT32_MAX),
                   sprintf(str2_2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1_2, str2_2);
}
END_TEST
START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *
// START HEX TEST WITH precision
START_TEST(test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision
// START HEX TEST WITH Length
START_TEST(test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%hx", 0),
                   sprintf(str2_1, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%hx", 11),
                   sprintf(str2_2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1_2, str2_2);

  char str1_3[BUFF_SIZE] = {'\0'};
  char str2_3[BUFF_SIZE] = {'\0'};
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1_3, "%lx", val),
                   sprintf(str2_3, "%lx", val));
  ck_assert_str_eq(str1_3, str2_3);

  char str1_4[BUFF_SIZE] = {'\0'};
  char str2_4[BUFF_SIZE] = {'\0'};
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1_4, "%lx", v), sprintf(str2_4, "%lx", v));
  ck_assert_str_eq(str1_4, str2_4);
}
END_TEST
START_TEST(test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);

  char str1_1[BUFF_SIZE] = {'\0'};
  char str2_1[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_1, "%hx", 0),
                   sprintf(str2_1, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1_1, str2_1);

  char str1_2[BUFF_SIZE] = {'\0'};
  char str2_2[BUFF_SIZE] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1_2, "%hx", 11),
                   sprintf(str2_2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1_2, str2_2);

  char str1_3[BUFF_SIZE] = {'\0'};
  char str2_3[BUFF_SIZE] = {'\0'};
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1_3, "%lx", val),
                   sprintf(str2_3, "%lx", val));
  ck_assert_str_eq(str1_3, str2_3);

  char str1_4[BUFF_SIZE] = {'\0'};
  char str2_4[BUFF_SIZE] = {'\0'};
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1_4, "%lx", v), sprintf(str2_4, "%lx", v));
  ck_assert_str_eq(str1_4, str2_4);
}
END_TEST
START_TEST(test_sprintf1) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf2) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf3) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf4) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf6) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf7) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf8) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf9) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf10) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf11) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf12) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf14) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf15) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf16) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf17) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf18) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf19) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf20) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(test_sprintf24) {
//   char str1[BUFF_SIZE] = {'\0'};
//   char str2[BUFF_SIZE] = {'\0'};
//   char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

//   ck_assert_int_eq(
//       s21_sprintf(str1, format, 'f', 21, 42, 666.666,
//                   "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
//       sprintf(str2, format, 'f', 21, 42, 666.666,
//               "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(test_sprintf25) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf28) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  int a = s21_sprintf(str1, "%d", 123);
  int b = sprintf(str2, "%d", 123);

  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf29) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf30) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf31) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf32) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf33) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf35) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf36) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf37) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf38) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf39) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf40) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf41) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf42) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf43) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf44) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_trailing_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_large) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(g_precision_zero)
// {
//     char str1[BUFF_SIZE] = {'\0'};
//     char str2[BUFF_SIZE] = {'\0'};
//     char format[] = "%.0g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_precision_missing)
// {
//     char str1[BUFF_SIZE] = {'\0'};
//     char str2[BUFF_SIZE] = {'\0'};
//     char format[] = "%.g";
//     double hex = 0.123000;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_many_zeroes_in_front)
// {
//     char str1[BUFF_SIZE] = {'\0'};
//     char str2[BUFF_SIZE] = {'\0'};
//     char format[] = "%.g";
//     double hex = 0.0004;
//     ck_assert_int_eq(s21_sprintf(str1, format, hex),
//                      sprintf(str2, format, hex));
//     ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(g_one_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss_flags) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_short_no_mantiss) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many) {
  char str1[BUFF_SIZE] = {'\0'};
  char str2[BUFF_SIZE] = {'\0'};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %lc";
//   unsigned long w = 'u';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(width_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %5c";
//   char w = 'c';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(minus_wide_char) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "This is a simple wide char %-5lc";
//   unsigned long w = 'r';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
START_TEST(wide_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %ls";
  wchar_t w[] = L"qwerty";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wide_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5.12ls";
  wchar_t w[] = L"aszxcv";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wide_string2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %120ls ABOBA";
  wchar_t w[] = L"assaq";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wide_string3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-43ls";
  wchar_t w[] = L"qw";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(wide_string4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %43ls";
  wchar_t w[] = L"qq";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST
// START_TEST(wide_char2) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//
//   char *format = "This is a simple wide char %30lc";
//   unsigned long w = 'c';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(shiraleo_sprintf_test_01) {
  char str1[100];
  char str2[100];
  char *format = "Number: %13.6d Pointer to number: %15.3p Null char:%*.0c";
  int a = -4568;
  int *p = 0;
  char c = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, a, p, 2, c),
                   sprintf(str2, format, a, p, 2, c));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(shiraleo_sprintf_test_02) {
  char str1[200];
  char str2[200];
  char *format = "%s";
  char *s = "\0";
  ck_assert_int_eq(s21_sprintf(str1, format, s), sprintf(str2, format, s));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(shiraleo_sprintf_test_03) {
  char str1[100];
  char str2[100];
  char *format =
      "Number: %013d Pointer to number: % 0#17X Null char:%*.0s Text:%10.5s";
  int a = -4568;
  int *p = 0;
  char *c = 0;
  char *str = "CHECK";
  ck_assert_int_eq(s21_sprintf(str1, format, a, p, 14, c, str),
                   sprintf(str2, format, a, p, 14, c, str));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf_1_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%c Test %c Test %c Test %c Test %c";
//   int a = 9;
//   int b = 10;
//   int c = 17;
//   int d = 66;
//   int e = 124;
//   ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
//                    s21_sprintf(str2, str3, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_2_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%c Test %c Test %c Test %c Test %c";
//   int a = -6;
//   int b = -10;
//   int c = -17;
//   int d = -66;
//   int e = -124;
//   ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
//                    s21_sprintf(str2, str3, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_3_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%c Test %c Test %c Test %c Test %c";
//   int a = 60;
//   int b = 50;
//   int c = 1744;
//   int d = 386;
//   int e = 257;
//   ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
//                    s21_sprintf(str2, str3, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_4_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%c Test %c Test %c Test %c Test %c";
//   int a = 60;
//   int b = 50;
//   int c = 1744;
//   int d = 386;
//   int e = 257;
//   ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
//                    s21_sprintf(str2, str3, a, b, c, d, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_5_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%c Test %c Test %c Test %c Test %c";
//   char a = 0;
//   ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
//                    s21_sprintf(str2, str3, a, a, a, a, a));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_6_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%05c Test % 5c Test %lc Test";
//   int a = 70;
//   unsigned long int b = 70;
//   sprintf(str1, str3, a, a, b);
//   s21_sprintf(str2, str3, a, a, b);
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_7_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%-010c Test % -10c Test %-lc";
//   int a = 74;
//   unsigned long int b = 74;
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b),
//                    s21_sprintf(str2, str3, a, a, b));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_8_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%+010.5c Test % +10.5c Test %-10lc Test %-10lc Test %+10lc";
//   char a = 92;
//   unsigned long int b = 92;
//   unsigned long int c = L'汉';
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
//                    s21_sprintf(str2, str3, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_9_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
//   int a = 10;
//   unsigned long int b = L'汉';
//   unsigned long int c = L'汉';
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
//                    s21_sprintf(str2, str3, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
// START_TEST(sprintf_10_c) {
//   char str1[100];
//   char str2[100];
//   char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
//   int a = -10;
//   unsigned long int b = L'汉';
//   unsigned long int c = L'汉';
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
//                    s21_sprintf(str2, str3, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST
START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '\0', '\0', '\0', 'c'),
                   s21_sprintf(str2, str3, '\n', '\0', '\0', '\0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '\0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '\0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '\0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '\0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-7c Test %-50c Test % 54c Test %0188c";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// START_TEST(sprintf_19_c) {
//   char str1[100];
//   char str2[100];  //%lc Test %llc Test %hc Test %hhc
//   char *str3 = "%c Test %lc Test %hc";
//   int a = 3;
//   unsigned long int b = 103;
//   unsigned short e = 255;
//   ck_assert_int_eq(sprintf(str1, str3, a, b, e),
//                    s21_sprintf(str2, str3, a, b, e));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

// One parameter signed
START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three signed parameters
START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %0d GOD %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Test %3.d Test %5.7d TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d Test %#3d Test %#5.7d TEST %#.7d Oof %#.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Simple extra test
START_TEST(sprintf_16_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hello %d %023d", val, val);  // нет нулей перед числом(бонус)
  s21_sprintf(str2, "Hello %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_signed) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_19_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test %- 15d sdasda %- 15d sdsad %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.e";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_2_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_4_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_5_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_6_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_7_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num =
      -59215632247759777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_8_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e\nFifth test: %0.0e!";
  double num =
      -59215632247759777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_9_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_10_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %020.4e\nForth test: %020.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_11_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %020.2e\nSixth test: %020.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_12_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: %020.e\n Eighth test: %020.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_13_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 20e\nSecond test: % 20.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_14_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 20.4e\nForth test: % 20.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_15_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 20.2e\nSixth test: % 20.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 20.e\n Eighth test: % 20.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 31e\nSecond test: % 30.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 33.4e\nForth test: % 35.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_19_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 36.2e\nSixth test: % 45.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_20_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 64.e\n Eighth test: % 80.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_21_e) {
  char str1[300];
  char str2[300];
  double num1 = -89435776876.;
  double num2 = -894357768.76;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_22_e) {
  char str1[300];
  char str2[300];
  double num3 = -89435.776876;
  double num4 = -0.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_23_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_24_e) {
  char str1[300];
  char str2[300];
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_25_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "test: %.E!\ntest: %#E!\ntest: %#.E!\ntest: %0.E!\n";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_26_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "test: % 013.E\ntest: %#4.9E\ntest: %016.2E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_27_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_28_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "test: % 30.1E\ntest: % 30.E\ntest: %030.0E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_29_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "test: %066.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_30_e) {
  char str1[300];
  char str2[300];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: %- 17.1E\ntest: % -17.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_31_e) {
  char str1[300];
  char str2[300];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "test: %# 10.2E\ntest: % #10.0E\ntest: %010.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_32_e) {
  char str1[600];
  char str2[600];
  double num1 = 1234567890000.0938217586;
  char *str3 = "test: %- 67.1E\ntest: % -67.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_33_e) {
  char str1[600];
  char str2[600];
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %# 100.0E\ntest: % #100.0E\ntest: %0100.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_34_e) {
  char str1[1000];
  char str2[1000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "test: % 030.10E\ntest: % -17.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_35_e) {
  char str1[1000];
  char str2[1000];
  double num1 = -12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_36_e) {
  char str1[600];
  char str2[600];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: % 10.1E\ntest: %- 10.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_37_e) {
  char str1[600];
  char str2[600];
  double num2 = 53296575676899283.734747273752737878257;
  char *str3 = "test: % -10.0E\ntest: %- 10.0E\ntest: % -10.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_38_e) {
  char str1[600];
  char str2[600];
  double num1 = .000000005329657567689928373474727375273787825732159676631957;
  double num2 = 53296575676899283.73474727375273787825732159676631957;
  char *str3 = "test: % 20E\ntest: %-20E\ntest: %+ 020.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num1),
                   s21_sprintf(str2, str3, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_39_e) {
  char str1[600];
  char str2[600];
  double num3 = 5329657567689928373474727375.273787825732159676631957;
  double num4 = 53296575676899283734747273752737878257.32159676631957;
  char *str3 = "test: %#20.E\ntest: %- 20E!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_40_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%.e\n%.2e\n%.5E\n%.9E\n%.13E!";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_41_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  long double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_42_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e\n%.e\n%.5e\n%.9e\n%.15E!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_43_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %20Le!\ntest: %Le!\ntest: %-10Le!";
  long double num =
      -932578123500000000000000000006836899883206165838263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_44_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %060Le!\ntest: %.14Le!";
  long double num =
      -9325781235000000000000000000053989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.f\ntest: %-+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.9f!\ntest: %-+25.15f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_23_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_27_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 26Lf!\ntest: %+- 18Lf!\ntest: %60Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_28_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +15Lf!test: %100Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_30_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020f!\ntest: %-020f!\ntest: %+025f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_31_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5f!\ntest: %- 020.4f\ntest: %+ 016.6f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_32_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015f!\ntest: %-026f!\ntest: %+018f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_33_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2f!\ntest: %- 025.7f\ntest: %+- 18.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.13Lf!\ntest: %- 30.8Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.14Lf!\ntest: % +40.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.9999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10Lf!\ntest: %.6Lf!\ntest: %.Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lf!\ntest: %.Lf\ntest: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_45_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -93257812356836.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_47_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235688.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_48_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 823631075973858583.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_49_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = 823631075977757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
  long double num = -932578129988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_51_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
  long double num = -932578129988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_54_f) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.11g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.12g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.46589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-026g!\ntest: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2g!\ntest: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.15Lg!\ntest: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg\ntest: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.13Lg!\ntest: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 99999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!\ntest: %.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.g!\ntest: %.2g!\ntest: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.15g!\ntest: %-16g!\ntest: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter hex
START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three hex parameters
START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter signed_i
START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three signed_i parameters
START_TEST(sprintf_2_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i Test %i Test %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li Test %li Test %hi GOD %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i Test %5i Test %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5i Test %.23i Test %3.i TEST %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i Test %-.8i Test %-7i TEST %-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i Test %0.i Test %0.0i TEST %0i GOD %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%i Test %3.i Test %5.7i TEST %10i %#i %-i %+i %.i % .i";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i Test % 3.i Test % 5.7i TEST % 10i GOD %.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i GOD %+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%#i Test %#3i Test %#5.7i TEST %#.7i Oof %#.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%*i Test %-*i Test %*.*i TEST %.*i";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Simple extra test
START_TEST(sprintf_16_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%- i Test %- 15i sdasda %- 15i sdsad %- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three octal parameters
START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Simple extra test
START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = 3231;
  int val2 = 3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Te%%st %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// // One parameter pointer
START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three pointer parameters
START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p7a4";
  char *val2 = "0p91ba123f";
  char *val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p3015";
  char *val2 = "0p712";
  char *val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p GOD %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%3p Test %5p Test %12p";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5p Test %.23p Test %3.p TEST %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %0.p Test %0.0p TEST %0p GOD %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  char *val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char *val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "% p Test % 3.p Test % 5.7p TEST % 10p GOD %.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p GOD %+.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%*p Test %-*p Test %*.*p TEST %.*p Lololol %.*p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "9193112312312";
  char *val4 = "32311";
  char *val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three string parameters
START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes WCHAR FOR LATER
START_TEST(sprintf_4_string) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
  //                s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeroes
START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zero vals
START_TEST(sprintf_10_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// START_TEST(sprintf_17_string) {
//   char str1[1024];
//   char str2[1024];
//   char *str3 =
//       "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s % "
//       "7.3s ";
//   char *val = NULL;
//   s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val,
//   val,
//               val);
//   sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
//           val);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// One parameter unsigned
START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three unsigned parameters
START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Three decimal parameters
START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different sizes
START_TEST(sprintf_4_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different width
START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Different precision and width
START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Minus flag
START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zerues
START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.u Test %0.0u TEST %0u GOD %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Pluses
START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Zeru vals
START_TEST(sprintf_10_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Spaces
START_TEST(sprintf_11_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3.u Test % 5.7u TEST % 10u GOD %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Plus
START_TEST(sprintf_12_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u GOD %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Hash
START_TEST(sprintf_13_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// ZERO flag
START_TEST(sprintf_14_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05.7u TEST %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
// Asterisk
START_TEST(sprintf_15_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_16_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_17_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s21_suite_1 = suite_create("s21_sprintf_tests");
  TCase *s21_sprintf_tests = tcase_create("s21_sprintf_test");
  suite_add_tcase(s21_suite_1, s21_sprintf_tests);

  tcase_add_test(s21_sprintf_tests, simple_int);
  tcase_add_test(s21_sprintf_tests, precise_int);
  tcase_add_test(s21_sprintf_tests, width_int);
  tcase_add_test(s21_sprintf_tests, minus_width_int);
  tcase_add_test(s21_sprintf_tests, plus_width_int);
  tcase_add_test(s21_sprintf_tests, padding_int);
  tcase_add_test(s21_sprintf_tests, star_width_int);
  tcase_add_test(s21_sprintf_tests, star_precision_int);
  tcase_add_test(s21_sprintf_tests, many_flags_many_ints);
  tcase_add_test(s21_sprintf_tests, flags_long_int);
  tcase_add_test(s21_sprintf_tests, flags_short_int);
  tcase_add_test(s21_sprintf_tests, flags_another_long_int);
  tcase_add_test(s21_sprintf_tests, zero_precision_zero_int);
  tcase_add_test(s21_sprintf_tests, space_flag_int);
  tcase_add_test(s21_sprintf_tests, unsigned_val);
  tcase_add_test(s21_sprintf_tests, unsigned_val_width);
  tcase_add_test(s21_sprintf_tests, unsigned_val_flags);
  tcase_add_test(s21_sprintf_tests, unsigned_val_precision);
  tcase_add_test(s21_sprintf_tests, unsigned_val_many_flags);
  tcase_add_test(s21_sprintf_tests, unsigned_val_short);
  tcase_add_test(s21_sprintf_tests, unsigned_val_long);
  tcase_add_test(s21_sprintf_tests, unsigned_val_many);
  tcase_add_test(s21_sprintf_tests, octal);
  tcase_add_test(s21_sprintf_tests, octal_width);
  tcase_add_test(s21_sprintf_tests, octal_flags);
  tcase_add_test(s21_sprintf_tests, octal_precision);
  tcase_add_test(s21_sprintf_tests, octal_many_flags);
  tcase_add_test(s21_sprintf_tests, octal_short);
  tcase_add_test(s21_sprintf_tests, octal_long);
  tcase_add_test(s21_sprintf_tests, octal_many);
  tcase_add_test(s21_sprintf_tests, octal_zero);
  tcase_add_test(s21_sprintf_tests, octal_hash);
  tcase_add_test(s21_sprintf_tests, unsigned_zero);
  tcase_add_test(s21_sprintf_tests, hex_width);
  tcase_add_test(s21_sprintf_tests, hex_flags);
  tcase_add_test(s21_sprintf_tests, hex_precision);
  tcase_add_test(s21_sprintf_tests, hex_many);
  tcase_add_test(s21_sprintf_tests, hex_many_flags);
  tcase_add_test(s21_sprintf_tests, hex_zero);
  tcase_add_test(s21_sprintf_tests, hex_huge);
  tcase_add_test(s21_sprintf_tests, hex_short);
  tcase_add_test(s21_sprintf_tests, hex_long);
  tcase_add_test(s21_sprintf_tests, hex_one_longer_width);
  tcase_add_test(s21_sprintf_tests, hex_two_longer_width);
  tcase_add_test(s21_sprintf_tests, one_char);
  tcase_add_test(s21_sprintf_tests, one_precision);
  tcase_add_test(s21_sprintf_tests, one_flags);
  tcase_add_test(s21_sprintf_tests, one_width);
  tcase_add_test(s21_sprintf_tests, one_many);
  tcase_add_test(s21_sprintf_tests, one_many_flags);
  tcase_add_test(s21_sprintf_tests, string);
  tcase_add_test(s21_sprintf_tests, string_precision);
  tcase_add_test(s21_sprintf_tests, string_width);
  tcase_add_test(s21_sprintf_tests, string_flags);
  tcase_add_test(s21_sprintf_tests, string_long);
  tcase_add_test(s21_sprintf_tests, string_many);
  tcase_add_test(s21_sprintf_tests, ptr);
  tcase_add_test(s21_sprintf_tests, ptr_width);
  tcase_add_test(s21_sprintf_tests, ptr_precision);
  tcase_add_test(s21_sprintf_tests, null_ptr);
  tcase_add_test(s21_sprintf_tests, n_specifier);
  tcase_add_test(s21_sprintf_tests, string_width_huge);
  tcase_add_test(s21_sprintf_tests, float_precision);
  tcase_add_test(s21_sprintf_tests, float_width);
  tcase_add_test(s21_sprintf_tests, float_precision_zero);
  tcase_add_test(s21_sprintf_tests, float_precision_empty);
  tcase_add_test(s21_sprintf_tests, float_precision_huge);
  tcase_add_test(s21_sprintf_tests, float_precision_huge_negative);
  tcase_add_test(s21_sprintf_tests, float_huge);
  tcase_add_test(s21_sprintf_tests, float_flags);
  tcase_add_test(s21_sprintf_tests, float_many);
  tcase_add_test(s21_sprintf_tests, e_precision);
  tcase_add_test(s21_sprintf_tests, e_precision_zero);
  tcase_add_test(s21_sprintf_tests, e_precision_empty);
  tcase_add_test(s21_sprintf_tests, e_precision_huge);
  tcase_add_test(s21_sprintf_tests, e_precision_huge_negative);
  tcase_add_test(s21_sprintf_tests, e_huge);
  tcase_add_test(s21_sprintf_tests, e_many);
  tcase_add_test(s21_sprintf_tests, e_width);
  tcase_add_test(s21_sprintf_tests, e_flags);
  tcase_add_test(s21_sprintf_tests, E_int);
  tcase_add_test(s21_sprintf_tests, all_empty);
  tcase_add_test(s21_sprintf_tests, empty_format_and_parameters);
  tcase_add_test(s21_sprintf_tests, test_one_char);
  tcase_add_test(s21_sprintf_tests, test_many_char);
  tcase_add_test(s21_sprintf_tests, test_one_string);
  tcase_add_test(s21_sprintf_tests, test_many_string);
  tcase_add_test(s21_sprintf_tests, test_one_dec);
  tcase_add_test(s21_sprintf_tests, test_many_dec);
  tcase_add_test(s21_sprintf_tests, test_one_int);
  tcase_add_test(s21_sprintf_tests, test_many_int);
  tcase_add_test(s21_sprintf_tests, test_one_float);
  tcase_add_test(s21_sprintf_tests, test_many_float);
  tcase_add_test(s21_sprintf_tests, test_one_unsigned_dec);
  tcase_add_test(s21_sprintf_tests, test_many_unsigned_dec);
  tcase_add_test(s21_sprintf_tests, test_one_char_with_alignment_left);
  tcase_add_test(s21_sprintf_tests, test_one_char_with_alignment_right);
  tcase_add_test(s21_sprintf_tests, test_many_char_with_alignment);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper);
  tcase_add_test(s21_sprintf_tests, test_many_hex_lower);
  tcase_add_test(s21_sprintf_tests, test_many_hex_upper);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower_with_alignment_left);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower_with_alignment_right);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_alignment_left);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_alignment_right);
  tcase_add_test(s21_sprintf_tests, test_many_hex_lower_with_alignment);
  tcase_add_test(s21_sprintf_tests, test_many_hex_upper_with_alignment);
  tcase_add_test(s21_sprintf_tests, test_one_hex_with_hashtag);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_hashtag);
  tcase_add_test(s21_sprintf_tests,
                 test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(s21_sprintf_tests,
                 test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower_with_width_star);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_width_star);
  tcase_add_test(s21_sprintf_tests,
                 test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(s21_sprintf_tests, test_many_hex_upper_with_width_star);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower_with_precision);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_precision);
  tcase_add_test(s21_sprintf_tests,
                 test_many_hex_lower_with_precision_and_other);
  tcase_add_test(s21_sprintf_tests,
                 test_many_hex_upper_with_precision_and_other);
  tcase_add_test(s21_sprintf_tests, test_one_hex_lower_with_length);
  tcase_add_test(s21_sprintf_tests, test_one_hex_upper_with_length);
  tcase_add_test(s21_sprintf_tests, test_sprintf1);
  tcase_add_test(s21_sprintf_tests, test_sprintf2);
  tcase_add_test(s21_sprintf_tests, test_sprintf3);
  tcase_add_test(s21_sprintf_tests, test_sprintf4);
  tcase_add_test(s21_sprintf_tests, test_sprintf6);
  tcase_add_test(s21_sprintf_tests, test_sprintf7);
  tcase_add_test(s21_sprintf_tests, test_sprintf8);
  tcase_add_test(s21_sprintf_tests, test_sprintf9);
  tcase_add_test(s21_sprintf_tests, test_sprintf10);
  tcase_add_test(s21_sprintf_tests, test_sprintf11);
  tcase_add_test(s21_sprintf_tests, test_sprintf12);
  tcase_add_test(s21_sprintf_tests, test_sprintf14);
  tcase_add_test(s21_sprintf_tests, test_sprintf15);
  tcase_add_test(s21_sprintf_tests, test_sprintf16);
  tcase_add_test(s21_sprintf_tests, test_sprintf17);
  tcase_add_test(s21_sprintf_tests, test_sprintf18);
  tcase_add_test(s21_sprintf_tests, test_sprintf19);
  tcase_add_test(s21_sprintf_tests, test_sprintf20);
  // tcase_add_test(s21_sprintf_tests, test_sprintf24);
  tcase_add_test(s21_sprintf_tests, test_sprintf25);
  tcase_add_test(s21_sprintf_tests, test_sprintf28);
  tcase_add_test(s21_sprintf_tests, test_sprintf29);
  tcase_add_test(s21_sprintf_tests, test_sprintf30);
  tcase_add_test(s21_sprintf_tests, test_sprintf31);
  tcase_add_test(s21_sprintf_tests, test_sprintf32);
  tcase_add_test(s21_sprintf_tests, test_sprintf33);
  tcase_add_test(s21_sprintf_tests, test_sprintf35);
  tcase_add_test(s21_sprintf_tests, test_sprintf36);
  tcase_add_test(s21_sprintf_tests, test_sprintf37);
  tcase_add_test(s21_sprintf_tests, test_sprintf38);
  tcase_add_test(s21_sprintf_tests, test_sprintf39);
  tcase_add_test(s21_sprintf_tests, test_sprintf40);
  tcase_add_test(s21_sprintf_tests, test_sprintf41);
  tcase_add_test(s21_sprintf_tests, test_sprintf42);
  tcase_add_test(s21_sprintf_tests, test_sprintf43);
  tcase_add_test(s21_sprintf_tests, test_sprintf44);
  tcase_add_test(s21_sprintf_tests, g_trailing_zero);
  tcase_add_test(s21_sprintf_tests, g_large);
  tcase_add_test(s21_sprintf_tests, g_small);
  tcase_add_test(s21_sprintf_tests, g_precision);
  // tcase_add_test(s21_sprintf_tests, g_precision_zero);
  // tcase_add_test(s21_sprintf_tests, g_precision_missing);
  // tcase_add_test(s21_sprintf_tests, g_many_zeroes_in_front);
  tcase_add_test(s21_sprintf_tests, g_one_zero);
  tcase_add_test(s21_sprintf_tests, g_mantiss);
  tcase_add_test(s21_sprintf_tests, g_mantiss_flags);
  tcase_add_test(s21_sprintf_tests, g_short_no_mantiss);
  tcase_add_test(s21_sprintf_tests, LG);
  tcase_add_test(s21_sprintf_tests, g_many);
  tcase_add_test(s21_sprintf_tests, g_zero);
  // tcase_add_test(s21_sprintf_tests, wide_char);
  // tcase_add_test(s21_sprintf_tests, width_char);
  // tcase_add_test(s21_sprintf_tests, minus_wide_char);
  tcase_add_test(s21_sprintf_tests, wide_string);
  tcase_add_test(s21_sprintf_tests, wide_string1);
  tcase_add_test(s21_sprintf_tests, wide_string2);
  tcase_add_test(s21_sprintf_tests, wide_string3);
  tcase_add_test(s21_sprintf_tests, wide_string4);
  //  tcase_add_test(s21_sprintf_tests, wide_char2);
  tcase_add_test(s21_sprintf_tests, shiraleo_sprintf_test_01);
  tcase_add_test(s21_sprintf_tests, shiraleo_sprintf_test_02);
  tcase_add_test(s21_sprintf_tests, shiraleo_sprintf_test_03);
  // tcase_add_test(s21_sprintf_tests, sprintf_1_c);
  // tcase_add_test(s21_sprintf_tests, sprintf_2_c);
  // tcase_add_test(s21_sprintf_tests, sprintf_3_c);
  // tcase_add_test(s21_sprintf_tests, sprintf_4_c);
  // tcase_add_test(s21_sprintf_tests, sprintf_5_c);
  // tcase_add_test(s21_sprintf_tests, sprintf_6_c);
  //  tcase_add_test(s21_sprintf_tests, sprintf_7_c);
  //  tcase_add_test(s21_sprintf_tests, sprintf_8_c);
  //  tcase_add_test(s21_sprintf_tests, sprintf_9_c);
  //  tcase_add_test(s21_sprintf_tests, sprintf_10_c);
  tcase_add_test(s21_sprintf_tests, sprintf_11_c);
  tcase_add_test(s21_sprintf_tests, sprintf_12_c);
  tcase_add_test(s21_sprintf_tests, sprintf_13_c);
  tcase_add_test(s21_sprintf_tests, sprintf_14_c);
  tcase_add_test(s21_sprintf_tests, sprintf_15_c);
  tcase_add_test(s21_sprintf_tests, sprintf_16_c);
  tcase_add_test(s21_sprintf_tests, sprintf_17_c);
  tcase_add_test(s21_sprintf_tests, sprintf_18_c);
  //  tcase_add_test(s21_sprintf_tests, sprintf_19_c);
  tcase_add_test(s21_sprintf_tests, sprintf_1_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_2_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_3_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_4_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_5_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_6_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_7_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_8_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_9_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_10_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_11_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_12_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_13_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_14_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_15_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_16_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_17_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_18_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_19_signed);
  tcase_add_test(s21_sprintf_tests, sprintf_1_e);
  tcase_add_test(s21_sprintf_tests, sprintf_2_e);
  tcase_add_test(s21_sprintf_tests, sprintf_3_e);
  tcase_add_test(s21_sprintf_tests, sprintf_4_e);
  tcase_add_test(s21_sprintf_tests, sprintf_5_e);
  tcase_add_test(s21_sprintf_tests, sprintf_6_e);
  tcase_add_test(s21_sprintf_tests, sprintf_7_e);
  tcase_add_test(s21_sprintf_tests, sprintf_8_e);
  tcase_add_test(s21_sprintf_tests, sprintf_9_e);
  tcase_add_test(s21_sprintf_tests, sprintf_10_e);
  tcase_add_test(s21_sprintf_tests, sprintf_11_e);
  tcase_add_test(s21_sprintf_tests, sprintf_12_e);
  tcase_add_test(s21_sprintf_tests, sprintf_13_e);
  tcase_add_test(s21_sprintf_tests, sprintf_14_e);
  tcase_add_test(s21_sprintf_tests, sprintf_15_e);
  tcase_add_test(s21_sprintf_tests, sprintf_16_e);
  tcase_add_test(s21_sprintf_tests, sprintf_17_e);
  tcase_add_test(s21_sprintf_tests, sprintf_18_e);
  tcase_add_test(s21_sprintf_tests, sprintf_19_e);
  tcase_add_test(s21_sprintf_tests, sprintf_20_e);
  tcase_add_test(s21_sprintf_tests, sprintf_21_e);
  tcase_add_test(s21_sprintf_tests, sprintf_22_e);
  tcase_add_test(s21_sprintf_tests, sprintf_23_e);
  tcase_add_test(s21_sprintf_tests, sprintf_24_e);
  tcase_add_test(s21_sprintf_tests, sprintf_25_e);
  tcase_add_test(s21_sprintf_tests, sprintf_26_e);
  tcase_add_test(s21_sprintf_tests, sprintf_27_e);
  tcase_add_test(s21_sprintf_tests, sprintf_28_e);
  tcase_add_test(s21_sprintf_tests, sprintf_29_e);
  tcase_add_test(s21_sprintf_tests, sprintf_30_e);
  tcase_add_test(s21_sprintf_tests, sprintf_31_e);
  tcase_add_test(s21_sprintf_tests, sprintf_32_e);
  tcase_add_test(s21_sprintf_tests, sprintf_33_e);
  tcase_add_test(s21_sprintf_tests, sprintf_34_e);
  tcase_add_test(s21_sprintf_tests, sprintf_35_e);
  tcase_add_test(s21_sprintf_tests, sprintf_36_e);
  tcase_add_test(s21_sprintf_tests, sprintf_37_e);
  tcase_add_test(s21_sprintf_tests, sprintf_38_e);
  tcase_add_test(s21_sprintf_tests, sprintf_39_e);
  tcase_add_test(s21_sprintf_tests, sprintf_40_e);
  tcase_add_test(s21_sprintf_tests, sprintf_41_e);
  tcase_add_test(s21_sprintf_tests, sprintf_42_e);
  tcase_add_test(s21_sprintf_tests, sprintf_43_e);
  tcase_add_test(s21_sprintf_tests, sprintf_44_e);
  tcase_add_test(s21_sprintf_tests, sprintf_1_f);
  tcase_add_test(s21_sprintf_tests, sprintf_2_f);
  tcase_add_test(s21_sprintf_tests, sprintf_3_f);
  tcase_add_test(s21_sprintf_tests, sprintf_4_f);
  tcase_add_test(s21_sprintf_tests, sprintf_5_f);
  tcase_add_test(s21_sprintf_tests, sprintf_6_f);
  tcase_add_test(s21_sprintf_tests, sprintf_7_f);
  tcase_add_test(s21_sprintf_tests, sprintf_8_f);
  tcase_add_test(s21_sprintf_tests, sprintf_9_f);
  tcase_add_test(s21_sprintf_tests, sprintf_10_f);
  tcase_add_test(s21_sprintf_tests, sprintf_11_f);
  tcase_add_test(s21_sprintf_tests, sprintf_12_f);
  tcase_add_test(s21_sprintf_tests, sprintf_13_f);
  tcase_add_test(s21_sprintf_tests, sprintf_14_f);
  tcase_add_test(s21_sprintf_tests, sprintf_15_f);
  tcase_add_test(s21_sprintf_tests, sprintf_16_f);
  tcase_add_test(s21_sprintf_tests, sprintf_17_f);
  tcase_add_test(s21_sprintf_tests, sprintf_18_f);
  tcase_add_test(s21_sprintf_tests, sprintf_19_f);
  tcase_add_test(s21_sprintf_tests, sprintf_20_f);
  tcase_add_test(s21_sprintf_tests, sprintf_21_f);
  tcase_add_test(s21_sprintf_tests, sprintf_22_f);
  tcase_add_test(s21_sprintf_tests, sprintf_23_f);
  tcase_add_test(s21_sprintf_tests, sprintf_24_f);
  tcase_add_test(s21_sprintf_tests, sprintf_25_f);
  tcase_add_test(s21_sprintf_tests, sprintf_26_f);
  tcase_add_test(s21_sprintf_tests, sprintf_27_f);
  tcase_add_test(s21_sprintf_tests, sprintf_28_f);
  tcase_add_test(s21_sprintf_tests, sprintf_30_f);
  tcase_add_test(s21_sprintf_tests, sprintf_31_f);
  tcase_add_test(s21_sprintf_tests, sprintf_32_f);
  tcase_add_test(s21_sprintf_tests, sprintf_33_f);
  tcase_add_test(s21_sprintf_tests, sprintf_34_f);
  tcase_add_test(s21_sprintf_tests, sprintf_35_f);
  tcase_add_test(s21_sprintf_tests, sprintf_36_f);
  tcase_add_test(s21_sprintf_tests, sprintf_37_f);
  tcase_add_test(s21_sprintf_tests, sprintf_38_f);
  tcase_add_test(s21_sprintf_tests, sprintf_39_f);
  tcase_add_test(s21_sprintf_tests, sprintf_40_f);
  tcase_add_test(s21_sprintf_tests, sprintf_41_f);
  tcase_add_test(s21_sprintf_tests, sprintf_42_f);
  tcase_add_test(s21_sprintf_tests, sprintf_43_f);
  tcase_add_test(s21_sprintf_tests, sprintf_44_f);
  tcase_add_test(s21_sprintf_tests, sprintf_45_f);
  tcase_add_test(s21_sprintf_tests, sprintf_46_f);
  tcase_add_test(s21_sprintf_tests, sprintf_47_f);
  tcase_add_test(s21_sprintf_tests, sprintf_48_f);
  tcase_add_test(s21_sprintf_tests, sprintf_49_f);
  tcase_add_test(s21_sprintf_tests, sprintf_50_f);
  tcase_add_test(s21_sprintf_tests, sprintf_51_f);
  tcase_add_test(s21_sprintf_tests, sprintf_54_f);
  tcase_add_test(s21_sprintf_tests, sprintf_1_g);
  tcase_add_test(s21_sprintf_tests, sprintf_2_g);
  tcase_add_test(s21_sprintf_tests, sprintf_3_g);
  tcase_add_test(s21_sprintf_tests, sprintf_4_g);
  tcase_add_test(s21_sprintf_tests, sprintf_5_g);
  tcase_add_test(s21_sprintf_tests, sprintf_6_g);
  tcase_add_test(s21_sprintf_tests, sprintf_7_g);
  tcase_add_test(s21_sprintf_tests, sprintf_8_g);
  tcase_add_test(s21_sprintf_tests, sprintf_9_g);
  tcase_add_test(s21_sprintf_tests, sprintf_10_g);
  tcase_add_test(s21_sprintf_tests, sprintf_11_g);
  tcase_add_test(s21_sprintf_tests, sprintf_12_g);
  tcase_add_test(s21_sprintf_tests, sprintf_13_g);
  tcase_add_test(s21_sprintf_tests, sprintf_14_g);
  tcase_add_test(s21_sprintf_tests, sprintf_15_g);
  tcase_add_test(s21_sprintf_tests, sprintf_16_g);
  tcase_add_test(s21_sprintf_tests, sprintf_17_g);
  tcase_add_test(s21_sprintf_tests, sprintf_18_g);
  tcase_add_test(s21_sprintf_tests, sprintf_19_g);
  tcase_add_test(s21_sprintf_tests, sprintf_20_g);
  tcase_add_test(s21_sprintf_tests, sprintf_21_g);
  tcase_add_test(s21_sprintf_tests, sprintf_22_g);
  tcase_add_test(s21_sprintf_tests, sprintf_23_g);
  tcase_add_test(s21_sprintf_tests, sprintf_24_g);
  tcase_add_test(s21_sprintf_tests, sprintf_25_g);
  tcase_add_test(s21_sprintf_tests, sprintf_26_g);
  tcase_add_test(s21_sprintf_tests, sprintf_27_g);
  tcase_add_test(s21_sprintf_tests, sprintf_28_g);
  tcase_add_test(s21_sprintf_tests, sprintf_29_g);
  tcase_add_test(s21_sprintf_tests, sprintf_30_g);
  tcase_add_test(s21_sprintf_tests, sprintf_31_g);
  tcase_add_test(s21_sprintf_tests, sprintf_32_g);
  tcase_add_test(s21_sprintf_tests, sprintf_33_g);
  tcase_add_test(s21_sprintf_tests, sprintf_34_g);
  tcase_add_test(s21_sprintf_tests, sprintf_35_g);
  tcase_add_test(s21_sprintf_tests, sprintf_36_g);
  tcase_add_test(s21_sprintf_tests, sprintf_37_g);
  tcase_add_test(s21_sprintf_tests, sprintf_38_g);
  tcase_add_test(s21_sprintf_tests, sprintf_39_g);
  tcase_add_test(s21_sprintf_tests, sprintf_40_g);
  tcase_add_test(s21_sprintf_tests, sprintf_41_g);
  tcase_add_test(s21_sprintf_tests, sprintf_42_g);
  tcase_add_test(s21_sprintf_tests, sprintf_43_g);
  tcase_add_test(s21_sprintf_tests, sprintf_1_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_2_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_3_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_4_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_5_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_6_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_7_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_8_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_9_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_10_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_11_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_12_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_13_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_14_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_15_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_16_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_17_hex);
  tcase_add_test(s21_sprintf_tests, sprintf_1_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_2_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_3_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_4_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_5_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_6_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_7_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_8_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_9_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_10_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_11_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_12_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_13_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_14_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_15_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_16_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_17_signed_i);
  tcase_add_test(s21_sprintf_tests, sprintf_1_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_2_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_3_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_4_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_5_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_6_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_7_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_8_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_9_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_10_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_11_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_12_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_13_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_14_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_15_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_16_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_17_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_18_octal);
  tcase_add_test(s21_sprintf_tests, sprintf_1_percent);
  tcase_add_test(s21_sprintf_tests, sprintf_2_percent);
  tcase_add_test(s21_sprintf_tests, sprintf_3_percent);
  tcase_add_test(s21_sprintf_tests, sprintf_1_string);
  tcase_add_test(s21_sprintf_tests, sprintf_2_string);
  tcase_add_test(s21_sprintf_tests, sprintf_3_string);
  tcase_add_test(s21_sprintf_tests, sprintf_4_string);  // WCHAR
  tcase_add_test(s21_sprintf_tests, sprintf_5_string);
  tcase_add_test(s21_sprintf_tests, sprintf_6_string);
  tcase_add_test(s21_sprintf_tests, sprintf_7_string);
  tcase_add_test(s21_sprintf_tests, sprintf_8_string);
  tcase_add_test(s21_sprintf_tests, sprintf_9_string);
  tcase_add_test(s21_sprintf_tests, sprintf_10_string);
  tcase_add_test(s21_sprintf_tests, sprintf_11_string);
  tcase_add_test(s21_sprintf_tests, sprintf_12_string);
  tcase_add_test(s21_sprintf_tests, sprintf_13_string);
  tcase_add_test(s21_sprintf_tests, sprintf_14_string);
  tcase_add_test(s21_sprintf_tests, sprintf_15_string);
  tcase_add_test(s21_sprintf_tests, sprintf_16_string);
  // tcase_add_test(s21_sprintf_tests, sprintf_17_string);
  tcase_add_test(s21_sprintf_tests, sprintf_1_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_2_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_3_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_4_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_5_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_6_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_7_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_8_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_9_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_10_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_11_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_12_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_13_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_14_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_15_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_16_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_17_unsigned);
  tcase_add_test(s21_sprintf_tests, sprintf_1_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_2_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_3_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_4_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_5_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_6_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_7_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_8_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_9_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_10_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_11_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_12_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_13_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_14_pointer);
  tcase_add_test(s21_sprintf_tests, sprintf_15_pointer);

  return s21_suite_1;
}

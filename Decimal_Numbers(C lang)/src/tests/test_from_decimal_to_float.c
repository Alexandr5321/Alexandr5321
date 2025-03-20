// #include "../print_s21_decimal.h"
// #include "../s21_decimal.h"
// #include "s21_check.h"
#include "tests.h"

// Должно быть 7 значимых цифр в float. Если больше, то округлять к ближайшему
// (к седьмой цифре)

START_TEST(decimal_to_float_test_1) {
  s21_decimal decimal = {
      {0b00000000000001010000001010001000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000110000000000000000}};
  float src = 0.0f;
  float result = 328.328;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_2) {
  s21_decimal decimal = {
      {0b00000000010001010000001010001000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000110000000000000000}};
  float src = 0.0f;
  float result = 4522.632f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_3) {
  s21_decimal decimal = {
      {0b00000000001000010001001010001000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001010000000000000000}};
  float src = 0.0f;
  float result = 21.67432f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_4) {
  s21_decimal decimal = {
      {0b00000000000100001000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  float src = 0.0f;
  float result = 10813.44f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_5) {
  s21_decimal decimal = {
      {0b0000000000001011000010010001000100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  float src = 0.0f;
  float result = 2892868.0f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_6) {
  // 000110101001
  s21_decimal decimal = {
      {0b00000000000000000000000110101001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000100000000000000000}};
  float src = 0.0f;
  float result = -4.25f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_7) {
  s21_decimal decimal = {
      {0b00000000001111010010010001000100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  float src = 0.0f;
  float result = 40069.80f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_8) {
  s21_decimal decimal = {
      {0b01010010100101000100000000000000, 0b00000000000000000000001110100011,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  float src = 0.0f;
  float result = -4000000000000.0f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_9) {
  s21_decimal decimal = {
      {0b00000000001111010010010001000101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000001000000000000000000}};
  float src = 0.0f;
  float result = -400.6981f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_10) {
  s21_decimal decimal = {
      {0b00000110000011111111111111111111,  // 10171.1871  ->(семь знаков) ->
                                            // 10171.19
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b10000000000001000000000000000000}};
  float src = 0.0f;
  float result = -10171.1871f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_11) {
  s21_decimal decimal = {
      {0b00000000101111110010010001100101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000001000000000000000000}};
  float src = 0.0f;
  float result = -1252.6693f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_12) {
  s21_decimal decimal = {
      {0b01101000111111111111111110000000,  // 176160.7552 -> 176160.8
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b10000000000001000000000000000000}};
  float src = 0.0f;
  float result = -176160.7552f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_13) {
  s21_decimal decimal = {
      {0b01111111111111111111111111111111,  // 2147483647 -> 214748.4
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000001000000000000000000}};
  float src = 0.0f;
  float result = 214748.3647f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_14) {
  s21_decimal decimal1 = decimal_from_string("0.00003003000030003");
  float src = 0.0f;
  float result = 0.00003003000030003f;
  s21_from_decimal_to_float(decimal1, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_15) {
  s21_decimal decimal = decimal_from_string("7.9228162514264337593543950335");
  float src = 0.0f;
  long double result = 7.9228162514264337593543950335f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_16) {
  s21_decimal decimal = decimal_from_string("792281625.14264337593543950335");
  float src = 0.0f;
  long double result = 792281625.14264337593543950335f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_17) {
  s21_decimal decimal = decimal_from_string("1e-28");
  float src = 0.0f;
  long double result = 1e-28f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_18) {
  s21_decimal decimal = decimal_from_string("0.0");
  float src = 0.0f;
  long double result = 0.0f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_19) {  // биты с 24 до 30 не пусты - ошибка
  s21_decimal decimal = {
      {0b01111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b0000000100000000000000000000000}};
  float src = 0.0f;
  long double result = 0.0f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

START_TEST(decimal_to_float_test_20) {  // биты с 0 до 15 не пусты - ошибка
  s21_decimal decimal = {
      {0b01111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b0000000000000000000000000001000}};
  float src = 0.0f;
  long double result = 0.0f;
  s21_from_decimal_to_float(decimal, &src);
  ck_assert_float_eq(src, result);
}
END_TEST

Suite *suite_from_decimal_to_float(void) {
  Suite *s1 = suite_create("decimal_to_float_suite");
  TCase *tc1_1 = tcase_create("decimal_to_float_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, decimal_to_float_test_1);
  tcase_add_test(tc1_1, decimal_to_float_test_2);
  tcase_add_test(tc1_1, decimal_to_float_test_3);
  tcase_add_test(tc1_1, decimal_to_float_test_4);
  tcase_add_test(tc1_1, decimal_to_float_test_5);
  tcase_add_test(tc1_1, decimal_to_float_test_6);
  tcase_add_test(tc1_1, decimal_to_float_test_7);
  tcase_add_test(tc1_1, decimal_to_float_test_8);
  tcase_add_test(tc1_1, decimal_to_float_test_9);
  tcase_add_test(tc1_1, decimal_to_float_test_10);
  tcase_add_test(tc1_1, decimal_to_float_test_11);
  tcase_add_test(tc1_1, decimal_to_float_test_12);
  tcase_add_test(tc1_1, decimal_to_float_test_13);
  tcase_add_test(tc1_1, decimal_to_float_test_14);
  tcase_add_test(tc1_1, decimal_to_float_test_15);
  tcase_add_test(tc1_1, decimal_to_float_test_16);
  tcase_add_test(tc1_1, decimal_to_float_test_17);
  tcase_add_test(tc1_1, decimal_to_float_test_18);
  tcase_add_test(tc1_1, decimal_to_float_test_19);
  tcase_add_test(tc1_1, decimal_to_float_test_20);

  return s1;
}
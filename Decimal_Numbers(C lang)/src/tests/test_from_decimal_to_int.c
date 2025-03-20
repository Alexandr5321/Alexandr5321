// #include "../s21_decimal.h"
// #include "s21_check.h"
#include "tests.h"

START_TEST(decimal_to_int_test_1) {
  s21_decimal decimal = {
      {0b00000000000001010000001010001000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = 328328;
  // int result;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_2) {
  s21_decimal decimal = {
      {0b01111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001000000000000000000}};
  int src = 0;
  int result = 214748;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_3) {
  s21_decimal decimal = {
      {0b00110101011100000000001000001001, 0b00000000010000100010000100000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_4) {
  s21_decimal decimal = {
      {0b01111011011111011101101111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001100000000000000000}};
  int src = 0;
  int result = 2071;  // 2071.845887
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_5) {
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_6) {
  s21_decimal decimal = {
      {0b00000000000000000000000000000001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = 1;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_7) {
  s21_decimal decimal = {
      {0b00000000000000011101101111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  int src = 0;
  int result = -121855;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_8) {
  s21_decimal decimal = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = (int)4294967295;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_9) {
  s21_decimal decimal = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_10) {
  s21_decimal decimal = {
      {0b00001111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000010000000000000000000}};
  int src = 0;
  int result = 2;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_11) {
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_12) {  // биты с 24 до 30 не пусты - ошибка
  s21_decimal decimal = {
      {0b01111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b0000000100000000000000000000000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

START_TEST(decimal_to_int_test_13) {  // биты с 0 до 15 не пусты - ошибка
  s21_decimal decimal = {
      {0b01111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b0000000000000000000000000001000}};
  int src = 0;
  int result = 0;
  s21_from_decimal_to_int(decimal, &src);
  ck_assert_int_eq(src, result);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s1 = suite_create("decimal_to_int_suite");
  TCase *tc1_1 = tcase_create("decimal_to_int_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, decimal_to_int_test_1);
  tcase_add_test(tc1_1, decimal_to_int_test_2);
  tcase_add_test(tc1_1, decimal_to_int_test_3);
  tcase_add_test(tc1_1, decimal_to_int_test_4);
  tcase_add_test(tc1_1, decimal_to_int_test_5);
  tcase_add_test(tc1_1, decimal_to_int_test_6);
  tcase_add_test(tc1_1, decimal_to_int_test_7);
  tcase_add_test(tc1_1, decimal_to_int_test_8);
  tcase_add_test(tc1_1, decimal_to_int_test_9);
  tcase_add_test(tc1_1, decimal_to_int_test_10);
  tcase_add_test(tc1_1, decimal_to_int_test_11);
  tcase_add_test(tc1_1, decimal_to_int_test_12);
  tcase_add_test(tc1_1, decimal_to_int_test_13);

  return s1;
}
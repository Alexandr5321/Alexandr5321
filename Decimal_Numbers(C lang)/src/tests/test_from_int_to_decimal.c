// #include "../s21_decimal.h"
// #include "s21_check.h"
#include "tests.h"

START_TEST(int_to_decimal_test_1) {
  int src = 284755;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000001000101100001010011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_2) {
  int src = 2147483647;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b01111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_3) {
  int src = -2147483648;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b10000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  // print_d(decimal);
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_4) {
  int src = 284;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000100011100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_5) {
  int src = -3435351;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);

  s21_decimal result = {
      {0b00000000001101000110101101010111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b10000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_6) {
  int src = 0;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_7) {
  int src = 284;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000100011100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // print_d(decimal);
  // printf("decimal=%d result=%d\n", get_scale(decimal), get_scale(result));
  // print_d(result);
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_8) {
  int src = 0;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_9) {
  int src = -0;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_int_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // print_d(decimal);
  // printf("\n");
  // print_d(result);
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(int_to_decimal_test_10) {
  int src = 0;
  s21_decimal decimal = {
      {0b00000000000000010000000001000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  int k = s21_from_int_to_decimal(src, &decimal);
  ck_assert_int_eq(0, k);
}
END_TEST

Suite *suite_from_int_to_decimal(void) {
  Suite *s1 = suite_create("int_to_decimal_suite");
  TCase *tc1_1 = tcase_create("int_to_decimal_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, int_to_decimal_test_1);
  tcase_add_test(tc1_1, int_to_decimal_test_2);
  tcase_add_test(tc1_1, int_to_decimal_test_3);
  tcase_add_test(tc1_1, int_to_decimal_test_4);
  tcase_add_test(tc1_1, int_to_decimal_test_5);
  tcase_add_test(tc1_1, int_to_decimal_test_6);
  tcase_add_test(tc1_1, int_to_decimal_test_7);
  tcase_add_test(tc1_1, int_to_decimal_test_8);
  tcase_add_test(tc1_1, int_to_decimal_test_9);
  tcase_add_test(tc1_1, int_to_decimal_test_10);

  return s1;
}
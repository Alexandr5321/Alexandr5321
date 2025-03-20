// #include "../print_s21_decimal.h"
// #include "../s21_decimal.h"
// #include "s21_check.h"
#include "tests.h"

START_TEST(float_to_decimal_test_1) {
  float src = 7.25f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000001011010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000100000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_2) {
  float src = 0.0f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_3) {
  float src = 100001e-12f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000011000011010100001, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000011000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_4) {
  float src = 12.2523f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000011101111010011011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_5) {
  float src = 123.7492f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000100101110000111110100, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_6) {
  float src = 0.1232312f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000100101100110110111000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001110000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_7) {
  float src = 1234567.0f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000100101101011010000111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  // print_d(decimal);
  // printf("decimal=%d result=%d\n", get_scale(decimal), get_scale(result));
  // print_d(result);
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_8) {
  float src = 4824963.0f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000010010011001111110000011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_9) {
  float src = 54.23245f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000010100101100000010001101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000001010000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_10) {
  float src = 5.9f;
  s21_decimal decimal = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = {
      {0b00000000000000000000000000111011, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000010000000000000000}};
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_11) {
  float src = 1.0f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("1");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_12) {
  float src = 7.9228162514264337593543950335f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("7.922816");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_13) {
  float src = 123456789.0f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("1234568");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_14) {
  float src = 1e-28f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("1e-28");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_15) {
  float src = 10.0f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("10");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_16) {
  float src = 0.0000000000000000000412f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("0.0000000000000000000412");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_17) {
  float src = 0.00000000000000023232412f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("0.0000000000000002323241");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_18) {
  float src = 23232412.0f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("2323241");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_19) {
  // 7.9228162514264337593543950335
  float src = 10000000000000000000000000000.0f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("9999999");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_20) {
  // 7.9228162514264337593543950335
  float src = 0.023023030000003203020302000302f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("2302303e-8");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_21) {
  // 7.9228162514264337593543950335
  float src = 79228162514264337593543950.335f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("7922817");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_22) {
  // 7.9228162514264337593543950335
  float src = 7922816251426433759354395033.5f;
  // float src = 1e+28f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("7922816");
  // print_d(decimal);
  // printf("!!dec=%d!!res=%d!!\n", get_scale(decimal), get_scale(result));
  // print_d(result);
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_23) {
  // 7.9228162514264337593543950335
  float src = 7922.8162514264337593543950335f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("7922.816");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

START_TEST(float_to_decimal_test_24) {
  // 7.9228162514264337593543950335
  float src = -7922816251426433759354395033.5f;
  s21_decimal decimal = decimal_from_string("0");
  s21_from_float_to_decimal(src, &decimal);
  s21_decimal result = decimal_from_string("-7922816");
  ck_assert_int_eq(0, compare(decimal, result));
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s1 = suite_create("float_to_decimal_suite");
  TCase *tc1_1 = tcase_create("float_to_decimal_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, float_to_decimal_test_1);
  tcase_add_test(tc1_1, float_to_decimal_test_2);
  tcase_add_test(tc1_1, float_to_decimal_test_3);
  tcase_add_test(tc1_1, float_to_decimal_test_4);
  tcase_add_test(tc1_1, float_to_decimal_test_5);
  tcase_add_test(tc1_1, float_to_decimal_test_6);
  tcase_add_test(tc1_1, float_to_decimal_test_7);
  tcase_add_test(tc1_1, float_to_decimal_test_8);
  tcase_add_test(tc1_1, float_to_decimal_test_9);
  tcase_add_test(tc1_1, float_to_decimal_test_10);
  tcase_add_test(tc1_1, float_to_decimal_test_11);
  tcase_add_test(tc1_1, float_to_decimal_test_12);
  tcase_add_test(tc1_1, float_to_decimal_test_13);
  tcase_add_test(tc1_1, float_to_decimal_test_14);
  tcase_add_test(tc1_1, float_to_decimal_test_15);
  tcase_add_test(tc1_1, float_to_decimal_test_16);
  tcase_add_test(tc1_1, float_to_decimal_test_17);
  tcase_add_test(tc1_1, float_to_decimal_test_18);
  tcase_add_test(tc1_1, float_to_decimal_test_19);
  tcase_add_test(tc1_1, float_to_decimal_test_20);
  tcase_add_test(tc1_1, float_to_decimal_test_21);
  tcase_add_test(tc1_1, float_to_decimal_test_22);
  tcase_add_test(tc1_1, float_to_decimal_test_23);
  tcase_add_test(tc1_1, float_to_decimal_test_24);
  return s1;
}
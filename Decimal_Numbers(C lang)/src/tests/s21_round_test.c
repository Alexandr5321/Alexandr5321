#include "tests.h"

START_TEST(round_test_1) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x10000}};  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999,
                                0x0}};  // 7922816251426433759354395034
  s21_decimal result = {0};
  s21_round(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(round_test_2) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x20000}};  // 792281625142643375935439503.35
  s21_decimal decimal_check = {
      {0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};  // 792281625142643375935439503
  s21_decimal result = {0};
  s21_round(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(round_test_3) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x50000}};  // 792281625142643375935439.50335
  s21_decimal decimal_check = {
      {0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};  // 792281625142643375935440
  s21_decimal result = {0};
  s21_round(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(round_test_4) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x80060000}};  // -79228162514264337593543.950335
  s21_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6,
                                0x80000000}};  // -79228162514264337593544
  s21_decimal result = {0};
  s21_round(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(round_test_5) {
  s21_decimal decimal = {{50, 0, 0, 0x10000}};  // 5
  s21_decimal decimal_check = {{5, 0, 0, 0}};   // 5
  s21_decimal result = {0};
  // print_d_harsleyb(decimal);
  s21_round(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

Suite *suite_round(void) {
  Suite *s1 = suite_create("round_suite");
  TCase *tc1_1 = tcase_create("round_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, round_test_1);
  tcase_add_test(tc1_1, round_test_2);
  tcase_add_test(tc1_1, round_test_3);
  tcase_add_test(tc1_1, round_test_4);
  tcase_add_test(tc1_1, round_test_5);

  return s1;
}

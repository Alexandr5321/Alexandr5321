#include "tests.h"

START_TEST(floor_test_1) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x80000000}};  // -79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                                0x80000000}};  // -79228162514264337593543950335
  s21_decimal result = {0};
  s21_floor(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(floor_test_2) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x10000}};  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999,
                                0x0}};  // 7922816251426433759354395033
  s21_decimal result = {0};
  s21_floor(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(floor_test_3) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x10000}};  // 7922816251426433759354395033.5
  s21_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999,
                                0x0}};  // 7922816251426433759354395033
  s21_decimal result = {0};
  s21_floor(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(floor_test_4) {
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                          0x80010000}};  // -7922816251426433759354395033.5
  s21_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999,
                                0x80000000}};  // -7922816251426433759354395034
  s21_decimal result = {0};
  s21_floor(decimal, &result);
  ck_assert_int_eq(s21_is_equal(result, decimal_check), 1);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s1 = suite_create("floor_suite");
  TCase *tc1_1 = tcase_create("floor_tcase");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, floor_test_1);
  tcase_add_test(tc1_1, floor_test_2);
  tcase_add_test(tc1_1, floor_test_3);
  tcase_add_test(tc1_1, floor_test_4);

  return s1;
}

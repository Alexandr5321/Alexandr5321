#include "tests.h"

START_TEST(test_sub_0) {
  s21_decimal decimal_1 = decimal_from_string("5");
  s21_decimal decimal_2 = decimal_from_string("3");
  s21_decimal true_decimal = decimal_from_string("2");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_1) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("-0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  // printf("1 decimal\n");
  // print_d(decimal_1);
  // printf("2 decimal\n");
  // print_d(decimal_2);
  // printf("result\n");
  // print_d(decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_2) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*0:number*/
START_TEST(test_sub_4) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_5) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_6) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_7) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*number:0*/
START_TEST(test_sub_8) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_9) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_10) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_11) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-1");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950334");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:marginal_values*/
START_TEST(test_sub_12) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950334");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_13) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950334");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_14) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  // printf("1 decimal\n");
  // print_d(decimal_1);
  // printf("2 decimal\n");
  // print_d(decimal_2);
  // printf("result\n");
  // print_d(decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_15) {
  s21_decimal decimal_1 = decimal_from_string("792281625142");
  s21_decimal decimal_2 = decimal_from_string("1e-9");
  s21_decimal true_decimal = decimal_from_string("792281625141999999999e-9");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:marginal_values*/
START_TEST(test_sub_16) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-5");
  s21_decimal decimal_2 = decimal_from_string("792281625142643375935439");
  s21_decimal true_decimal = decimal_from_string("50335e-5");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_17) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("69228162514264337593543950335e-28");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_18) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_19) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950334e-28");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:marginal_values*/
START_TEST(test_sub_20) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950334");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_21) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_22) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("-69228162514264337593543950335e-28");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_23) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("0.9999999999999999999999999999");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:marginal_values*/
START_TEST(test_sub_24) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 =
      decimal_from_string("-79228162514264337593543950334e-28");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_25) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("-0.9999999999999999999999999999");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_26) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950334e-28");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_27) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 0*/
START_TEST(test_sub_28) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337589248983040");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_29) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950334");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("-1");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_sub_30) {
  s21_decimal decimal_1 = decimal_from_string("79142643335");
  s21_decimal decimal_2 = decimal_from_string("1.556546867");
  s21_decimal true_decimal = decimal_from_string("79142643333.443453133");
  s21_decimal decimal_result = {0};
  s21_sub(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

Suite *suite_test_sub(void) {
  Suite *s1 = suite_create("suite_test_sub");
  TCase *tc1_1 = tcase_create("suite_test_sub");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_sub_0);
  tcase_add_test(tc1_1, test_sub_1);
  tcase_add_test(tc1_1, test_sub_2);
  tcase_add_test(tc1_1, test_sub_4);
  tcase_add_test(tc1_1, test_sub_5);
  tcase_add_test(tc1_1, test_sub_6);
  tcase_add_test(tc1_1, test_sub_7);
  tcase_add_test(tc1_1, test_sub_8);
  tcase_add_test(tc1_1, test_sub_9);
  tcase_add_test(tc1_1, test_sub_10);
  tcase_add_test(tc1_1, test_sub_11);
  tcase_add_test(tc1_1, test_sub_12);
  tcase_add_test(tc1_1, test_sub_13);
  tcase_add_test(tc1_1, test_sub_14);
  tcase_add_test(tc1_1, test_sub_15);
  tcase_add_test(tc1_1, test_sub_16);
  tcase_add_test(tc1_1, test_sub_17);
  tcase_add_test(tc1_1, test_sub_18);
  tcase_add_test(tc1_1, test_sub_19);
  tcase_add_test(tc1_1, test_sub_20);
  tcase_add_test(tc1_1, test_sub_21);
  tcase_add_test(tc1_1, test_sub_22);
  tcase_add_test(tc1_1, test_sub_23);
  tcase_add_test(tc1_1, test_sub_24);
  tcase_add_test(tc1_1, test_sub_25);
  tcase_add_test(tc1_1, test_sub_26);
  tcase_add_test(tc1_1, test_sub_27);
  tcase_add_test(tc1_1, test_sub_28);
  tcase_add_test(tc1_1, test_sub_29);
  tcase_add_test(tc1_1, test_sub_30);

  return s1;
}

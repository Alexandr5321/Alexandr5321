#include "tests.h"

/*0+0*/
START_TEST(test_add_0) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_1) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("-0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_2) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_3) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("-0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*0+number*/
START_TEST(test_add_4) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_5) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_6) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_7) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*number+0*/
START_TEST(test_add_8) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_9) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_10) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_11) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal =
      decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:marginal_values*/
START_TEST(test_add_12) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_13) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_14) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_15) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:marginal_values*/
START_TEST(test_add_16) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_17) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("8.922816251426433759354395034");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_18) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("15.845632502852867518708790067");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_19) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("7.922816251426433759354395034");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:marginal_values*/
START_TEST(test_add_20) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_21) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("2");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_22) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("8.922816251426433759354395034");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_23) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("1.0000000000000000000000000001");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:marginal_values*/
START_TEST(test_add_24) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_25) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("1.0000000000000000000000000001");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_26) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("7.922816251426433759354395034");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_27) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string("2e-28");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 0*/
START_TEST(test_add_28) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_29) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_30) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_31) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_32) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_33) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 14*/
START_TEST(test_add_34) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_35) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_36) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_37) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 26409387498605864508043122005
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_38) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_39) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_40) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 28*/
START_TEST(test_add_41) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_42) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_43) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_44) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_45) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_46) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 0*/
START_TEST(test_add_47) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal =
      decimal_from_string("4294967302.9228162514264337594");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_48) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal =
      decimal_from_string("18446744069414584327.922816251");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_49) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593519834398728");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_50) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593524129366023");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_51) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337589248983048");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_52) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("18446744073709551622.922816251");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 14*/
START_TEST(test_add_53) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal =
      decimal_from_string("7.922830567984083759354395034");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_54) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal =
      decimal_from_string("61497.069714300040833759354395");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_55) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("264093874986066.56788236608883");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_56) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("264093874986066.56789668264648");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_57) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("264093875047555.71478041470323");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_58) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal =
      decimal_from_string("61497.069728616598483759354395");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_59) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal =
      decimal_from_string("264093875047555.71479473126088");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 28*/
START_TEST(test_add_60) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("7.922816251426433759783891763");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_61) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("7.922816253271108166295853466");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_62) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("15.845632501008193111337834906");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_63) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("15.845632501008193111767331635");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_64) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("15.845632502852867518279293338");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_65) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("7.922816253271108166725350195");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 0*/
START_TEST(test_add_66) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string("4294967296");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_67) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string("18446744069414584321");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_68) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593519834398721");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_69) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593524129366016");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_70) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337589248983041");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_71) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string("18446744073709551616");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_add_72) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string("1.00001431655765");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_73) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = {
      {0b00010000011110100100000000000000, 0b01010101010101011011000001001000,
       0b00000000000000000000000000000000, 0b00000000000011100000000000000000}};
  // s21_decimal true_decimal = decimal_from_string("61490.1468980486144");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_74) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("264093874986059.64506611466240");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_75) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("264093874986059.64508043122005");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_76) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("264093875047548.79196416327680");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_77) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string("61490.14691236517205");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_78) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal =
      decimal_from_string("264093875047548.79197847983445");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 28*/
START_TEST(test_add_79) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("1.0000000000000000004294967295");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_80) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("1.0000000018446744069414584320");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_81) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("8.922816249581759351983439872");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_82) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("8.922816249581759352412936602");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_83) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("8.922816251426433758924898304");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_84) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("1.0000000018446744073709551615");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 0*/
START_TEST(test_add_85) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal =
      decimal_from_string("4294967295.0000000000000000000");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_86) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal =
      decimal_from_string("18446744069414584320.000000000");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_87) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593519834398720");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_88) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("79228162495817593524129366015");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_89) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337589248983040");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_90) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("18446744073709551615.000000000");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_add_91) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal =
      decimal_from_string("0.0000143165576500000000000001");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_92) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal =
      decimal_from_string("61489.146898048614400000000000");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_93) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("264093874986058.64506611466240");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_94) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("264093874986058.64508043122005");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_95) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("264093875047547.79196416327680");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_96) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal =
      decimal_from_string("61489.146912365172050000000000");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_97) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal =
      decimal_from_string("264093875047547.79197847983445");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 28*/
START_TEST(test_add_98) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000004294967296");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_99) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("0.0000000018446744069414584321");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_100) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("7.9228162495817593519834398721");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_101) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("7.9228162495817593524129366016");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_102) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("7.9228162514264337589248983041");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_103) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("0.0000000018446744073709551616");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*error codes*/
START_TEST(test_add_104) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  int true_int_result = 0;
  s21_decimal decimal_result = {0};
  int result_div = s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_add_105) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  int true_int_result = 1;
  s21_decimal decimal_result = {0};
  int result_div = s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_add_106) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  int true_int_result = 2;
  s21_decimal decimal_result = {0};
  int result_div = s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

/*rounding*/
START_TEST(test_add_107) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("10e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395034");  // 7.9228162514264337593543950345 ->
                                         // 7922816251426433759354395034.5 ->
                                         // цел часть четн значит банковское-->
                                         // 7922816251426433759354395034
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_108) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("11e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395035");  // 7.9228162514264337593543950346 ->
                                         // 7922816251426433759354395034.6 -> +1
                                         // --> 7922816251426433759354395035
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_109) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("9e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395034");  // 7.9228162514264337593543950344 ->
                                         // 7922816251426433759354395034.4 ->
                                         // оставляем как есть-->
                                         // 7922816251426433759354395034
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_110) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("20e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395036");  // 7.9228162514264337593543950355 ->
                                         // 7922816251426433759354395035.5 ->
                                         // цел часть Нечетн значит +1
                                         // --> 7.922816251426433759354395036
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_111) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("21e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395036");  // 7.9228162514264337593543950356 ->
                                         // 7922816251426433759354395035.6 -> +1
                                         // --> 7.922816251426433759354395036
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_112) {
  s21_decimal decimal_1 = decimal_from_string("7.9228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("19e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.922816251426433759354395035");  // 7.9228162514264337593543950354 ->
                                         // 7922816251426433759354395035.4 ->
                                         // ост как есть
                                         // --> 7.922816251426433759354395035
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_add_113) {
  s21_decimal decimal_1 = decimal_from_string("50");
  s21_decimal decimal_2 = decimal_from_string("-100");
  s21_decimal true_decimal = decimal_from_string("-50");
  s21_decimal decimal_result = {0};
  s21_add(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

Suite *suite_test_add(void) {
  Suite *s1 = suite_create("suite_test_add");
  TCase *tc1_1 = tcase_create("suite_test_add");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_add_0);
  tcase_add_test(tc1_1, test_add_1);
  tcase_add_test(tc1_1, test_add_2);
  tcase_add_test(tc1_1, test_add_3);
  tcase_add_test(tc1_1, test_add_4);
  tcase_add_test(tc1_1, test_add_5);
  tcase_add_test(tc1_1, test_add_6);
  tcase_add_test(tc1_1, test_add_7);
  tcase_add_test(tc1_1, test_add_8);
  tcase_add_test(tc1_1, test_add_9);
  tcase_add_test(tc1_1, test_add_10);
  tcase_add_test(tc1_1, test_add_11);
  tcase_add_test(tc1_1, test_add_12);
  tcase_add_test(tc1_1, test_add_13);
  tcase_add_test(tc1_1, test_add_14);
  tcase_add_test(tc1_1, test_add_15);
  tcase_add_test(tc1_1, test_add_16);
  tcase_add_test(tc1_1, test_add_17);
  tcase_add_test(tc1_1, test_add_18);
  tcase_add_test(tc1_1, test_add_19);
  tcase_add_test(tc1_1, test_add_20);
  tcase_add_test(tc1_1, test_add_21);
  tcase_add_test(tc1_1, test_add_22);
  tcase_add_test(tc1_1, test_add_23);
  tcase_add_test(tc1_1, test_add_24);
  tcase_add_test(tc1_1, test_add_25);
  tcase_add_test(tc1_1, test_add_26);
  tcase_add_test(tc1_1, test_add_27);
  tcase_add_test(tc1_1, test_add_28);
  tcase_add_test(tc1_1, test_add_29);
  tcase_add_test(tc1_1, test_add_30);
  tcase_add_test(tc1_1, test_add_31);
  tcase_add_test(tc1_1, test_add_32);
  tcase_add_test(tc1_1, test_add_33);
  tcase_add_test(tc1_1, test_add_34);
  tcase_add_test(tc1_1, test_add_35);
  tcase_add_test(tc1_1, test_add_36);
  tcase_add_test(tc1_1, test_add_37);
  tcase_add_test(tc1_1, test_add_38);
  tcase_add_test(tc1_1, test_add_39);
  tcase_add_test(tc1_1, test_add_40);
  tcase_add_test(tc1_1, test_add_41);
  tcase_add_test(tc1_1, test_add_42);
  tcase_add_test(tc1_1, test_add_43);
  tcase_add_test(tc1_1, test_add_44);
  tcase_add_test(tc1_1, test_add_45);
  tcase_add_test(tc1_1, test_add_46);
  tcase_add_test(tc1_1, test_add_47);
  tcase_add_test(tc1_1, test_add_48);
  tcase_add_test(tc1_1, test_add_49);
  tcase_add_test(tc1_1, test_add_50);
  tcase_add_test(tc1_1, test_add_51);
  tcase_add_test(tc1_1, test_add_52);
  tcase_add_test(tc1_1, test_add_53);
  tcase_add_test(tc1_1, test_add_54);
  tcase_add_test(tc1_1, test_add_55);
  tcase_add_test(tc1_1, test_add_56);
  tcase_add_test(tc1_1, test_add_57);
  tcase_add_test(tc1_1, test_add_58);
  tcase_add_test(tc1_1, test_add_59);
  tcase_add_test(tc1_1, test_add_60);
  tcase_add_test(tc1_1, test_add_61);
  tcase_add_test(tc1_1, test_add_62);
  tcase_add_test(tc1_1, test_add_63);
  tcase_add_test(tc1_1, test_add_64);
  tcase_add_test(tc1_1, test_add_65);
  tcase_add_test(tc1_1, test_add_66);
  tcase_add_test(tc1_1, test_add_67);
  tcase_add_test(tc1_1, test_add_68);
  tcase_add_test(tc1_1, test_add_69);
  tcase_add_test(tc1_1, test_add_70);
  tcase_add_test(tc1_1, test_add_71);
  tcase_add_test(tc1_1, test_add_72);
  tcase_add_test(tc1_1, test_add_73);
  tcase_add_test(tc1_1, test_add_74);
  tcase_add_test(tc1_1, test_add_75);
  tcase_add_test(tc1_1, test_add_76);
  tcase_add_test(tc1_1, test_add_77);
  tcase_add_test(tc1_1, test_add_78);
  tcase_add_test(tc1_1, test_add_79);
  tcase_add_test(tc1_1, test_add_80);
  tcase_add_test(tc1_1, test_add_81);
  tcase_add_test(tc1_1, test_add_82);
  tcase_add_test(tc1_1, test_add_83);
  tcase_add_test(tc1_1, test_add_84);
  tcase_add_test(tc1_1, test_add_85);
  tcase_add_test(tc1_1, test_add_86);
  tcase_add_test(tc1_1, test_add_87);
  tcase_add_test(tc1_1, test_add_88);
  tcase_add_test(tc1_1, test_add_89);
  tcase_add_test(tc1_1, test_add_90);
  tcase_add_test(tc1_1, test_add_91);
  tcase_add_test(tc1_1, test_add_92);
  tcase_add_test(tc1_1, test_add_93);
  tcase_add_test(tc1_1, test_add_94);
  tcase_add_test(tc1_1, test_add_95);
  tcase_add_test(tc1_1, test_add_96);
  tcase_add_test(tc1_1, test_add_97);
  tcase_add_test(tc1_1, test_add_98);
  tcase_add_test(tc1_1, test_add_99);
  tcase_add_test(tc1_1, test_add_100);
  tcase_add_test(tc1_1, test_add_101);
  tcase_add_test(tc1_1, test_add_102);
  tcase_add_test(tc1_1, test_add_103);
  tcase_add_test(tc1_1, test_add_104);
  tcase_add_test(tc1_1, test_add_105);
  tcase_add_test(tc1_1, test_add_106);
  tcase_add_test(tc1_1, test_add_107);
  tcase_add_test(tc1_1, test_add_108);
  tcase_add_test(tc1_1, test_add_109);
  tcase_add_test(tc1_1, test_add_110);
  tcase_add_test(tc1_1, test_add_111);
  tcase_add_test(tc1_1, test_add_112);
  tcase_add_test(tc1_1, test_add_113);

  return s1;
}

// /*79228162514264337593543950335:intermediate_values, scale = 14*/
// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}}; // 0.00004294967295
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}}; // 184467.4406941458432
//   s21_decimal true_decimal =
//   decimal_from_string("429496729700000000023283.06437"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}}; // 792281624958175.9351983439872
//   s21_decimal true_decimal =
//   decimal_from_string("100000000023283.06437080797375"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("1.0000000002328306436538696288"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("1.0000000000000000000542101086"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("4294967296.0000000002328306436"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 28*/
// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000000000000001431655765
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.000000000614891468980486144
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938749860586450661146624
//   s21_decimal true_decimal =
//   decimal_from_string("30000000006984919311242392126"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("30000000006984919309616088867"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938750475477919641632768
//   s21_decimal true_decimal =
//   decimal_from_string("30000000000000000001626303258"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000006148914691236517205
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387504754779197847983445
//   s21_decimal true_decimal =
//   decimal_from_string("30000000000000000000000000000"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 0*/
// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //1431655765
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000055340232234013556739"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //6148914689804861440
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000012884901891"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387498605864506611466240
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387504754779196416327680
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //6148914691236517205
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000012884901888"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387504754779197847983445
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 28*/
// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000000000000001431655765
//   s21_decimal true_decimal = decimal_from_string("55340232234013556739");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.000000000614891468980486144
//   s21_decimal true_decimal =
//   decimal_from_string("12884901891.000000000698491931"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938749860586450661146624
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000006984919311242392126"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000006984919309616088867"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938750475477919641632768
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000000000000001626303258"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000006148914691236517205
//   s21_decimal true_decimal =
//   decimal_from_string("12884901888.000000000698491931"); s21_decimal
//   decimal_result = {0}; s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_add_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387504754779197847983445
//   s21_decimal true_decimal = decimal_from_string("3");
//   s21_decimal decimal_result = {0};
//   s21_add(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST
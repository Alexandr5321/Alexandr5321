#include "tests.h"

/*0:0*/
START_TEST(test_div_0) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_1) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_2) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_3) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*0:number*/
START_TEST(test_div_4) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_5) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_6) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_7) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*number:0*/
START_TEST(test_div_8) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_9) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_10) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_11) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:marginal_values*/
START_TEST(test_div_12) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_13) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_14) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("10000000000000000000000000000");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_15) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:marginal_values*/
START_TEST(test_div_16) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("1e-28");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_17) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_18) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_19) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:marginal_values*/
START_TEST(test_div_20) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_21) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_22) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal =
      decimal_from_string("0.1262177448353618888658765704");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_23) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal =
      decimal_from_string("10000000000000000000000000000");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:marginal_values*/
START_TEST(test_div_24) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_25) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("1e-28");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_26) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_27) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 0*/
START_TEST(test_div_28) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal = decimal_from_string("18446744078004518913");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_29) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("4294967297.0000000002328306437");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_30) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("1.0000000002328306437080797375");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_31) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("1.0000000002328306436538696289");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_32) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("1.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_33) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("4294967296.0000000002328306436");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 14*/
START_TEST(test_div_34) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_35) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal =
      decimal_from_string("1288490189100000000069849.1931");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_36) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("300000000069849.19311242392126");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_37) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 26409387498605864508043122005
  s21_decimal true_decimal =
      decimal_from_string("300000000069849.19309616088867");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_38) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("300000000000000.00001626303258");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_39) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal =
      decimal_from_string("1288490188800000000069849.1931");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_40) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string("300000000000000");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 28*/
START_TEST(test_div_41) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_42) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_43) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("10000000002328306437080797375");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_44) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("10000000002328306436538696289");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_45) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("10000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_46) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 0*/
START_TEST(test_div_47) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal =
      decimal_from_string("0.0000000018446744078004518913");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_48) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000004294967297");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_49) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111, 0b00000000000000000000000000000000}};
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000000000001");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_50) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000000000001");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_51) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000000000001");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_52) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000004294967296");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 14*/
START_TEST(test_div_53) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string("553402.32234013556739");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_54) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal =
      decimal_from_string("0.0001288490189100000000069849");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_55) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000300000000069849");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_56) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000300000000069849");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_57) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000300000000000000");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_58) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal =
      decimal_from_string("0.0001288490188800000000069849");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_59) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string("0.00000000000003");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 28*/
START_TEST(test_div_60) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string("18446744078004518913");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_61) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("4294967297.0000000002328306437");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_62) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("1.0000000002328306437080797375");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_63) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("1.0000000002328306436538696289");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_64) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("1.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_65) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("4294967296.0000000002328306436");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 0*/
START_TEST(test_div_66) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal =
      decimal_from_string("0.0000000002328306437080797375");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_67) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_68) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_69) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_70) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_71) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_div_72) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal =
      decimal_from_string("69849.193112423921262944098856");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_73) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal =
      decimal_from_string("0.0000162630325910690988560543");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_74) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000037865323459425");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_75) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000037865323459425");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_76) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000037865323450609");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_77) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal =
      decimal_from_string("0.0000162630325872825665109934");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_78) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000037865323450609");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 28*/
START_TEST(test_div_79) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("2328306437080797375.4314699619");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_80) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("542101086.36896996186847564808");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_81) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("0.1262177448647492476432760358");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_82) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal =
      decimal_from_string("0.1262177448647492476364337581");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_83) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("0.1262177448353618888727188481");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_84) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("542101086.24275221703311375921");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 0*/
START_TEST(test_div_85) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_86) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_87) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_88) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_89) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_90) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_div_91) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000000069849");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_92) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_93) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_94) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_95) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_96) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_97) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 28*/
START_TEST(test_div_98) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal =
      decimal_from_string("0.0000000002328306437080797375");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_99) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_100) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_101) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_102) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_div_103) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal =
      decimal_from_string("0.0000000000000000000542101086");
  s21_decimal decimal_result = {0};
  s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*error codes*/
START_TEST(test_div_104) {
  s21_decimal decimal_1 = decimal_from_string("-10");
  s21_decimal decimal_2 = decimal_from_string("10");
  int true_int_result = 0;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_div_105) {
  s21_decimal decimal_1 = decimal_from_string("10");
  s21_decimal decimal_2 = decimal_from_string("0");
  int true_int_result = 3;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_div_106) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  int true_int_result = 1;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_div_107) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  int true_int_result = 1;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_div_108) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  int true_int_result = 2;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_div_109) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-1e-28");
  int true_int_result = 2;
  s21_decimal decimal_result = {0};
  int result_div = s21_div(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

Suite *suite_test_div(void) {
  Suite *s1 = suite_create("suite_test_div");
  TCase *tc1_1 = tcase_create("suite_test_div");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_div_0);
  tcase_add_test(tc1_1, test_div_1);
  tcase_add_test(tc1_1, test_div_2);
  tcase_add_test(tc1_1, test_div_3);
  tcase_add_test(tc1_1, test_div_4);
  tcase_add_test(tc1_1, test_div_5);
  tcase_add_test(tc1_1, test_div_6);
  tcase_add_test(tc1_1, test_div_7);
  tcase_add_test(tc1_1, test_div_8);
  tcase_add_test(tc1_1, test_div_9);
  tcase_add_test(tc1_1, test_div_10);
  tcase_add_test(tc1_1, test_div_11);
  tcase_add_test(tc1_1, test_div_12);
  tcase_add_test(tc1_1, test_div_13);
  tcase_add_test(tc1_1, test_div_14);
  tcase_add_test(tc1_1, test_div_15);
  tcase_add_test(tc1_1, test_div_16);
  tcase_add_test(tc1_1, test_div_17);
  tcase_add_test(tc1_1, test_div_18);
  tcase_add_test(tc1_1, test_div_19);
  tcase_add_test(tc1_1, test_div_20);
  tcase_add_test(tc1_1, test_div_21);
  tcase_add_test(tc1_1, test_div_22);
  tcase_add_test(tc1_1, test_div_23);
  tcase_add_test(tc1_1, test_div_24);
  tcase_add_test(tc1_1, test_div_25);
  tcase_add_test(tc1_1, test_div_26);
  tcase_add_test(tc1_1, test_div_27);
  tcase_add_test(tc1_1, test_div_28);
  tcase_add_test(tc1_1, test_div_29);
  tcase_add_test(tc1_1, test_div_30);
  tcase_add_test(tc1_1, test_div_31);
  tcase_add_test(tc1_1, test_div_32);
  tcase_add_test(tc1_1, test_div_33);
  tcase_add_test(tc1_1, test_div_34);
  tcase_add_test(tc1_1, test_div_35);
  tcase_add_test(tc1_1, test_div_36);
  tcase_add_test(tc1_1, test_div_37);
  tcase_add_test(tc1_1, test_div_38);
  tcase_add_test(tc1_1, test_div_39);
  tcase_add_test(tc1_1, test_div_40);
  tcase_add_test(tc1_1, test_div_41);
  tcase_add_test(tc1_1, test_div_42);
  tcase_add_test(tc1_1, test_div_43);
  tcase_add_test(tc1_1, test_div_44);
  tcase_add_test(tc1_1, test_div_45);
  tcase_add_test(tc1_1, test_div_46);
  tcase_add_test(tc1_1, test_div_47);
  tcase_add_test(tc1_1, test_div_48);
  tcase_add_test(tc1_1, test_div_49);
  tcase_add_test(tc1_1, test_div_50);
  tcase_add_test(tc1_1, test_div_51);
  tcase_add_test(tc1_1, test_div_52);
  tcase_add_test(tc1_1, test_div_53);
  tcase_add_test(tc1_1, test_div_54);
  tcase_add_test(tc1_1, test_div_55);
  tcase_add_test(tc1_1, test_div_56);
  tcase_add_test(tc1_1, test_div_57);
  tcase_add_test(tc1_1, test_div_58);
  tcase_add_test(tc1_1, test_div_59);
  tcase_add_test(tc1_1, test_div_60);
  tcase_add_test(tc1_1, test_div_61);
  tcase_add_test(tc1_1, test_div_62);
  tcase_add_test(tc1_1, test_div_63);
  tcase_add_test(tc1_1, test_div_64);
  tcase_add_test(tc1_1, test_div_65);
  tcase_add_test(tc1_1, test_div_66);
  tcase_add_test(tc1_1, test_div_67);
  tcase_add_test(tc1_1, test_div_68);
  tcase_add_test(tc1_1, test_div_69);
  tcase_add_test(tc1_1, test_div_70);
  tcase_add_test(tc1_1, test_div_71);
  tcase_add_test(tc1_1, test_div_72);
  tcase_add_test(tc1_1, test_div_73);
  tcase_add_test(tc1_1, test_div_74);
  tcase_add_test(tc1_1, test_div_75);
  tcase_add_test(tc1_1, test_div_76);
  tcase_add_test(tc1_1, test_div_77);
  tcase_add_test(tc1_1, test_div_78);
  tcase_add_test(tc1_1, test_div_79);
  tcase_add_test(tc1_1, test_div_80);
  tcase_add_test(tc1_1, test_div_81);
  tcase_add_test(tc1_1, test_div_82);
  tcase_add_test(tc1_1, test_div_83);
  tcase_add_test(tc1_1, test_div_84);
  tcase_add_test(tc1_1, test_div_85);
  tcase_add_test(tc1_1, test_div_86);
  tcase_add_test(tc1_1, test_div_87);
  tcase_add_test(tc1_1, test_div_88);
  tcase_add_test(tc1_1, test_div_89);
  tcase_add_test(tc1_1, test_div_90);
  tcase_add_test(tc1_1, test_div_91);
  tcase_add_test(tc1_1, test_div_92);
  tcase_add_test(tc1_1, test_div_93);
  tcase_add_test(tc1_1, test_div_94);
  tcase_add_test(tc1_1, test_div_95);
  tcase_add_test(tc1_1, test_div_96);
  tcase_add_test(tc1_1, test_div_97);
  tcase_add_test(tc1_1, test_div_98);
  tcase_add_test(tc1_1, test_div_99);
  tcase_add_test(tc1_1, test_div_100);
  tcase_add_test(tc1_1, test_div_101);
  tcase_add_test(tc1_1, test_div_102);
  tcase_add_test(tc1_1, test_div_103);
  tcase_add_test(tc1_1, test_div_104);
  tcase_add_test(tc1_1, test_div_105);
  tcase_add_test(tc1_1, test_div_106);
  tcase_add_test(tc1_1, test_div_107);
  tcase_add_test(tc1_1, test_div_108);
  tcase_add_test(tc1_1, test_div_109);

  return s1;
}

// /*79228162514264337593543950335:intermediate_values, scale = 14*/
// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}}; // 0.00004294967295
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}}; // 184467.4406941458432
//   s21_decimal true_decimal =
//   decimal_from_string("429496729700000000023283.06437"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}}; // 792281624958175.9351983439872
//   s21_decimal true_decimal =
//   decimal_from_string("100000000023283.06437080797375"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("1.0000000002328306436538696288"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
//      0b11111111111111111111111111111111,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("1.0000000000000000000542101086"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//     {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
//      0b00000000000000000000000000000000,
//      0b00000000000011100000000000000000}};
//   s21_decimal true_decimal =
//   decimal_from_string("4294967296.0000000002328306436"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 28*/
// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000000000000001431655765
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.000000000614891468980486144
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938749860586450661146624
//   s21_decimal true_decimal =
//   decimal_from_string("30000000006984919311242392126"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("30000000006984919309616088867"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938750475477919641632768
//   s21_decimal true_decimal =
//   decimal_from_string("30000000000000000001626303258"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000006148914691236517205
//   s21_decimal true_decimal = decimal_from_string("0");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335"); s21_decimal decimal_2
//   = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387504754779197847983445
//   s21_decimal true_decimal =
//   decimal_from_string("30000000000000000000000000000"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 0*/
// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //1431655765
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000055340232234013556739"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //6148914689804861440
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000012884901891"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387498605864506611466240
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387504754779196416327680
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000}}; //6148914691236517205
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000012884901888"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000}}; //26409387504754779197847983445
//   s21_decimal true_decimal =
//   decimal_from_string("0.0000000000000000000000000003"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// /*79228162514264337593543950335:intermediate_values, scale = 28*/
// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
// {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000000000000001431655765
//   s21_decimal true_decimal = decimal_from_string("55340232234013556739");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.000000000614891468980486144
//   s21_decimal true_decimal =
//   decimal_from_string("12884901891.000000000698491931"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938749860586450661146624
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000006984919311242392126"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b00000000000000000000000000000000,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387498605864508043122005
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000006984919309616088867"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b00000000000000000000000000000000,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.640938750475477919641632768
//   s21_decimal true_decimal =
//   decimal_from_string("3.0000000000000000001626303258"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b00000000000000000000000000000000,
//        0b00000000000111000000000000000000}}; //0.0000000006148914691236517205
//   s21_decimal true_decimal =
//   decimal_from_string("12884901888.000000000698491931"); s21_decimal
//   decimal_result = {0}; s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST

// START_TEST(test_div_0) {
//   s21_decimal decimal_1 =
//   decimal_from_string("79228162514264337593543950335e-28"); s21_decimal
//   decimal_2 = {
//       {0b01010101010101010101010101010101,
//       0b01010101010101010101010101010101,
//        0b01010101010101010101010101010101,
//        0b00000000000111000000000000000000}}; //2.6409387504754779197847983445
//   s21_decimal true_decimal = decimal_from_string("3");
//   s21_decimal decimal_result = {0};
//   s21_div(decimal_1, decimal_2, &decimal_result);
//   ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
// }
// END_TEST
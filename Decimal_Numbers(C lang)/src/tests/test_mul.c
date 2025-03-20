#include "tests.h"

/*0:0*/
START_TEST(test_mul_0) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_1) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_2) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_3) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*0:number*/
START_TEST(test_mul_4) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_5) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_6) {
  s21_decimal decimal_1 = decimal_from_string("0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_7) {
  s21_decimal decimal_1 = decimal_from_string("-0");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*number:0*/
START_TEST(test_mul_8) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_9) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_10) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_11) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-0");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:marginal_values*/
START_TEST(test_mul_12) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получается число
             // 6,277,101,735,386,680,763,835,789,423,049,210,091,073,826,769,276,946,612,225
             // и выглядит как переполнение
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_13) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_14) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK
             // 627,710,173,538,668,076,383,578,942,304.9210091073826769276946612225
             // здесь тоже не уверена, но будто переполнение
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_15) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162514264337593543950335");  // OK
                                          // получилось 7.9228162514264337593543950335
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:marginal_values*/
START_TEST(test_mul_16) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,538,668,076,383,578,942,304.9210091073826769276946612225
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_17) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_18) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string(
      "62.771017353866807638357894230");  // OK
                                          // получилось 62.77101735386680763835789423049
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_19) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000000008");  // OK получилось
                                          // 0.00000000000000000000000000079
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:marginal_values*/
START_TEST(test_mul_20) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal =
      decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_21) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("1");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_22) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162514264337593543950335");  // OK
                                          // получилось 7.9228162514264337593543950335
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_23) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string(
      "1e-28");  // OK получилось 0.0000000000000000000000000001
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:marginal_values*/
START_TEST(test_mul_24) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162514264337593543950335");  // OK
                                          // получилось 7.9228162514264337593543950335
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_25) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1");
  s21_decimal true_decimal = decimal_from_string("1e-28");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_26) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000000008");  // OK получилось
                                          // 0.00000000000000000000000000079
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_27) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = decimal_from_string("1e-28");
  s21_decimal true_decimal = decimal_from_string("0");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 0*/
START_TEST(test_mul_28) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 340,282,366,841,710,300,949,110,269,833,929,293,825
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_29) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 1,461,501,636,990,620,551,282,746,369,234,461,668,154,749,747,200
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_30) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 6,277,101,733,925,179,126,504,886,504,924,753,420,890,254,831,288,267,571,200
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_31) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 6,277,101,733,925,179,126,845,168,871,766,463,721,839,365,101,122,196,865,025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_32) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 6,277,101,735,386,680,763,495,507,056,207,499,790,124,716,499,443,017,318,400
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_33) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 1,461,501,637,330,902,918,124,456,670,183,571,937,988,679,041,025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 14*/
START_TEST(test_mul_34) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string(
      "1134274556139034336497034.2328");  // OK получилось
                                          // 1,134,274,556,139,034,336,497,034.23277976431275
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_35) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 4,871,672,123,302,068,504,275,821,230,781,538.893849165824
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_36) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 4,871,672,123,302,068,504,275,821,230,781,538.893849165824
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_37) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 26409387498605864508043122005
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 2,092,367,244,641,726,375,615,056,290,588,821,240,613,121,700,374,065,621,675
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_38) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 20,923,672,451,288,935,878,318,356,854,024,999,300,415,721.664810057728
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_39) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 4,871,672,124,436,343,060,414,855,567,278,573.12662893013675
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_40) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 20,923,672,451,288,935,879,452,631,410,164,033,636,912,755.89758982204075
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335:intermediate_values, scale = 28*/
START_TEST(test_mul_41) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string(
      "34028236684.171030094911026983");  // OK получилось
                                          // 34,028,236,684.1710300949110269833929293825
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_42) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal = decimal_from_string(
      "146150163699062055128.27463692");  // получилось
                                          // 146,150,163,699,062,055,128.27463692344616681547497472
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_43) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,392,517,912,650,488,650,492.47534208902548312882675712
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_44) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,392,517,912,684,516,887,176.6463721839365101122196865025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_45) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,538,668,076,349,550,705,620.74997901247164994430173184
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_46) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "146150163733090291812.44566702");  // OK получилось
                                          // 146,150,163,733,090,291,812.4456670183571937988679041025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 0*/
START_TEST(test_mul_47) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string(
      "34028236684.171030094911026983");  // OK получилось
                                          // 34,028,236,684.1710300949110269833929293825
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_48) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string(
      "146150163699062055128.27463692");  // OK получилось
                                          // 146,150,163,699,062,055,128.27463692344616681547497472
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_49) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,392,517,912,650,488,650,492.47534208902548312882675712
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_50) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,392,517,912,684,516,887,176.6463721839365101122196865025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_51) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string(
      "0");  // OK получилось
             // 627,710,173,538,668,076,349,550,705,620.74997901247164994430173184
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_52) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "146150163733090291812.44566702");  // OK получилось
                                          // 146,150,163,733,090,291,812.4456670183571937988679041025
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 14*/
START_TEST(test_mul_53) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string(
      "00.0001134274556139034336497034");  // OK получилось
                                           // 0.00011342745561390343364970342
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_54) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string(
      "487167.21233020685042758212308");  // OK получилось
                                          // 487,167.21233020685042758212307815388
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_55) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal = decimal_from_string(
      "2092367244641726.3755016288350");  // OK получилось
                                          // 2,092,367,244,641,726.37550162883497491780696341827
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_56) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal = decimal_from_string(
      "2092367244641726.3756150562906");  // OK получилось
                                          // 2,092,367,244,641,726.3756150562905888212406131217
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_57) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal = decimal_from_string(
      "2092367245128893.5878318356854");  // OK получилось
                                          // 2,092,367,245,128,893.58783183568540249993004157216
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_58) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string(
      "487167.21244363430604148555673");  // OK получилось
                                          // 487,167.21244363430604148555672785731
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_59) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string(
      "2092367245128893.5879452631410");  // OK получилось
                                          // 2,092,367,245,128,893.58794526314101640336369127558
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*79228162514264337593543950335e-28:intermediate_values, scale = 28*/
START_TEST(test_mul_60) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000034028236684");  // OK получилось
                                          // 0.00000000000000000340282366841
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_61) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000146150163699062055128");  // OK получилось
                                          // 0.00000001461501636990620551282
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_62) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal = decimal_from_string(
      "62.771017339251791265048865049");  // OK
                                          // получилось 62.77101733925179126504886504924
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_63) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "62.771017339251791268451688718");  // OK
                                          // получилось 62.77101733925179126845168871766
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_64) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal = decimal_from_string(
      "62.771017353866807634955070562");  // OK
                                          // получилось 62.77101735386680763495507056207
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_65) {
  s21_decimal decimal_1 =
      decimal_from_string("79228162514264337593543950335e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000146150163733090291812");  // OK получилось
                                          // 0.00000001461501637330902918124
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 0*/
START_TEST(test_mul_66) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal =
      decimal_from_string("4294967295");  // получилось 4,294,967,295
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_67) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string("18446744069414584320");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_68) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string(
      "79228162495817593519834398720");  // получилось
                                         // 79228162495817593519834398720
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_69) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "79228162495817593524129366015");  // получилось
                                         // 79228162495817593524129366015
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_70) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string(
      "79228162514264337589248983040");  // получилось
                                         // 79228162514264337589248983040
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_71) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string("18446744073709551615");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_mul_72) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string("0.00001431655765");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_73) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string("61489.14689804861440");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_74) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal =
      decimal_from_string("264093874986058.64506611466240");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_75) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal =
      decimal_from_string("264093874986058.64508043122005");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_76) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal =
      decimal_from_string("264093875047547.79196416327680");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_77) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string("61489.14691236517205");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_78) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal =
      decimal_from_string("264093875047547.79197847983445");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 28*/
START_TEST(test_mul_79) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000004294967295");  // не уверена, получилось
                                          // 0.0000000000000000004294967295
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_80) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000018446744069414584320");  // получилось
                                          // 0.000000001844674406941458432
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_81) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal =
      decimal_from_string("7.9228162495817593519834398720");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_82) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162495817593524129366015");  // получилось 7.9228162495817593524129366015
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_83) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal =
      decimal_from_string("7.9228162514264337589248983040");
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_84) {
  s21_decimal decimal_1 = decimal_from_string("1");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000018446744073709551615");  // получилось
                                          // 0.000000001844674407370955161
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 0*/
START_TEST(test_mul_85) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {{0b11111111111111111111111111111111,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000,
                            0b00000000000000000000000000000000}};  // 4294967295
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000004294967295");  //  OK не уверена, получилось
                                          //  0.0000000000000000004294967295
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_86) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744069414584320
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000018446744069414584320");  // получилось
                                          // 0.000000001844674406941458432
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_87) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593519834398720
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162495817593519834398720");  // получилось 7.922816249581759351983439872
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_88) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162495817593524129366015");  // получилось 7.9228162495817593524129366015
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_89) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000000000000000000000000}};  // 79228162514264337589248983040
  s21_decimal true_decimal = decimal_from_string(
      "7.9228162514264337589248983040");  // получилось 7.922816251426433758924898304
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_90) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};  // 18446744073709551615
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000018446744073709551615");  // получилось
                                          // 0.0000000018446744073709551615
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1:intermediate_values, scale = 14*/
START_TEST(test_mul_91) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};            // 0.00001431655765
  s21_decimal true_decimal = decimal_from_string("0");  // получилось 0
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_92) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.1468980486144
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000061489");  // получилось
                                          // 0.00000000000000000000000614891
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_93) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.6450661146624
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000264093874986059");  // получилось
                                          // 0.00000000000002640938749860586
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_94) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b00000000000000000000000000000000,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093874986058.64508043122005
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000264093874986059");  // получилось
                                          // 0.00000000000002640938749860586
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_95) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.7919641632768
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000264093875047548");  // получилось
                                          // 0.00000000000002640938750475477
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_96) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b00000000000000000000000000000000,
       0b00000000000011100000000000000000}};  // 61489.14691236517205
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000061489");  // получилось
                                          // 0.000000000000000000000006148
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_97) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b01010101010101010101010101010101, 0b01010101010101010101010101010101,
       0b01010101010101010101010101010101,
       0b00000000000011100000000000000000}};  // 264093875047547.79197847983445
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000264093875047548");  // получилось
                                          // 0.00000000000002640938750475477
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*1e-28:intermediate_values, scale = 28*/
START_TEST(test_mul_98) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000000000000004294967295
  s21_decimal true_decimal = decimal_from_string("0");  // получилось 0
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_99) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.000000001844674406941458432
  s21_decimal true_decimal = decimal_from_string("0");  // получилось 0
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_100) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816249581759351983439872
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000000008");  // получилось
                                          // 0.00000000000000000000000000079
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_101) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.9228162495817593524129366015
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000000008");  // получилось
                                          // 0.00000000000000000000000000079
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_102) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b00000000000000000000000000000000, 0b11111111111111111111111111111111,
       0b11111111111111111111111111111111,
       0b00000000000111000000000000000000}};  // 7.922816251426433758924898304
  s21_decimal true_decimal = decimal_from_string(
      "0.0000000000000000000000000008");  // получилось
                                          // 0.00000000000000000000000000079
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

START_TEST(test_mul_103) {
  s21_decimal decimal_1 = decimal_from_string("1e-28");
  s21_decimal decimal_2 = {
      {0b11111111111111111111111111111111, 0b11111111111111111111111111111111,
       0b00000000000000000000000000000000,
       0b00000000000111000000000000000000}};  // 0.0000000018446744073709551615
  s21_decimal true_decimal = decimal_from_string("0");  // получилось 0
  s21_decimal decimal_result = {0};
  s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(1, s21_is_equal(decimal_result, true_decimal));
}
END_TEST

/*error codes*/
START_TEST(test_mul_104) {
  s21_decimal decimal_1 = decimal_from_string("-10");
  s21_decimal decimal_2 = decimal_from_string("10");
  int true_int_result = 0;  // не уверена, получилось -100
  s21_decimal decimal_result = {0};
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_mul_105) {
  s21_decimal decimal_1 = decimal_from_string("10");
  s21_decimal decimal_2 = decimal_from_string("0");
  int true_int_result = 0;
  s21_decimal decimal_result = {0};
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_mul_106) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  int true_int_result = 1;
  s21_decimal decimal_result = {
      0};  // предварительный результат -7.92281625142643375935439503 || в
           // калькуляторе получилось -7.9228162514264337593543950335
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_mul_107) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("79228162514264337593543950335");
  int true_int_result = 1;  // как выше
  s21_decimal decimal_result = {0};
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_mul_108) {
  s21_decimal decimal_1 = decimal_from_string("-79228162514264337593543950335");
  s21_decimal decimal_2 =
      decimal_from_string("79228162514264337593543950335");  // как выше
  int true_int_result = 2;
  s21_decimal decimal_result = {0};
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

START_TEST(test_mul_109) {
  s21_decimal decimal_1 = decimal_from_string("79228162514264337593543950335");
  s21_decimal decimal_2 = decimal_from_string("-79228162514264337593543950335");
  int true_int_result = 2;
  s21_decimal decimal_result = {0};
  int result_div = s21_mul(decimal_1, decimal_2, &decimal_result);
  ck_assert_int_eq(result_div, true_int_result);
}
END_TEST

Suite *suite_test_mul(void) {
  Suite *s1 = suite_create("suite_test_mul");
  TCase *tc1_1 = tcase_create("suite_test_mul");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_mul_0);
  tcase_add_test(tc1_1, test_mul_1);
  tcase_add_test(tc1_1, test_mul_2);
  tcase_add_test(tc1_1, test_mul_3);
  tcase_add_test(tc1_1, test_mul_4);
  tcase_add_test(tc1_1, test_mul_5);
  tcase_add_test(tc1_1, test_mul_6);
  tcase_add_test(tc1_1, test_mul_7);
  tcase_add_test(tc1_1, test_mul_8);
  tcase_add_test(tc1_1, test_mul_9);
  tcase_add_test(tc1_1, test_mul_10);
  tcase_add_test(tc1_1, test_mul_11);
  tcase_add_test(tc1_1, test_mul_12);
  tcase_add_test(tc1_1, test_mul_13);
  tcase_add_test(tc1_1, test_mul_14);
  tcase_add_test(tc1_1, test_mul_15);
  tcase_add_test(tc1_1, test_mul_16);
  tcase_add_test(tc1_1, test_mul_17);
  tcase_add_test(tc1_1, test_mul_18);
  tcase_add_test(tc1_1, test_mul_19);
  tcase_add_test(tc1_1, test_mul_20);
  tcase_add_test(tc1_1, test_mul_21);
  tcase_add_test(tc1_1, test_mul_22);
  tcase_add_test(tc1_1, test_mul_23);
  tcase_add_test(tc1_1, test_mul_24);
  tcase_add_test(tc1_1, test_mul_25);
  tcase_add_test(tc1_1, test_mul_26);
  tcase_add_test(tc1_1, test_mul_27);
  tcase_add_test(tc1_1, test_mul_28);
  tcase_add_test(tc1_1, test_mul_29);
  tcase_add_test(tc1_1, test_mul_30);
  tcase_add_test(tc1_1, test_mul_31);
  tcase_add_test(tc1_1, test_mul_32);
  tcase_add_test(tc1_1, test_mul_33);
  tcase_add_test(tc1_1, test_mul_34);
  tcase_add_test(tc1_1, test_mul_35);
  tcase_add_test(tc1_1, test_mul_36);
  tcase_add_test(tc1_1, test_mul_37);
  tcase_add_test(tc1_1, test_mul_38);
  tcase_add_test(tc1_1, test_mul_39);
  tcase_add_test(tc1_1, test_mul_40);
  tcase_add_test(tc1_1, test_mul_41);
  tcase_add_test(tc1_1, test_mul_42);
  tcase_add_test(tc1_1, test_mul_43);
  tcase_add_test(tc1_1, test_mul_44);
  tcase_add_test(tc1_1, test_mul_45);
  tcase_add_test(tc1_1, test_mul_46);
  tcase_add_test(tc1_1, test_mul_47);
  tcase_add_test(tc1_1, test_mul_48);
  tcase_add_test(tc1_1, test_mul_49);
  tcase_add_test(tc1_1, test_mul_50);
  tcase_add_test(tc1_1, test_mul_51);
  tcase_add_test(tc1_1, test_mul_52);
  tcase_add_test(tc1_1, test_mul_53);
  tcase_add_test(tc1_1, test_mul_54);
  tcase_add_test(tc1_1, test_mul_55);
  tcase_add_test(tc1_1, test_mul_56);
  tcase_add_test(tc1_1, test_mul_57);
  tcase_add_test(tc1_1, test_mul_58);
  tcase_add_test(tc1_1, test_mul_59);
  tcase_add_test(tc1_1, test_mul_60);
  tcase_add_test(tc1_1, test_mul_61);
  tcase_add_test(tc1_1, test_mul_62);
  tcase_add_test(tc1_1, test_mul_63);
  tcase_add_test(tc1_1, test_mul_64);
  tcase_add_test(tc1_1, test_mul_65);
  tcase_add_test(tc1_1, test_mul_66);
  tcase_add_test(tc1_1, test_mul_67);
  tcase_add_test(tc1_1, test_mul_68);
  tcase_add_test(tc1_1, test_mul_69);
  tcase_add_test(tc1_1, test_mul_70);
  tcase_add_test(tc1_1, test_mul_71);
  tcase_add_test(tc1_1, test_mul_72);
  tcase_add_test(tc1_1, test_mul_73);
  tcase_add_test(tc1_1, test_mul_74);
  tcase_add_test(tc1_1, test_mul_75);
  tcase_add_test(tc1_1, test_mul_76);
  tcase_add_test(tc1_1, test_mul_77);
  tcase_add_test(tc1_1, test_mul_78);
  tcase_add_test(tc1_1, test_mul_79);
  tcase_add_test(tc1_1, test_mul_80);
  tcase_add_test(tc1_1, test_mul_81);
  tcase_add_test(tc1_1, test_mul_82);
  tcase_add_test(tc1_1, test_mul_83);
  tcase_add_test(tc1_1, test_mul_84);
  tcase_add_test(tc1_1, test_mul_85);
  tcase_add_test(tc1_1, test_mul_86);
  tcase_add_test(tc1_1, test_mul_87);
  tcase_add_test(tc1_1, test_mul_88);
  tcase_add_test(tc1_1, test_mul_89);
  tcase_add_test(tc1_1, test_mul_90);
  tcase_add_test(tc1_1, test_mul_91);
  tcase_add_test(tc1_1, test_mul_92);
  tcase_add_test(tc1_1, test_mul_93);
  tcase_add_test(tc1_1, test_mul_94);
  tcase_add_test(tc1_1, test_mul_95);
  tcase_add_test(tc1_1, test_mul_96);
  tcase_add_test(tc1_1, test_mul_97);
  tcase_add_test(tc1_1, test_mul_98);
  tcase_add_test(tc1_1, test_mul_99);
  tcase_add_test(tc1_1, test_mul_100);
  tcase_add_test(tc1_1, test_mul_101);
  tcase_add_test(tc1_1, test_mul_102);
  tcase_add_test(tc1_1, test_mul_103);
  tcase_add_test(tc1_1, test_mul_104);
  tcase_add_test(tc1_1, test_mul_105);
  tcase_add_test(tc1_1, test_mul_106);
  tcase_add_test(tc1_1, test_mul_107);
  tcase_add_test(tc1_1, test_mul_108);
  tcase_add_test(tc1_1, test_mul_109);
  return s1;
}
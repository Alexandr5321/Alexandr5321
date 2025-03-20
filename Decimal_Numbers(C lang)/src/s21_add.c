// #include "arithmetics.h"
#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 666;
  s21_big_decimal big_decimal_1 = {0};
  s21_big_decimal big_decimal_2 = {0};
  s21_big_decimal big_decimal_result = {0};

  if ((mantissa_is_zero(value_1) && mantissa_is_zero(value_2))) {  // 0+0
    null_decimal(result);
    error_code = 0;
  } else if (mantissa_is_zero(value_1)) {  // 0+число
    *result = value_2;
    error_code = 0;
  } else if (mantissa_is_zero(value_2)) {  // число+0
    *result = value_1;
    error_code = 0;
  } else {
    // конвертация decimal в big_decimal
    decimal_to_big(value_1, &big_decimal_1);
    decimal_to_big(value_2, &big_decimal_2);

    // сложение биг децимал
    big_add(big_decimal_1, big_decimal_2, &big_decimal_result);

    // округление
    big_decimal_rounding(&big_decimal_result);

    // обратная конвертация
    final_decision(big_decimal_result, result, &error_code);
  }

  return error_code;
}
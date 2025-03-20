// #include "arithmetics.h"
#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 666;
  s21_big_decimal multiplier = {0};    // множитель 1
  s21_big_decimal multiplicand = {0};  // множитель 2
  s21_big_decimal product = {0};       // произведение

  // проверка граничных условий
  if (mantissa_is_zero(value_2) || mantissa_is_zero(value_1)) {  // число:0
    null_decimal(result);
    error_code = 0;
  } else {
    // конвертация decimal в big_decimal
    decimal_to_big(value_1, &multiplier);
    decimal_to_big(value_2, &multiplicand);

    // умножение
    big_mul(multiplier, multiplicand, &product);

    // округление
    big_decimal_rounding(&product);

    // обратная конвертация
    final_decision(product, result, &error_code);
  }

  return error_code;
}
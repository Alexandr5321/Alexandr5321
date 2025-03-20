// #include "arithmetics.h"
#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error_code = 666;
  s21_big_decimal divisible = {0};  // делимое
  s21_big_decimal divisor = {0};    // Делитель
  s21_big_decimal quotient_sum = {
      0};  // Кумулятивное частное - важна мантисса и масштаб

  // проверка граничных условий
  if (mantissa_is_zero(value_2)) {  // число:0
    error_code = 3;
  } else if (mantissa_is_zero(value_1)) {  // 0:число
    null_decimal(result);
    error_code = 0;
  } else {
    // конвертация decimal в big_decimal
    decimal_to_big(value_1, &divisible);
    decimal_to_big(value_2, &divisor);

    // деление
    big_div(divisible, divisor, &quotient_sum);

    // округление
    big_decimal_rounding(&quotient_sum);

    // обратная конвертация
    final_decision(quotient_sum, result, &error_code);
  }

  return error_code;
}
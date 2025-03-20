#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  if (result != NULL && is_correct_decimal(value)) {
    copy_decimal(value, result);
    int sign = get_sign(value);
    set_sign(result, sign == 0);
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  if (result != NULL && is_correct_decimal(value)) {
    copy_decimal(value, result);
    int scale = get_scale(*result);
    decrease_scale(result, scale);
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  s21_decimal aux = {{5, 0, 0, 65536}};  // 0.5
  if (result != NULL && is_correct_decimal(value)) {
    if (!get_sign(value)) {
      s21_add(value, aux, &value);  // positive
    } else {
      s21_sub(value, aux, &value);  // negative
    }
    s21_truncate(value, result);
  } else {
    error_code = 1;
  }
  return error_code;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int error_code = 0;
  s21_decimal aux = {{1, 0, 0, 0}};  // 1
  if (result != NULL && is_correct_decimal(value)) {
    if (!s21_truncate(value, result) && s21_is_not_equal(value, *result) &&
        get_sign(*result)) {
      s21_sub(*result, aux, result);
    }
  } else {
    error_code = 1;
  }
  return error_code;
}
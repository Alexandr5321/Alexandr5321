#include "s21_decimal.h"

int s21_is_less(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) < 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int s21_is_less_or_equal(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) <= 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int s21_is_greater(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) > 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int s21_is_greater_or_equal(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) >= 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int s21_is_equal(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) == 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int s21_is_not_equal(s21_decimal n1, s21_decimal n2) {
  int res = (compare(n1, n2) != 0) ? 1 : 0;  // 1 - true, 0 - false
  return res;
}

int compare(s21_decimal n1, s21_decimal n2) {
  int sign = compare_sign(n1, n2);

  if (sign == 0) {
    s21_big_decimal big_decimal_1 = {0};
    s21_big_decimal big_decimal_2 = {0};
    decimal_to_big(n1, &big_decimal_1);
    decimal_to_big(n2, &big_decimal_2);
    normalize_scales(&big_decimal_1, &big_decimal_2);
    int scale = big_get_scale(big_decimal_1) - big_get_scale(big_decimal_2);
    if (scale >= 0) {
      sign = compare_bits(big_decimal_1, big_decimal_2);
    }
    // } else {
    //   sign = compare_bits(big_decimal_2, big_decimal_1);
    // }
  } else {
    if (is_zero(n1) && is_zero(n2)) {
      sign = 0;
    }
  }
  return sign;
}

int compare_bits(s21_big_decimal n1, s21_big_decimal n2) {
  int res = 0;
  int diff = 0;
  int sign = big_get_sign(n1);
  for (int i = 95; i >= 0; i--) {
    diff = big_get_bit(n1, i) - big_get_bit(n2, i);
    if (diff < 0) {
      res = -1;
      break;
    } else if (diff > 0) {
      res = 1;
      break;
    }
  }
  if (sign == 1) {
    res *= (-1);
  }

  return res;
}

int compare_sign(s21_decimal n1, s21_decimal n2) {
  int firstN = get_sign(n1);
  int secondN = get_sign(n2);
  int res = 0;
  if (firstN > secondN) {
    res = -1;
  } else if (firstN < secondN) {
    res = 1;
  }
  return res;
}
#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0, exp = get_float_exp(&src);

  if (dst && src != 0 && !isinf(src)) {
    null_decimal(dst);
    int sign = 0;
    if (src < 0) {
      src *= -1;
      sign = -1;
    }
    src = (float)src;
    long double tmp = (long double)src;
    int scale = 0;
    while (scale < 28 && (int)tmp / (int)999999 == 0) {
      tmp *= 10;
      scale++;
    }
    rounding_int_seven_number(&tmp);
    tmp = round(tmp);
    if (scale <= 28 && (exp >= -94 && exp <= 96)) {
      fbits mant;
      tmp = (float)tmp;
      for (; fmod(tmp, 10) == 0 && scale > 0; scale--, tmp /= 10) {
      }
      mant.fl = tmp;
      exp = get_float_exp(&mant.fl);
      set_bit(dst, exp, 1);
      for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
        if ((mant.ui & (1 << j)) != 0) {
          set_bit(dst, i, 1);
        }
      }
      set_sign(dst, sign);
      set_scale(dst, scale);
      res = 0;
    }
  } else {
    res = 1;
  }
  return res;
}
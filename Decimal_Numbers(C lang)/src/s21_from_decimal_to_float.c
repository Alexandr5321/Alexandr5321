#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int status = 0;
  *dst = 0;
  long double result = 0, two = 0;
  int minus = 0;
  status = check_decimal(src);
  if (status != 1) {
    minus = get_sign(src);
    result = 0, two = 1;
    int exp = get_scale(src);

    for (int k = 0; k < 96; k++) {
      if (get_bit(src, k)) {
        result += two;
      }
      two *= 2;
    }
    for (int k = 0; k < exp; k++) {
      result /= 10;
    }
  }
  if (minus == 1)
    *dst = (float)(-1 * result);
  else
    *dst = result;
  return status;
}

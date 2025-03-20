#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int flag = 0;
  int tmp = 0;
  int scale = get_scale(src);
  flag = check_decimal(src);
  for (int i = 32; i <= 95; i++) {
    if (get_bit(src, i)) flag = 1;
  }
  if (flag != 1) {
    for (int i = 31; i >= 0; i--) {
      tmp <<= 1;
      tmp |= get_bit(src, i);
    }

    if (get_bit(src, 127)) {
      tmp = tmp * (-1);
    }

    *dst = tmp;
    for (int i = scale; i > 0; i--) {
      *dst = *dst / 10;
    }
  }
  return flag;
}
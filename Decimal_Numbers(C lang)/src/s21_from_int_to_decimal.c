#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int result = 0;
  null_decimal(dst);
  if (dst) {
    if (src < 0) {
      set_bit(dst, 127, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    result = 1;
  }
  return result;
}
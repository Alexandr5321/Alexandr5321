#include "s21_decimal.h"

int get_bit(s21_decimal arr, int ind) {
  int degree = 1u << (ind % 32);
  int bit = arr.bits[ind / 32] & degree;
  return bit != 0;
}

int big_get_bit(s21_big_decimal arr, int ind) {
  unsigned degree = 1u << (ind % 32);
  unsigned bit = arr.bits[ind / 32] & degree;
  return bit != 0;
}

void set_bit(s21_decimal *arr, int ind, int bit) {
  int degree = 1u << (ind % 32);
  arr->bits[ind / 32] =
      bit ? arr->bits[ind / 32] | degree : arr->bits[ind / 32] & ~degree;
}

void big_set_bit(s21_big_decimal *arr, int ind, int bit) {
  unsigned degree = 1u << (ind % 32);
  arr->bits[ind / 32] =
      bit ? arr->bits[ind / 32] | degree : arr->bits[ind / 32] & ~degree;
}

int is_zero(s21_decimal num) {
  int result = 1;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(int) - 1); i++) {
    if (num.bits[i] != 0) {
      result = 0;
      break;
    }
  }
  return result;
}

int is_correct_decimal(s21_decimal arr) {
  int result = 1;
  unsigned scale_check = 1;
  if (get_scale(arr) > 28) {
    result = 0;
  } else {
    for (int i = 0; i < 31; i++) {
      if (((scale_check << i) & arr.bits[3]) != 0 && (i < 16 || i > 23)) {
        result = 0;
        break;
      }
    }
  }
  return result;
}

void null_decimal(s21_decimal *num) {
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(int)); i++) {
    num->bits[i] = 0;
  }
}

void big_null_decimal(s21_big_decimal *num) {
  for (int i = 0; i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned)); i++) {
    num->bits[i] = 0;
  }
}

int get_sign(s21_decimal num) {
  int bit = get_bit(num, sign_bit_index);
  return bit != 0;
}

int big_get_sign(s21_big_decimal num) {
  int bit = big_get_bit(num, big_sign_bit_index);
  return bit != 0;
}

void set_sign(s21_decimal *num, int sign) {
  set_bit(num, sign_bit_index, sign);
}

void big_set_sign(s21_big_decimal *num, int sign) {
  big_set_bit(num, big_sign_bit_index, sign);
}

void big_shift_left(s21_big_decimal *num, int shift) {
  unsigned last_bit = 0;
  // for (int i = 0; i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned int) -
  // 1);
  for (int i = 0; i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned int) - 1);
       i++) {
    // unsigned int temp = num->bits[i];
    // num->bits[i] <<= shift;
    unsigned int temp = num->bits[i];
    num->bits[i] <<= shift;
    num->bits[i] |= last_bit;
    last_bit = temp >> (32 - shift);
  }
}

int get_scale(s21_decimal arr) {
  int degree = 255 << 16;
  int scale = arr.bits[3] & degree;
  return scale >> 16;
}

int big_get_scale(s21_big_decimal arr) {
  unsigned degree = 255 << 16;
  unsigned scale = arr.bits[6] & degree;
  return scale >> 16;
}

void decrease_scale(s21_decimal *arr, int shift) {
  uint64_t num = 0;
  uint64_t res = 0;
  int init_shift = shift;
  while (shift > 0) {
    for (int i = 2; i >= 0; i--) {
      num = (unsigned)arr->bits[i];
      num += res << 32;
      res = num % 10;
      num /= 10;
      arr->bits[i] = (int)num;
    }
    shift--;
    num = 0;
    res = 0;
  }
  int scale = get_scale(*arr);
  set_scale(arr, scale - init_shift);
}

void set_scale(s21_decimal *arr, int scale) {
  int degree = 255 << 16;
  arr->bits[3] = (arr->bits[3] & ~degree) | (scale << 16);
}

void big_set_scale(s21_big_decimal *arr, int scale) {
  int degree = 255 << 16;
  arr->bits[6] = (arr->bits[6] & ~degree) | (scale << 16);
}

void copy_decimal(s21_decimal src, s21_decimal *dist) {
  for (unsigned int i = 0; i < (int)sizeof(s21_decimal) / sizeof(int); i++) {
    for (unsigned int i = 0; i < (int)sizeof(s21_decimal) / sizeof(int); i++) {
      dist->bits[i] = src.bits[i];
    }
  }
}

int check_decimal(s21_decimal src) {
  int status = 0;
  for (int i = 96; i <= 111; i++) {
    if (get_bit(src, i) == 1) status = 1;
  }
  for (int i = 119; i <= 126; i++) {
    if (get_bit(src, i) == 1) status = 1;
  }
  if (get_scale(src) > 28) status = 1;
  return status;
}

int rounding_int_seven_number(long double *src) {
  int flag = 0;
  int ten = 10;
  long double tmp = *src;
  long double result = 0;
  for (int i = 0; tmp >= 1; i++) {
    if (tmp >= 1) {
      tmp = tmp / ten;
      flag++;
    }
  }

  if (flag >= 8) {
    result = *src;
    for (int k = 0; k < flag - 7; k++) {
      result /= 10;
    }
    *src = round(result);
    // printf("\n[%Lf]\n", result);
    // printf("[!%d!]\n", *src);
  } else {
    flag = 7;
  }
  return flag - 7;
}

int get_float_exp(float *value) {
  return ((*((int *)value) & ~(1u << 31)) >> 23) - 127;
}

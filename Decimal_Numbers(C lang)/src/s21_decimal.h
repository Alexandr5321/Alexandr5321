#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#define sign_bit_index 127
#define big_sign_bit_index 223
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef struct s21_decimal {
  int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  unsigned int bits[7];
} s21_big_decimal;

typedef union {
  int ui;
  float fl;
} fbits;

// helpers
int get_bit(s21_decimal arr, int ind);
int big_get_bit(s21_big_decimal arr, int ind);
void set_bit(s21_decimal *arr, int ind, int bit);
void big_set_bit(s21_big_decimal *arr, int ind, int bit);
int get_scale(s21_decimal arr);
int big_get_scale(s21_big_decimal arr);
int get_scale(s21_decimal arr);
int big_get_scale(s21_big_decimal arr);
void set_scale(s21_decimal *arr, int scale);
void big_set_scale(s21_big_decimal *arr, int scale);
int is_zero(s21_decimal num);
int big_is_zero(s21_big_decimal num);
void null_decimal(s21_decimal *num);
void big_null_decimal(s21_big_decimal *num);
int get_sign(s21_decimal num);
int big_get_sign(s21_big_decimal num);
void set_sign(s21_decimal *num, int sign);
void big_set_sign(s21_big_decimal *num, int sign);
void big_shift_left(s21_big_decimal *num, int shift);
void copy_decimal(s21_decimal src, s21_decimal *dist);
int s21_is_less_or_equal(s21_decimal n1, s21_decimal n2);
int s21_is_less(s21_decimal n1, s21_decimal n2);
int s21_is_greater(s21_decimal n1, s21_decimal n2);
int s21_is_greater_or_equal(s21_decimal n1, s21_decimal n2);
int s21_is_equal(s21_decimal n1, s21_decimal n2);
int s21_is_not_equal(s21_decimal n1, s21_decimal n2);
void decrease_scale(s21_decimal *num, int scale);
int is_correct_decimal(s21_decimal arr);
void print_bin(int n);
void big_print_bin(unsigned n);
void print_d(s21_decimal n);
void big_print_d(s21_big_decimal n);
void print_bin_2(int n);
void big_print_bin_2(unsigned n);
void print_d_2(s21_decimal n);
void big_print_d_2(s21_big_decimal n);

// other funcs
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int rounding_int_seven_number(long double *src);
int get_float_exp(float *value);

int compare(s21_decimal n1, s21_decimal n2);
// int compare_bits(s21_decimal n1, s21_decimal n2);
int compare_bits(s21_big_decimal n1, s21_big_decimal n2);
int compare_sign(s21_decimal n1, s21_decimal n2);
int check_decimal(s21_decimal src);

// арифметика
void bitwise_addition(s21_big_decimal *value_1, s21_big_decimal *value_2,
                      s21_big_decimal *result);
void bitwise_subtraction(s21_big_decimal *value_1, s21_big_decimal *value_2,
                         s21_big_decimal *result);
void multiply_by_ten_and_add(s21_big_decimal *value_1, s21_big_decimal *value_2,
                             s21_big_decimal *result);
void increase_scale_and_mantissa(s21_big_decimal *inp);
void adjust_scale(s21_big_decimal *value_1, s21_big_decimal *value_2);
void normalize_scales(s21_big_decimal *value_1, s21_big_decimal *value_2);
void normalize_negative_scale(s21_big_decimal *value_1, int *scale);
void normalize_mantissa(s21_big_decimal *value_1, s21_big_decimal *value_2);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void big_add(s21_big_decimal big_decimal_1, s21_big_decimal big_decimal_2,
             s21_big_decimal *big_decimal_result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void big_sub(s21_big_decimal big_decimal_1, s21_big_decimal big_decimal_2,
             s21_big_decimal *big_decimal_result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void big_div(s21_big_decimal divisible, s21_big_decimal divisor,
             s21_big_decimal *quotient_sum);
void get_quotient_residue_1(s21_big_decimal divisible, s21_big_decimal divisor,
                            s21_big_decimal *quotient, s21_big_decimal *residue,
                            int *scale);
void get_quotient_residue(s21_big_decimal divisible, s21_big_decimal divisor,
                          s21_big_decimal *quotient, s21_big_decimal *residue,
                          int scale);
void shift_left_divisor_and_quotient(s21_big_decimal *value_1,
                                     s21_big_decimal *value_2,
                                     s21_big_decimal *result);
int get_sign_from_div_mul(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void big_mul(s21_big_decimal multiplier, s21_big_decimal multiplicand,
             s21_big_decimal *product);

// округление
void big_decimal_rounding(s21_big_decimal *inp);
void int_div_by_ten_and_getting_residues(s21_big_decimal *inp,
                                         unsigned int *array_of_residuals,
                                         int *counter,
                                         int *flag_residue_is_zero);
void banking_or_arithmetic_rounding(s21_big_decimal *inp,
                                    unsigned int *array_of_residuals,
                                    int counter, int flag_residue_is_zero);
int residue_is_zero(unsigned int *array_of_residuals, int counter);
void big_add_one(s21_big_decimal *divisible, int current_scale);
int big_is_even(s21_big_decimal inp);
void final_decision(s21_big_decimal inp, s21_decimal *outp, int *error_code);

// конвертация дец-биг
void decimal_to_big(s21_decimal inp, s21_big_decimal *outp);
void big_to_decimal(s21_big_decimal inp, s21_decimal *outp);

// функции сравнения
int big_compare_scales(s21_big_decimal value_1, s21_big_decimal value_2);
int big_compare_signs(s21_big_decimal value_1, s21_big_decimal value_2);
int big_compare_mantissa(s21_big_decimal value_1, s21_big_decimal value_2);
int big_mantissa_is_zero(s21_big_decimal num);
int mantissa_is_zero(s21_decimal num);
int big_mantissa_leq_decimal_mantissa(s21_big_decimal inp);
int big_mantissa_le_ten(s21_big_decimal inp);
#endif

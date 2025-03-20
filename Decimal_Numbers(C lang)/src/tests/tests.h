#ifndef S21_TESTS_H
#define S21_TESTS_H
#include <check.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
#define S21_MAX_UINT (int)4294967295
#define S21_TRUE 1
#define S21_FALSE 0

#include "../print_s21_decimal.h"
#include "../s21_decimal.h"

void run_suite(Suite *test_suite);

// арифметика
Suite *suite_test_div(void);
Suite *suite_test_add(void);
Suite *suite_test_mul(void);
Suite *suite_test_sub(void);

// конвертация
Suite *suite_from_float_to_decimal(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_from_decimal_to_int(void);
Suite *suite_from_decimal_to_float(void);

// сравнение
Suite *suite_less(void);
Suite *suite_less_equal(void);
Suite *suite_greater(void);
Suite *suite_greater_equal(void);
Suite *suite_equal(void);
Suite *suite_not_equal(void);

// другие функции
Suite *suite_trunc(void);
Suite *suite_round(void);
Suite *suite_negate(void);
Suite *suite_floor(void);
#endif
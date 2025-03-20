// #include "arithmetics.h"
#include "s21_decimal.h"

void bitwise_addition(s21_big_decimal *value_1, s21_big_decimal *value_2,
                      s21_big_decimal *result) {
  unsigned int memory = 0;
  for (int i = 0;
       i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned int) - 1) * 32;
       i++) {
    unsigned int result_bit =
        big_get_bit(*value_1, i) + big_get_bit(*value_2, i) + memory;
    memory = result_bit / 2;
    result_bit %= 2;
    big_set_bit(result, i, result_bit);
  }
}

void bitwise_subtraction(s21_big_decimal *value_1, s21_big_decimal *value_2,
                         s21_big_decimal *result) {
  unsigned int memory = 0;
  for (int i = 0;
       i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned int) - 1) * 32;
       i++) {
    unsigned int bit_1 = big_get_bit(*value_1, i);
    unsigned int bit_2 = big_get_bit(*value_2, i);
    unsigned int result_bit = bit_1 - bit_2 - memory;

    // assign memory
    if (bit_1 < bit_2 + memory) {
      memory = 1;
    } else {
      memory = 0;
    }

    // assign result_bit
    result_bit *= -1;
    result_bit %= 2;
    big_set_bit(result, i, result_bit);
  }
}

void multiply_by_ten_and_add(s21_big_decimal *value_1, s21_big_decimal *value_2,
                             s21_big_decimal *result) {
  big_shift_left(value_1, 3);
  big_shift_left(value_2, 1);
  bitwise_addition(value_1, value_2, result);
}

void increase_scale_and_mantissa(s21_big_decimal *inp) {
  s21_big_decimal value_1 = *inp;
  s21_big_decimal value_2 = *inp;
  multiply_by_ten_and_add(&value_1, &value_2, inp);
  int new_scale = big_get_scale(*inp) + 1;
  big_set_scale(inp, new_scale);
}

void adjust_scale(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int result_compare_scales = big_compare_scales(*value_1, *value_2);
  if (result_compare_scales == 1) {
    increase_scale_and_mantissa(value_2);
  } else if (result_compare_scales == -1) {
    increase_scale_and_mantissa(value_1);
  }
}

void normalize_scales(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  // // debug print
  // int i = 0;
  // printf("value_1 before normalize_scales, i=%d:\n", i);
  // big_print_d_2(*value_1);
  // printf("value_2 before normalize_scales, i=%d:\n", i);
  // big_print_d_2(*value_2);

  while (big_compare_scales(*value_1, *value_2) != 0) {
    adjust_scale(value_1, value_2);

    // // debug print
    // printf("value_1 inside while loop in normalize_scales, i=%d:\n", i);
    // big_print_d_2(*value_1);
    // printf("value_2 inside while loop in normalize_scales, i=%d:\n", i);
    // big_print_d_2(*value_2);
    // i++;
  }
}

void normalize_negative_scale(s21_big_decimal *value_1, int *scale) {
  // // debug print
  // int i = 0;
  // printf("value_1 before normalize_negative_scale, i=%d:\n", i);
  // big_print_d_2(*value_1);

  while (*scale < 0) {
    increase_scale_and_mantissa(value_1);
    *scale += 1;

    // // debug print
    // printf("value_1 inside while loop in normalize_negative_scale, i=%d:\n",
    // i); big_print_d_2(*value_1); i++;
  }
}

void normalize_mantissa(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  // // debug print
  // int i = 0;
  // printf("value_1 before normalize_mantissa, i=%d:\n", i);
  // big_print_d_2(*value_1);
  // printf("value_2 before normalize_mantissa, i=%d:\n", i);
  // big_print_d_2(*value_2);

  while (big_compare_mantissa(*value_1, *value_2) == -1) {
    increase_scale_and_mantissa(value_1);

    // // debug print
    // printf("value_1 after normalize_mantissa, i=%d:\n", i);
    // big_print_d_2(*value_1);
    // printf("value_2 after normalize_mantissa, i=%d:\n", i);
    // big_print_d_2(*value_2);
    // i++;
  }
}

void big_add(s21_big_decimal big_decimal_1, s21_big_decimal big_decimal_2,
             s21_big_decimal *big_decimal_result) {
  // нормализация по масштабу
  normalize_scales(&big_decimal_1, &big_decimal_2);

  // установка большего масштаба в результат
  int scale = big_get_scale(big_decimal_1);
  big_set_scale(big_decimal_result, scale);

  int sign_1 = big_get_sign(big_decimal_1);
  int sign_2 = big_get_sign(big_decimal_2);

  int result_compare_signs = big_compare_signs(big_decimal_1, big_decimal_2);
  int result_compare_mantissa =
      big_compare_mantissa(big_decimal_1, big_decimal_2);

  // сложение или вычитание в зависимости от знака и мантиссы
  if (result_compare_signs == 0) {
    bitwise_addition(&big_decimal_1, &big_decimal_2, big_decimal_result);
    big_set_sign(big_decimal_result, sign_1);
  } else {
    if (result_compare_mantissa >= 0) {
      bitwise_subtraction(&big_decimal_1, &big_decimal_2, big_decimal_result);
      big_set_sign(big_decimal_result, sign_1);
    } else {
      bitwise_subtraction(&big_decimal_2, &big_decimal_1, big_decimal_result);
      big_set_sign(big_decimal_result, sign_2);
    }
  }

  // // debug print
  //   printf("big_decimal_result after big_add inside big_add\n");
  //   big_print_d_2(*big_decimal_result);
}

void big_sub(s21_big_decimal big_decimal_1, s21_big_decimal big_decimal_2,
             s21_big_decimal *big_decimal_result) {
  // нормализация
  normalize_scales(&big_decimal_1, &big_decimal_2);

  // установка большего масштаба в результат
  int scale = big_get_scale(big_decimal_1);
  big_set_scale(big_decimal_result, scale);

  int sign_1 = big_get_sign(big_decimal_1);
  int sign_2 = big_get_sign(big_decimal_2);

  int result_compare_signs = big_compare_signs(big_decimal_1, big_decimal_2);
  int result_compare_mantissa =
      big_compare_mantissa(big_decimal_1, big_decimal_2);

  // сложение или вычитание в зависимости от знака и мантиссы
  if (result_compare_signs == 0) {
    if (result_compare_mantissa >= 0) {
      bitwise_subtraction(&big_decimal_1, &big_decimal_2, big_decimal_result);
      big_set_sign(big_decimal_result, sign_1);
    } else {
      bitwise_subtraction(&big_decimal_2, &big_decimal_1, big_decimal_result);
      big_set_sign(big_decimal_result, !sign_2);  // обратный знак
    }
  } else {
    bitwise_addition(&big_decimal_1, &big_decimal_2, big_decimal_result);
    big_set_sign(big_decimal_result, sign_1);
  }
}

void big_div(s21_big_decimal divisible, s21_big_decimal divisor,
             s21_big_decimal *quotient_sum) {
  // получение результирующего знака до деления для использования потом
  int sign_result = get_sign_from_div_mul(divisible, divisor);

  // нормализация по мантиссе 0я итерация - нужно чтобы уже сразу нормализовать
  //  и потом скейл занулить и двигаться с 0го скейла, чтобы больше влезло в
  //  мантиссу значащих цифр (а не нулей перед цифрами)
  normalize_mantissa(&divisible, &divisor);

  // получение разности масштабов из 2х чисел перед делением для использования
  // потом
  int scale_1 = big_get_scale(divisible) - big_get_scale(divisor);

  // зануляю скейл чтобы с нулевого скейла двигаться (больше знач цифр влезет в
  // мантиссу)
  big_set_scale(&divisible, 0);
  int scale_temp = 0;
  while (
      big_mantissa_is_zero(divisible) == 0 &&
      scale_temp <=
          29) {  // пока остаток не равен 0 или пока скейл не будет равным 28.
    // Это значит мантисса заполнит все 96 бит и количество значимых цифр в
    // мантиссе будет равно 29 что соответсвутет размеру децимал. Мантисса
    // больше нам не нужна, нам все равно при конвертации "обрезать" лишнее
    s21_big_decimal quotient = {0};  // важна мантисса и масштаб
    s21_big_decimal quotient_temp = {0};  // важна мантисса и масштаб
    s21_big_decimal residue = {0};  // важна только мантисса

    // получаем частное и остаток от деления
    get_quotient_residue_1(divisible, divisor, &quotient, &residue,
                           &scale_temp);

    // прибавим полученное частное к общей сумме
    big_add(*quotient_sum, quotient, &quotient_temp);
    *quotient_sum = quotient_temp;

    // теперь полученный остаток становится делителем
    divisible = residue;

    // // debug print
    // printf("quotient_sum after big_add inside while loop in big_div\n");
    // big_print_d_2(*quotient_sum);
    // printf("divisible after big_add inside while loop in big_div\n");
    // big_print_d_2(divisible);
  }

  // получение финального скейла
  int scale_2 = big_get_scale(*quotient_sum);
  int scale_result = scale_2 + scale_1;

  if (scale_result < 0) {
    // нормализация отрицательного скейла (если он есть)
    // тут главное что мантиссу увеличиваем в 10 раз каждую итерацию, скейл
    // правильный поставим ниже
    normalize_negative_scale(quotient_sum, &scale_result);
  }

  // установка скейла финального. Если он был отрицательный то стал нулем. Если
  // был положительный то таким и остался
  big_set_scale(quotient_sum, scale_result);

  // установка знака
  big_set_sign(quotient_sum, sign_result);

  // // debug print
  // printf("quotient_sum after big_div inside big_div\n");
  // big_print_d_2(*quotient_sum);
}

void get_quotient_residue_1(s21_big_decimal divisible, s21_big_decimal divisor,
                            s21_big_decimal *quotient, s21_big_decimal *residue,
                            int *scale) {
  // /// debug print
  // printf("%d", *scale);

  // s21_big_decimal residue = divisible;
  s21_big_decimal residue_temp = {0};
  s21_big_decimal quotient_sum = {0};
  s21_big_decimal quotient_temp = {0};

  // нормализация по мантиссе
  normalize_mantissa(&divisible, &divisor);

  // взятие скейла после нормализации (1я итерация он 0)
  *scale = big_get_scale(divisible);

  while (big_compare_mantissa(divisible, divisor) >=
         0) {  // пока мантисса остатка больше или равна делимому

    s21_big_decimal shifted_quotient = {0};
    big_set_bit(&shifted_quotient, 0, 1);  // установка единички в младший бит
    s21_big_decimal shifted_divisor = divisor;

    shift_left_divisor_and_quotient(&divisible, &shifted_divisor,
                                    &shifted_quotient);

    // частное
    bitwise_addition(&quotient_sum, &shifted_quotient, &quotient_temp);
    quotient_sum = quotient_temp;

    // остаток
    bitwise_subtraction(&divisible, &shifted_divisor, &residue_temp);
    divisible = residue_temp;
  }

  // возвращаем частное
  *quotient = quotient_sum;         // установка мантиссы
  big_set_scale(quotient, *scale);  // установка масштаба

  // возвращаем остаток
  *residue = divisible;            // установка мантиссы
  big_set_scale(residue, *scale);  // установка масштаба

  // // debug print
  // printf("quotient after get_quotient_residue\n");
  // big_print_d_2(*quotient);
  // printf("residue after get_quotient_residue\n");
  // big_print_d_2(*residue);
}

void get_quotient_residue(s21_big_decimal divisible, s21_big_decimal divisor,
                          s21_big_decimal *quotient, s21_big_decimal *residue,
                          int scale) {
  // s21_big_decimal residue = divisible;
  s21_big_decimal residue_temp = {0};
  s21_big_decimal quotient_sum = {0};
  s21_big_decimal quotient_temp = {0};

  // нормализация по мантиссе
  normalize_mantissa(&divisible, &divisor);

  while (big_compare_mantissa(divisible, divisor) >=
         0) {  // пока мантисса остатка больше или равна делимому

    s21_big_decimal shifted_quotient = {0};
    big_set_bit(&shifted_quotient, 0, 1);  // установка единички в младший бит
    s21_big_decimal shifted_divisor = divisor;

    shift_left_divisor_and_quotient(&divisible, &shifted_divisor,
                                    &shifted_quotient);

    // частное
    bitwise_addition(&quotient_sum, &shifted_quotient, &quotient_temp);
    quotient_sum = quotient_temp;

    // остаток
    bitwise_subtraction(&divisible, &shifted_divisor, &residue_temp);
    divisible = residue_temp;
  }

  // возвращаем частное
  *quotient = quotient_sum;        // установка мантиссы
  big_set_scale(quotient, scale);  // установка масштаба

  // возвращаем остаток
  *residue = divisible;  // установка мантиссы

  // // debug print
  // printf("quotient after get_quotient_residue\n");
  // big_print_d_2(*quotient);
  // printf("residue after get_quotient_residue\n");
  // big_print_d_2(*residue);
}

void shift_left_divisor_and_quotient(s21_big_decimal *value_1,
                                     s21_big_decimal *value_2,
                                     s21_big_decimal *result) {
  // // debug print
  // int i = 0;
  // printf("value_2 before while loop in shift_left_divisor_and_quotient,
  // i=%d:\n", i); big_print_d_2(*value_2); printf("result before while
  // loop in shift_left_divisor_and_quotient, i=%d:\n", i);
  // big_print_d_2(*result);

  s21_big_decimal value_2_temp = *value_2;
  s21_big_decimal result_temp = *result;
  // пока сдвинутое частное <= делимому И сдвинутое частное не стало переполнять
  // децимал (уменьшаясь)
  while (big_compare_mantissa(*value_1, value_2_temp) >= 0 &&
         big_compare_mantissa(value_2_temp, *value_2) >= 0) {
    *value_2 = value_2_temp;
    *result = result_temp;
    big_shift_left(&value_2_temp, 1);
    big_shift_left(&result_temp, 1);

    // // debug print
    // printf(
    //     "value_2 inside while loop in shift_left_divisor_and_quotient,
    //     i=%d:\n", i);
    // big_print_d_2(*value_2);
    // printf(
    //     "result inside while loop in shift_left_divisor_and_quotient,
    //     i=%d:\n", i);
    // big_print_d_2(*result);
    // i++;
  }
}

int get_sign_from_div_mul(s21_big_decimal value_1, s21_big_decimal value_2) {
  int sign_1 = big_get_sign(value_1);
  int sign_2 = big_get_sign(value_2);
  int result = sign_1 ^ sign_2;

  return result;
}

void big_mul(s21_big_decimal multiplier, s21_big_decimal multiplicand,
             s21_big_decimal *product) {
  // получение результирующего знака и скейла до умножения для использования
  // потом
  int sign_result = get_sign_from_div_mul(multiplier, multiplicand);
  int scale_result = big_get_scale(multiplier) + big_get_scale(multiplicand);

  s21_big_decimal temp_multiplier = multiplier;
  s21_big_decimal temp_product = *product;

  for (int i = 0;
       i < (int)(sizeof(s21_decimal) / sizeof(unsigned int) - 1) * 32; i++) {
    if (multiplicand.bits[i / 32] & (1 << (i % 32))) {
      bitwise_addition(&temp_product, &temp_multiplier, product);
      temp_product = *product;
    }
    big_shift_left(&temp_multiplier, 1);

    // // debug print
    // printf("temp_product after bitwise_addition inside while loop in
    // big_mul\n"); big_print_d_2(temp_product); printf("temp_multiplier
    // after big_shift_left inside while loop in big_mul\n");
    // big_print_d_2(temp_multiplier);
  }

  // установка скейла финального
  big_set_scale(product, scale_result);

  // установка знака
  big_set_sign(product, sign_result);

  // // debug print
  // printf("product after big_mul inside big_mul\n");
  // big_print_d_2(*product);
}

void big_decimal_rounding(s21_big_decimal *inp) {
  // сохраним знак
  int sign = big_get_sign(*inp);

  int flag_residue_is_zero = 666;
  unsigned int array_of_residuals[256] = {666};
  int counter = 0;

  while ((big_mantissa_leq_decimal_mantissa(*inp) == 0 &&
          big_get_scale(*inp) > 28) ||
         (big_mantissa_leq_decimal_mantissa(*inp) == 0 &&
          big_get_scale(*inp) > 0) ||
         (big_mantissa_is_zero(*inp) == 0 && big_get_scale(*inp) > 28)) {
    int_div_by_ten_and_getting_residues(inp, array_of_residuals, &counter,
                                        &flag_residue_is_zero);

    // // debug print
    // printf(
    //     "inp after int_div_by_ten_and_getting_residues inside while loop in "
    //     "big_decimal_rounding\n");
    // big_print_d_2(*inp);

    banking_or_arithmetic_rounding(inp, array_of_residuals, counter,
                                   flag_residue_is_zero);

    // // debug print
    // printf(
    //     "inp after banking_or_arithmetic_rounding inside while loop in "
    //     "big_decimal_rounding\n");
    // big_print_d_2(*inp);
  }

  // установка знака обратно
  big_set_sign(inp, sign);
}

void int_div_by_ten_and_getting_residues(s21_big_decimal *inp,
                                         unsigned int *array_of_residuals,
                                         int *counter,
                                         int *flag_residue_is_zero) {
  s21_big_decimal divisible = *inp;
  s21_big_decimal divisor = {
      // 10
      {0b00000000000000000000000000001010, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
       0b00000000000000000000000000000000}};

  while (
      (big_mantissa_leq_decimal_mantissa(divisible) == 0 &&
       big_get_scale(divisible) > 28) ||
      (big_mantissa_leq_decimal_mantissa(divisible) == 0 &&
       big_get_scale(divisible) > 0) ||
      (big_mantissa_is_zero(divisible) == 0 && big_get_scale(divisible) > 28)) {
    s21_big_decimal quotient = {0};  // важна мантисса и масштаб
    s21_big_decimal residue = {0};  // важна только мантисса

    // новый скейл после деления
    int next_scale = big_get_scale(divisible) - 1;

    if (big_mantissa_le_ten(divisible) == 1) {
      // мантисса остается нулем с новым скейлом
      big_set_scale(&quotient, next_scale);
      // делитель становится остатком
      residue = divisible;
    } else {
      // деление на 10: получаем частное и остаток от деления
      get_quotient_residue(divisible, divisor, &quotient, &residue, next_scale);
    }
    // теперь полученное целое частное становится делителем с уменьшенным
    // скейлом на 1
    divisible = quotient;

    // сохраняем остаток от итерации в массив
    array_of_residuals[*counter] = residue.bits[0];

    *counter += 1;

    // // debug print
    // printf(
    //     "divisible inside while loop in
    //     int_div_by_ten_and_getting_residues\n");
    // big_print_d_2(divisible);
  }

  // в случае если m=0 и s>28 мы добавляем нолик в массив остатков и
  // занулю скейл
  if (big_mantissa_is_zero(divisible) == 1 && big_get_scale(divisible) > 28) {
    big_set_scale(&divisible, 0);      // скейл = 0
    array_of_residuals[*counter] = 0;  // сounter тут +1
  } else {
    // тк counter +1 с последней итерации, то мне нужно указатель вернуть на шаг
    // назад, чтобы он смотрел на последнюю записанную цифру, а не вперед
    *counter -= 1;
  }

  // проверяем был ли остаток нулем (кроме последней цифры)
  *flag_residue_is_zero = residue_is_zero(array_of_residuals, *counter);

  // возврат
  *inp = divisible;

  // // debug print
  // printf("divisible after int_div_by_ten_and_getting_residues\n");
  // big_print_d_2(divisible);
}

int residue_is_zero(unsigned int *array_of_residuals, int counter) {
  int result = 666;
  if (counter > 0) {
    for (int i = counter - 1; i >= 0; i--) {
      if (array_of_residuals[i] != 0) {
        result = 0;
      }
    }
  } else {
    result = 1;
  }
  return result;
}

void banking_or_arithmetic_rounding(s21_big_decimal *inp,
                                    unsigned int *array_of_residuals,
                                    int counter, int flag_residue_is_zero) {
  if (array_of_residuals[counter] > 5) {  // арифметическое округление
    big_add_one(inp, big_get_scale(*inp));
  } else if (array_of_residuals[counter] == 5) {
    if (big_is_even(*inp) == 1 &&
        flag_residue_is_zero == 1) {  // банковское округление вниз
    } else {  // в остальных случаях арифметическое округление для 5ки
      big_add_one(inp, big_get_scale(*inp));
    }
  }
}

void big_add_one(s21_big_decimal *divisible, int current_scale) {
  // создадим биг децимал равный 1чке
  s21_big_decimal one = {0};
  big_set_bit(&one, 0, 1);
  big_set_scale(&one, current_scale);

  // временная переменная для сложения
  s21_big_decimal divisible_temp = {0};

  // округлим вверх +1
  big_add(*divisible, one, &divisible_temp);
  *divisible = divisible_temp;
}

int big_is_even(s21_big_decimal inp) {
  int result = 666;

  // делимое
  s21_big_decimal divisible = inp;
  // установка масштаба в ноль, чтобы после деления если скейл будет >0, значит
  // остаток != 0, значит число нечетное
  big_set_scale(&divisible, 0);

  // делитель = 2
  s21_big_decimal two = {0};
  big_set_bit(&two, 1, 1);

  s21_big_decimal quotient_sum = {
      0};  // Кумулятивное частное - важна мантисса и масштаб

  // деление
  big_div(divisible, two, &quotient_sum);

  if (big_get_scale(quotient_sum) == 0) {
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

void final_decision(s21_big_decimal inp, s21_decimal *outp, int *error_code) {
  if (big_mantissa_leq_decimal_mantissa(inp) == 0 && big_get_scale(inp) == 0) {
    if (big_get_sign(inp) == 0) {
      *error_code = 1;  // число слишком велико или равно бесконечности;
    } else {
      *error_code =
          2;  // число слишком мало или равно отрицательной бесконечности;
    }
  } else {  // мантисса бд меньше или равна децимала
    big_to_decimal(inp, outp);
    *error_code = 0;  // OK
  }
}

void decimal_to_big(s21_decimal inp, s21_big_decimal *outp) {
  // nullify big_decimal
  big_null_decimal(
      outp);  // надо ли занулять? после инициализации она и так нулевая

  // copy mantissa, second way, to test!
  for (int i = 0; i < 3; i++) {
    outp->bits[i] = inp.bits[i];
  }

  // copy scale
  int scale = get_scale(inp);
  big_set_scale(outp, scale);

  // copy sign
  int sign = get_sign(inp);
  big_set_sign(outp, sign);
}

void big_to_decimal(s21_big_decimal inp, s21_decimal *outp) {
  // nullify decimal
  null_decimal(outp);

  // copy mantissa, second way, to test!
  for (int i = 0; i < 3; i++) {
    outp->bits[i] = inp.bits[i];
  }

  // copy scale
  int scale = big_get_scale(inp);
  set_scale(outp, scale);

  // copy sign
  int sign = big_get_sign(inp);
  set_sign(outp, sign);
}

// функции сравнения

int big_compare_scales(s21_big_decimal value_1, s21_big_decimal value_2) {
  int scale_1 = big_get_scale(value_1);
  int scale_2 = big_get_scale(value_2);

  int result = 666;
  if (scale_1 == scale_2) {
    result = 0;
  } else if (scale_1 > scale_2) {
    result = 1;
  } else if (scale_1 < scale_2) {
    result = -1;
  }
  return result;
}

int big_compare_signs(s21_big_decimal value_1, s21_big_decimal value_2) {
  int sign_1 = big_get_sign(value_1);
  int sign_2 = big_get_sign(value_2);

  int result = 666;
  if (sign_1 == sign_2) {
    result = 0;
  } else if (sign_1 > sign_2) {
    result = 1;
  } else if (sign_1 < sign_2) {
    result = -1;
  }
  return result;
}

int big_compare_mantissa(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 666;
  for (int i = (int)(sizeof(s21_big_decimal) / sizeof(unsigned int) - 1) * 32;
       i >= 0; i--) {
    int bit_1 = big_get_bit(value_1, i);
    int bit_2 = big_get_bit(value_2, i);

    if (bit_1 == bit_2) {
      result = 0;
      continue;
    } else if (bit_1 > bit_2) {
      result = 1;
      break;
    } else if (bit_1 < bit_2) {
      result = -1;
      break;
    }
  }
  return result;
}

int big_mantissa_is_zero(s21_big_decimal num) {
  int result = 1;
  for (int i = 0; i < (int)(sizeof(s21_big_decimal) / sizeof(unsigned) - 1);
       i++) {
    if (num.bits[i] != 0) {
      result = 0;
      break;
    }
  }
  return result;
}

int mantissa_is_zero(s21_decimal num) {
  int result = 1;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(unsigned) - 1); i++) {
    if (num.bits[i] != 0) {
      result = 0;
      break;
    }
  }
  return result;
}

int big_mantissa_leq_decimal_mantissa(s21_big_decimal inp) {
  int result = 1;
  for (int i = 3; i < 6; i++) {
    if (inp.bits[i] != 0) {
      result = 0;  // мантисса больше чем у децимала
      break;
    }
  }
  return result;
}

int big_mantissa_le_ten(s21_big_decimal inp) {
  int result = 1;
  if ((inp.bits[0] >= (unsigned int)10) || (inp.bits[1] > (unsigned int)0) ||
      (inp.bits[2] > (unsigned int)0) || (inp.bits[3] > (unsigned int)0) ||
      (inp.bits[4] > (unsigned int)0) || (inp.bits[5] > (unsigned int)0)) {
    result = 0;
  }
  return result;
}

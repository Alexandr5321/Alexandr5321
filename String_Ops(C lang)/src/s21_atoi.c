#include "s21_string.h"

int s21_atoi(char *str) {
  int res = 0;
  int cf = 1;
  str += s21_strcspn(str, TRIM);
  if (*str == '+') {
    str++;
  }
  if (*str == '-') {
    cf = -1;
    str++;
  }
  while (*str >= '0' && *str <= '9') {
    res = res * 10 + *str++ - '0';
  }
  return res * cf;
}

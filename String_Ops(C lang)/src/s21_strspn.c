#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != S21_NULL) && (str2 != S21_NULL)) {
    while (*str1 != '\0') {
      if (s21_strchr(str2, *str1) == S21_NULL) {
        break;
      } else {
        str1++;
        len++;
      }
    }
  }
  return len;
}
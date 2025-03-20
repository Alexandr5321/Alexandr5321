#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t length_str = s21_strlen(str);
  char *pointer = S21_NULL;
  for (s21_size_t i = 0; i < length_str + 1; i++) {
    if (str[i] == c) {
      pointer = (char *)&str[i];
    }
  }
  return pointer;
}
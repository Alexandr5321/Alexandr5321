#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  unsigned char *ptr1 = (unsigned char *)str1;
  unsigned char *ptr2 = (unsigned char *)str2;
  int diff = 0;
  for (size_t i = 0; i < n || (ptr1 == s21_NULL || ptr2 == s21_NULL); i++) {
    diff = *ptr1 - *ptr2;
    if (*ptr1 != *ptr2) {
      break;
    }
    ptr1++;
    ptr2++;
  }
  return diff;
}
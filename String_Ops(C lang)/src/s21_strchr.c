#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  unsigned char *ptr = (unsigned char *)str;
  void *out = s21_NULL;
  for (size_t i = 0; i < s21_strlen(str) && ptr; i++) {
    if (*ptr == (unsigned char)c) {
      out = ptr;
      break;
    }
    ptr++;
  }
  return out;
}
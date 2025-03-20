#include "s21_string.h"

void *s21_memchr(const char *str, int c, s21_size_t len) {
  unsigned char *ptr = (unsigned char *)str;
  void *out = s21_NULL;
  for (s21_size_t i = 0; i < len && ptr; i++) {
    if (*ptr == (unsigned char)c) {
      out = ptr;
      break;
    }
    ptr++;
  }
  return out;
}
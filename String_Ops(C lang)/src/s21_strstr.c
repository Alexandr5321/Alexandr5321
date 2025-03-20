#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len_needle = s21_strlen(needle);
  s21_size_t len_haystack = s21_strlen(haystack);

  if (!len_needle) {
    return (char *)haystack;
  }

  for (s21_size_t i = 0; i <= len_haystack - len_needle; ++i) {
    if (haystack[i] == needle[0]) {
      bool match = true;
      for (s21_size_t j = 1; j < len_needle; ++j) {
        if (haystack[i + j] != needle[j]) {
          match = false;
          break;
        }
      }

      if (match) {
        return (char *)(haystack + i);
      }
    }
  }

  return NULL;
}

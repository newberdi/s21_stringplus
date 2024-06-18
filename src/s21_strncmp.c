#include "s21_string.h"

// Compares at most the first n bytes of str1 and str2

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (int i = 0; (n > 0) && !result; n--, i++) {
    if (str1[i] != str2[i]) {
      result = str1[i] - str2[i];
    }
  }
  return result;
}
#include "s21_string.h"

// Compares the first n bytes of str1 and str2

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  char* s1 = (char*)str1;
  char* s2 = (char*)str2;

  int result = 0;
  int flag = 1;

  for (s21_size_t i = 0; i < n && flag; i++) {
    if (*s1 == *s2) {
      s1++;
      s2++;
    } else {
      result = *s1 - *s2;
      flag = 0;
    }
  }

  return result;
}
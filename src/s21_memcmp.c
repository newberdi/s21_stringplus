#include "s21_string.h"

// Compares the first n bytes of str1 and str2

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  unsigned char* s1 = (unsigned char*)str1;
  unsigned char* s2 = (unsigned char*)str2;
  int result = 0;
  while (n && (s1 == s2)) {
    s1++;
    s2++;
    n--;
  }
  if (s1 > s2) {
    result = *s1;
  }
  if (s1 < s2) {
    result = *s2 * (-1);
  }
  return result;
}
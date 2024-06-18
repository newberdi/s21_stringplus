#include "s21_string.h"

// Copies the character c (an unsigned char) to the
// first n characters of the string pointed to, by the argument str

void* s21_memset(void* str, int c, s21_size_t n) {
  unsigned char* result = (unsigned char*)str;
  while (n) {
    *result = c;
    result++;
    n--;
  }
  return result;
}
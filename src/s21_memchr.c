#include "s21_string.h"

// Searches for the first occurrence of the character c (an unsigned char)
// in the first n bytes of the string pointed to, by the argument str

void* s21_memchr(const void* str, int ch, s21_size_t size) {
  unsigned char* s = (unsigned char*)str;
  int result = 0;
  while (size && !result) {
    if (*s == ch) {
      result++;
    }
    size--;
    s++;
  }
  if (!result) {
    return (S21_NULL);
  } else {
    return (void*)s;
  }
}
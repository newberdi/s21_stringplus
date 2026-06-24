#include "s21_string.h"

// Searches for the first occurrence of the character c (an unsigned char)
// in the first n bytes of the string pointed to, by the argument str

void* s21_memchr(const void* str, int ch, s21_size_t size) {
  char* s = (char*)str;
  void* result = S21_NULL;
  int flag = 1;

  for (s21_size_t i = 0; i < size && flag; i++)
    if (*s == (char)ch) {
      result = (void*)s;
      flag = 0;
    } else
      s++;

  return result;
}
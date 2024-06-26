#include "s21_string.h"

// Copies n characters from src to dest

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  char* result = (char*)dest;
  char* src_ptr = (char*)src;
  while (n) {
    *result = *src_ptr;
    result++;
    src_ptr++;
    n--;
  }
  return dest;
}
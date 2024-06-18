#include "s21_string.h"

// Copies n characters from src to dest

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  unsigned char* result = (unsigned char*)dest;
  unsigned char* src_ptr = (unsigned char*)src;
  while (n) {
    *result = *src_ptr;
    result++;
    src_ptr++;
    n--;
  }
  return result;
}
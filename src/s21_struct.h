#ifndef S21_STRUCTURES_H_
#define S21_STRUCTURES_H_
#include <stdint.h>

typedef union s21_decimal
{
   union {
      unsigned int bit1;
      unsigned int bit2;
      unsigned int bit3;
   } data;

   union{
      int16_t non_use;
      int8_t degree;
      int8_t sign;
   } header;
} s21_decimal;

typedef enum {
    ARITHMETIC_OK = 0,
    S21_INFINITY = 1,
    S21_NEGATIVE_INFINITY = 2,
    S21_NAN = 3
} arithmetic_result;

typedef enum {
    POS = 0,
    NEG = 1
} arithmetic_consts;

typedef enum {
    FALSE = 0,
    TRUE = 1,
} comparison_result;

typedef enum {
    CONVERTATION_OK = 0,
    CONVERTATION_ERROR = 1
} convertation_result;

#endif  // S21_STRUCTURES_H_

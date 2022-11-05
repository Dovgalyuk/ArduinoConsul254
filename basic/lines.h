#ifndef __LINES_H__
#define __LINES_H__

#include <stdbool.h>
#include <stdint.h>
#include <avr/pgmspace.h>

typedef struct line line;

typedef uint_farptr_t codeptr_t;

#define MAX_LINE_LEN 128

struct line
{
  uint16_t  number;
  //uint8_t   length;
  char      contents[MAX_LINE_LEN];
};

codeptr_t lines_get_contents(uint16_t number);

uint16_t lines_first(void);
uint16_t lines_next(uint16_t number);

#endif // __LINES_H__

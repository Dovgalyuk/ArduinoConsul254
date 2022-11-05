// -- Lines BASIC program storage

// TODO:
//  v delete line
//  v wipe
//  v get_line
//  . clean up code
//  v integrate with parser

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lines.h"

extern codeptr_t __memory;

  static codeptr_t
_next(codeptr_t l)
{
  return l + sizeof(line);
}

static uint16_t _get_number(codeptr_t l)
{
  return pgm_read_word_far(l);
}

static bool
_is_end(codeptr_t l)
{
  return l && _get_number(l) == 0;
}

  static codeptr_t
_find_end(codeptr_t l)
{
  codeptr_t n = l;
  while ( ! _is_end( n ) )
  {
    n = _next( n );
  }
  return n;  
}

codeptr_t
lines_get_contents(uint16_t number)
{
  codeptr_t l = __memory;
  while( ! _is_end( l )
    && _get_number(l) != number)
  {
    l = _next( l );
  }

  if ( _is_end( l ) )
  {
    return NULL;
  }

  return l + 2;//offsetof(line, contents);
}

uint16_t
lines_first(void)
{
  codeptr_t l = __memory;
  return _get_number(l);
}

uint16_t
lines_next(uint16_t number)
{
  codeptr_t l = __memory;
  while( ! _is_end( l ) && _get_number(l) <= number)
  {
    l = _next( l );
  }

  if ( number == _get_number(l) )
  {
    return 0;
  }

  return _get_number(l);
}

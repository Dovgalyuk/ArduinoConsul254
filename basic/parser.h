#ifndef __PARSER_H__
#define __PARSER_H__

#include "tokenizer.h"
#include "io.h"

#include <stdbool.h>

char* basic_readline(char* prompt, char* buffer, size_t buffer_size);

#ifdef __cplusplus
extern "C" {
#endif
void basic_init(void);
void basic_clear(void);
void basic_run(codeptr_t program);
#ifdef __cplusplus
}
#endif

// For extensions

typedef float (*function)(float number);

typedef struct
{
  token _token;
  function _function;
} token_to_function;

typedef enum {
  basic_function_type_keyword,
  basic_function_type_op,
  basic_function_type_numeric,
  basic_function_type_string,
  basic_function_type_print
} basic_function_type;

typedef enum {
  kind_numeric,
  kind_string
} kind;

typedef union {
  float number;
  char* string;
} value;

typedef struct {
  kind kind;
  bool empty;
  bool mallocd;
  value value;
} basic_type;

typedef int (*function_0)(basic_type* rv);
typedef int (*function_1)(basic_type* v1, basic_type* rv);
typedef int (*function_2)(basic_type* v1, basic_type* v2, basic_type* rv);
typedef int (*function_3)(basic_type* v1, basic_type* v2, basic_type* v3, basic_type* rv);
//typedef int (*function_4)(basic_type* v1, basic_type* v2, basic_type* v3, basic_type* v4, basic_type* rv);
//typedef int (*function_5)(basic_type* v1, basic_type* v2, basic_type* v3, basic_type* v4, basic_type* v5, basic_type* rv);

token register_token(char* token_name);
token register_function_0(basic_function_type type, char* keyword, function_0 function);
token register_function_1(basic_function_type type, char* keyword, function_1 function, kind v1);
token register_function_2(basic_function_type type, char* keyword, function_2 function, kind v1, kind v2);
token register_function_3(basic_function_type type, char* keyword, function_3 function, kind v1, kind v2, kind v3);
//token register_function_4(basic_function_type type, char* keyword, function_4 function, kind v1, kind v2, kind v3, kind v4);
//token register_function_5(basic_function_type type, char* keyword, function_5 function, kind v1, kind v2, kind v3, kind v4, kind v5);

#endif // __PARSER_H__

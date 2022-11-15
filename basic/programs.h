#ifndef PROGRAMS_H
#define PROGRAMS_H

#include "lines.h"

#ifdef __cplusplus
extern "C" {
#endif
void program_menu(void);
codeptr_t program_get(uint8_t n);
#ifdef __cplusplus
}
#endif

#endif

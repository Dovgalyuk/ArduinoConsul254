#ifndef __IO_H__
#define __IO_H__

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
void system_io_init(void);
#ifdef __cplusplus
}
#endif

void __putch(int ch);
int __getch(void);

void basic_io_print(char* buffer);
char* basic_io_readline(char* prompt, char* buffer, size_t buffer_size);

#endif // __IO_H__

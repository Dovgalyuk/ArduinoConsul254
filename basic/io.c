#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "io.h"

  void
basic_io_print(char* buffer)
{
    for(size_t i=0; i<strlen(buffer); ++i)
    {
      __putch(buffer[i]);
    }
}

char*
basic_io_readline(char* prompt, char* buffer, size_t buffer_size)
{
  size_t len = 0;
  char ch;
  basic_io_print(prompt);
  __putch('\01');
  while ((ch = __getch()) != '\n' && len < buffer_size - 1)
  {
    if (ch == '\r') break;
//    ch = toupper(ch);
    __putch(ch);
//     switch(ch){
//       case '\b':
//         if(len>0){
//           buffer[--len] = '\0';
// #         ifdef BASIC_READLINE_ECHO
//           __putch(' ');
//           __putch('\b');
// #         endif
//         }
//         break;
//       default:
        buffer[len++] = ch;
    // }
  }
  __putch('\n');
  buffer[len] = '\0';
  return buffer;
}

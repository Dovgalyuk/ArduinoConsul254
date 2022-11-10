#ifndef __ERROR_H__
#define __ERROR_H__

//extern char *last_error;
//void error(const char *error_msg);

#define error(E) do basic_io_print(E); while(0)

#endif

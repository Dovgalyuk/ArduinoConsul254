#include "parser.h"
#include "programs.h"
#include "io.h"

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  //basic_io_print("SYSTEM INIT\n");
  system_io_init();
  //basic_io_print("BASIC INIT\n");
  basic_init();
}

void loop() {
  char buf[3] = {};
  char msg[] = "SELECT GAME (0 - PRINT MENU)";
  basic_io_readline(msg, buf, 3);
//  while(1);
  uint8_t n = atoi(buf);
  codeptr_t prog = program_get(n);
  if (prog)
  {
  //   //basic_io_print("BASIC RUN\n");
    srand(millis());
    basic_run(prog);
  //   //basic_io_print("!!!!!!!!!!!!END\n");
    basic_clear();
  }
  else
  {
    program_menu();
  }

// pgm_read_byte_far
//uint_farptr_t a = pgm_get_far_address()
}

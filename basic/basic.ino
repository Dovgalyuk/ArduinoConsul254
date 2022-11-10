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
  // put your main code here, to run repeatedly:

  //basic_io_print("BASIC RUN\n");
  basic_run(pgm_get_far_address(program_tictactoe2));
  //basic_io_print("!!!!!!!!!!!!END\n");
  basic_clear();

// pgm_read_byte_far
//uint_farptr_t a = pgm_get_far_address()
}

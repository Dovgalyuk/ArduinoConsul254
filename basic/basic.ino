#include "parser.h"
#include "programs.h"
#include "io.h"

void setup() {
  system_io_init();
  basic_init();
  basic_run(pgm_get_far_address(program_tictactoe2));
}

void loop() {
  // put your main code here, to run repeatedly:


// pgm_read_byte_far
//uint_farptr_t a = pgm_get_far_address()
}

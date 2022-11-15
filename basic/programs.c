#include "programs.h"
#include "io.h"

extern const PROGMEM line program_23matches[];
extern const PROGMEM line program_animal[];
extern const PROGMEM line program_bagels[];
extern const PROGMEM line program_buzzword[];
extern const PROGMEM line program_guess[];
extern const PROGMEM line program_hammurabi[];
extern const PROGMEM line program_hangman[];
extern const PROGMEM line program_hello[];
extern const PROGMEM line program_nicomachus[];
extern const PROGMEM line program_russianroulette[];
extern const PROGMEM line program_tictactoe2[];

void program_menu(void)
{
  basic_io_print("1. 23 MATCHES  2. ANIMAL     3. BAGELS   4. BUZZWORD\n");
  basic_io_print("5. GUESS       6. HAMMURABI  7. HANGMAN  8. HELLO\n");
  basic_io_print("9. NICOMACHUS  10. RUSSIAN ROULETTE 11. TIC-TAC-TOE\n");
}

codeptr_t program_get(uint8_t n)
{
  switch (n)
  {
    case 1: return pgm_get_far_address(program_23matches);
    case 2: return pgm_get_far_address(program_animal);
    case 3: return pgm_get_far_address(program_bagels);
    case 4: return pgm_get_far_address(program_buzzword);
    case 5: return pgm_get_far_address(program_guess);
    case 6: return pgm_get_far_address(program_hammurabi);
    case 7: return pgm_get_far_address(program_hangman);
    case 8: return pgm_get_far_address(program_hello);
    case 9: return pgm_get_far_address(program_nicomachus);
    case 10: return pgm_get_far_address(program_russianroulette);
    case 11: return pgm_get_far_address(program_tictactoe2);
  }
  return 0;
}

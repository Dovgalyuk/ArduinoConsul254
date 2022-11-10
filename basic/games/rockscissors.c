#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_rockscissors[] = {
{10, "PRINT TAB(21);\"GAME OF ROCK, SCISSORS, PAPER\""},
{20, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\""},
{25, "PRINT:PRINT:PRINT"},
{30, "INPUT \"HOW MANY GAMES\";Q"},
{40, "IF Q<11 THEN 60"},
{50, "PRINT \"SORRY, BUT WE AREN'T ALLOWED TO PLAY THAT MANY.\": GOTO 30"},
{60, "FOR G=1 TO Q"},
{70, "PRINT: PRINT \"GAME NUMBER\";G"},
{80, "X=INT(RND(1)*3+1)"},
{90, "PRINT \"3=ROCK...2=SCISSORS...1=PAPER\""},
{100, "INPUT \"1...2...3...WHAT'S YOUR CHOICE\";K"},
{110, "IF (K-1)*(K-2)*(K-3)<>0 THEN PRINT \"INVALID.\": GOTO 90"},
{120, "PRINT \"THIS IS MY CHOICE...\""},
{130, "ON X GOTO 140,150,160"},
{140, "PRINT \"...PAPER\": GOTO 170"},
{150, "PRINT \"...SCISSORS\": GOTO 170"},
{160, "PRINT \"...ROCK\""},
{170, "IF X=K THEN 250"},
{180, "IF X>K THEN 230"},
{190, "IF X=1 THEN 210"},
{200, "PRINT \"YOU WIN!!!\":H=H+1: GOTO 260"},
{210, "IF K<>3 THEN 200"},
{220, "PRINT \"WOW!  I WIN!!!\":C=C+1:GOTO 260"},
{230, "IF K<>1 OR X<>3 THEN 220"},
{240, "GOTO 200"},
{250, "PRINT \"TIE GAME.  NO WINNER.\""},
{260, "NEXT G"},
{270, "PRINT: PRINT \"HERE IS THE FINAL GAME SCORE:\""},
{280, "PRINT \"I HAVE WON \";C;\" GAME(S).\""},
{290, "PRINT \"YOU HAVE WON \";H;\" GAME(S).\""},
{300, "PRINT \"AND \";Q-(C+H);\" GAME(S) ENDED IN A TIE.\""},
{310, "PRINT: PRINT \"THANKS FOR PLAYING!!\""},
{320, "END"},
{},
};

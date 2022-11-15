#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_23matches[] = {
{20, "PRINT TAB(31);\"23 MATCHES\""},
{30, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\""},
{40, "PRINT:PRINT:PRINT"},
{80, "PRINT \" THIS IS A GAME CALLED '23 MATCHES'.\""},
{90, "PRINT"},
{100, "PRINT \"WHEN IT IS YOUR TURN, YOU MAY TAKE ONE, TWO, OR THREE\""},
{110, "PRINT \"MATCHES. THE OBJECT OF THE GAME IS NOT TO HAVE TO TAKE\""},
{120, "PRINT \"THE LAST MATCH.\""},
{130, "PRINT"},
{140, "PRINT \"LET'S FLIP A COIN TO SEE WHO GOES FIRST.\""},
{150, "PRINT \"IF IT COMES UP HEADS, I WILL WIN THE TOSS.\""},
{155, "PRINT"},
{160, "REM"},
{165, "N = 23"},
{170, "Q = INT(2*RND(5))"},
{180, "IF Q = 1 THEN 210"},
{190, "PRINT \"TAILS! YOU GO FIRST. \""},
{195, "PRINT"},
{200, "GOTO 300"},
{210, "PRINT \"HEADS! I WIN! HA! HA!\""},
{220, "PRINT \"PREPARE TO LOSE, MEATBALL-NOSE!!\""},
{230, "PRINT"},
{250, "PRINT \"I TAKE 2 MATCHES\""},
{260, "N = N -2"},
{270, "PRINT \"THE NUMBER OF MATCHES IS NOW\" N"},
{280, "PRINT"},
{290, "PRINT \"YOUR TURN -- YOU MAY TAKE 1, 2 OR 3 MATCHES.\""},
{300, "PRINT \"HOW MANY DO YOU WISH TO REMOVE\","},
{310, "INPUT K"},
{320, "IF K > 3 THEN 430"},
{330, "IF K <= 0 THEN 430"},
{340, "N = N - K"},
{350, "PRINT \"THERE ARE NOW\";N;\"MATCHES REMAINING.\""},
{351, "IF N = 4 THEN 381"},
{352, "IF N = 3 THEN 383"},
{353, "IF N = 2 THEN 385"},
{360, "IF N <= 1 THEN  530"},
{370, "Z = 4 - K"},
{372, "GOTO 390"},
{380, "PRINT"},
{381, "Z = 3"},
{382, "GOTO 390"},
{383, "Z = 2"},
{384, "GOTO 390"},
{385, "Z = 1"},
{390, "PRINT \"MY TURN ! I REMOVE\" Z \"MATCHES\""},
{400, "N = N - Z"},
{410, "IF N <= 1 THEN 470"},
{420, "GOTO 270"},
{430, "PRINT \"VERY FUNNY! DUMMY!\""},
{440, "PRINT \"DO YOU WANT TO PLAY OR GOOF AROUND?\""},
{450, "PRINT \"NOW, HOW MANY MATCHES DO YOU WANT\","},
{460, "GOTO 310"},
{470, "PRINT"},
{480, "PRINT\"YOU POOR BOOB! YOU TOOK THE LAST MATCH! I GOTCHA!!\""},
{490, "PRINT \"HA ! HA ! I BEAT YOU !!!\""},
{500, "PRINT"},
{510, "PRINT \"GOOD BYE LOSER!\""},
{520, "GOTO 560"},
{530, "PRINT \"YOU WON, FLOPPY EARS !\""},
{540, "PRINT \"THINK YOU'RE PRETTY SMART !\""},
{550, "PRINT \"LETS PLAY AGAIN AND I'LL BLOW YOUR SHOES OFF !!\""},
{560, "STOP"},
{570, "END"},
{},
};

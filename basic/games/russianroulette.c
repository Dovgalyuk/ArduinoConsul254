#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_russianroulette[] = {
{1, "PRINT TAB(28);\"RUSSIAN ROULETTE\"\n"},
{2, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\"\n"},
{3, "PRINT:PRINT:PRINT\n"},
{5, "PRINT \"THIS IS A GAME OF >>>>>>>>>>RUSSIAN ROULETTE.\"\n"},
{10, "PRINT:PRINT \"HERE IS A REVOLVER.\"\n"},
{20, "PRINT \"TYPE '1' TO SPIN CHAMBER AND PULL TRIGGER.\"\n"},
{22, "PRINT \"TYPE '2' TO GIVE UP.\"\n"},
{23, "PRINT \"GO\";\n"},
{25, "N=0\n"},
{30, "INPUT I\n"},
{31, "IF I<>2 THEN 35\n"},
{32, "PRINT \"     CHICKEN!!!!!\"\n"},
{33, "GOTO 72\n"},
{35, "N=N+1\n"},
{40, "IF RND(1)>.833333 THEN 70\n"},
{45, "IF N>10 THEN 80\n"},
{50, "PRINT \"- CLICK -\"\n"},
{60, "PRINT: GOTO 30\n"},
{70, "PRINT \"     BANG!!!!!   YOU'RE DEAD!\"\n"},
{71, "PRINT \"CONDOLENCES WILL BE SENT TO YOUR RELATIVES.\"\n"},
{72, "PRINT:PRINT:PRINT\n"},
{75, "PRINT \"...NEXT VICTIM...\":GOTO 20\n"},
{80, "PRINT \"YOU WIN!!!!!\"\n"},
{85, "PRINT \"LET SOMEONE ELSE BLOW HIS BRAINS OUT.\"\n"},
{90, "GOTO 10\n"},
{99, "END\n"},
{},
};

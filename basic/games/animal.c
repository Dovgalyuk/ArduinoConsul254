#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_animal[] = {
{10, "PRINT TAB(32);\"ANIMAL\"\n"},
{20, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\"\n"},
{30, "PRINT: PRINT: PRINT\n"},
{40, "PRINT \"PLAY 'GUESS THE ANIMAL'\"\n"},
{45, "PRINT\n"},
{50, "PRINT \"THINK OF AN ANIMAL AND THE COMPUTER WILL TRY TO GUESS IT.\"\n"},
{60, "PRINT\n"},
{70, "DIM A$(200)\n"},
{80, "FOR I=0 TO 3\n"},
{90, "READ A$(I)\n"},
{100, "NEXT I\n"},
{110, "N=VAL(A$(0))\n"},
{120, "REM          MAIN CONTROL SECTION\n"},
{130, "INPUT \"ARE YOU THINKING OF AN ANIMAL\";A$\n"},
{140, "IF A$=\"LIST\" THEN 600\n"},
{150, "IF LEFT$(A$,1)<>\"Y\" THEN 120\n"},
{160, "K=1\n"},
{170, "GOSUB 390\n"},
{180, "IF LEN(A$(K))=0 THEN 999\n"},
{190, "IF LEFT$(A$(K),2)=\"\Q\" THEN 170\n"},
{200, "PRINT \"IS IT A \";RIGHT$(A$(K),LEN(A$(K))-2);\n"},
{210, "INPUT A$\n"},
{220, "A$=LEFT$(A$,1)\n"},
{230, "IF LEFT$(A$,1)=\"Y\" THEN PRINT \"WHY NOT TRY ANOTHER ANIMAL?\": GOTO 120\n"},
{240, "INPUT \"THE ANIMAL YOU WERE THINKING OF WAS A \";V$\n"},
{250, "PRINT \"PLEASE TYPE IN A QUESTION THAT WOULD DISTINGUISH A\"\n"},
{260, "PRINT V$;\" FROM A \";RIGHT$(A$(K),LEN(A$(K))-2)\n"},
{270, "INPUT X$\n"},
{280, "PRINT \"FOR A \";V$;\" THE ANSWER WOULD BE \";\n"},
{290, "INPUT A$\n"},
{300, "A$=LEFT$(A$,1): IF A$<>\"Y\" AND A$<>\"N\" THEN 280\n"},
{310, "IF A$=\"Y\" THEN B$=\"N\"\n"},
{320, "IF A$=\"N\" THEN B$=\"Y\"\n"},
{330, "Z1=VAL(A$(0))\n"},
{340, "A$(0)=STR$(Z1+2)\n"},
{350, "A$(Z1)=A$(K)\n"},
{360, "A$(Z1+1)=\"\A\"+V$\n"},
{370, "A$(K)=\"\Q\"+X$+\"\\"+A$+STR$(Z1+1)+\"\\"+B$+STR$(Z1)+\"\\"\n"},
{380, "GOTO 120\n"},
{390, "REM     SUBROUTINE TO PRINT QUESTIONS\n"},
{400, "Q$=A$(K)\n"},
{410, "FOR Z=3 TO LEN(Q$)\n"},
{415, "IF MID$(Q$,Z,1)<>\"\\" THEN PRINT MID$(Q$,Z,1);: NEXT Z\n"},
{420, "INPUT C$\n"},
{430, "C$=LEFT$(C$,1)\n"},
{440, "IF C$<>\"Y\" AND C$<>\"N\" THEN 410\n"},
{450, "T$=\"\\"+C$\n"},
{455, "FOR X=3 TO LEN(Q$)-1\n"},
{460, "IF MID$(Q$,X,2)=T$ THEN 480\n"},
{470, "NEXT X\n"},
{475, "STOP\n"},
{480, "FOR Y=X+1 TO LEN(Q$)\n"},
{490, "IF MID$(Q$,Y,1)=\"\\" THEN 510\n"},
{500, "NEXT Y\n"},
{505, "STOP\n"},
{510, "K=VAL(MID$(Q$,X+2,Y-X-2))\n"},
{520, "RETURN\n"},
{530, "DATA \"4\",\"\QDOES IT SWIM\Y2\N3\\",\"\AFISH\",\"\ABIRD\"\n"},
{600, "PRINT:PRINT \"ANIMALS I ALREADY KNOW ARE:\"\n"},
{605, "X=0\n"},
{610, "FOR I=1 TO 200\n"},
{620, "IF LEFT$(A$(I),2)<>\"\A\" THEN 650\n"},
{624, "PRINT TAB(15*X);\n"},
{630, "FOR Z=3 TO LEN(A$(I))\n"},
{640, "IF MID$(A$(I),Z,1)<>\"\\" THEN PRINT MID$(A$(I),Z,1);: NEXT Z\n"},
{645, "X=X+1: IF X=4 THEN X=0: PRINT\n"},
{650, "NEXT I\n"},
{660, "PRINT\n"},
{670, "PRINT\n"},
{680, "GOTO 120\n"},
{999, "END\n"},
{},
};

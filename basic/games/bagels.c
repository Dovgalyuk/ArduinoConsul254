#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_bagels[] = {
{5, "PRINT TAB(33);\"BAGELS\"\n"},
{10, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\":PRINT:PRINT\n"},
{15, "REM *** BAGLES NUMBER GUESSING GAME\n"},
{20, "REM *** ORIGINAL SOURCE UNKNOWN BUT SUSPECTED TO BE\n"},
{25, "REM *** LAWRENCE HALL OF SCIENCE, U.C. BERKELY\n"},
{30, "DIM A1(6),A(3),B(3)\n"},
{40, "Y=0:T=255\n"},
{50, "PRINT:PRINT:PRINT\n"},
{70, "INPUT \"WOULD YOU LIKE THE RULES (YES OR NO)\";A$\n"},
{90, "IF LEFT$(A$,1)=\"N\" THEN 150\n"},
{100, "PRINT:PRINT \"I AM THINKING OF A THREE-DIGIT NUMBER.  TRY TO GUESS\"\n"},
{110, "PRINT \"MY NUMBER AND I WILL GIVE YOU CLUES AS FOLLOWS:\"\n"},
{120, "PRINT \"   PICO   - ONE DIGIT CORRECT BUT IN THE WRONG POSITION\"\n"},
{130, "PRINT \"   FERMI  - ONE DIGIT CORRECT AND IN THE RIGHT POSITION\"\n"},
{140, "PRINT \"   BAGELS - NO DIGITS CORRECT\"\n"},
{150, "FOR I=1 TO 3\n"},
{160, "A(I)=INT(10*RND(1))\n"},
{165, "IF I-1=0 THEN 200\n"},
{170, "FOR J=1 TO I-1\n"},
{180, "IF A(I)=A(J) THEN 160\n"},
{190, "NEXT J\n"},
{200, "NEXT I\n"},
{210, "PRINT:PRINT \"O.K.  I HAVE A NUMBER IN MIND.\"\n"},
{220, "FOR I=1 TO 20\n"},
{230, "PRINT \"GUESS #\";I,\n"},
{240, "INPUT A$\n"},
{245, "IF LEN(A$)<>3 THEN 630\n"},
{250, "FOR Z=1 TO 3:A1(Z)=ASC(MID$(A$,Z,1)):NEXT Z\n"},
{260, "FOR J=1 TO 3\n"},
{270, "IF A1(J)<48 THEN 300\n"},
{280, "IF A1(J)>57 THEN 300\n"},
{285, "B(J)=A1(J)-48\n"},
{290, "NEXT J\n"},
{295, "GOTO 320\n"},
{300, "PRINT \"WHAT?\"\n"},
{310, "GOTO 230\n"},
{320, "IF B(1)=B(2) THEN 650\n"},
{330, "IF B(2)=B(3) THEN 650\n"},
{340, "IF B(3)=B(1) THEN 650\n"},
{350, "C=0:D=0\n"},
{360, "FOR J=1 TO 2\n"},
{370, "IF A(J)<>B(J+1) THEN 390\n"},
{380, "C=C+1\n"},
{390, "IF A(J+1)<>B(J) THEN 410\n"},
{400, "C=C+1\n"},
{410, "NEXT J\n"},
{420, "IF A(1)<>B(3) THEN 440\n"},
{430, "C=C+1\n"},
{440, "IF A(3)<>B(1) THEN 460\n"},
{450, "C=C+1\n"},
{460, "FOR J=1 TO 3\n"},
{470, "IF A(J)<>B(J) THEN 490\n"},
{480, "D=D+1\n"},
{490, "NEXT J\n"},
{500, "IF D=3 THEN 680\n"},
{505, "IF C=0 THEN 545\n"},
{520, "FOR J=1 TO C\n"},
{530, "PRINT \"PICO \";\n"},
{540, "NEXT J\n"},
{545, "IF D=0 THEN 580\n"},
{550, "FOR J=1 TO D\n"},
{560, "PRINT \"FERMI \";\n"},
{570, "NEXT J\n"},
{580, "IF C+D<>0 THEN 600\n"},
{590, "PRINT \"BAGELS\";\n"},
{600, "PRINT\n"},
{605, "NEXT I\n"},
{610, "PRINT \"OH WELL.\"\n"},
{615, "PRINT \"THAT'S TWENTY GUESSES.  MY NUMBER WAS \";100*A(1)+10*A(2)+A(3)\n"},
{620, "GOTO 700\n"},
{630, "PRINT \"TRY GUESSING A THREE-DIGIT NUMBER.\":GOTO 230\n"},
{650, "PRINT \"OH, I FORGOT TO TELL YOU THAT THE NUMBER I HAVE IN MIND\"\n"},
{660, "PRINT \"HAS NO TWO DIGITS THE SAME.\":GOTO 230\n"},
{680, "PRINT \"YOU GOT IT!!!\":PRINT\n"},
{690, "Y=Y+1\n"},
{700, "INPUT \"PLAY AGAIN (YES OR NO)\";A$\n"},
{720, "IF LEFT$(A$,1)=\"YES\" THEN 150\n"},
{730, "IF Y=0 THEN 750\n"},
{740, "PRINT:PRINT \"A \";Y;\" POINT BAGELS BUFF!!\"\n"},
{750, "PRINT \"HOPE YOU HAD FUN.  BYE.\"\n"},
{999, "END\n"},
{},
};

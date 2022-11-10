#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_chomp[] = {
{10, "PRINT TAB(33);\"CHOMP\""},
{20, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\""},
{30, "PRINT:PRINT:PRINT"},
{40, "DIM A(10,10)"},
{100, "REM *** THE GAME OF CHOMP *** COPYRIGHT PCC 1973 ***"},
{110, "PRINT"},
{120, "PRINT \"THIS IS THE GAME OF CHOMP (SCIENTIFIC AMERICAN, JAN 1973)\""},
{130, "PRINT \"DO YOU WANT THE RULES (1=YES, 0=NO!)\";"},
{140, "INPUT R"},
{150, "IF R=0 THEN 340"},
{160, "F=1"},
{170, "R=5"},
{180, "C=7"},
{190, "PRINT \"CHOMP IS FOR 1 OR MORE PLAYERS (HUMANS ONLY).\""},
{200, "PRINT"},
{210, "PRINT \"HERE'S HOW A BOARD LOOKS (THIS ONE IS 5 BY 7):\""},
{220, "GOSUB 540"},
{230, "PRINT"},
{240, "PRINT \"THE BOARD IS A BIG COOKIE - R ROWS HIGH AND C COLUMNS\""},
{250, "PRINT \"WIDE. YOU INPUT R AND C AT THE START. IN THE UPPER LEFT\""},
{260, "PRINT \"CORNER OF THE COOKIE IS A POISON SQUARE (P). THE ONE WHO\""},
{270, "PRINT \"CHOMPS THE POISON SQUARE LOSES. TO TAKE A CHOMP, TYPE THE\""},
{280, "PRINT \"ROW AND COLUMN OF ONE OF THE SQUARES ON THE COOKIE.\""},
{290, "PRINT \"ALL OF THE SQUARES BELOW AND TO THE RIGHT OF THAT SQUARE\""},
{300, "PRINT \"(INCLUDING THAT SQUARE, TOO) DISAPPEAR -- CHOMP!!\""},
{310, "PRINT \"NO FAIR CHOMPING SQUARES THAT HAVE ALREADY BEEN CHOMPED,\""},
{320, "PRINT \"OR THAT ARE OUTSIDE THE ORIGINAL DIMENSIONS OF THE COOKIE.\""},
{330, "PRINT"},
{340, "PRINT \"HERE WE GO...\""},
{350, "REM"},
{360, "F=0"},
{370, "FOR I=1 TO 10"},
{372, "FOR J=1 TO 10"},
{375, "A(I,J)=0"},
{377, "NEXT J"},
{379, "NEXT I"},
{380, "PRINT"},
{390, "PRINT \"HOW MANY PLAYERS\";"},
{400, "INPUT P"},
{410, "I1=0"},
{420, "PRINT \"HOW MANY ROWS\";"},
{430, "INPUT R"},
{440, "IF R <= 9 THEN 470"},
{450, "PRINT \"TOO MANY ROWS (9 IS MAXIMUM). NOW, \";"},
{460, "GOTO 420"},
{470, "PRINT \"HOW MANY COLUMNS\";"},
{480, "INPUT C"},
{490, "IF C <= 9 THEN 530"},
{500, "PRINT \"TOO MANY COLUMNS (9 IS MAXIMUM). NOW, \";"},
{510, "GOTO 470"},
{530, "PRINT"},
{540, "FOR I=1 TO R"},
{550, "FOR J=1 TO C"},
{560, "A(I,J)=1"},
{570, "NEXT J"},
{580, "NEXT I"},
{590, "A(1,1)=-1"},
{600, "REM PRINT THE BOARD"},
{610, "PRINT"},
{620, "PRINT TAB(7);\"1 2 3 4 5 6 7 8 9\""},
{630, "FOR I=1 TO R"},
{640, "PRINT I;TAB(7);"},
{650, "FOR J=1 TO C"},
{660, "IF A(I,J)=-1 THEN 700"},
{670, "IF A(I,J)=0 THEN 720"},
{680, "PRINT \"* \";"},
{690, "GOTO 710"},
{700, "PRINT \"P \";"},
{710, "NEXT J"},
{720, "PRINT"},
{730, "NEXT I"},
{740, "PRINT"},
{750, "IF F=0 THEN 770"},
{760, "RETURN"},
{770, "REM GET CHOMPS FOR EACH PLAYER IN TURN"},
{780, "LET I1=I1+1"},
{790, "LET P1=I1-INT(I1/P)*P"},
{800, "IF P1 <> 0 THEN 820"},
{810, "P1=P"},
{820, "PRINT \"PLAYER\";P1"},
{830, "PRINT \"COORDINATES OF CHOMP (ROW,COLUMN)\";"},
{840, "INPUT R1,C1"},
{850, "IF R1<1 THEN 920"},
{860, "IF R1>R THEN 920"},
{870, "IF C1<1 THEN 920"},
{880, "IF C1>C THEN 920"},
{890, "IF A(R1,C1)=0 THEN 920"},
{900, "IF A(R1,C1)=-1 THEN 1010"},
{910, "GOTO 940"},
{920, "PRINT \"NO FAIR. YOU'RE TRYING TO CHOMP ON EMPTY SPACE!\""},
{930, "GOTO 820"},
{940, "FOR I=R1 TO R"},
{950, "FOR J=C1 TO C"},
{960, "A(I,J)=0"},
{970, "NEXT J"},
{980, "NEXT I"},
{990, "GOTO 610"},
{1000, "REM END OF GAME DETECTED IN LINE 900"},
{1010, "PRINT \"YOU LOSE, PLAYER\";P1"},
{1020, "PRINT"},
{1030, "PRINT \"AGAIN (1=YES, 0=NO!)\";"},
{1040, "INPUT R$"},
{1050, "IF R=1 THEN 340"},
{1060, "END"},
{},
};

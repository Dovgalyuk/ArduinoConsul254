#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_tictactoe2[] = {
{2, "PRINT TAB(30);\"TIC-TAC-TOE\"\n"},
{4, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\"\n"},
{6, "PRINT:PRINT:PRINT\n"},
{8, "PRINT \"THE BOARD IS NUMBERED:\"\n"},
{10, "PRINT \" 1  2  3\"\n"},
{12, "PRINT \" 4  5  6\"\n"},
{14, "PRINT \" 7  8  9\"\n"},
{16, "PRINT:PRINT:PRINT\n"},
{20, "DIM S(9)\n"},
{50, "INPUT\"DO YOU WANT 'X' OR 'O'\";C$\n"},
{55, "IF C$=\"X\"THEN 475\n"},
{60, "P$=\"O\":Q$=\"X\"\n"},
{100, "G=-1:H=1:IF S(5)<>0 THEN 103\n"},
{102, "S(5)=-1:GOTO 195\n"},
{103, "IF S(5)<>1 THEN 106\n"},
{104, "IF S(1)<>0 THEN 110\n"},
{105, "S(1)=-1:GOTO 195\n"},
{106, "IF S(2)=1 AND S(1)=0 THEN 181\n"},
{107, "IF S(4)=1 AND S(1)=0 THEN 181\n"},
{108, "IF S(6)=1 AND S(9)=0 THEN 189\n"},
{109, "IF S(8)=1 AND S(9)=0 THEN 189\n"},
{110, "IF G=1 THEN 112\n"},
{111, "GOTO 118\n"},
{112, "J=3*INT((M-1)/3)+1\n"},
{113, "IF 3*INT((M-1)/3)+1=M THEN K=1\n"},
{114, "IF 3*INT((M-1)/3)+2=M THEN K=2\n"},
{115, "IF 3*INT((M-1)/3)+3=M THEN K=3\n"},
{116, "GOTO 120\n"},
{118, "FOR J=1 TO 7 STEP 3:FOR K=1 TO 3\n"},
{120, "IF S(J)<>G THEN 130\n"},
{122, "IF S(J+2)<>G THEN 135\n"},
{126, "IF S(J+1)<>0 THEN 150\n"},
{128, "S(J+1)=-1:GOTO 195\n"},
{130, "IF S(J)=H THEN 150\n"},
{131, "IF S(J+2)<>G THEN 150\n"},
{132, "IF S(J+1)<>G THEN 150\n"},
{133, "S(J)=-1:GOTO 195\n"},
{135, "IF S(J+2)<>0 THEN 150\n"},
{136, "IF S(J+1)<>G THEN 150\n"},
{138, "S(J+2)=-1:GOTO 195\n"},
{150, "IF S(K)<>G THEN 160\n"},
{152, "IF S(K+6)<>G THEN 165\n"},
{156, "IF S(K+3)<>0 THEN 170\n"},
{158, "S(K+3)=-1:GOTO 195\n"},
{160, "IF S(K)=H THEN 170\n"},
{161, "IF S(K+6)<>G THEN 170\n"},
{162, "IF S(K+3)<>G THEN 170\n"},
{163, "S(K)=-1:GOTO 195\n"},
{165, "IF S(K+6)<>0 THEN 170\n"},
{166, "IF S(K+3)<>G THEN 170\n"},
{168, "S(K+6)=-1:GOTO 195\n"},
{170, "GOTO 450\n"},
{171, "IF S(3)=G AND S(7)=0 THEN 187\n"},
{172, "IF S(9)=G AND S(1)=0 THEN 181\n"},
{173, "IF S(7)=G AND S(3)=0 THEN 183\n"},
{174, "IF S(9)=0 AND S(1)=G THEN 189\n"},
{175, "IF G=-1 THEN G=1:H=-1:GOTO 110\n"},
{176, "IF S(9)=1 AND S(3)=0 THEN 182\n"},
{177, "FOR I=2 TO 9:IF S(I)<>0 THEN 179\n"},
{178, "S(I)=-1:GOTO 195\n"},
{179, "NEXT I\n"},
{181, "S(1)=-1:GOTO 195\n"},
{182, "IF S(1)=1 THEN 177\n"},
{183, "S(3)=-1:GOTO 195\n"},
{187, "S(7)=-1:GOTO 195\n"},
{189, "S(9)=-1\n"},
{195, "PRINT:PRINT\"THE COMPUTER MOVES TO...\"\n"},
{202, "GOSUB 1000\n"},
{205, "GOTO 500\n"},
{450, "IF G=1 THEN 465\n"},
{455, "IF J=7 AND K=3 THEN 465\n"},
{460, "NEXT K\n"},
{461, "NEXT J\n"},
{465, "IF S(5)=G THEN 171\n"},
{467, "GOTO 175\n"},
{475, "P$=\"X\":Q$=\"O\"\n"},
{500, "PRINT:INPUT\"WHERE DO YOU MOVE\";M\n"},
{502, "IF M=0 THEN PRINT\"THANKS FOR THE GAME.\":GOTO 2000\n"},
{503, "IF M>9 THEN 506\n"},
{505, "IF S(M)=0 THEN 510\n"},
{506, "PRINT\"THAT SQUARE IS OCCUPIED.\":PRINT:PRINT:GOTO 500\n"},
{510, "G=1:S(M)=1\n"},
{520, "GOSUB 1000\n"},
{530, "GOTO 100\n"},
{1000, "PRINT:FOR I=1 TO 9:PRINT\" \";:IF S(I)<>-1 THEN 1014\n"},
{1012, "PRINT Q$;\" \";:GOTO 1020\n"},
{1014, "IF S(I)<>0 THEN 1018\n"},
{1016, "PRINT\"  \";:GOTO 1020\n"},
{1018, "PRINT P$;\" \";\n"},
{1020, "IF I<>3 AND I<>6 THEN 1050\n"},
{1030, "PRINT:PRINT\"---+---+---\"\n"},
{1040, "GOTO 1080\n"},
{1050, "IF I=9 THEN 1080\n"},
{1060, "PRINT\"!\";\n"},
{1080, "NEXT I:PRINT:PRINT:PRINT\n"},
{1095, "FOR I=1 TO 7 STEP 3\n"},
{1100, "IF S(I)<>S(I+1)THEN 1115\n"},
{1105, "IF S(I)<>S(I+2)THEN 1115\n"},
{1110, "IF S(I)=-1 THEN 1350\n"},
{1112, "IF S(I)=1 THEN 1200\n"},
{1115, "NEXT I:FOR I=1 TO 3:IF S(I)<>S(I+3)THEN 1150\n"},
{1130, "IF S(I)<>S(I+6)THEN 1150\n"},
{1135, "IF S(I)=-1 THEN 1350\n"},
{1137, "IF S(I)=1 THEN 1200\n"},
{1150, "NEXT I:FOR I=1 TO 9:IF S(I)=0 THEN 1155\n"},
{1152, "NEXT I:GOTO 1400\n"},
{1155, "IF S(5)<>G THEN 1170\n"},
{1160, "IF S(1)=G AND S(9)=G THEN 1180\n"},
{1165, "IF S(3)=G AND S(7)=G THEN 1180\n"},
{1170, "RETURN\n"},
{1180, "IF G=-1 THEN 1350\n"},
{1200, "PRINT\"YOU BEAT ME!! GOOD GAME.\":GOTO 2000\n"},
{1350, "PRINT\"I WIN, TURKEY!!!\":GOTO 2000\n"},
{1400, "PRINT\"IT'S A DRAW. THANK YOU.\"\n"},
{2000, "END\n"},
{},
};

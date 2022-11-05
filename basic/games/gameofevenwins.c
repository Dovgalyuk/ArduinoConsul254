#include <avr/pgmspace.h>
#include "programs.h"
const PROGMEM line program_gameofevenwins[] = {
{1, "PRINT TAB(28);\"GAME OF EVEN WINS\"\n"},
{2, "PRINT TAB(15);\"CREATIVE COMPUTING  MORRISTOWN, NEW JERSEY\"\n"},
{3, "PRINT:PRINT\n"},
{4, "INPUT \"DO YOU WANT INSTRUCTIONS (YES OR NO)\";A$:PRINT\n"},
{5, "IF A$=\"NO\" THEN 20\n"},
{6, "PRINT \"THE GAME IS PLAYED AS FOLLOWS:\":PRINT\n"},
{7, "PRINT \"AT THE BEGINNING OF THE GAME, A RANDOM NUMBER OF CHIPS ARE\"\n"},
{8, "PRINT \"PLACED ON THE BOARD.  THE NUMBER OF CHIPS ALWAYS STARTS\"\n"},
{9, "PRINT \"AS AN ODD NUMBER.  ON EACH TURN, A PLAYER MUST TAKE ONE,\"\n"},
{10, "PRINT \"TWO, THREE, OR FOUR CHIPS.  THE WINNER IS THE PLAYER WHO\"\n"},
{11, "PRINT \"FINISHES WITH A TOTAL NUMBER OF CHIPS THAT IS EVEN.\"\n"},
{12, "PRINT \"THE COMPUTER STARTS OUT KNOWING ONLY THE RULES OF THE\"\n"},
{13, "PRINT \"GAME.  IT GRADUALLY LEARNS TO PLAY WELL.  IT SHOULD BE\"\n"},
{14, "PRINT \"DIFFICULT TO BEAT THE COMPUTER AFTER TWENTY GAMES IN A ROW.\"\n"},
{15, "PRINT \"TRY IT!!!!\": PRINT\n"},
{16, "PRINT \"TO QUIT AT ANY TIME, TYPE A '0' AS YOUR MOVE.\": PRINT\n"},
{20, "DIM R(1,5)\n"},
{25, "L=0: B=0\n"},
{30, "FOR I=0 TO 5\n"},
{40, "R(1,I)=4\n"},
{50, "R(0,I)=4\n"},
{60, "NEXT I\n"},
{70, "A=0: B=0\n"},
{90, "P=INT((13*RND(1)+9)/2)*2+1\n"},
{100, "IF P=1 THEN 530\n"},
{110, "PRINT \"THERE ARE \";P;\" CHIPS ON THE BOARD.\"\n"},
{120, "E1=E\n"},
{130, "L1=L\n"},
{140, "E=(A/2-INT(A/2))*2\n"},
{150, "L=INT((P/6-INT(P/6))*6+.5)\n"},
{160, "IF R(E,L)>=P THEN 320\n"},
{170, "M=R(E,L)\n"},
{180, "IF M<=0 THEN 370\n"},
{190, "P=P-M\n"},
{200, "IF M=1 THEN 510\n"},
{210, "PRINT \"COMPUTER TAKES \";M;\" CHIPS LEAVING \";P;\"... YOUR MOVE\";\n"},
{220, "B=B+M\n"},
{230, "INPUT M\n"},
{240, "M=INT(M)\n"},
{250, "IF M<1 THEN 450\n"},
{260, "IF M>4 THEN 460\n"},
{270, "IF M>P THEN 460\n"},
{280, "IF M=P THEN 360\n"},
{290, "P=P-M\n"},
{300, "A=A+M\n"},
{310, "GOTO 100\n"},
{320, "IF P=1 THEN 550\n"},
{330, "PRINT \"COMPUTER TAKES \";P;\" CHIPS.\"\n"},
{340, "R(E,L)=P\n"},
{350, "B=B+P\n"},
{360, "IF B/2=INT(B/2) THEN 420\n"},
{370, "PRINT \"GAME OVER ... YOU WIN!!!\": PRINT\n"},
{390, "IF R(E,L)=1 THEN 480\n"},
{400, "R(E,L)=R(E,L)-1\n"},
{410, "GOTO 70\n"},
{420, "PRINT \"GAME OVER ... I WIN!!!\": PRINT\n"},
{430, "GOTO 70\n"},
{450, "IF M=0 THEN 570\n"},
{460, "PRINT M;\"IS AN ILLEGAL MOVE ... YOUR MOVE\";\n"},
{470, "GOTO 230\n"},
{480, "IF R(E1,L1)=1 THEN 70\n"},
{490, "R(E1,L1)=R(E1,L1)-1\n"},
{500, "GOTO 70\n"},
{510, "PRINT \"COMPUTER TAKES 1 CHIP LEAVING \";P;\"... YOUR MOVE\";\n"},
{520, "GOTO 220\n"},
{530, "PRINT \"THERE IS 1 CHIP ON THE BOARD.\"\n"},
{540, "GOTO 120\n"},
{550, "PRINT \"COMPUTER TAKES 1 CHIP.\"\n"},
{560, "GOTO 340\n"},
{570, "END\n"},
{},
};

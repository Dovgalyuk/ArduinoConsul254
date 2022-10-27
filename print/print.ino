// PA - выбор столбца I..P
// PC - выбор ряда A..H

#define PRINTING_PIN 38
#define CR_PIN 39

#define H_BIT 0x80
#define L_BIT 0x40
#define SWITCH_REG(r) ((r) ^ (H_BIT | L_BIT))
#define ROW_SHIFT 0
#define COL_SHIFT 3

uint8_t out_table[256];
uint8_t reg;

void fill_tables()
{
#define HH H_BIT |
#define LL L_BIT |
#define A (0 << ROW_SHIFT) |
#define B (1 << ROW_SHIFT) |
#define C (2 << ROW_SHIFT) |
#define D (3 << ROW_SHIFT) |
#define E (4 << ROW_SHIFT) |
#define F (5 << ROW_SHIFT) |
#define G (6 << ROW_SHIFT) |
#define H (7 << ROW_SHIFT) |
#define I (0 << COL_SHIFT)
#define J (1 << COL_SHIFT)
#define K (2 << COL_SHIFT)
#define L (3 << COL_SHIFT)
#define M (4 << COL_SHIFT)
#define N (5 << COL_SHIFT)
#define O (6 << COL_SHIFT)
#define P (7 << COL_SHIFT)
    out_table[' '] = HH LL C I;
    out_table['!'] = LL H K;
    //out_table['"'] = ;
    out_table['#'] = LL F J; // equivalent sign
    out_table['$'] = LL H N; // diamond
    out_table['%'] = LL B M;
    out_table['&'] = LL A I; // x cross
    out_table['\''] = LL H M;
    out_table['('] = LL A N;
    out_table[')'] = LL A L;
    // out_table['*'] = HH G M; // ?????
    out_table['+'] = HH E K;
    out_table[','] = LL A M;
    out_table['-'] = LL B P;
    out_table['.'] = LL A K;
    out_table['/'] = HH E J;
    out_table['0'] = HH A P;
    out_table['1'] = HH A M;
    out_table['2'] = HH A K;
    out_table['3'] = HH A O;
    out_table['4'] = HH A J;
    out_table['5'] = HH A N;
    out_table['6'] = HH A L;
    out_table['7'] = HH A I;
    out_table['8'] = HH E P;
    out_table['9'] = HH E M;
    out_table[':'] = LL B N;
    out_table[';'] = LL E P;
    out_table['<'] = LL D N;
    out_table['='] = LL E O;
    out_table['>'] = LL E J;
    out_table['?'] = LL A J; // up arrow
    out_table['@'] = LL B O; // 10
    out_table['A'] = HH B P;
    out_table['B'] = HH B K;
    out_table['C'] = HH D M;
    out_table['D'] = LL B J;
    out_table['E'] = HH B N;
    out_table['F'] = LL D J;
    out_table['G'] = LL B O;
    out_table['H'] = HH F N;
    out_table['I'] = LL F P;
    out_table['J'] = LL F M;
    out_table['K'] = LL F K;
    out_table['L'] = LL F O;
    out_table['M'] = HH F J;
    out_table['N'] = LL F N;
    out_table['O'] = HH F L;
    out_table['P'] = HH D P;
    out_table['Q'] = LL H L;
    out_table['R'] = LL D P;
    out_table['S'] = LL D M;
    out_table['T'] = HH D K;
    out_table['U'] = LL D O;
    out_table['V'] = LL B L;
    out_table['W'] = LL B K;
    out_table['X'] = HH D N;
    out_table['Y'] = HH D O;
    out_table['Z'] = LL B I;
    out_table['['] = LL E M;
    //out_table['\\'] = ;
    out_table[']'] = LL A P;
    out_table['^'] = LL H O;
    out_table['_'] = LL E K;
    out_table['`'] = LL H P;
    //out_table['{'] = ;
    //out_table['|'] = LL G M; // ?????
    //out_table['}'] = ;
    //out_table['~'] = ;

    // out_table['А'] = out_table['A'];
    // out_table['Б'] = ;
    // out_table['В'] = out_table['B'];
    // out_table['Г'] = ;
    // out_table['Д'] = ;
    // out_table['Е'] = out_table['E'];
    // out_table['Ё'] = out_table['E'];
    // out_table['Ж'] = ;
    // out_table['З'] = ;
    // out_table['И'] = ;
    // out_table['Й'] = ;
    // out_table['К'] = out_table['K'];
    // out_table['Л'] = ;
    // out_table['М'] = out_table['M'];
    // out_table['Н'] = out_table['H'];
    // out_table['О'] = out_table['O'];
    // out_table['П'] = ;
    // out_table['Р'] = out_table['P'];
    // out_table['С'] = out_table['C'];
    // out_table['Т'] = out_table['T'];
    // out_table['У'] = out_table['Y'];
    // out_table['Ф'] = ;
    // out_table['Х'] = out_table['X'];
    // out_table['Ц'] = ;
    // out_table['Ч'] = ;
    // out_table['Ш'] = ;
    // out_table['Щ'] = ;
    // out_table['Ъ'] = ;
    // out_table['Ы'] = ;
    // out_table['Ь'] = ;
    // out_table['Э'] = ;
    // out_table['Ю'] = ;
    // out_table['Я'] = ;
#undef HH
#undef LL
#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef I
#undef J
#undef K
#undef L
#undef M
#undef N
#undef O
#undef P
    for (char i = 'a' ; i <= 'z' ; ++i)
        out_table[i] = out_table[i - 'a' + 'A'];

    const char upper[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const char lower[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
}

void sendCodeDelay(uint8_t r, uint8_t c, int d)
{
  // DJ is some symbol
  PORTA = 0xff ^ (1 << c);
  //if (r == 0) PORTC = 0xff ^ 2; else
  PORTC = 0xff ^ (1 << r);
  delay(d);
  //while (!digitalRead(PRINTING_PIN));
  PORTA = 0xff;
  PORTC = 0xff;
  delay(100);
}

void sendSymbolCode(uint8_t r, uint8_t c)
{
  // DJ is some symbol
  PORTA = 0xff ^ (1 << c);
  PORTC = 0xff ^ (1 << r);
  //delay(1);
  //while (true) {
  while (digitalRead(PRINTING_PIN));// delay(1);
  //delay(5);
  PORTA = 0xff;
  PORTC = 0xff;
  //while (!digitalRead(PRINTING_PIN));
  //delay(50);
  delay(100);
}

void sendCode(uint8_t r, uint8_t c)
{
  sendCodeDelay(r, c, 10);
}

void lowReg()
{
    sendCode(2, 3);
}

void highReg()
{
    sendCode(2, 1);
}

void sendSymbol(char c)
{
    if (c == '\n') {
        // CR LF
        sendCodeDelay(2, 7, 30);
        while (!digitalRead(CR_PIN));
        delay(100);
    } else if (!out_table[c]) {
        sendSymbol(' ');
    } else {
        uint8_t code = out_table[c];
        if (!(code & reg)) {
            reg = SWITCH_REG(reg);
            if (reg == H_BIT) {
                highReg();
            } else {
                lowReg();
            }
        }
        if (c == ' '/* || (c >= '0' && c <= '9')*/)
          sendCode((code >> ROW_SHIFT) & 7, (code >> COL_SHIFT) & 7);
        else
          sendSymbolCode((code >> ROW_SHIFT) & 7, (code >> COL_SHIFT) & 7);
    }
}

void print(const char *s)
{
    while (*s) {
        sendSymbol(*s++);
    }
}

void setup() {
  // for (int i = 22 ; i <= 37 ; ++i)
  //   pinMode(i, OUTPUT);
  DDRA = 0xff;
  DDRC = 0xff;
  PORTA = 0xff;
  PORTC = 0xff;
  pinMode(PRINTING_PIN, INPUT_PULLUP);
  pinMode(CR_PIN, INPUT_PULLUP);

//   sendCode(2, 1); // high reg
//   sendCode(5, 5); // H
//   sendCode(1, 5); // E
//   sendCode(2, 3); // low reg
//   sendCode(5, 6); // L
//   sendCode(5, 6); // L
//   sendCode(2, 1); // high reg
//   sendCode(5, 3); // O
//   sendCode(2, 3); // low reg
//   sendCode(0, 4); // ,
//   sendCode(2, 0); // space
//   sendCode(1, 2); // W
//   sendCode(2, 1); // high reg
//   sendCode(5, 3); // O
//   sendCode(2, 3); // low reg
//   sendCode(3, 7); // R
//   sendCode(5, 6); // L
//   sendCode(1, 1); // D
//   sendCode(7, 2); // !
//   sendCodeDelay(2, 7, 30); // CR


  //for (int i = 0 ; i < 20 ; ++i)
  //sendCodeDelay(2, 7, 10 + i * 100); // CR
  // for (int i = 0 ; i < 20 ; ++i)
  // sendCode(2, 0); // space
  // CP is carriage feed
  // PORTA = B01111111;
  // PORTC = B11111011;
  // delay(7);
  // PORTA = 0xff;
  // PORTC = 0xff;

    fill_tables();
    reg = H_BIT;
    highReg();


//    print("0123456789\n");
    //print("HELLO, WORLD!\nAND HELLO AGAIN\n");
/*
     print(
 "           ____                              ____\n"
 "         o8%8888,                          o8%8888,\n"
 "       o88%8888888.                      o88%8888888.\n"
 "      8'-    -:8888b                    8'-    -:8888b\n"
 "     8'         8888                   8'         8888\n"
 "    d8.-=. ,==-.:888b                 d8.-=. ,==-.:888b\n"
 "    >8 `~` :`~' d8888                 >8 `=` :`=' d8888\n"
 "    88         ,88888                 88         ,88888\n"
 "    88b. `-~  ':88888                 88b` `--  ':88888\n"
 "    888b ~==~ .:88888                 888b -==- .:88888\n"
 "    88888o--:':::8888                 88888o--:':::8888\n"
 "    `88888| :::' 8888b                `88888| :::' 8888b\n"
 "    8888^^'       8888b               8888^^'       8888b\n"
 "   d888           ,%888b.            d888           ,%888b.\n"
 "  d88%            %%%8--'-.         d88%            %%%8--'-.\n"
 " /88:.__ ,       _%-' ---  -       /88:.__ ,       _%-' ---  -\n"
 "     '''::===..-'   =  --.  `          '''::===..-'   =  --.  `\n"
 "      Normal Mona                      Depressed Mona\n"
     );
*/
print(
"                                  _______\n"
"                           _,,%J888888888866%,_\n"
"                        ,%J88888I8888888888888886%,\n"
"                      ,88888888I88888888888888888888%,\n"
"                    ,J888888888I88888888888888888888886,\n"
"                   J88888PP"""" ""YY888888888888888888886,\n"
"                 ,J88"'__,,--------,,,,.;ZZZY8888888888888,\n"
"                ,8II1'"                ;;1"ZZZIII8888888888,\n"
"               ,I881;'                  ;1ZZZZZ888III8888888,\n"
"             ,II88Z1;.                  ;11ZZZZZ888888I888888,\n"
"            ,II888Z1;.                .;;;;;111ZZZ888888I88886\n"
"           ,II8888Z;;                 `;;;;;''11ZZ8888888I8888,\n"
"           II88888Z;'                        .;1ZZZ8888888I8886\n"
"           II88888Z; _,%%%,      .,%%%%%,__.1;11ZZZ88888888I888\n"
"           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;11ZZ88888888I888,\n"
"           II88888IZZ<'(00>ZI  IZZZ<'(00>ZZZZ;;11ZZ888888888I88I\n"
"          ,II88888;   `""" ;I  IZZ; `"""     ;;11Z8888888888I888\n"
"          II8888881            `;;          .;11ZZ8888888888I888,\n"
"         ,II888888Z;           ;;;        .;;11ZZZ8888888888I888I\n"
"         III888888Z1;    ..,   `;;       ,;;111ZZZ88888888888I888\n"
"         II88888888Z;;...;(_    _)      ,;;;11ZZZZ88888888888I888,\n"
"         II88888888Z1;;;;;' `--'Z;.   .,;;;;11ZZZZ88888888888I8886\n"
"         ]I888888888Z;;;;'   ";111111;..;;;111ZZZZ88888888888I8888,\n"
"         II888888888Z1.;;"Y886J888P";;,..;111ZZZZZ88888888888I8888I\n"
"         II8888888888Z1;.; `"PPP";;;,..;111ZZZZZZZ88888888888I88888\n"
"         II888888888888Z1;;. `;;;1;;;;111ZZZZZZZZW88888888888I88888\n"
"         `II8888888888888Z1;.    ,;;111ZZZZZZZZWMZ88888888888I88888\n"
"          II8888888888888888Z6%%111ZZZZZZZZZWWMZZZ8888888888I888888,\n"
"          `II888888888888888886"WWZZZZZWWWMMZZZZZZI888888888I8888886\n"
"           `II88888888888888888;ZZMMMMMMZZZZZZZZ11I888888888I8888888\n"
"            `II8888888888888888 `;1ZZZZZZZZZZZ11111888888888I8888888,\n"
"             II8888888888888888, `;111ZZZZ111111;;.Y88888888I88888886,\n"
"            ,II88888888888888886   .;;1111111;;;.;..88888888I888888886,\n"
"            II888888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,\n"
"            II888888888888PZ;;';;.   ;. .;.  .;. .. Y8888888I888888888886,\n"
"           ,II888888888PZ;;'                        `8888888I88888888888886,\n"
"           II888888888'                              888888I88888888888888886\n"
"          ,II888888888                              ,888888I88888888888888888\n"
"         ,J88888888888                              J888888I8888888888ZZZZZZZ\n"
"      ,%J888888888888I                              8888888I8888ZZZZZZZZZZZZZ\n"
"    ,J888888888888888'                              888888IZZZZZZZZZZZZZZZZZZ\n"
"  ,J888888888888P'8P'                               Y888ZZZZZZZZZZZZZZZZZZZZZ\n"
" ,8888888888888,  "                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ\n"
"J888888888888888,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n"
"888888888888888888%,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888\n"
"8888888888888888888886%,_J'                  ,ZZZZZZZZZZZZZZZZZ88888888888888\n"
"8888888888888888888888888888666%%%,,,______,ZZZZZZZZZZZZZZZ888888888888888888\n"
"88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888\n"
"8888888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888\n"
"888888888888888888888888888888888888888ZZZZZZZZZZZZZZ888888888888888888888888\n"
"8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888\n"
"88888888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888\n"
"8888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888 NORMAND  88\n"
"88888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888 VEILLEUX 88\n"
"8888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888888888\n"
);

}

void loop() {

}

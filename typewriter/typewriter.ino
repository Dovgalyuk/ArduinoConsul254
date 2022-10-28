// PA - выбор столбца I..P
// PC - выбор ряда A..H

#define PRINTING_PIN 38
#define CR_PIN 39

#define KEY_HIGHREG B11010110
#define KEY_LOWREG  B10010111

#define H_BIT 0x80
#define L_BIT 0x40
#define SWITCH_REG(r) ((r) ^ (H_BIT | L_BIT))
#define ROW_SHIFT 0
#define COL_SHIFT 3

char in_table[256];
uint8_t out_table[256];
uint8_t reg;

void fill_tables()
{
  // некоторые символы не существуют в ASCII, некоторых не разобрать на скане
  in_table[B11111000] = '-'; //
  in_table[B11111011] = 'A'; //
  in_table[B01111001] = '%'; //
  in_table[B01111010] = 'Б'; //
  in_table[B00010000] = '/'; // знак деления
  in_table[B00010011] = 'Ч'; //
  in_table[B11011001] = 'D'; //
  in_table[B11011010] = 'Д'; //
  in_table[B01011000] = ':'; //
  in_table[B01011011] = 'E'; //
  in_table[B11010000] = 'F'; //
  in_table[B11010011] = 'Ф'; //
  in_table[B00111000] = 'G'; //
  in_table[B00111011] = 'Г'; //
  in_table[B11000001] = '#'; // >=
  in_table[B11000010] = 'Э'; //
  in_table[B11101001] = 'I'; //
  in_table[B11101010] = 'И'; //
  in_table[B01101000] = 'J'; //
  in_table[B01101011] = 'Й'; //
  in_table[B10101000] = '#'; // <=
  in_table[B10101011] = 'K'; //
  in_table[B00101001] = 'L'; //
  in_table[B00101010] = 'Л'; //
  in_table[B11001000] = '#'; // знак тождественности
  in_table[B11001011] = 'M'; //
  in_table[B01001001] = 'N'; //
  in_table[B01001010] = 'H'; //
  in_table[B10001001] = '#'; // знак отрицания
  in_table[B10001010] = 'O'; //
  in_table[B00001000] = '#'; // знак надмножества
  in_table[B00001011] = 'П'; //
  in_table[B10000000] = 'Q'; //
  in_table[B10000011] = 'Я'; //
  in_table[B11110001] = 'R'; //
  in_table[B11110010] = 'Г'; //
  in_table[B01110000] = 'S'; //
  in_table[B01110011] = 'C'; //
  in_table[B10110000] = 'V'; //
  in_table[B10110011] = 'T'; //
  in_table[B00110001] = 'U'; //
  in_table[B00110010] = 'У'; //
  in_table[B10011000] = 'Y'; // ???
  in_table[B10011011] = 'Ж'; //
  in_table[B10111001] = 'W'; //
  in_table[B10111010] = 'B'; //
  in_table[B01010001] = '<'; //
  in_table[B01010010] = 'X'; //
  in_table[B10100001] = '!'; //
  in_table[B10100010] = 'Ы'; //
  in_table[B00011001] = 'Z'; //
  in_table[B00011010] = 'З'; //
  in_table[B10010001] = '#'; // знак неравенства
  in_table[B10010010] = 'Ц'; //
  in_table[B01000000] = '#'; // ромбик
  in_table[B01000011] = 'Ю'; //
  in_table[B11100000] = '#'; // открывающая кавычка
  in_table[B11100011] = 'Ш'; //
  in_table[B01100001] = '#'; // закрывающая кавычка
  in_table[B01100010] = 'Щ'; //
  in_table[B01111100] = ','; //
  in_table[B01111111] = '1'; //
  in_table[B10111100] = '.'; //
  in_table[B10111111] = '2'; //
  in_table[B00111101] = '@'; // символ "10"
  in_table[B00111110] = '3'; //
  in_table[B11011100] = '+'; //
  in_table[B11011111] = '4'; //
  in_table[B01011101] = '('; //
  in_table[B01011110] = '5'; //
  in_table[B10011101] = ')'; //
  in_table[B10011110] = '6'; //
  in_table[B00011100] = '&'; // x cross
  in_table[B00011111] = '7'; //
  in_table[B11101100] = ';'; //
  in_table[B11101111] = '8'; //
  in_table[B01101101] = '['; //
  in_table[B01101110] = '9'; //
  in_table[B11111101] = ']'; //
  in_table[B11111110] = '0'; //
  in_table[B01100100] = '|'; //
  in_table[B01100111] = '*'; //
  in_table[B00101100] = '='; //
  in_table[B00101111] = '-'; // какой-то минус
  in_table[B11001101] = '>'; //
  in_table[B11001110] = '/'; //
  in_table[B11100110] = '-'; // какой-то минус
  in_table[B11100101] = '-'; // какой-то минус
  in_table[B10101101] = '_'; //
  in_table[B10101110] = '+'; //
  in_table[B00100000] = '^'; //
  in_table[B00100011] = 'Ь'; //
  in_table[B01010111] = '$'; // табулятор
  in_table[B11110111] = '\n'; // возврат каретки
  //in_table[B11010110] = '$'; // верхний регистр
  //in_table[B10010111] = '$'; // нижний регистр
  in_table[B00010110] = ' '; // пробел
  in_table[B01110110] = '\n'; // перевод строки
  in_table[B10110110] = '$'; // красная лента
  in_table[B00110111] = '$'; // черная лента

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
    out_table['*'] = HH G M;
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
    out_table['|'] = LL G M;
    //out_table['}'] = ;
    //out_table['~'] = ;

    out_table['А'] = out_table['A'];
    out_table['Б'] = HH B M;
    out_table['В'] = out_table['B'];
    out_table['Г'] = HH B O;
    out_table['Д'] = HH B J;
    out_table['Е'] = out_table['E'];
    out_table['Ё'] = out_table['E'];
    out_table['Ж'] = HH B L;
    out_table['З'] = HH B I;
    out_table['И'] = HH F P;
    out_table['Й'] = HH F M;
    out_table['К'] = out_table['K'];
    out_table['Л'] = HH F O;
    out_table['М'] = out_table['M'];
    out_table['Н'] = out_table['H'];
    out_table['О'] = out_table['O'];
    out_table['П'] = HH F I;
    out_table['Р'] = out_table['P'];
    out_table['С'] = out_table['C'];
    out_table['Т'] = out_table['T'];
    out_table['У'] = out_table['Y'];
    out_table['Ф'] = HH D J;
    out_table['Х'] = out_table['X'];
    out_table['Ц'] = HH D L;
    out_table['Ч'] = HH D I;
    out_table['Ш'] = HH H P;
    out_table['Щ'] = HH H M;
    out_table['Ъ'] = LL H M;
    out_table['Ы'] = HH H K;
    out_table['Ь'] = HH H O;
    out_table['Э'] = HH H J;
    out_table['Ю'] = HH H N;
    out_table['Я'] = HH H L;
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
    for (int i = 0 ; i < 33 ; ++i)
        out_table[lower[i]] = out_table[upper[i]];
}

void sendCodeDelay(uint8_t r, uint8_t c, int d)
{
  // DJ is some symbol
  PORTA = 0xff ^ (1 << c);
  PORTC = 0xff ^ (1 << r);
  delay(d);
  //while (!digitalRead(PRINTING_PIN));
  PORTA = 0xff;
  PORTC = 0xff;
  delay(200);
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


void setup() {
  // for (int i = 22 ; i <= 37 ; ++i)
  //   pinMode(i, OUTPUT);
  DDRA = 0xff;
  DDRC = 0xff;
  PORTA = 0xff;
  PORTC = 0xff;
  pinMode(PRINTING_PIN, INPUT_PULLUP);

  changeRegister(true);
}


void loop() {
    if (!digitalRead(12)) {
        unsigned int v = 0;
        for (int i = 2 ; i <= 9 ; ++i)
            v = (v << 1) + digitalRead(i);
        if (v == KEY_LOWREG && reg == H_BIT) {
            reg = SWITCH_REG(reg);
            highReg();
        } else if (v == KEY_HIGHREG && reg == L_BIT) {
            reg = SWITCH_REG(reg);
            lowReg();
        } else {
            if (reg == H_BIT) {
                v = v ^ 3;
            }
            sendSymbol(in_table[v]);
        }
        delay(50);
    }
}

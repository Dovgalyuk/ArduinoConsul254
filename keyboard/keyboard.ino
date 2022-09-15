#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27

char table[256];

void fill_table()
{  
  // некоторые символы не существуют в ASCII, некоторых не разобрать на скане
  table[B11111000] = '-'; //
  table[B11111011] = 'A'; //
  table[B01111001] = '%'; //
  table[B01111010] = 'Б'; //
  table[B00010000] = '/'; // знак деления
  table[B00010011] = 'Ч'; //
  table[B11011001] = 'D'; //
  table[B11011010] = 'Д'; //
  table[B01011000] = ':'; //
  table[B01011011] = 'E'; //
  table[B11010000] = 'F'; //
  table[B11010011] = 'Ф'; //
  table[B00111000] = 'G'; //
  table[B00111011] = 'Г'; //
  table[B11000001] = '#'; // >=
  table[B11000010] = 'Э'; //
  table[B11101001] = 'I'; //
  table[B11101010] = 'И'; //
  table[B01101000] = 'J'; //
  table[B01101011] = 'Й'; //
  table[B10101000] = '#'; // <=
  table[B10101011] = 'K'; //
  table[B00101001] = 'L'; //
  table[B00101010] = 'Л'; //
  table[B11001000] = '#'; // знак тождественности
  table[B11001011] = 'M'; //
  table[B01001001] = 'N'; //
  table[B01001010] = 'H'; //
  table[B10001001] = '#'; // знак отрицания
  table[B10001010] = 'O'; //
  table[B00001000] = '#'; // знак надмножества
  table[B00001011] = 'П'; //
  table[B10000000] = 'Q'; //
  table[B10000011] = 'Я'; //
  table[B11110001] = 'R'; //
  table[B11110010] = 'Г'; //
  table[B01110000] = 'S'; //
  table[B01110011] = 'C'; //
  table[B10110000] = 'V'; //
  table[B10110011] = 'T'; //
  table[B00110001] = 'U'; //
  table[B00110010] = 'У'; //
  table[B10011000] = 'Y'; // ???
  table[B10011011] = 'Ж'; //
  table[B10111001] = 'W'; //
  table[B10111010] = 'B'; //
  table[B01010001] = '<'; //
  table[B01010010] = 'X'; //
  table[B10100001] = '!'; //
  table[B10100010] = 'Ы'; //
  table[B00011001] = 'Z'; //
  table[B00011010] = 'З'; //
  table[B10010001] = '#'; // знак неравенства
  table[B10010010] = 'Ц'; //
  table[B01000000] = '#'; // ромбик
  table[B01000011] = 'Ю'; //
  table[B11100000] = '#'; // открывающая кавычка
  table[B11100011] = 'Ш'; //
  table[B01100001] = '#'; // закрывающая кавычка
  table[B01100010] = 'Щ'; //
  table[B01111100] = ','; //
  table[B01111111] = '1'; //
  table[B10111100] = '.'; //
  table[B10111111] = '2'; //
  table[B00111101] = '#'; // символ "10"
  table[B00111110] = '3'; //
  table[B11011100] = '+'; //
  table[B11011111] = '4'; //
  table[B01011101] = '('; //
  table[B01011110] = '5'; //
  table[B10011101] = ')'; //
  table[B10011110] = '6'; //
  table[B00011100] = 'x'; //
  table[B00011111] = '7'; //
  table[B11101100] = ';'; //
  table[B11101111] = '8'; //
  table[B01101101] = '['; //
  table[B01101110] = '9'; //
  table[B11111101] = ']'; //
  table[B11111110] = '0'; //
  table[B01100100] = '|'; //
  table[B01100111] = '*'; //
  table[B00101100] = '='; //
  table[B00101111] = '-'; // какой-то минус
  table[B11001101] = '>'; //
  table[B11001110] = '/'; //
  table[B11100110] = '-'; // какой-то минус
  table[B11100101] = '-'; // какой-то минус
  table[B10101101] = '_'; //
  table[B10101110] = '+'; //
  table[B00100000] = '^'; //
  table[B00100011] = 'Ь'; //
  table[B01010111] = '$'; // табулятор
  table[B11110111] = '$'; // возврат каретки
  table[B11010110] = '$'; // верхний регистр
  table[B10010111] = '$'; // нижний регистр
  table[B00010110] = ' '; // пробел
  table[B01110110] = '$'; // перевод строки
  table[B10110110] = '$'; // красная лента
  table[B00110111] = '$'; // черная лента
}

#define HIGHREG B11010110
#define LOWREG  B10010111

// Судя по цифрам, разряды будет удобнее развернуть и инвертировать

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  fill_table();

  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home();
  lcd.clear();

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

int x = 0;
bool reg = true;

void loop() {
    if (!digitalRead(12)) {
      unsigned int v = 0;
      for (int i = 2 ; i <= 9 ; ++i)
        v = (v << 1) + digitalRead(i);
      if (v == LOWREG) {
        reg = false;
      } else if (v == HIGHREG) {
        reg = true;
      } else {
        if (reg) {
          v = v ^ 3;
        }
        lcd.write(table[v]);
        if (x == 16) {
          lcd.scrollDisplayLeft();
        } else {
          ++x;
        }
      }
      delay(50);
    }
}

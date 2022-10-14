// PA - выбор столбца I..P
// PC - выбор ряда A..H

#define PRINTING_PIN 38

void sendCode(uint8_t r, uint8_t c)
{
  // DJ is some symbol
  PORTA = 0xff ^ (1 << c);
  PORTC = 0xff ^ (1 << r);
  delay(7);
  //while (!digitalRead(PRINTING_PIN));
  PORTA = 0xff;
  PORTC = 0xff;
  delay(200);
}

void setup() {
  // for (int i = 22 ; i <= 37 ; ++i)
  //   pinMode(i, OUTPUT);
  DDRA = 0xff;
  DDRC = 0xff;
  PORTA = 0xff;
  PORTC = 0xff;
  pinMode(PRINTING_PIN, INPUT_PULLUP);

  // sendCode(2, 1); // high reg
  // sendCode(5, 5); // H
  // sendCode(1, 5); // E
  // sendCode(2, 3); // low reg
  // sendCode(5, 6); // L
  // sendCode(5, 6); // L
  // sendCode(2, 1); // high reg
  // sendCode(5, 3); // O
  // sendCode(2, 3); // low reg
  // sendCode(0, 4); // ,
  // sendCode(2, 0); // space
  // sendCode(1, 2); // W
  // sendCode(2, 1); // high reg
  // sendCode(5, 3); // O
  // sendCode(2, 3); // low reg
  // sendCode(3, 7); // R
  // sendCode(5, 6); // L
  // sendCode(1, 1); // D
  // sendCode(7, 2); // !
  // sendCode(2, 7); // CR
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  sendCode(2, 0); // space
  // CP is carriage feed
  // PORTA = B01111111;
  // PORTC = B11111011;
  // delay(7);
  // PORTA = 0xff;
  // PORTC = 0xff;


}

void loop() {

}

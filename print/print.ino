// PA - выбор ряда I..P
// PC - выбор столбца A..H

void setup() {
  // for (int i = 22 ; i <= 37 ; ++i)
  //   pinMode(i, OUTPUT);
  DDRA = 0xff;
  DDRC = 0xff;
  PORTA = 0xff;
  PORTC = 0xff;

  // DJ is some symbol
  PORTA = B11111101;
  PORTC = B11110111;
  delay(7);
  PORTA = 0xff;
  PORTC = 0xff;

  // CP is carriage feed
  // PORTA = B01111111;
  // PORTC = B11111011;
  // delay(7);
  // PORTA = 0xff;
  // PORTC = 0xff;


}

void loop() {

}

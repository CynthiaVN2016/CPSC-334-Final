const int PIEZO_PIN_1 = 36; // Piezo output
const int PIEZO_PIN_2 = 34; // Piezo output
const int PIEZO_PIN_3 = 35; // Piezo output
const int PIEZO_PIN_4 = 33; // Piezo output
const int PIEZO_PIN_5 = 25; // Piezo output
const int PIEZO_PIN_6 = 26; // Piezo output
const int PIEZO_PIN_7 = 27; // Piezo output
const int PIEZO_PIN_8 = 12; // Piezo output
const int PIEZO_PIN_9 = 13; // Piezo output

int prevVal = 0;
int zeroCount = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Read Piezo ADC value in, and convert it to a voltage
  int piezo1 = analogRead(PIEZO_PIN_1);
  int piezo2 = analogRead(PIEZO_PIN_2);
  int piezo3 = analogRead(PIEZO_PIN_3);
  int piezo4 = analogRead(PIEZO_PIN_4);
  int piezo5 = analogRead(PIEZO_PIN_5);
  int piezo6 = analogRead(PIEZO_PIN_6);
  int piezo7 = analogRead(PIEZO_PIN_7);
  int piezo8 = analogRead(PIEZO_PIN_8);
  int piezo9 = analogRead(PIEZO_PIN_9);

  if (piezo1 > 4000 & prevVal != 1 & zeroCount > 10) {
    zeroCount = 0;
    Serial.write(1);
    //    Serial.println("1");
    //    Serial.println(piezo1);
    prevVal = 1;
  }
  if (piezo2 > 4000 & prevVal != 2 & zeroCount > 10) {
    zeroCount = 0;
    Serial.write(2);
    //    Serial.println("2");
    //    Serial.println(piezo2);
    prevVal = 2;
  }
  if (piezo3 > 4000 & prevVal != 3 & zeroCount > 10) {
    zeroCount = 0;
    Serial.write(3);
    //    Serial.println("3");
    //    Serial.println(piezo3);
    prevVal = 3;
  }
  if (piezo4 > 4000 & prevVal != 4 & zeroCount > 10) {
    zeroCount = 0;
    Serial.write(4);
    //    Serial.println("4");
    //    Serial.println(piezo4);
    prevVal = 4;
  }
  if (piezo5 > 4000 & prevVal != 5 & zeroCount > 10) {
    zeroCount = 0;
    Serial.write(5);
    //    Serial.println("5");
    //    Serial.println(piezo5);
    prevVal = 5;
  }
  if (piezo6 > 4000 & prevVal != 6 & zeroCount > 30) {
    zeroCount = 0;
    Serial.write(6);
    //    Serial.println("6");
    //    Serial.println(piezo6);
    prevVal = 6;
  }
  if (piezo7 > 4000 & prevVal != 7 & zeroCount > 30) {
    zeroCount = 0;
    Serial.write(7);
    //    Serial.println("7");
    //    Serial.println(piezo7);
    prevVal = 7;
  }
  if (piezo8 > 4000 & prevVal != 8 & zeroCount > 30) {
    zeroCount = 0;
    Serial.write(8);
    //    Serial.println("8");
    //    Serial.println(piezo8);
    prevVal = 8;
  }
  if (piezo9 > 4000 & prevVal != 9 & zeroCount > 30) {
    zeroCount = 0;
    Serial.write(9);
    //    Serial.println("9");
    //    Serial.println(piezo9);
    prevVal = 9;
  }

  if (piezo1 == 0 & piezo2 == 0 & piezo3 == 0 &
      piezo4 == 0 & piezo5 == 0 & piezo4 == 0) {
    prevVal = 0;
    zeroCount += 1;
  }
}

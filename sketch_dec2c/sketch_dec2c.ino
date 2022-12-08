#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); //RX, TX
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(9600);
pinMode(7, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
bool f = digitalRead(7);
bool r_f = !f;
if (r_f) {
  mySerial.println("JJJJJ");
} else {
  Serial.println("Hallo");
}
}

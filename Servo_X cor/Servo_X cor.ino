#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
Servo myServo;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
bool raw = digitalRead(2);
bool raw_s =!raw;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approx your card to the reader");
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  myServo.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
if (!mfrc522.PICC_IsNewCardPresent()) {
  return;
}
if (!mfrc522.PICC_ReadCardSerial()) {
  return;
}
Serial.print("UID Tag: ");
String content ="";
byte letter;
for (byte i =0; i <mfrc522.uid.size; i++) {
  Serial.print(mfrc522.uid.uidByte[i]<0X10 ? " 0": "");
  Serial.print(mfrc522.uid.uidByte[i], HEX);
  content.concat(String(mfrc522.uid.uidByte[i]<0X10 ? " 0": ""));
  content.concat(String(mfrc522.uid.uidByte[i], HEX));
}
Serial.println();
Serial.print("Message: ");
content.toUpperCase();
Serial.print(digitalRead(2));
if (content.substring(0) == "118B5B23" || content.substring(0) == "70377021") {
  Serial.println("Authorized Access");
  Serial.println();
  digitalWrite(6, 1);
  delay(300);
  for (int i =0; i<180; i++) {
    delay(10);
    myServo.write(i);
    delay(10);
  }

} else if (content.substring(0) !="118B5B23"|| content.substring(0) != "70377021") {
  Serial.println("Access Denied");
  digitalWrite(5, 1);
  delay(3000);
}
else if (raw_s == 0) {
  digitalWrite(6, 0);
}
}

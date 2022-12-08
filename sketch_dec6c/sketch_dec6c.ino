#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approx your card to the reader");

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
if (content.substring(1)== "" ) {
  Serial.println("Authorized Access");
  Serial.println();
  delay(3000);
} else {
  Serial.println("Access Denied");
  delay(3000);
}
}

#include <IRremote.h>
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Enabling IRin");     
irrecv.enableIRIn();
Serial.println("Enabled IRin");
pinMode(12, OUTPUT);
pinMode(12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (irrecv.decode()) {
  Serial.println(results.value);
  irrecv.resume();
}
//delay(100);
}

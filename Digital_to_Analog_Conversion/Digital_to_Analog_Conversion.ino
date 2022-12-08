
void setup() {
 Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  digitalWrite(13, 1);
 
  
 for (int x =0; x <= 176; x += 1){
delay(10);
  analogWrite(6, x);

 }
 for (int x = 176; x >= 0; x -= 1) {
   delay(10);
   analogWrite(6, x);
 }
}

  
bool val = 0;
bool LED_Status = 0;
bool last_val = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool val = digitalRead(13);
  if (val!=last_val && val && !LED_Status) {
    digitalWrite(12, 1);
    LED_Status = 1;
  } else if (val!=last_val && val && LED_Status) {
    digitalWrite(12, 0);
    LED_Status = 0;
  }
  Serial.println(LED_Status);
  last_val = val;
  delay(100);
}

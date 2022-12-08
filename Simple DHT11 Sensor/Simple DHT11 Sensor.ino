
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
void setup() {
 Serial.begin(9600);
 Serial.println(F("DHTxx Test!"));
 dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT Sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity"));
  Serial.print(h);

  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("C!"));
  Serial.print(f);
  Serial.print(F("F! Heat index: "));
  Serial.print(hic);
  Serial.print(F("C!"));
  Serial.print(hif);
  Serial.println(F("F!"));

}
  
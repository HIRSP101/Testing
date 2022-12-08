#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
#define DHTPIN_2 6
#define DHTTYPE_2 DHT11

DHT dht(DHTPIN, DHTTYPE);
DHT dht_2(DHTPIN_2, DHTTYPE_2);
void setup() {
 pinMode(13, OUTPUT);
 Serial.begin(9600);
 Serial.println(F("DHTxx Test!"));
 dht.begin();
}

void loop() {
  delay(1000);

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
  Serial.print(F("C"));
  Serial.print(f);
  Serial.print(F("F Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F "));

  Serial.println(F("Second Sensor Reading: "));
  delay(1000);

  float h_2 = dht_2.readHumidity();
  float t_2 = dht_2.readTemperature();
  float f_2 = dht_2.readTemperature(true);

  if (isnan(h_2) || isnan(t_2) || isnan(f_2)) {
    Serial.println(F("2.Failed to read from DHT Sensor!"));
    return;
  }

  float hif_2 = dht_2.computeHeatIndex(f, h);
  float hic_2 = dht_2.computeHeatIndex(t, h, false);

  Serial.print(F("2.Humidity"));
  Serial.print(h_2);

  Serial.print(F("% Temperature: "));
  Serial.print(t_2);
  Serial.print(F("C"));
  Serial.print(f_2);
  Serial.print(F("F Heat index: "));
  Serial.print(hic_2);
  Serial.print(F("C "));
  Serial.print(hif_2);
  Serial.println(F("F "));

}
  
#include "DHT.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#define DHTTYPE DHT22   

const int DHTPin = 12;     
DHT dht(DHTPin, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  Serial.println("Test Sensor Suhu");
  lcd.clear();
}

void loop() {
 
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  lcd.setCursor(0,0);
  lcd.print("Humidity : ");
  Serial.print(h);
  lcd.print(h);
  Serial.print(" %\t");
  lcd.print(" %t");
  Serial.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  Serial.print(t);
  lcd.print(t);
  Serial.println(" *C ");
  lcd.print(" *C ");
}
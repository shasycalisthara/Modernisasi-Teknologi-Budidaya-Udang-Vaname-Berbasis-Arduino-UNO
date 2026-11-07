#include <OneWire.h>
#include <DallasTemperature.h>

// Pin data DS18B20 dihubungkan ke pin 2 Arduino
const int oneWireBus = 2;     

// Setup oneWire instance
OneWire oneWire(oneWireBus);
// Teruskan oneWire reference ke Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin(); // Memulai sensor
  Serial.println("Sistem Monitoring Suhu Udang Vaname Dimulai...");
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  
  Serial.print("Suhu Air: ");
  Serial.print(temperatureC);
  Serial.println(" ºC");
  
  delay(1000);
}

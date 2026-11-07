/*
 * MODERNISASI TEKNOLOGI BUDIDAYA UDANG VANAME
 * Fitur: Monitoring Suhu (DS18B20) dan pH Air
 * Board: Arduino UNO
 */

#include <OneWire.h>
#include <DallasTemperature.h>

// ================= PENGATURAN PIN =================
const int pinSuhu = 2;       // Pin digital untuk DS18B20
const int pinPH = A0;        // Pin analog untuk Sensor pH

// ================= INSTANSIASI OBJEK ==============
OneWire oneWire(pinSuhu);
DallasTemperature sensorSuhu(&oneWire);

// ================= VARIABEL GLOBAL ================
float kalibrasi_offset_pH = 0.00; // Sesuaikan berdasarkan kalibrasi manual

void setup() {
  Serial.begin(9600);
  
  // Inisialisasi Sensor Suhu
  sensorSuhu.begin();
  
  Serial.println("==================================================");
  Serial.println(" SISTEM MONITORING AIR BUDIDAYA UDANG VANAME ");
  Serial.println("==================================================");
  delay(2000);
}

void loop() {
  // 1. MEMBACA DATA SUHU
  sensorSuhu.requestTemperatures(); 
  float suhuAir = sensorSuhu.getTempCByIndex(0);

  // 2. MEMBACA DATA PH
  int nilaiAnalogPH = analogRead(pinPH);
  float teganganPH = nilaiAnalogPH * (5.0 / 1023.0);
  float nilaiPH = 3.5 * teganganPH + kalibrasi_offset_pH;

  // 3. MENAMPILKAN DATA KE SERIAL MONITOR
  Serial.print("Suhu Air: ");
  Serial.print(suhuAir);
  Serial.print(" ºC \t|\t ");
  
  Serial.print("Nilai pH: ");
  Serial.println(nilaiPH);

  // (Opsional) 4. LOGIKA KONDISI IDEAL UDANG VANAME
  // Suhu optimal udang vaname: 28-32 C
  // pH optimal udang vaname: 7.5 - 8.5
  if(suhuAir < 26.0 || suhuAir > 33.0 || nilaiPH < 7.0 || nilaiPH > 9.0) {
    Serial.println("⚠️ PERINGATAN: Kualitas air di luar batas optimal!");
  } else {
    Serial.println("✅ STATUS: Kualitas air terpantau AMAN.");
  }
  
  Serial.println("--------------------------------------------------");
  
  // Delay 2 detik sebelum pembacaan berikutnya agar tidak flood
  delay(2000); 
}

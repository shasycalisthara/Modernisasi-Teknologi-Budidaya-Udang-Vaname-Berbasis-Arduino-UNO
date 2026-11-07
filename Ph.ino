const int pinSensorPH = A0;
float tegangan;
float nilai_pH;
float kalibrasi_offset = 0.00; // Ubah nilai ini saat kalibrasi dengan air netral (pH 7)

void setup() {
  Serial.begin(9600);
  Serial.println("Sistem Monitoring pH Udang Vaname Dimulai...");
}

void loop() {
  int nilaiAnalog = analogRead(pinSensorPH);
  
  // Mengubah nilai analog (0-1023) menjadi tegangan (0-5V)
  tegangan = nilaiAnalog * (5.0 / 1023.0);
  
  // Rumus umum pendekatan sensor pH (Tergantung tipe modul, kalibrasi diperlukan)
  nilai_pH = 3.5 * tegangan + kalibrasi_offset;
  
  Serial.print("Tegangan: ");
  Serial.print(tegangan);
  Serial.print(" V | Nilai pH: ");
  Serial.println(nilai_pH);
  
  delay(1000);
}

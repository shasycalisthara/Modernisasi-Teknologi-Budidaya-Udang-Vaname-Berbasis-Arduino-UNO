# 🦐 Modernisasi Teknologi Budidaya Udang Vaname Berbasis Arduino UNO

Proyek *Internet of Things* (IoT) dan sistem tertanam (*embedded system*) untuk memonitoring kualitas air pada tambak budidaya Udang Vaname (*Litopenaeus vannamei*). Sistem ini menggunakan Arduino UNO yang diintegrasikan dengan sensor Suhu (DS18B20) dan sensor pH untuk memastikan kondisi air tetap berada dalam parameter optimal agar udang dapat tumbuh dengan baik.

## 🎯 Fitur Utama
- **Monitoring Suhu Air Real-time:** Menggunakan sensor *waterproof* DS18B20 untuk akurasi tinggi.
- **Monitoring pH Air:** Menggunakan modul sensor pH analog untuk membaca tingkat keasaman/kebasaan air.
- **Sistem Terintegrasi:** Pembacaan data secara simultan yang dapat dikembangkan ke *dashboard* web atau aktuator (seperti aerator otomatis).

## 🛠️ Kebutuhan Perangkat Keras (Hardware)
1. Arduino UNO (atau kompatibel)
2. Sensor Suhu DS18B20 (Waterproof)
3. Modul Sensor pH (misal: pH-4502C)
4. Resistor 4.7kΩ (untuk *pull-up* sensor suhu)
5. Kabel Jumper (Male-to-Male, Male-to-Female)
6. Breadboard
7. LCD I2C 16x2 (Opsional, untuk *display* langsung di lapangan)

## 🔌 Skema Rangkaian (Wiring Diagram)

| Komponen | Pin Komponen | Pin Arduino UNO | Keterangan |
| :--- | :--- | :--- | :--- |
| **DS18B20 (Suhu)** | VCC (Merah) | 5V | |
| | GND (Hitam) | GND | |
| | DATA (Kuning) | Pin D2 | Pasang resistor 4.7kΩ antara DATA dan VCC |
| **Modul Sensor pH** | VCC | 5V | |
| | GND | GND | |
| | Po (Analog Out)| Pin A0 | Pin data pH ke Analog 0 |
| **LCD 16x2 I2C** *(Opsional)*| VCC | 5V | |
| | GND | GND | |
| | SDA | A4 | Sesuai standar I2C Arduino UNO |
| | SCL | A5 | Sesuai standar I2C Arduino UNO |

*Catatan: Pastikan pasokan daya (Power Supply) stabil, terutama jika nantinya digabungkan dengan relay atau ESP32 untuk pengiriman data nirkabel.*

## ⚙️ Cara Kerja Sistem (Flowchart)

Sistem bekerja dengan siklus pembacaan data sensor secara periodik. Data analog dari sensor pH dikonversi menjadi nilai pH (0-14), dan data digital dari sensor suhu DS18B20 dibaca melalui protokol 1-Wire.

```mermaid
graph TD;
    A([Mulai]) --> B[Inisialisasi Pin & Library];
    B --> C[Baca Data Sensor Suhu DS18B20];
    C --> D[Baca Tegangan Modul pH];
    D --> E[Konversi Tegangan ke Nilai pH];
    E --> F[Tampilkan Data di Serial Monitor / LCD];
    F --> G{Apakah Suhu/pH Optimal?};
    G -- Tidak (Abnormal) --> H[Kirim Peringatan / Aktifkan Relay Aerator];
    G -- Ya (Normal) --> I[Tunggu 2 Detik];
    H --> I;
    I --> C;

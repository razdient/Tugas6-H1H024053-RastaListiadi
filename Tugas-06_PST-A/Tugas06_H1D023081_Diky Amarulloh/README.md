Penjelasan kode
1. Library yang Digunakan

```cpp
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
```

* `Wire.h` → digunakan untuk komunikasi I2C.
* `Adafruit_LiquidCrystal.h` → library untuk mengontrol LCD I2C.

2. Inisialisasi LCD

```cpp
Adafruit_LiquidCrystal lcd(0);
```

* Membuat objek LCD dengan alamat I2C = `0`

3. Variabel Teks (Quote)

```cpp
String quote = "HIDUP JOKOWI!!!!";
```

* Ini adalah kalimat yang akan berjalan (scrolling), Disimpan dalam tipe data `String`

4. Fungsi `setup()`

```cpp
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
```

* `lcd.begin(16, 2)` → mengatur LCD dengan ukuran **16 kolom, 2 baris**
* `lcd.setBacklight(1)` → menyalakan lampu LCD
Menampilkan teks statis (baris 0)

```cpp
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
```

* `setCursor(5, 0)` → posisi kolom ke-5, baris ke-0
* Tujuannya agar tulisan `"QUOTE"` berada di tengah layar
* Ini bersifat statis

5. Fungsi `loop()`

Fungsi ini akan berjalan terus-menerus.

```cpp
int panjang = quote.length();
```

* Mengambil panjang karakter dari teks `"HIDUP JOKOWI!!!!"`
* Digunakan untuk menentukan batas pergerakan teks


6. Logika Scrolling (Gerakan Teks)

```cpp
for (int pos = 15; pos >= -panjang; pos--)
```

* `pos = 15` → mulai dari paling kanan layar
* `pos--` → bergerak ke kiri
* `-panjang` → agar teks benar-benar keluar dari layar

 Jadi teks akan:

* Muncul dari kanan
* Bergerak ke kiri
* Sampai hilang

7. Membersihkan Baris Kedua

```cpp
lcd.setCursor(0, 1);
lcd.print("                ");
```

* Mengisi baris ke-2 dengan spasi
* Tujuannya untuk menghapus teks sebelumnya
* Karena LCD tidak otomatis clear

8. Menampilkan Teks Berjalan

```cpp
lcd.setCursor(pos, 1);
lcd.print(quote);
```

* Menampilkan teks di posisi `pos`
* Karena `pos` berubah → teks terlihat bergerak

9. Delay (Kecepatan)

```cpp
delay(2);
```

* Mengatur kecepatan scroll
* kecepatan diatur 2 ms

Dokumentasi

![Tugas](Tugas06.gif)

/*
  Ketika diperlukan jumlah Input Tombol yang lebih banyak,
  namun dengan kaki IO yang terbatas,
  maka keypad merupakan solusi yang menarik.
  
  Di modul hardware PLCArduino ini, keypad 4x4 dihubungkan 
  ke 6 kaki IO, dengan pola sambungan seperti berikut: 
  L1-A0, L2-A1, L3-A2, R1-A3, R2-A4, R3-A5.
  Karena hanya 6 kaki IO, maka tombol yang bisa digunakan
  sebagai input hanyalah 9 tombol (3x3).
  
  Untuk mengetahui tombol mana saja yang dijadikan input,
  program berikut ini akan menampilkan angka dari 1 s/d 9 
  di Serial Monitor, ketika tombol yang digunakan ditekan. 
  Catat posisi tombol dan angka yang ditampilkan 
  sebagai nama dari tombol tersebut.
*/
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
  char tombolku = 0; 
  const byte ROWS = 3; 
  const byte COLS = 3; 
  char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
   };
  byte rowPins[ROWS] = { 14, 15, 16 };
  byte colPins[COLS] = { 17, 18, 19 }; 
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  
  void setup() {
    setupku();
    Serial.begin(9600);
  }
  void loop() {
    tombolku = kpd.getKey();   
    Serial.println(tombolku);
    delay(100);
  }

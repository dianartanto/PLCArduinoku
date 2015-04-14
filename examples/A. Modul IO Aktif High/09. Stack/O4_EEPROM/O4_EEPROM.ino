/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input Digital : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Input Analog  : A4 (kaki A4 Arduino)
  Kaki Output : Y6, Y7, Y8, Y9, Y10, Y11, Y12, Y13 
  (kaki D6, D7, D8, D9, D10, D11, D12 dan D13 Arduino)
  Alat Input Digital : Tombol 3x
  Alat Input Analog  : Potensio 1x
  Alat Output : LED 8x
  
2.Program:
  Program berikut ini akan membaca nilai analog potensio di A4, 
  dan kemudian mengubah nilainya dari 10 bit menjadi 8 bit.
  Penekanan tombol X1 akan menyimpan nilai analog tersebut ke dalam EEPROM.
  Penekanan tombol X2 akan memanggil nilai yang disimpan di dalam EEPROM,
  dan kemudian menampilkannya dalam bentuk nyala LED.
  Untuk nilai analog 0 berarti semua LED padam.
  Untuk nilai analog 255 berarti kedelapan LED menyala, dstnya.
  Untuk menguji penyimpanan permanen EEPROM, matikan PLCArduino,
  kemudian hidupkan kembali. Kemudian tekan tombol X2, seharusnya LED 
  yang menyala susunannya sama seperti sebelum PLCArduino dimatikan.
  Penekanan tombol X3 akan menghapus isi EEPROM.
*/
#include<PLCArduinoku.h>
#include <EEPROM.h>
unsigned int R1, RX1, RX2, RX3, RY5, RY6, RY7, RY8, RY9, RY10, RY11, RY12;
void setup() {
  setupku();
  outLow();
  Serial.begin(9600);
}

void loop() {
  //bagian input
  R1=inAnalog(A4)/4;
  in(X1); out(RX1);
  in(X2); out(RX2);
  in(X3); out(RX3);
  
  //bagian proses
  if(in(RX1)){             // simpan nilai ke EEPROM
  for(int i=0; i<8; i++){
    EEPROM.write(i,bitRead(R1,i));}}

  if(in(RX2)){            // tampilkan nilai di EEPROM
    RY5=EEPROM.read(0);
    RY6=EEPROM.read(1);
    RY7=EEPROM.read(2);
    RY8=EEPROM.read(3);
    RY9=EEPROM.read(4);
    RY10=EEPROM.read(5);
    RY11=EEPROM.read(6);
    RY12=EEPROM.read(7);  }

  if(in(RX3)){            // bersihkan EEPROM
  for(int i=0; i<8; i++){
    EEPROM.write(i,0);}}

  //bagian output
  in(RY5); out(Y5);
  in(RY6); out(Y6);
  in(RY7); out(Y7);
  in(RY8); out(Y8);
  in(RY9); out(Y9);
  in(RY10); out(Y10);
  in(RY11); out(Y11);
  in(RY12); out(Y12);
 }


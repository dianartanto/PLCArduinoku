/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 4x
  
2.Program:
  Program berikut ini sangat diperlukan untuk mengetahui
  apa yang terjadi pada program, khususnya ketika program
  tidak bekerja sesuai dengan yang diharapkan.
   
  Program ini akan memonitor nilai input dan output digital,
  pada program Examples, yaitu IO Penyederhanaan
  
  Perhatikan, untuk menampilkan nilai input di Serial Monitor, 
  jangan menggunakan nama pin atau variabel berinisial X. 
  Untuk menampilkan nilai output di Serial Monitor,
  jangan menggunakan nama pin atau variabel berinisial Y.
  Untuk menampilkan nilai input dan output tersebut, 
  gunakan variabel berinisial R, seperti ditunjukkan dalam program berikut ini.
*/
#include<PLCArduinoku.h>
unsigned int R1, RX1, RY1, RY2, RY3, RY4;
void setup() {
  setupku();
  outHigh();
  Serial.begin(9600);
}

void loop() {
  //bagian input
  inNot(X1); out(RX1);
  
  //bagian proses
  in(RX1); out(R1); out(RY1); outNot(RY3);
  inNot(R1); out(RY2); outNot(RY4);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
  
  Serial.print(RX1);
  Serial.print(',');
  Serial.print(RY1);
  Serial.print(',');
  Serial.print(RY2);
  Serial.print(',');
  Serial.print(RY3);
  Serial.print(',');
  Serial.println(RY4);
 }

/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 3x
  Alat Output : Relay 2x
  
2.Program:
  Program berikut ini sangat diperlukan untuk mengetahui
  apa yang terjadi pada program, khususnya ketika program
  tidak bekerja sesuai dengan yang diharapkan.
   
  Program ini akan memonitor nilai variabel Shift Register 
  dengan menampilkan nilai 16 bit Register dan nilai 1 bit 
  di posisi tertentu.
 */
#include <PLCArduinoku.h>
Shift SF1(0x1111); 
unsigned long T1 = 0;  
void setup() {
  setupku();    
  outLow();
  Serial.begin(9600);
}

void loop() {
  in(X1); SF1.inputBit();
  in(X2); timerOn(T1, 10); SF1.shiftLeft();
  in(X3); SF1.reset();
  SF1.bitValue(3); out(Y4);
  SF1.bitValue(2); out(Y3);
  SF1.bitValue(1); out(Y2);
  SF1.bitValue(0); out(Y1);
  
  Serial.print(SF1.value(),BIN);
  Serial.print(',');
  Serial.print(SF1.bitValue(3));
  Serial.print(',');
  Serial.print(SF1.bitValue(2));
  Serial.print(',');
  Serial.print(SF1.bitValue(1));
  Serial.print(',');
  Serial.println(SF1.bitValue(0));
}

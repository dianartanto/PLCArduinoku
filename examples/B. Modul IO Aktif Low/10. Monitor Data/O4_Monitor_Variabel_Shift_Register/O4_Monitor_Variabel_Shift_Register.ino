/*
1.Rangkaian:
  Modul Input Output Aktif Low.
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
unsigned int RX1, RX2, RX3, RY1, RY2, RY3, RY4;
void setup() {
  setupku();    
  outHigh();
  Serial.begin(9600);
}

void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  inNot(X3); out(RX3);
  
  //bagian proses
  in(RX1); SF1.inputBit();
  in(RX2); timerOn(T1, 10); SF1.shiftLeft();
  in(RX3); SF1.reset();
  SF1.bitValue(3); out(RY4);
  SF1.bitValue(2); out(RY3);
  SF1.bitValue(1); out(RY2);
  SF1.bitValue(0); out(RY1);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
  
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

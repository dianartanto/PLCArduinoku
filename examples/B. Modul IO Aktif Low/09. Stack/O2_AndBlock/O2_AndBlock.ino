/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 4x
  
2.Program:
  Fungsi Stack dan andBlock akan mempermudah pengubahan 
  program Ladder Diagram yang kompleks ke dalam Ladder Diagram Teks.
  Perhatikan contoh Ladder Diagram di LDmicro berikut ini:
  
              X1               X3               Y1        
   1 ||-------] [------+-------] [------+-------( )-------||
     ||       X2       |       X4       |       Y2        ||
     ||-------] [------+-------] [------+-------(/)-------||
  
  Program berikut ini akan menghasilkan Ladder Diagram Teks dari Ladder Diagram 
  LDmicro di atas, dengan penerapan instruksi Stack dan andBlock.
*/
#include <PLCArduinoku.h>
Stack ST1;
unsigned int RX1, RX2, RX3, RX4, RY1, RY2;
void setup() {
  setupku(); 
  outHigh();
}

void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  inNot(X3); out(RX3);
  inNot(X4); out(RX4);
        
  //bagian proses        
  in(RX1); orBit(RX2); ST1.push();
  in(RX3); orBit(RX4); ST1.andBlock(); out(RY1); outNot(RY2);   

  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
}

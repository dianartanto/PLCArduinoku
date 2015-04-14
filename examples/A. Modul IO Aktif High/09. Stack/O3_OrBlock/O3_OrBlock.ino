/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 4x

2.Program:
  Fungsi Stack dan orBlock akan mempermudah pengubahan 
  program Ladder Diagram yang kompleks ke dalam Ladder Diagram Teks.
  Perhatikan contoh Ladder Diagram di LDmicro berikut ini:

            X1               X3               Y1        
 1 ||-------] [--------------] [------+-------( )-------||
   ||       X2               X4       |       Y2        ||
   ||-------] [--------------] [------+-------(/)-------||

  Program berikut ini akan menghasilkan Ladder Diagram Teks dari Ladder Diagram 
  LDmicro di atas, dengan penerapan instruksi Stack dan orBlock.
*/
#include <PLCArduinoku.h>
Stack ST1;

void setup() {
  setupku(); 
  outLow();
}

void loop() {
  in(X1); andBit(X3); ST1.push();
  in(X2); andBit(X4); ST1.orBlock(); out(Y1); outNot(Y2);         
}

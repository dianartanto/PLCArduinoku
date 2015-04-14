/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 1x

2.Program:
            X1               X2               Y1       
 1 ||-------]/[--------------] [------+-------(/)-------||
   ||       X1               X2       |                 ||
   ||-------] [--------------]/[------+                 ||

  Ketika tombol di X1 dan tombol di X2 ditekan atau ketika 
  tombol di X1 dan tombol di X2 dilepas, maka Relay di Y1 hidup. 
  Di luar kondisi itu maka Relay di Y1 mati.
*/
#include<PLCArduinoku.h>
void setup() {
  setupku();
  outLow();
}

void loop() {
  in(X1); xorBit(X2); outNot(Y1);
}

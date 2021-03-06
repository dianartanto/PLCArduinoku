/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4, D5 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 4x

2.Program:
            X1               R1        
 1 ||-------] [------+-------( )-------||
   ||                |       Y1        ||
   ||                +-------( )-------||
   ||                |       Y3        ||
   ||                +-------(/)-------||
   ||       R1               Y2        ||
 2 ||-------]/[------+-------( )-------||
   ||                |       Y4        ||
   ||                +-------(/)-------||

  Ketika tombol di X1 ditekan, LED di D2, D5 menyala, LED di D3, D4 padam
  Ketika tombol di X1 dilepas, LED di D2, D5 padam, LED di D3, D4 menyala
*/
#include<PLCArduinoku.h>
unsigned int R1;
void setup() {
  setupku();
  outLow();
}
void loop() {
  in(X1); out(R1); out(Y1); outNot(Y3);
  inNot(R1); out(Y2); outNot(Y4);
}




/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4, D5 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 4x

2.Program:
            X1               R1        
 1 ||-------] [--------------( )-------||
   ||       R1               Y1        ||
 2 ||-------] [--------------( )-------||
   ||       R1               Y2        ||
 3 ||-------]/[--------------( )-------||
   ||       R1               Y3        ||
 4 ||-------] [--------------(/)-------||
   ||       R1               Y4        ||
 5 ||-------]/[--------------(/)-------||

  Ketika tombol di X1 ditekan, LED di D2, D5 menyala, LED di D3, D4 padam
  Ketika tombol di X1 dilepas, LED di D2, D5 padam, LED di D3, D4 menyala
*/
#include<PLCArduinoku.h>
unsigned int R1, RX1, RY1, RY2, RY3, RY4;
void setup() {
  setupku();
  outHigh();
}
void loop() {
//bagian input
  inNot(X1); out(RX1);  //membalik input
  
//bagian proses
  in(RX1); out(R1);
  in(R1); out(RY1);
  inNot(R1); out(RY2);
  in(R1); outNot(RY3);
  inNot(R1); outNot(RY4);
  
//bagian output
  in(RY1); outNot(Y1);  //membalik output
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);  
}



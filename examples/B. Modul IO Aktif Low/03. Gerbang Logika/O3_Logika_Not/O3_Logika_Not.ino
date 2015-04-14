/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x

2.Program:
            X1               Y1      
 1 ||-------]/[--------------( )-------||

  Ketika tombol di X1 ditekan maka Relay di Y1 mati, 
  Ketika tombol di X1 dilepas maka Relay di Y1 hidup.
*/
#include<PLCArduinoku.h>
void setup() {
  setupku();
  outHigh();
}

void loop() {
  inNot(X1); out(Y1);
}

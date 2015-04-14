/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 1x
  
2.Program:
            X1               Y1        
 1 ||-------] [--------------(S)-------||
   ||       X2               Y1        ||
 2 ||-------] [--------------(R)-------||
 
   Ketika tombol di X1 ditekan, maka Relay di Y1 hidup dan 
   tetap hidup sekalipun tombol di X1 telah dilepas.
   Ketika tombol di X2 ditekan barulah Relay di Y1 mati.
*/
#include <PLCArduinoku.h>
unsigned int RX1, RX2, RY1;
void setup() {
  setupku();
  outHigh();
}
void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  
  //bagian proses  
  in(RX1); set(RY1);   
  in(RX2); reset(RY1);
  
  //bagian output
  in(RY1); outNot(Y1);
}


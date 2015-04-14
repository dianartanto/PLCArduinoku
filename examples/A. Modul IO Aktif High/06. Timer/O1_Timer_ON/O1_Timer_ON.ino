/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 2x
  
2.Program:
            X1               T1               Y1        
 1 ||-------] [---------[TON 2.000 s]---------( )-------||
   ||       X2               T2               Y2        ||
 2 ||-------] [---------[TON 4.000 s]---------( )-------||

  Ketika tombol di X1 ditekan, Relay di Y1 tidak langsung hidup.
  Ketika penekanan tombol di X1 telah 2 detik, barulah Relay di Y1 hidup.
  Begitu pula ketika tombol di X2 ditekan, Relay di Y2 tidak langsung hidup.
  Ketika penekanan tombol di X2 telah 4 detik, barulah Relay di Y2 hidup.
  Baik tombol di X1 maupun di X2, begitu tombol dilepas, maka Relay mati.
*/
#include <PLCArduinoku.h>
unsigned long T1, T2;
void setup() {
  setupku(); 
  outLow();
}
void loop() {
  in(X1); timerOn(T1, 2000); out(Y1);
  in(X2); timerOn(T2, 4000); out(Y2);
}





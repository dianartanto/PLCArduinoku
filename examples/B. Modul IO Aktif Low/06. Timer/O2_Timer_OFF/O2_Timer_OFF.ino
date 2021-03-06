/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x
  
2.Program:
            X1               T1               Y1        
 1 ||-------] [---------[TOF 3.000 s]---------( )-------||

  Ketika tombol di X1 ditekan, Relay di Y1 langsung hidup.
  Ketika tombol di X1 dilepas, Relay di Y1 tidak langsung mati.
  Setelah 3 detik barulah Relay Y1 mati.
*/
#include <PLCArduinoku.h>
unsigned long T1;
unsigned int RX1, RY1;
void setup() {
  setupku();
  outHigh();
}
void loop() {
  //bagian input
  inNot(X1); out(RX1);

  //bagian proses
  in(RX1); timerOff(T1, 3000); out(RY1);   
 
   //bagian output
  in(RY1); outNot(Y1); 
}




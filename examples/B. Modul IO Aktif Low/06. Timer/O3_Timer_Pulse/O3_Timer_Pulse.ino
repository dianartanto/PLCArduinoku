/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x
  
2.Program:
            X1               R1               Y1        
 1 ||-------] [------+-------]/[--------------( )-------||
   ||       Y1       |                                  ||
   ||-------] [------+                                  ||
   ||       Y1               T1               R1        ||
 2 ||-------] [---------[TON 5.000 s]---------( )-------||
  
  Timer Pulse bekerja seperti Timer Off, hanya bedanya:
  waktu Timer Off dimulai dari saat tombol dilepas, sedangkan
  waktu Timer Pulse dimulai dari saat tombol ditekan.

  Contoh program berikut ini menghasilkan pulsa High dengan 
  lebar waktu 5 detik, yang dimulai saat tombol X1 ditekan.
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
  in(RX1); timerPulse(T1, 5000); out(RY1);      
  
  //bagian output
  in(RY1); outNot(Y1); 
}




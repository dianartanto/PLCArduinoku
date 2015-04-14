/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 1x
  
2.Program:
            X1                _               Y1        
 1 ||-------] [-----------[OSF \_]------------(S)-------||
   ||       X2                                Y1        ||
 2 ||-------] [-------------------------------(R)-------||
 
  Ketika tombol di X1 ditekan, dan kemudian dilepas,
  maka OSF mendeteksi sisi turun pulsa input
  membuat Relay Y1 akan hidup. Karena output OSF hanya sesaat, 
  maka Relay Y1 harus ditahan hidup dengan dibuat set.
  Penekanan tombol di X2 akan mereset Relay di Y1.
*/ 
#include<PLCArduinoku.h>
unsigned int RX1, RX2, R1, RY1;
void setup() {
  setupku();
  outHigh();
}
void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  
  //bagian proses
  osf(RX1,R1); set(RY1);
  in(RX2); reset(RY1);
  
  //bagian output
  in(RY1); outNot(Y1);
}



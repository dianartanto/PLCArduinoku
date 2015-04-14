/*
1.Rangkaian:
  Modul Input Output Aktif High.
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
unsigned int R1;
void setup() {
  setupku();
  outLow();
}
void loop() {
  osf(X1,R1); set(Y1);
  in(X2); reset(Y1);
}



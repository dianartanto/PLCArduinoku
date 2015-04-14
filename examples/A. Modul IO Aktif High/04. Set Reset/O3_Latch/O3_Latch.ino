/*    
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 1x
  
2.Program:
            X1               X2               Y1        
 1 ||-------] [------+-------]/[--------------( )-------||
   ||       Y1       |                                  ||
   ||-------] [------+                                  ||

   Ketika tombol di X1 ditekan, maka Relay di Y1 hidup dan 
   tetap hidup sekalipun tombol di X1 telah dilepas.
   Ketika tombol di X2 ditekan barulah Relay di Y1 mati.
*/
#include <PLCArduinoku.h>
void setup() {
  setupku();  
  outLow();  
}
void loop() {
  in(X1); latch(Y1, X2);       
}




/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 3x
  Alat Output : Relay 4x
  
2.Program:
  Program berikut ini adalah Shift Register 32 bit, 
  yang dibuat dari 2 buah Shift Register 16 bit yang disusun bertingkat. 
  Berikut ini adalah Shift Register 16 bit pertama dengan nilai awal 0xF0F0
                 Posisi Bit  1 1 1 1    1 1
                             5 4 3 2    1 0 9 8    7 6 5 4    3 2 1 0
                             | | | |    | | | |    | | | |    | | | |
              X1 -> -> -> -> 1 1 1 1 -> 0 0 0 0 -> 1 1 1 1 -> 0 0 0 0 ->
            
              X2 -> Clock      
      
              X3 -> Reset

  Berikut ini adalah Shift Register 16 bit kedua dengan nilai awal 0xAAAA
                 Posisi Bit  1 1 1 1    1 1
                             5 4 3 2    1 0 9 8    7 6 5 4    3 2 1 0
                             | | | |    | | | |    | | | |    | | | |
       Shift1.bitValue(0) -> 1 0 1 0 -> 1 0 1 0 -> 1 0 1 0 -> 1 0 1 0 ->
                                                              | | | |
              X2 -> Clock                                     | | | |      
                                                              | | | |
              X3 -> Reset                                     | | | |  
                                                              Y Y Y Y
                                                   Output     4 3 2 1
                                                   
  Untuk melihat nilai Shift Register ini di Serial Monitor, 
  gunakan instruksi Serial.print(SF1.value(),BIN);
*/
#include <PLCArduinoku.h>
Shift SF1(0xF0F0);      
Shift SF2(0xAAAA); 
unsigned long T1;
void setup() {
  setupku(); 
  outLow();
  Serial.begin(9600);
}
void loop() { 
  in(X1); SF1.inputBit(); 
  SF1.bitValue(0); SF2.inputBit();     
  in(X2); timerOn(T1, 10); SF1.shiftRight(); SF2.shiftRight();
  in(X3); SF1.reset(); SF2.reset();
  SF2.bitValue(3); out(Y4);
  SF2.bitValue(2); out(Y3);
  SF2.bitValue(1); out(Y2);
  SF2.bitValue(0); out(Y1);
  Serial.print(SF1.value(),BIN);
  Serial.print(',');
  Serial.println(SF2.value(),BIN);
}

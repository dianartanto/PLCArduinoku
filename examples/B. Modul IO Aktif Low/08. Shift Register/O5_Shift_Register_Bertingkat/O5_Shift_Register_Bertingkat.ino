/* 
1.Rangkaian:
  Modul Input Output Aktif Low.
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
unsigned int RX1, RX2, RX3, RY1, RY2, RY3, RY4;
void setup() {
  setupku(); 
  outHigh();
  Serial.begin(9600);
}
void loop() { 
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  inNot(X3); out(RX3);

  //bagian proses
  in(RX1); SF1.inputBit(); 
  SF1.bitValue(0); SF2.inputBit();     
  in(RX2); timerOn(T1, 10); SF1.shiftRight(); SF2.shiftRight();
  in(RX3); SF1.reset(); SF2.reset();
  SF2.bitValue(3); out(RY4);
  SF2.bitValue(2); out(RY3);
  SF2.bitValue(1); out(RY2);
  SF2.bitValue(0); out(RY1);
      
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
  Serial.print(SF1.value(),BIN);
  Serial.print(',');
  Serial.println(SF2.value(),BIN);
}

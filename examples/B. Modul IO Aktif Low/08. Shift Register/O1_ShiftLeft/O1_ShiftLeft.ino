/* 
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 3x
  Alat Output : Relay 4x
  
2.Program:
            X2                  _       {SHIFT REG   }   
 1 ||-------] [-----------[OSR_/ ]------{ reg0..7    }--||
   ||       X1                          {reg0  :=    }  ||
 2 ||-------] [-------------------------{ 1       MOV}--||
   ||       X3                          {reg0  :=    }  ||
 3 ||-------] [------+------------------{ 0       MOV}--||
   ||                |                  {reg1  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg2  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg3  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg4  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg5  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg6  :=    }  ||
   ||                +------------------{ 0       MOV}--||
   ||                |                  {reg7  :=    }  ||
   ||                +------------------{ 0       MOV}--||

  Program berikut ini adalah Shift Register Shift Left 16 bit,
  yang menggeser satu bit ke kiri, setiap kali tombol di X2 ditekan. 
  Data yang dimasukkan dari kiri adalah nilai input di X1. 
  Ketika tombol di X1 ditekan, berarti 1, ketika dilepas berarti 0.
  Ketika tombol reset di X3 ditekan, nilai Shift Register menjadi 0.
                    1 1 1 1    1 1
        Posisi Bit  5 4 3 2    1 0 9 8    7 6 5 4    3 2 1 0
                    | | | |    | | | |    | | | |    | | | |
                 <- 0 0 0 1 <- 0 0 0 1 <- 0 0 0 1 <- 0 0 0 1 <- X1
       X2 -> Clock                                   | | | |
                                                     | | | |
       X3 -> Reset                                   | | | |
                                                     Y Y Y Y
                                          Output     4 3 2 1
  
  Untuk melihat nilai Shift Register ini di Serial Monitor, 
  gunakan instruksi Serial.println(SF1.value(),BIN); 
*/
#include <PLCArduinoku.h>
Shift SF1(0x1111); 
unsigned long T1 = 0;  
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
  in(RX2); timerOn(T1, 10); SF1.shiftLeft();
  in(RX3); SF1.reset();
  SF1.bitValue(3); out(RY4);
  SF1.bitValue(2); out(RY3);
  SF1.bitValue(1); out(RY2);
  SF1.bitValue(0); out(RY1);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
  Serial.println(SF1.value(),BIN);
}

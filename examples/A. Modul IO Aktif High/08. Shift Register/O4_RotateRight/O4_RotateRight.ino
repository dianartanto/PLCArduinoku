/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 4x
  
2.Program:
            X1                  _                        {SHIFT REG   }  
 1 ||-------] [-----------[OSR_/ ]----+------------------{ reg0..4    }--||
   ||                                 |                  {reg0  :=    }  ||
   ||                                 +------------------{ reg4    MOV}--||
   ||       X2                                           {reg0  :=    }  ||
 2 ||-------] [------+-----------------------------------{ 0       MOV}--||
   ||                |                                   {reg1  :=    }  ||
   ||                +-----------------------------------{ 0       MOV}--||
   ||                |                                   {reg2  :=    }  ||
   ||                +-----------------------------------{ 0       MOV}--||
   ||                |                                   {reg3  :=    }  ||
   ||                +-----------------------------------{ 0       MOV}--||
   ||    [reg0 ==]                                             Y1        ||
 3 ||----[ 1     ]---------------------------------------------( )-------||
   ||    [reg1 ==]                                             Y2        ||
   ||----[ 1     ]---------------------------------------------( )-------||
   ||    [reg2 ==]                                             Y3        ||
   ||----[ 1     ]---------------------------------------------( )-------||
   ||    [reg3 ==]                                             Y4        ||
   ||----[ 1     ]---------------------------------------------( )-------||
 
  Program berikut ini adalah Shift Register Rotate Right 4 bit,
  yang akan menggeser ke kanan dan memutar data kembali dari posisi bit 
  terkecil (paling kanan) ke posisi bit terbesar (paling kiri).
                        Output       Y Y Y Y
                                     3 2 1 0
                     
                      Posisi Bit     1 1 1 1
                                     5 4 3 2
                                     | | | |
                                  -> 1 0 0 0 ->
                                  |           |
                                  |           |
                   X1 -> Clock    -<--<--<--<--
                 
                   X2 -> Reset

  Untuk melihat nilai Shift Register ini di Serial Monitor, 
  gunakan instruksi Serial.println(SF1.value(),BIN);
*/
#include <PLCArduinoku.h>
Shift SF1(0x8000);     
unsigned long T1;
void setup() {
  setupku(); 
  outLow();
  Serial.begin(9600);
}

void loop() {  
  SF1.bitValue(12);  SF1.inputBit();
  in(X1); timerOn(T1,10); SF1.shiftRight();
  in(X2); SF1.reset();
  SF1.bitValue(15); out(Y4);
  SF1.bitValue(14); out(Y3);
  SF1.bitValue(13); out(Y2);
  SF1.bitValue(12); out(Y1);
  Serial.println(SF1.value(),BIN);
}

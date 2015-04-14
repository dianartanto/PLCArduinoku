/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 4x
  
2.Program:
   ||       X1                  _                        {SHIFT REG   }  ||
 1 ||-------] [-----------[OSR_/ ]----+------------------{ reg0..4    }--||
   ||                                 |                  {akhir  :=   }  ||
   ||                                 +------------------{ reg4    MOV}--||
   ||                                 |   [akhir ==]     {reg0  :=    }  ||
   ||                                 +---[ 1      ]-----{ 0       MOV}--||
   ||                                 |   [akhir ==]     {reg0  :=    }  ||
   ||                                 +---[ 0      ]-----{ 1       MOV}--||
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
   ||------[END]---------------------------------------------------------||

  Program berikut ini menghasilkan aplikasi Johnson Counter 4 bit.
  Aplikasi Johnson Counter ini sama dengan Shift Register Rotate Left,
  hanya bedanya, di Johnson Counter ini nilai data yang diputar dibalik. 
  sedangkan di Rotate Left tidak. Lebih jelasnya lihat diagram berikut:

                  Output          Y Y Y Y
                                  4 3 2 1
                 Posisi Bit       3 2 1 0
                                  | | | |
                               <- 0 0 0 0 <-
                               |           |
                             |Not|         |
                               |           |
                X1 -> Clock    ->-->-->-->--

                X2 -> Reset
*/
#include <PLCArduinoku.h>
Shift SF1(0x0000);      
unsigned long T1, T2;
unsigned int R1;
void setup() {
  setupku();
  outLow();
}

void loop() {  
  SF1.bitValue(3); outNot(R1);  
  in(R1); SF1.inputBit();
  in(X1);  timerOn(T1, 10); SF1.shiftLeft();            
  in(X2);  SF1.reset();
  SF1.bitValue(3); out(Y4);
  SF1.bitValue(2); out(Y3);
  SF1.bitValue(1); out(Y2);
  SF1.bitValue(0); out(Y1);
}

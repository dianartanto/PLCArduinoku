/* 
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4, Y5, Y6, Y7, Y8 Y9, Y10, Y11, Y12
  (kaki D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12 dan D13 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 4x dan LED 8x
  
2.Program:
            X1                  _             C1        
 1 ||-------] [-----------[OSR_/ ]---------[CTU >=0]----||
   ||       X2                  _             C1        ||
 2 ||-------] [-----------[OSR_/ ]---_-----[CTD >=0]----||
   ||     [C1 >]                        {C1  :=      }  ||
 3 ||-----[ 12 ]------------------------{ 12      MOV}--||
   ||     [C1 <]                        {C1  :=      }  ||
 4 ||-----[ 0  ]------------------------{ 0       MOV}--||
   ||       X3                                C1        ||
 5 ||-------] [------------------------------{RES}------||
   ||       X4                          {C1  :=      }  ||
 6 ||-------] [-------------------------{ 12      MOV}--||
   ||     [C1 ==]                             Y1        ||
 7 ||-----[ 1   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y2        ||
   ||-----[ 2   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y3        ||
   ||-----[ 3   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y4        ||
   ||-----[ 4   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y5        ||
   ||-----[ 5   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y6        ||
   ||-----[ 6   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y7        ||
   ||-----[ 7   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y8        ||
   ||-----[ 8   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y9        ||
   ||-----[ 9   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y10       ||
   ||-----[ 10  ]-----------------------------( )-------||
   ||     [C1 ==]                             Y11       ||
   ||-----[ 11  ]-----------------------------( )-------||
   ||     [C1 ==]                             Y12       ||
   ||-----[ 12  ]-----------------------------( )-------||

  Program ini akan menghasilkan Counter Up Down dengan nilai preset 12,
  yang pencacahannya dimulai dari 12. 
  Ketika tombol X1 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah naik 1 nilai setiap kali ditekan.
  Ketika tombol X2 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah turun 1 nilai setiap kali ditekan.
  Ketika tombol X3 ditekan, nilai Counter akan direset ke 0.
  Ketika tombol X4 ditekan, nilai Counter akan dipreset ke 12.
  Diinginkan sebuah output akan hidup berdasarkan nilai Counternya.
  Ketika nilai Counter = 0, tidak ada output yang hidup.
  Ketika nilai Counter = 1, output Y1 yang hidup.
  Ketika nilai Counter = 2, output Y2 yang hidup.
  Ketika nilai Counter = 3, output Y3 yang hidup.
  Ketika nilai Counter = 4, output Y4 yang hidup.
  Ketika nilai Counter = 5, output Y5 yang hidup.
  Ketika nilai Counter = 6, output Y6 yang hidup.
  Ketika nilai Counter = 7, output Y7 yang hidup.
  Ketika nilai Counter = 8, output Y8 yang hidup.
  Ketika nilai Counter = 9, output Y9 yang hidup.
  Ketika nilai Counter = 10, output Y10 yang hidup.
  Ketika nilai Counter = 11, output Y11 yang hidup.
  Ketika nilai Counter = 12, output Y12 yang hidup.
  Untuk mengetahui nilai Counter C1, digunakan instruksi Serial.print, yang
  akan menampilkan nilai Counter di Serial Monitor.
*/
#include <PLCArduinoku.h>
Counter C1(12,1); 
unsigned int RX1, RX2, RX3, RX4;
unsigned int RY1, RY2, RY3, RY4, RY5, RY6;
unsigned int RY7, RY8, RY9, RY10, RY11, RY12;
unsigned int R1=1;
unsigned int R2=2;
unsigned int R3=3;
unsigned int R4=4;
unsigned int R5=5;
unsigned int R6=6;
unsigned int R7=7;
unsigned int R8=8;
unsigned int R9=9;
unsigned int R10=10;
unsigned int R11=11;
unsigned int R12=12;
unsigned long T1, T2; 

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
  inNot(X4); out(RX4);
  
  //bagian proses
  in(RX1); timerOn(T1,10); C1.countUp();           
  in(RX2); timerOn(T2,10); C1.countDown();           
  in(RX3); C1.clear();  
  in(RX4); C1.preset();
  inAnalog(C1.count()); compareEQ(R1); out(RY1);
  inAnalog(C1.count()); compareEQ(R2); out(RY2);
  inAnalog(C1.count()); compareEQ(R3); out(RY3);
  inAnalog(C1.count()); compareEQ(R4); out(RY4);
  inAnalog(C1.count()); compareEQ(R5); out(RY5);
  inAnalog(C1.count()); compareEQ(R6); out(RY6);
  inAnalog(C1.count()); compareEQ(R7); out(RY7);
  inAnalog(C1.count()); compareEQ(R8); out(RY8);
  inAnalog(C1.count()); compareEQ(R9); out(RY9);
  inAnalog(C1.count()); compareEQ(R10); out(RY10);
  inAnalog(C1.count()); compareEQ(R11); out(RY11);
  inAnalog(C1.count()); compareEQ(R12); out(RY12);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
  in(RY5); outNot(Y5);
  in(RY6); outNot(Y6);
  in(RY7); outNot(Y7);
  in(RY8); outNot(Y8);
  in(RY9); outNot(Y9);
  in(RY10); outNot(Y10);
  in(RY11); outNot(Y11);
  in(RY12); outNot(Y12);
  Serial.println(C1.count());
}


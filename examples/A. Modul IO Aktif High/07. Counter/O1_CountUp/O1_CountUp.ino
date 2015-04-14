/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 3x
  Alat Output : Relay 2x
  
2.Program:
            X1                  _             C1        
 1 ||-------] [-----------[OSR_/ ]---------[CTU >=0]----||
   ||     [C1 >]                        {C1  :=      }  ||
 2 ||-----[ 10 ]------------------------{ 10      MOV}--||
   ||       X2                                C1        ||
 3 ||-------] [------------------------------{RES}------||
   ||       X3                          {C1  :=      }  ||
 4 ||-------] [-------------------------{ 10      MOV}--||
   ||     [C1 ==]                             Y1        ||
 5 ||-----[ 0   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y2        ||
 6 ||-----[ 10  ]-----------------------------( )-------||

  Program ini akan menghasilkan Counter Up, yang dimulai dari 0, 
  dengan nilai preset Counter adalah 10.
  Ketika tombol X1 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah naik 1 nilai setiap kali ditekan.
  Ketika tombol X2 ditekan, nilai Counter akan direset ke 0.
  Ketika tombol X3 ditekan, nilai Counter akan dipreset ke 10.
  Ketika nilai Counter = 0, maka instruksi C1.lowerQ() bernilai 1,
  membuat Relay di Y1 hidup.
  Ketika nilai Counter = 10, maka instruksi C1.upperQ() bernilai 1,
  membuat Relay di Y2 hidup.
  Untuk mengetahui nilai Counter C1, digunakan instruksi Serial.print, yang
  akan menampilkan nilai Counter di Serial Monitor.
*/
#include <PLCArduinoku.h>
Counter C1(10);
unsigned long T1; 
void setup() {
  setupku(); 
  outLow();
  Serial.begin(9600);  
}

void loop() {
  in(X1); timerOn(T1,10); C1.countUp();            
  in(X2); C1.clear();  
  in(X3); C1.preset();
  C1.lowerQ(); out(Y1);
  C1.upperQ(); out(Y2);
  Serial.println(C1.count());
}

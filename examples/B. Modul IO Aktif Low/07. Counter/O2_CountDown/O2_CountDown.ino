/* 
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1, X2, X3 (kaki A0, A1 dan A2 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 3x
  Alat Output : Relay 2x
  
2.Program:
               _                        {C1  :=      }  
 1 ||----[OSR_/ ]-----------------------{ 10      MOV}--||
   ||       X1                 _              C1        ||
 2 ||-------] [----------[OSR_/ ]----------[CTD >=0]----||
   ||     [C1 <]                        {C1  :=      }  ||
 3 ||-----[ 0  ]------------------------{ 0       MOV}--||
   ||       X2                                C1        ||
 4 ||-------] [------------------------------{RES}------||
   ||       X3                          {C1  :=      }  ||
 5 ||-------] [-------------------------{ 10      MOV}--||
   ||     [C1 ==]                             Y1        ||
 6 ||-----[ 0   ]-----------------------------( )-------||
   ||     [C1 ==]                             Y2        ||
 7 ||-----[ 10  ]-----------------------------( )-------||

  Program ini akan menghasilkan Counter Down dengan nilai mulai dari 10.
  -> Instruksi Counter C1(10,1); membuat Counter C1 mulai dari angka 10
  -> Instruksi Counter C1(10); membuat Counter C1 mulai dari angka 0
  
  Ketika tombol X1 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah turun 1 nilai setiap kali ditekan.
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
Counter C1(10,1);
unsigned long T1; 
unsigned int RX1, RX2, RX3, RY1, RY2;
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
  in(RX1); timerOn(T1,10); C1.countDown();           
  in(RX2); C1.clear();  
  in(RX3); C1.preset();
  C1.lowerQ(); out(RY1);
  C1.upperQ(); out(RY2);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);  
  Serial.println(C1.count());
}

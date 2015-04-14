/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2 (kaki A0 dan A1 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 2x
  Alat Output : Relay 4x
  
2.Program:
            X1                   _            C1        
 1 ||-------] [------------[OSR_/ ]--------{CTC 0:3}----||
   ||     [C1 ==]                             Y1        ||
 2 ||-----[ 0   ]-----------------------------( )-------||
   ||                                                   ||
   ||     [C1 ==]                             Y2        ||
 3 ||-----[ 1   ]-----------------------------( )-------||
   ||                                                   ||
   ||     [C1 ==]                             Y3        ||
 4 ||-----[ 2   ]-----------------------------( )-------||
   ||                                                   ||
   ||     [C1 ==]                             Y4        ||
 5 ||-----[ 3   ]-----------------------------( )-------||
 
  Program ini akan menghasilkan Counter Circular, yaitu sebuah Counter Up,
  yang akan kembali secara otomatis ke 0 setelah mencapai nilai presetnya.
  Ketika tombol X1 ditekan (diberi TimerOn untuk debouncing),
  maka Counter C1 akan mencacah naik 1 nilai setiap kali ditekan.
  Begitu nilai Counter mencapai nilai preset(=4), maka nilai Counter menjadi 0.
  Ketika nilai Counter = 0, output Y1 yang hidup.
  Ketika nilai Counter = 1, output Y2 yang hidup.
  Ketika nilai Counter = 2, output Y3 yang hidup.
  Ketika nilai Counter = 3, output Y4 yang hidup.
  
  Untuk membuat nilai Counter menjadi 0 ketika sudah mencapai nilai maksimumnya,
  digunakan instruksi C1.upperQ(); diikuti dengan C1.clear().
  Sebelum C1.clear(), perlu ditambahkan instruksi timerOff(T1,200); 
  untuk menahan agar nilai Counter tidak melompat ke 1 
  Untuk mengetahui nilai Counter C1, digunakan instruksi Serial.print, yang
  akan menampilkan nilai Counter di Serial Monitor.
*/
#include <PLCArduinoku.h>
Counter C1(4); 
unsigned int R1=0;
unsigned int R2=1;
unsigned int R3=2;
unsigned int R4=3;
unsigned long T1, T2; 

void setup() {
  setupku();
  outLow();
  Serial.begin(9600);      
}

void loop() {
  in(X1); timerOn(T1,10); C1.countUp();           
  in(X2); C1.clear();  
  C1.upperQ(); timerOff(T2,200); C1.clear();
  inAnalog(C1.count()); compareEQ(R1); out(Y1);
  inAnalog(C1.count()); compareEQ(R2); out(Y2);
  inAnalog(C1.count()); compareEQ(R3); out(Y3);
  inAnalog(C1.count()); compareEQ(R4); out(Y4);
  Serial.println(C1.count());
}

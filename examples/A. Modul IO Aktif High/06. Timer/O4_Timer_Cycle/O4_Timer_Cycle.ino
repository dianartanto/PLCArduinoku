/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 2x
  
2.Program:
         X1         Y1            T1            Y1     
 1 ||----] [---+----]/[-----[TON 900.0 ms]------(S)----||
   ||          |    Y1            T2            Y1     ||
   ||          +----] [-----[TON 100.0 ms]------(R)----||
   ||    R1         Y2            T3            Y2     ||
 2 ||----] [---+----]/[-----[TON 900.0 ms]------(S)----||
   ||          |    Y2            T4            Y2     ||
   ||          +----] [-----[TON 100.0 ms]------(R)----||

  Contoh program berikut ini akan membuat gelombang kotak di kaki Y1 dan Y2.
  Kedua kaki tersebut akan menghasilkan gelombang kotak dengan lebar waktu 
  LOW sebesar 900 milidetik dan lebar waktu HIGH sebesar 100 milidetik.
  Bedanya adalah Y1 akan menghasilkan gelombang kotak apabila tombol X1 ditekan.
  Sementara Y2 akan selalu membangkitkan gelombang kotak ketika R1 diisi 1. 
*/
#include <PLCArduinoku.h>
unsigned long T1, T2, T3, T4;
unsigned int R1=1;
void setup() {
  setupku();
  outLow();
}
void loop() {
  in(X1); timerCycle(T1, 900, T2, 100); out(Y1);
  in(R1); timerCycle(T3, 900, T4, 100); out(Y2);
}



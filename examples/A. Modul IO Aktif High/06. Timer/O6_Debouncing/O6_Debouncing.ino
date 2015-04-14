/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x
  
2.Program:
            X1                T1              Y1        
 1 ||-------] [---------[TON 10.00 ms]--------( )-------||

  Bouncing adalah kecenderungan tombol untuk menghasilkan lebih dari 
  satu pulsa saat tombol ditekan, akibat sifat mekanik tombol.
  Program Debouncing ini adalah sebuah cara untuk menghilangkan
  efek bouncing tersebut, dan memastikan bahwa hanya satu sinyal 
  yang dibaca saat sebuah tombol ditekan. Cara paling mudah adalah 
  dengan menunda pembacaan dalam waktu singkat, menggunakan Timer ON.
  Debouncing ini sangat diperlukan khususnya pada aplikasi counter.
  
  Sekedar info: debouncing di software LDmicro tidak menggunakan instruksi
  timer on, berhubung delay pada timer on di LDmicro paling kecil adalah 100ms.
  sebagai gantinya, LDmicro menggunakan instruksi OSR atau OSF sebagai debouncing.
*/
#include <PLCArduinoku.h>
unsigned long T1;
void setup() {
  setupku(); 
  outLow();
}
void loop() {
  in(X1); timerOn(T1,10); out(Y1);
}





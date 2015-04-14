/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x
  
2.Program:
            X1               T1               Y1        
 1 ||-------] [---------[RTO 5.000 s]---------( )-------||
   ||       X2                                T1        ||
 2 ||-------] [------------------------------{RES}------||

  RTO bekerja seperti Timer ON, hanya bedanya, pada RTO nilai waktu lewat 
  sebelumnya ditambahkan, sekalipun timer tidak diaktifkan terus menerus.
  Kemudian ketika akumulasi dari waktu lewat telah mencapai batas waktunya, 
  barulah output akan di-ON-kan oleh RTO.

  Berbeda dengan instruksi RTO di LDmicro yang outputnya dikunci, 
  sehingga perlu direset untuk mengaktifkan kembali, 
  instruksi RTO di PLCArduino ini outputnya tidak dikunci, 
  selama tombol X1 tetap ditekan, output RTO akan menghidupkan Relay,
  begitu tombol X1 dilepas, output RTO menjadi Low, dan 
  nilai waktu lewat RTO akan direset kembali. 
  
  Lebih jelasnya lihat contoh program berikut ini.
  Ketika tombol X1 ditekan dan dilepas berulang kali 
  RTO akan mengakumulasi waktu yang lewat ketika timer diaktifkan.
  Setelah akumulasi waktu lewat sebesar 5 detik, RTO akan menghidupkan Relay di Y1.
  Begitu tombol di X1 dilepas, RTO mereset waktu lewatnya, dan Relay di Y1 mati.
*/
#include<PLCArduinoku.h>
unsigned long T1,T2;
unsigned int RX1, RY1;
void setup() {
  setupku();
  outHigh();
}
void loop() {
  //bagian input
  inNot(X1); out(RX1);
  
  //bagian proses
  in(RX1); RTO(T1,5000,T2); out(RY1);

  //bagian output
  in(RY1); outNot(Y1);
}



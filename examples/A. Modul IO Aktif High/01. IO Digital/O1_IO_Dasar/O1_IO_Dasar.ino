/* 
Catatan:
1.Bagian yang diapit oleh tanda garing (/) diikuti bintang (*) ini 
  adalah bagian komentar. Pembaca bisa menghapus bagian komentar ini.
  Bagian komentar ini tidak berpengaruh pada program.
  
2.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1 (kaki A0 Arduino)
  Kaki Output : Y1 (kaki D2 Arduino)
  Alat Input  : Tombol 1x
  Alat Output : Relay 1x

3.Program:
          X1               Y1         
 ||-------] [--------------( )-------||

  Ketika tombol di X1 ditekan, Relay di Y1 hidup. 
  Ketika tombol di X1 dilepas, Relay di Y1 mati.
*/

#include<PLCArduinoku.h>
void setup() {     //untuk inisialisasi
  setupku();       //berisi penugasan kaki IO, mana input mana output. 
  outLow();        //berisi instruksi untuk membuat semua kaki output menjadi Low.
}
void loop() {      //program utama
  in(X1); out(Y1); //lihat deskripsi program di atas
}

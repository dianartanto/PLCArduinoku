/* 
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2, Y3, Y4 (kaki D2, D3, D4 dan D5 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 4x
  
2.Program:
  Di LDmicro, tidak ada instruksi stack.
  Sebenarnya penyimpanan data 1 bit tidak hanya dengan instruksi stack saja,
  tetapi bisa juga dengan rele internal. Keuntungan stack adalah, variabel yang
  dibutuhkan hanya 1 buah untuk jumlah data hingga 32, sedangkan dengan rele internal,
  variabelnya harus sebanyak jumlah data yang disimpan.
  
  Program berikut ini memperlihatkan penyimpanan 4 buah data 1 bit dengan stack
  dan kemudian mengambilnya satu per satu mulai dari tumpukan paling atas.
  Instruksi untuk menyimpan data: namastack.push(), instruksi untuk mengambil data 
  mulai dari tumpukan teratas: namastack.pop().
*/
#include <PLCArduinoku.h>
Stack ST1;     
void setup() {
  setupku();
  outLow();
}

void loop() {
  in(X1); ST1.push(); 
  in(X2); ST1.push(); 
  in(X3); ST1.push(); 
  in(X4); ST1.push(); 
 
  ST1.pop(); out(Y1);
  ST1.pop(); out(Y2);
  ST1.pop(); out(Y3);
  ST1.pop(); out(Y4);
}

/* 
1.Rangkaian:
  Modul Input Output Aktif Low.
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
unsigned int RX1, RX2, RX3, RX4, RY1, RY2, RY3, RY4;
void setup() {
  setupku();
  outHigh();
}

void loop() {
  //bagian input
  inNot(X1); out(RX1);
  inNot(X2); out(RX2);
  inNot(X3); out(RX3);
  inNot(X4); out(RX4);
        
  //bagian proses      
  in(RX1); ST1.push(); 
  in(RX2); ST1.push(); 
  in(RX3); ST1.push(); 
  in(RX4); ST1.push(); 
  ST1.pop(); out(RY1);
  ST1.pop(); out(RY2);
  ST1.pop(); out(RY3);
  ST1.pop(); out(RY4);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  in(RY4); outNot(Y4);
}

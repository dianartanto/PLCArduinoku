/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input  : X1, X2, X3, X4 (kaki A0, A1, A2 dan A3 Arduino)
  Kaki Output : Y1, Y2 (kaki D2 dan D3 Arduino)
  Alat Input  : Tombol 4x
  Alat Output : Relay 2x
  
2.Program:
  Program berikut ini sangat diperlukan untuk mengetahui
  apa yang terjadi pada program, khususnya ketika program
  tidak bekerja sesuai dengan yang diharapkan.
   
  Program ini akan memonitor nilai variabel Counter, 
  yaitu menampilkan nilai Counter saat itu dan nilai preset Counter,
  pada program Examples, CountUpDown.
  
  Untuk menampilkan nilai counter gunakan variabel namacounter.count().
  Untuk menampilkan nilai preset gunakan variabel namacounter.presetValue().
*/
  #include <PLCArduinoku.h>
  Counter C1(12); 
  unsigned long T1, T2;  
  void setup() {
    setupku();
    outLow();
    Serial.begin(9600);      
  }
  
  void loop() {
    
    in(X1); timerOn(T1,10); C1.countUp();           
    in(X2); timerOn(T2,10); C1.countDown();           
    in(X3); C1.clear();  
    in(X4); C1.preset();
    C1.lowerQ(); out(Y1);
    C1.upperQ(); out(Y2);
    
    Serial.print(C1.count());
    Serial.print(',');
    Serial.println(C1.presetValue());
  }

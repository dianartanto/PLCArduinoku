/*
1.Rangkaian:
  Modul Input Output Aktif Low.
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
  unsigned int RX1, RX2, RX3, RX4, RY1, RY2;
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
    inNot(X4); out(RX4);
    
    //bagian proses
    in(RX1); timerOn(T1,10); C1.countUp();           
    in(RX2); timerOn(T2,10); C1.countDown();           
    in(RX3); C1.clear();  
    in(RX4); C1.preset();
    C1.lowerQ(); out(RY1);
    C1.upperQ(); out(RY2);
    
    //bagian output
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);
    
    Serial.print(C1.count());
    Serial.print(',');
    Serial.println(C1.presetValue());
  }

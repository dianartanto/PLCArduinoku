/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input  : A4, A5 (kaki A4 dan A5 Arduino)
  Kaki Output : Y6, Y9 (kaki D6 dan D9 Arduino)
  Alat Input Analog  : Potensio 2x
  Alat Output Analog : LED 2x
  
2.Program:
  Program berikut ini sangat diperlukan untuk mengetahui
  apa yang terjadi pada program, khususnya ketika program
  tidak bekerja sesuai dengan yang diharapkan.
   
  Program ini akan memonitor nilai input dan output analog,
  pada program Examples, yaitu IO Analog
  
  Perhatikan, untuk menampilkan nilai input dan output analog di Serial Monitor, 
  tambahkan variabel berinisial R untuk menampung hasil inAnalog dan outPWM, 
  seperti ditunjukkan dalam program berikut ini.
*/
  #include<PLCArduinoku.h>
  unsigned int R1, R2, R3, R4;
  void setup() {
    setupku();
    outHigh();
    Serial.begin(9600);
  }
  
  void loop() {  
    R1=inAnalog(A4);    
    R2=outPWM(Y6);  
    R3=inAnalog(A5);
    R4=outPWM(Y9);
  
    Serial.print(R1);
    Serial.print(',');
    Serial.print(R2);
    Serial.print(',');
    Serial.print(R3);
    Serial.print(',');
    Serial.println(R4);
   }

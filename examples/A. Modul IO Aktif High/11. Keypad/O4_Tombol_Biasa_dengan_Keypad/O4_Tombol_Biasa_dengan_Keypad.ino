/*
  Program berikut ini membuat tombol pada Keypad bekerja
  seperti tombol biasa, yaitu ketika tombol ditekan menghasilkan sinyal HIGH dan
  ketika dilepas, menghasilkan sinyal LOW.
  
  Pengujian sifat tombol tersebut diterapkan pada program Timer, 
  termasuk timer ON, timer OFF, timer Pulse, timer Cycle, dan RTO.
  
  Catatan: program berikut ini menganggap rangkaian IO Aktif High.
  Untuk penggunaan rangkaian IO Aktif Low, maka tinggal mengubah instruksi set menjadi reset
  dan sebaliknya reset menjadi set.
  */
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
  char tombolku = 0; 
  const byte ROWS = 3; 
  const byte COLS = 3; 
  char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
   };
  byte rowPins[ROWS] = { 14, 15, 16 };
  byte colPins[COLS] = { 17, 18, 19 }; 
  Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );//objek keypad
  unsigned int RX1, RX2, RX3, RX4, RX5;
  unsigned int RY1, RY2, RY3, RY4, RY5;
  unsigned long T1, T2, T3, T4, T5, T6, T7;
  void setup() {
    setupku();
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent);
  }
  
  void loop() {
    //bagian input
    //bagian proses
    tombolku = keypad.getKey();   
    if(tombolku) Serial.println(tombolku);
    in(RX1); timerOn(T1, 2000); out(RY1);
    in(RX2); timerOff(T2,3000); out(RY2);
    in(RX3); timerPulse(T3,4000); out(RY3);
    in(RX4); timerCycle(T4,200,T5,100); out(RY4);
    in(RX5); RTO(T6, 5000, T7); out(RY5);
    
    //bagian output
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);    
    in(RY3); outNot(Y3);  
    in(RY4); outNot(Y4);
    in(RY5); outNot(Y5);
  }
  
  void keypadEvent(KeypadEvent tombolku){
    switch (keypad.getState()){
    case PRESSED: //sisi naik pulsa, saat tombol ditekan
    if (tombolku == '1') RX1=1;
    if (tombolku == '2') RX2=1;
    if (tombolku == '3') RX3=1;
    if (tombolku == '4') RX4=1;
    if (tombolku == '5') RX5=1;
    break;

    case RELEASED: //sisi turun pulsa, saat tombol dilepas
    if (tombolku == '1') RX1=0;
    if (tombolku == '2') RX2=0;
    if (tombolku == '3') RX3=0;
    if (tombolku == '4') RX4=0;
    if (tombolku == '5') RX5=0;     
    break;
    }
}
  

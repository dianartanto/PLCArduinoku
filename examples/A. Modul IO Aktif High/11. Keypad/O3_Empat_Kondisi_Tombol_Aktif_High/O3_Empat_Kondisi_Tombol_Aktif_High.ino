/*
  Program berikut ini membaca 4 kondisi tombol, yaitu:
  1. Tombol ditekan 
  2. Saat tombol ditekan (sisi naik pulsa)
  3. Saat tombol sedang ditekan 
  4. Saat tombol dilepas (sisi turun pulsa)
  
  Untuk melihat perbedaan di antaranya, jalankan program berikut ini.
  
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
  unsigned int RY1, RY2, RY3, RY4;
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
    if(tombolku=='1') RY1=1;
    if(tombolku=='5') RY1=0;
    
    //bagian output
    in(RY1); out(Y1);
    in(RY2); out(Y2);    
    in(RY3); out(Y3);  
    in(RY4); out(Y4);
  }
  
  void keypadEvent(KeypadEvent tombolku){
    switch (keypad.getState()){
    case PRESSED: //sisi naik pulsa, saat tombol ditekan
    if (tombolku == '2') RY2=1;
    if (tombolku == '6') RY2=0;
        break;

    case HOLD: //saat tombol sedang ditekan lama
    if (tombolku == '3') RY3=1;
    if (tombolku == '7') RY3=0;
         break;

    case RELEASED: //sisi turun pulsa, saat tombol dilepas
    if (tombolku == '4') RY4=1;
    if (tombolku == '8') RY4=0;
        break;
    }
}
  

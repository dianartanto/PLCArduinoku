/*
  Program berikut ini membaca 4 kondisi tombol, yaitu:
  1. Tombol ditekan 
  2. Saat tombol ditekan (sisi naik pulsa)
  3. Saat tombol sedang ditekan 
  4. Saat tombol dilepas (sisi turun pulsa)
  
  Untuk melihat perbedaan di antaranya, jalan program berikut ini.
  
  Catatan: program berikut ini menganggap rangkaian IO Aktif High.
  Untuk penggunaan rangkaian IO Aktif Low, maka aktifkan program untuk IO Aktif Low di bawah,
  dengan membuka tanda comment out pada program IO Aktif Low, dan 
  sebaliknya memberi tanda comment out pada program IO Aktif High
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
  
  void setup() {
    setupku();
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
  }
  void loop() {
    tombolku = keypad.getKey();   
    if (tombolku) {
      Serial.println(tombolku);
    }
    if(tombolku=='1') digitalWrite(2,HIGH);
    if(tombolku=='5') digitalWrite(2,LOW);

  }
  void keypadEvent(KeypadEvent tombolku){
    switch (keypad.getState()){
    case PRESSED: //sisi naik pulsa, saat tombol ditekan
        if (tombolku == '2') digitalWrite(3,HIGH);
        if (tombolku == '6') digitalWrite(3,LOW);
        break;

    case HOLD: //saat tombol sedang ditekan lama
        if (tombolku == '3') digitalWrite(4,HIGH);
        if (tombolku == '7') digitalWrite(4,LOW);
        break;

    case RELEASED: //sisi turun pulsa, saat tombol dilepas
        if (tombolku == '4') digitalWrite(5,HIGH);
        if (tombolku == '8') digitalWrite(5,LOW);
        break;
    }
}
  

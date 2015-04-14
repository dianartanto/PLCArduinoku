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
    if(tombolku) Serial.println(tombolku);
 //   if(tombolku=='1') reset(Y1);
 //   if(tombolku=='5') set(Y1);
    if(tombolku=='1') digitalWrite(2,LOW);
    if(tombolku=='5') digitalWrite(2,HIGH);
 
  }
  
  void keypadEvent(KeypadEvent tombolku){
    switch (keypad.getState()){
    case PRESSED: //sisi naik pulsa, saat tombol ditekan
 //       if (tombolku == '2') reset(Y2);
 //       if (tombolku == '6') set(Y2);
    if(tombolku=='2') digitalWrite(3,LOW);
    if(tombolku=='6') digitalWrite(3,HIGH);
        break;

    case HOLD: //saat tombol sedang ditekan lama
 //       if (tombolku == '3') reset(Y3);
 //       if (tombolku == '7') set(Y3);
    if(tombolku=='3') digitalWrite(4,LOW);
    if(tombolku=='7') digitalWrite(4,HIGH);
 
        break;

    case RELEASED: //sisi turun pulsa, saat tombol dilepas
 //       if (tombolku == '4') reset(Y4);
 //       if (tombolku == '8') set(Y4);
    if(tombolku=='4') digitalWrite(5,LOW);
    if(tombolku=='8') digitalWrite(5,HIGH);
 
        break;
    }
}
  

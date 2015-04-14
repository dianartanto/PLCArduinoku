/*
  Sesuai tujuannya, seharusnya tombol-tombol di Keypad
  bisa bekerja menggantikan tombol input biasa yang sudah ada. 
  
  Hanya saja, tombol-tombol di Keypad ternyata menghasilkan sinyal
  aktif yang sesaat, seperti pulsa denyut, yang mengabaikan berapa lama
  tombol tersebut ditekan. Berbeda dengan tombol biasa, yang akan
  memberikan sinyal aktifnya selama tombol ditekan.
  
  Untuk mengatasi nilai input tombol yang hanya sesaat tersebut,
  maka perlu sebuah instruksi untuk mengunci sinyal keluaran dari Keypad tersebut,
  seperti contoh program Latch berikut:
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
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  
  void setup() {
    setupku();
    Serial.begin(9600);
  }
  void loop() {
    tombolku = kpd.getKey();   
    if(tombolku=='1') set(Y1);
    if(tombolku=='2') reset(Y1);
    
    if(tombolku=='3') set(Y2);
    if(tombolku=='4') reset(Y2);
    
    if(tombolku=='5') set(Y3);
    if(tombolku=='6') reset(Y3);
    
    if(tombolku=='7') set(Y4);
    if(tombolku=='8') reset(Y4);
    
    Serial.println(tombolku);
  }

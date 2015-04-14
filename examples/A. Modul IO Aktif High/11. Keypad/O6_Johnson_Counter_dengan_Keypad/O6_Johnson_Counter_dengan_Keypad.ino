/*
  Program berikut ini menerapkan Counter Circular dengan tombol Keypad.
  Perhatikan bahwa dengan Keypad tidak diperlukan timerOn untuk Debouncing,
  karena ketika tombol Keypad ditekan selalu hanya menghasilkan satu karakter.
  
  Perhatikan juga reset Counter tidak memerlukan timerOff,
  karena perubahan nilai input yang cukup singkat, 
  lebih singkat dari instruksi clear counter, 
  sehingga counter belum sempat mencacah naik
 
  Catatan: program berikut ini menganggap rangkaian IO Aktif High.
  Untuk penggunaan rangkaian IO Aktif Low, maka tinggal mengubah instruksi set menjadi reset
  dan sebaliknya reset menjadi set.
  */
  #include <Keypad.h>  
  #include <PLCArduinoku.h>
Shift SF1(0x0001);      
unsigned long T1, T2;
unsigned int R1, RX1, RX2, RY1, RY2, RY3, RY4;
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
  }
  
  void loop() {
    tombolku=keypad.getKey();
    if(tombolku) {
      Serial.print(tombolku);
      Serial.print(',');
      Serial.println(SF1.value(),BIN);}
  SF1.bitValue(3); outNot(R1);   
  in(R1); SF1.inputBit();
  if(tombolku=='1') RX1=1;
  else RX1=0;
  in(RX1);  SF1.shiftLeft();   
  if(tombolku=='2') RX2=1;
  else RX2=0;  
  in(RX2);  SF1.reset();
  SF1.bitValue(3); out(RY4);
  SF1.bitValue(2); out(RY3);
  SF1.bitValue(1); out(RY2);
  SF1.bitValue(0); out(RY1);
  //bagian output
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);    
    in(RY3); outNot(Y3);  
    in(RY4); outNot(Y4); 
 }


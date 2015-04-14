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
  Counter C1(4);
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
  unsigned int RX1, RX2, RX3, RY1, RY2, RY3, RY4;
  unsigned int R1=0;
  unsigned int R2=1;
  unsigned int R3=2;
  unsigned int R4=3;
  unsigned long T1, T2;
  void setup() {
    setupku();
    Serial.begin(9600);
  }
  
  void loop() {
    tombolku=keypad.getKey();
    if(tombolku) {
      Serial.print(tombolku);
      Serial.print(',');
      Serial.println(C1.count());}

    if(tombolku=='1') RX1=1;
    else RX1=0;
    in(RX1); C1.countUp();           
    if(tombolku=='2') RX2=1;
    else RX2=0;   
    in(RX2); C1.countDown(); 
    if(tombolku=='3') RX3=1;
    else RX3=0;   
    in(RX3); C1.clear();    
    C1.upperQ(); C1.clear(); 
  
    inAnalog(C1.count()); compareEQ(R1); out(RY1);
    inAnalog(C1.count()); compareEQ(R2); out(RY2);
    inAnalog(C1.count()); compareEQ(R3); out(RY3);
    inAnalog(C1.count()); compareEQ(R4); out(RY4);

    //bagian output
    in(RY1); outNot(Y1);
    in(RY2); outNot(Y2);    
    in(RY3); outNot(Y3);  
    in(RY4); outNot(Y4);   
 }
  

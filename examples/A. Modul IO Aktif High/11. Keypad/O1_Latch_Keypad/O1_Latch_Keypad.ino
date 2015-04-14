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
  //L1-A0, L2-A1, L3-A2, R1-A3, R2-A4, R3-A5
  byte rowPins[ROWS] = { 14, 15, 16 };
  byte colPins[COLS] = { 17, 18, 19 }; 
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
  
  void setup() {
    setupku();
    Serial.begin(9600);
  }
  void loop() {
    tombolku = kpd.getKey();   
    Serial.println(tombolku);
    delay(100);
  }

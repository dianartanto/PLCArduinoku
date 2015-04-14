/*
1.Rangkaian:
  Modul Input Output Aktif Low.
  Kaki Input Analog  : A4, A5 (kaki A4 dan A5 Arduino)
  Kaki Output Analog : Y6, Y9 (kaki PWM: D6 dan D9 Arduino)
  Alat Input Analog  : Potensio 2x
  Alat Output Analog : LED 2x

2.Program:
                             A4        
 1 ||--------------------{READ ADC}----||
   ||          {DIV  Y6  :=}           ||
 2 ||----------{ A4 / 4    }-----------||
   ||                        Y6        ||
 3 ||------------------{PWM 1.00 kHz}--||
   ||                        A5        ||
 4 ||--------------------{READ ADC}----||
   ||          {DIV  Y9  :=}           ||
 5 ||----------{ A5 / 4    }-----------||
   ||                        Y9        ||
 6 ||------------------{PWM 1.00 kHz}--||
   
  Ketika potensio di kaki A4 diputar knobnya,  
  maka LED di kaki D6 akan berubah intensitas cahayanya 
  Begitu pula ketika potensio di kaki A5 diputar knobnya,  
  maka LED di kaki D9 akan berubah intensitas cahayanya 
*/
#include<PLCArduinoku.h>
void setup() {
  setupku();
  outHigh();
}

void loop() {
  inAnalog(A4);    
  outPWM(Y6);   
  inAnalog(A5);    
  outPWM(Y9);
}

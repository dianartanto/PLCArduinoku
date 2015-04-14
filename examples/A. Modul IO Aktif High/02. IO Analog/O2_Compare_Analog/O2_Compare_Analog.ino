/*
1.Rangkaian:
  Modul Input Output Aktif High.
  Kaki Input Analog : A4, A5 (kaki A4 dan A5 Arduino)
  Kaki Output Digital : Y1, Y2, Y3 (kaki D2, D3 dan D4 Arduino)
  Alat Input Analog : Potensio 2x
  Alat Output Digital : LED 3x

2.Program:
                             A1        
 1 ||--------------------{READ ADC}----||
   ||                        A2        ||
   ||--------------------{READ ADC}----||
   ||     [A1 >]             Y1        ||
 2 ||-----[ A2 ]-------------( )-------||
   ||     [A1 ==]            Y2        ||
   ||-----[ A2  ]------------( )-------||
   ||     [A1 <]             Y3        ||
   ||-----[ A2 ]-------------( )-------||

  Ketika nilai tegangan analog di A4 > di A5, Rele 1 hidup,
  ketika nilai tegangan analog di A4 = di A5, Rele 2 hidup,
  ketika nilai tegangan analog di A4 < di A5, Rele 3 hidup.
*/
#include<PLCArduinoku.h>
void setup() {
  setupku();
  outLow();
  Serial.begin(9600);
}

void loop() {
  inAnalog(A4);    
  compareGT(A5);    
  out(Y1);
  inAnalog(A4);    
  compareEQ(A5);    
  out(Y2);
  inAnalog(A4);    
  compareLT(A5);    
  out(Y3);
  Serial.print(analogRead(A4));
  Serial.print(',');
  Serial.println(analogRead(A5));
}

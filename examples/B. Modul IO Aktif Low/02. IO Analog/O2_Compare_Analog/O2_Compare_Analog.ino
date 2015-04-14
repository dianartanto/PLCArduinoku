/*
1.Rangkaian:
  Modul Input Output Aktif Low.
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
unsigned int RY1, RY2, RY3;
void setup() {
  setupku();
  outHigh();
  Serial.begin(9600);
}

void loop() {
  //bagian proses
  inAnalog(A4);    
  compareGT(A5);    
  out(RY1);
  inAnalog(A4);    
  compareEQ(A5);    
  out(RY2);
  inAnalog(A4);    
  compareLT(A5);    
  out(RY3);
  
  //bagian output
  in(RY1); outNot(Y1);
  in(RY2); outNot(Y2);
  in(RY3); outNot(Y3);
  Serial.print(analogRead(A4));
  Serial.print(',');
  Serial.println(analogRead(A5));
}

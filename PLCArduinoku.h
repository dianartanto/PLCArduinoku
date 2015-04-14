/*
  Library ini disalin dari plcLib Versi 1.0, oleh W. Ditch,
  dengan sedikit penambahan, dan diupdate terakhir tgl 20 maret 2015.
  Lebih jauh mengenai plcLib, dapat dilihat di www.electronics-micros.com

*/

#ifndef PLCArduinoku_h
#define PLCArduinoku_h
#include "Arduino.h"

// Penugasan kaki IO
const int X1 = 14;
const int X2 = 15;
const int X3 = 16;
const int X4 = 17;
const int X5 = 18;
const int X6 = 19;
const int Y1 = 2;
const int Y2 = 3;
const int Y3 = 4;
const int Y4 = 5;
const int Y5 = 6;
const int Y6 = 7;
const int Y7 = 8;
const int Y8 = 9;
const int Y9 = 10;
const int Y10 = 11;
const int Y11 = 12;
const int Y12 = 13;

void setupku();
void outHigh();
void outLow();
unsigned int osf(int input,unsigned int &dulu);
unsigned int osf(unsigned int input,unsigned int &dulu);
unsigned int osf(unsigned long input,unsigned long &dulu);
unsigned int osr(int input,unsigned int &dulu);
unsigned int osr(unsigned int input,unsigned int &dulu);
unsigned int osr(unsigned long input,unsigned long &dulu);
unsigned int in(int input);
unsigned int in(unsigned int input);
unsigned int in(unsigned long input);
unsigned int inNot(int input);
unsigned int inNot(unsigned int input);
unsigned int inNot(unsigned long input);
unsigned int inAnalog(int input);
unsigned int inAnalog(unsigned int input);
unsigned int inAnalog(unsigned long input);
unsigned int out(int output);
unsigned int out(unsigned int &output);
unsigned int out(unsigned long &output);
unsigned int outNot(int output);
unsigned int outNot(unsigned int &output);
unsigned int outNot(unsigned long &output);
unsigned int outPWM(int output);
unsigned int andBit(int input);
unsigned int andBit(unsigned int input);
unsigned int andBit(unsigned long input);
unsigned int andNotBit(int input);
unsigned int andNotBit(unsigned int input);
unsigned int andNotBit(unsigned long input);
unsigned int orBit(int input);
unsigned int orBit(unsigned int input);
unsigned int orBit(unsigned long input);
unsigned int orNotBit(int input);
unsigned int orNotBit(unsigned int input);
unsigned int orNotBit(unsigned long input);
unsigned int xorBit(int input);
unsigned int xorBit(unsigned int input);
unsigned int xorBit(unsigned long input);
unsigned int latch(int output, int reset);
unsigned int latch(int output, unsigned int reset);
unsigned int latch(int output, unsigned long reset);
unsigned int latch(unsigned int &output, int reset);
unsigned int latch(unsigned long &output, int reset);
unsigned int latch(unsigned int &output, unsigned int reset);
unsigned int latch(unsigned long &output, unsigned long reset);
unsigned int timerOn(unsigned long &timerState, unsigned long timerPeriod);
unsigned int RTO(unsigned long &timerState, unsigned long timerPeriod, unsigned long &simpan);
unsigned int timerPulse(unsigned long &timerState, unsigned long timerPeriod);
unsigned int timerOff(unsigned long &timerState, unsigned long timerPeriod);
unsigned int timerCycle(unsigned long &timer1State, unsigned long timer1Period, unsigned long &timer2State, unsigned long timer2Period);
unsigned int compareGT(int input);
unsigned int compareGT(unsigned int input);
unsigned int compareGT(unsigned long input);
unsigned int compareLT(int input);
unsigned int compareLT(unsigned int input);
unsigned int compareLT(unsigned long input);
unsigned int compareEQ(int input);
unsigned int compareEQ(unsigned int input);
unsigned int compareEQ(unsigned long input);
unsigned int set(int output);
unsigned int set(unsigned int &output);
unsigned int set(unsigned long &output);
unsigned int reset(int output);
unsigned int reset(unsigned int &output);
unsigned int reset(unsigned long &output);

class Counter
{
  public:
    Counter(unsigned int presetValue);
    Counter(unsigned int presetValue, unsigned int direction);
    void countUp();
    void countDown();
    void preset();
    void clear();
    unsigned int upperQ();
    unsigned int lowerQ();
    unsigned int count();
    unsigned int presetValue();
  private:
    unsigned int _pv;
    unsigned int _ct;
    unsigned int _ctUpEdge;
    unsigned int _ctDownEdge;
    unsigned int _uQ;
    unsigned int _lQ;
};

class Shift
{
  public:
    Shift();
	Shift(unsigned int sreg);
	unsigned int bitValue(unsigned int bitno);
	unsigned int value();
	void reset();
	void inputBit();
	void shiftLeft();
	void shiftRight();
  private:
    unsigned int _srLeftEdge;
    unsigned int _srRightEdge;
	unsigned int _sreg;
	unsigned int _inbit;
};

class Stack
{
  public:
    Stack();
	void push();
	void pop();
	void orBlock();
	void andBlock();
  private:
	unsigned long _sreg;
};

#endif

/*
  Library ini disalin dari plcLib Versi 1.0, oleh W. Ditch,
  dengan sedikit penambahan, dan diupdate terakhir tgl 20 maret 2015.
  Lebih jauh mengenai plcLib, dapat dilihat di www.electronics-micros.com

*/

#include "Arduino.h"
#include "PLCArduinoku.h"
extern unsigned int scanValue = 0;
void setupku(){
	pinMode(X1,INPUT);
	pinMode(X2,INPUT);
	pinMode(X3,INPUT);
	pinMode(X4,INPUT);
	pinMode(X5,INPUT);
	pinMode(X6,INPUT);
	pinMode(Y1,OUTPUT);
	pinMode(Y2,OUTPUT);
	pinMode(Y3,OUTPUT);
	pinMode(Y4,OUTPUT);
	pinMode(Y5,OUTPUT);
	pinMode(Y6,OUTPUT);
	pinMode(Y7,OUTPUT);
	pinMode(Y8,OUTPUT);
	pinMode(Y9,OUTPUT);
	pinMode(Y10,OUTPUT);
	pinMode(Y11,OUTPUT);
	pinMode(Y12,OUTPUT);
}

void outHigh(){
	digitalWrite(Y1,HIGH);
	digitalWrite(Y2,HIGH);
	digitalWrite(Y3,HIGH);
	digitalWrite(Y4,HIGH);
	digitalWrite(Y5,HIGH);
	digitalWrite(Y6,HIGH);
	digitalWrite(Y7,HIGH);
	digitalWrite(Y8,HIGH);
	digitalWrite(Y9,HIGH);
	digitalWrite(Y10,HIGH);
	digitalWrite(Y11,HIGH);
	digitalWrite(Y12,HIGH);
}

void outLow(){
	digitalWrite(Y1,LOW);
	digitalWrite(Y2,LOW);
	digitalWrite(Y3,LOW);
	digitalWrite(Y4,LOW);
	digitalWrite(Y5,LOW);
	digitalWrite(Y6,LOW);
	digitalWrite(Y7,LOW);
	digitalWrite(Y8,LOW);
	digitalWrite(Y9,LOW);
	digitalWrite(Y10,LOW);
	digitalWrite(Y11,LOW);
	digitalWrite(Y12,LOW);
}

// OSF an input pin (pin number supplied as integer)
unsigned int osf(int input,unsigned int &dulu) {
	if(digitalRead(input) != dulu & digitalRead(input)==0) {scanValue=1;}
	else {scanValue=0;}
	dulu=digitalRead(input);
	return(scanValue);
}

// OSF an auxiliary input (variable supplied as unsigned integer)
unsigned int osf(unsigned int input,unsigned int &dulu) {
	if(input != dulu & input==0) {scanValue=1;}
	else {scanValue=0;}
	dulu=input;
	return(scanValue);
}


// OSF an auxiliary input (variable supplied as unsigned long)
unsigned int osf(unsigned long input,unsigned int &dulu) {
	if(input != dulu & input==0) {scanValue=1;}
	else {scanValue=0;}
	dulu=input;
	return(scanValue);
}

// OSR an input pin (pin number supplied as integer)
unsigned int osr(int input,unsigned int &dulu) {
	if(digitalRead(input) != dulu & digitalRead(input)==1) {scanValue=1;}
	else {scanValue=0;}
	dulu=digitalRead(input);
	return(scanValue);
}

// OSR an auxiliary input (variable supplied as unsigned integer)
unsigned int osr(unsigned int input,unsigned int &dulu) {
	if(input != dulu & input==1) {scanValue=1;}
	else {scanValue=0;}
	dulu=input;
	return(scanValue);
}


// OSR an auxiliary input (variable supplied as unsigned long)
unsigned int osr(unsigned long input,unsigned int &dulu) {
	if(input != dulu & input==1) {scanValue=1;}
	else {scanValue=0;}
	dulu=input;
	return(scanValue);
}

// Read an input pin (pin number supplied as integer)
unsigned int in(int input) {
	scanValue = digitalRead(input);
	return(scanValue);
}

// Read an auxiliary input (variable supplied as unsigned integer)
unsigned int in(unsigned int input) {
	scanValue = input;
	return(scanValue);
}

// Read an auxiliary input (variable supplied as unsigned long)
unsigned int in(unsigned long input) {
	scanValue = input;
	return(scanValue);
}

// Read an inverted input (pin number supplied as integer)
unsigned int inNot(int input) {
	if (digitalRead(input) == 1) {
		scanValue = 0;
	}
	else {
		scanValue = 1;
	}
	return(scanValue);
}

// Read an inverted auxiliary input (variable supplied as unsigned integer)
unsigned int inNot(unsigned int input) {
	if (input == 1) {
		scanValue = 0;
	}
	else {
		scanValue = 1;
	}
	return(scanValue);
}

// Read an inverted auxiliary input (variable supplied as unsigned long)
unsigned int inNot(unsigned long input) {
	if (input == 1) {
		scanValue = 0;
	}
	else {
		scanValue = 1;
	}
	return(scanValue);
}

// Read an analogue input (input pin supplied as an integer)
unsigned int inAnalog(int input) {
	scanValue = analogRead(input);
	return(scanValue);
}

// Read an analogue auxiliary value (variable supplied as an unsigned integer)
unsigned int inAnalog(unsigned int input) {
	scanValue = input;
	return(scanValue);
}

// Read an analogue auxiliary value (variable supplied as an unsigned long)
unsigned int inAnalog(unsigned long input) {
	scanValue = input;
	return(scanValue);
}

// Output to an output pin
unsigned int out(int output) {
	if (scanValue == 1) {
		digitalWrite(output, HIGH);
	}
	else {
		digitalWrite(output, LOW);
	}
	return(scanValue);
}

// Output to an auxiliary variable (variable type = unsigned integer)
unsigned int out(unsigned int &output) {
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

// Output to an auxiliary variable (variable type = unsigned long)
unsigned int out(unsigned long &output) {
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

// Output to an output pin (inverted)
unsigned int outNot(int output) {
	if (scanValue == 1) {
		digitalWrite(output, LOW);
	}
	else {
		digitalWrite(output, HIGH);
	}
	return(scanValue);
}

// Output to an auxiliary variable (inverted) (variable type = unsigned integer)
unsigned int outNot(unsigned int &output) {
	if (scanValue == 1) {
		output = 0;
	}
	else {
		output = 1;
	}
	return(scanValue);
}

// Output to an auxiliary variable (inverted) (variable type = unsigned long)
unsigned int outNot(unsigned long &output) {
	if (scanValue == 1) {
		output = 0;
	}
	else {
		output = 1;
	}
	return(scanValue);
}

// Output a PWM value to an output pin (scanValue in range 0-1023)
unsigned int outPWM(int output) {
	analogWrite(output, scanValue / 4);
	return(scanValue);
}

// AND scanValue with input (pin number supplied as integer)
unsigned int andBit(int input) {
	scanValue = scanValue & digitalRead(input);
	return(scanValue);
}

// AND scanValue with auxiliary variable (variable supplied as unsigned integer)
unsigned int andBit(unsigned int input) {
	scanValue = scanValue & input;
	return(scanValue);
}

// AND scanValue with auxiliary variable (variable supplied as unsigned long)
unsigned int andBit(unsigned long input) {
	scanValue = scanValue & input;
	return(scanValue);
}

// AND scanValue with inverted input (pin number supplied as integer)
unsigned int andNotBit(int input) {
	scanValue = scanValue & ~digitalRead(input);
	return(scanValue);
}

// AND scanValue with inverted auxiliary variable (variable supplied as unsigned integer)
unsigned int andNotBit(unsigned int input) {
	scanValue = scanValue & ~input;
	return(scanValue);
}

// AND scanValue with inverted auxiliary variable (variable supplied as unsigned long)
unsigned int andNotBit(unsigned long input) {
	scanValue = scanValue & ~input;
	return(scanValue);
}

// OR scanValue with input (pin number supplied as integer)
unsigned int orBit(int input) {
	scanValue = scanValue | digitalRead(input);
	return(scanValue);
}

// OR scanValue with auxiliary variable (variable supplied as unsigned integer)
unsigned int orBit(unsigned int input) {
	scanValue = scanValue | input;
	return(scanValue);
}

// OR scanValue with auxiliary variable (variable supplied as unsigned long)
unsigned int orBit(unsigned long input) {
	scanValue = scanValue | input;
	return(scanValue);
}

// OR scanValue with inverted input (pin number supplied as integer)
unsigned int orNotBit(int input) {
	if (scanValue == 1) {
	}
	else {
		if (digitalRead(input) == 0) {
			scanValue = 1;
		}
		else {
			scanValue = 0;
		}
	}
	return(scanValue);
}

// OR scanValue with inverted auxiliary variable (variable supplied as unsigned integer)
unsigned int orNotBit(unsigned int input) {
	if (scanValue == 1) {
	}
	else {
		if (input == 0) {
			scanValue = 1;
		}
		else {
			scanValue = 0;
		}
	}
	return(scanValue);
}

// OR scanValue with inverted auxiliary variable (variable supplied as unsigned long)
unsigned int orNotBit(unsigned long input) {
	if (scanValue == 1) {
	}
	else {
		if (input == 0) {
			scanValue = 1;
		}
		else {
			scanValue = 0;
		}
	}
	return(scanValue);
}

// XOR scanValue with input (pin number supplied as integer)
unsigned int xorBit(int input) {
	scanValue = scanValue ^ digitalRead(input);
	return(scanValue);
}

// XOR scanValue with auxiliary variable (variable supplied as unsigned integer)
unsigned int xorBit(unsigned int input) {
	scanValue = scanValue ^ input;
	return(scanValue);
}

// XOR scanValue with auxiliary variable (variable supplied as unsigned long)
unsigned int xorBit(unsigned long input) {
	scanValue = scanValue ^ input;
	return(scanValue);
}

// Set - Reset latch (output and reset pin numbers supplied as integers)
unsigned int latch(int output, int reset) {
	scanValue = scanValue | digitalRead(output);		// Self latch by ORing with Output pin (Q)
	scanValue = scanValue & ~digitalRead(reset);		// AND-Not with Reset Pin
	if (scanValue == 1) {
		digitalWrite(output, HIGH);
	}
	else {
		digitalWrite(output, LOW);
	}
	return(scanValue);
}

// Set - Reset latch (output pin number supplied as integer, reset as unsigned integer variable)
unsigned int latch(int output, unsigned int reset) {
	scanValue = scanValue | digitalRead(output);		// Self latch by ORing with Output pin (Q)
	scanValue = scanValue & ~reset;						// AND-Not with Reset variable
	if (scanValue == 1) {
		digitalWrite(output, HIGH);
	}
	else {
		digitalWrite(output, LOW);
	}
	return(scanValue);
}

// Set - Reset latch (output pin number supplied as integer, reset as unsigned long variable)
unsigned int latch(int output, unsigned long reset) {
	scanValue = scanValue | digitalRead(output);		// Self latch by ORing with Output pin (Q)
	scanValue = scanValue & ~reset;						// AND-Not with Reset variable
	if (scanValue == 1) {
		digitalWrite(output, HIGH);
	}
	else {
		digitalWrite(output, LOW);
	}
	return(scanValue);
}

// Set - Reset latch (output as unsigned integer variable and reset pin as integer)
unsigned int latch(unsigned int &output, int reset) {
	scanValue = scanValue | output;						// Self latch by ORing with Output pin (Q)
	scanValue = scanValue & ~digitalRead(reset);		// AND-Not with Reset Pin
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

// Set - Reset latch (output as unsigned long variable and reset pin as integer)
unsigned int latch(unsigned long &output, int reset) {
	scanValue = scanValue | output;						// Self latch by ORing with Output pin (Q)
	scanValue = scanValue & ~digitalRead(reset);		// AND-Not with Reset Pin
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

// Set - Reset latch (output and reset values are unsigned integer auxiliary variables)
unsigned int latch(unsigned int &output, unsigned int reset) {
	scanValue = scanValue | output;				// Self latch by ORing with Output variable (Q)
	scanValue = scanValue & ~reset;				// AND-Not with Reset variable
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

// Set - Reset latch (output and reset values are unsigned long auxiliary variables)
unsigned int latch(unsigned long &output, unsigned long reset) {
	scanValue = scanValue | output;				// Self latch by ORing with Output variable (Q)
	scanValue = scanValue & ~reset;				// AND-Not with Reset variable
	if (scanValue == 1) {
		output = 1;
	}
	else {
		output = 0;
	}
	return(scanValue);
}

unsigned int timerOn(unsigned long &timerState, unsigned long timerPeriod) {
	if (scanValue == 0) {					// timer is disabled
		timerState = 0;					// Clear timerState (0 = 'not started')
	}
	else {							// Timer is enabled
		if (timerState == 0) {				// Timer hasn't started counting yet
			timerState = millis();			// Set timerState to current time in milliseconds
			scanValue = 0;				// Result = 'not finished' (0)
		}
		else {						// Timer is active and counting
			if (millis() > (timerState + timerPeriod)) {	// Timer has finished
				scanValue = 1;			// Result = 'finished' (1)
			}
			else {					// Timer has not finished
				scanValue = 0;			// Result = 'not finished' (0)
			}
		}
	}
	return(scanValue);					// Return result (1 = 'finished',
								// 0 = 'not started' / 'not finished')
}

unsigned int RTO(unsigned long &timerState, unsigned long timerPeriod, unsigned long &simpan) {
	if (scanValue == 0) {					// timer is disabled
		timerState = 0;					// Clear timerState (0 = 'not started')
	}
	else {							// Timer is enabled
		if (timerState == 0) {				// Timer hasn't started counting yet
			timerState = millis()-simpan;		// timerState akan diisi nilai millis yang dikurangi dengan simpan
			scanValue = 0;				// Result = 'not finished' (0)
		}
		else {						// Timer is active and counting
			if (millis() > (timerState + timerPeriod)) {	// Timer has finished
				scanValue = 1;			// Result = 'finished' (1)
				simpan=0;			// begitu akumulasi tercapai, maka simpan dinolkan
			}
			else {					// Timer has not finished
				simpan=millis()-timerState;	// variable simpan menyimpan waktu yang telah habis
				scanValue = 0;			// Result = 'not finished' (0)
			}
		}
	}
	return(scanValue);					// Return result (1 = 'finished',
								// 0 = 'not started' / 'not finished')
}

unsigned int timerPulse(unsigned long &timerState, unsigned long timerPeriod) {
	if (scanValue == 0 & timerState == 0) {					// timer is either not triggered or finished
		timerState = 0;										// Clear timerState (0 = 'not started')
	}
	else {													// Timer is enabled
		if (timerState == 0) {								// Timer hasn't started counting yet
			timerState = millis();							// Set timerState to current time in milliseconds
			scanValue = 0;									// Result = 'not finished' (0)
		}
		else {												// Timer is active and counting
			if (millis() > (timerState + timerPeriod)) {	// Timer has finished
				scanValue = 0;								// Pulse = 'finished' (0)
				timerState = 0;
			}
			else {											// Timer has not finished
				scanValue = 1;								// Pulse = 'Active' (1)
			}
		}
	}
	return(scanValue);										// Return result (1 = 'finished',
															// 0 = 'not started' / 'not finished')
}

unsigned int timerOff(unsigned long &timerState, unsigned long timerPeriod) {
	if (scanValue == 0) {									// Timer input is off (scanValue = 0)
		if (timerState == 0) {								// Timer is not started so do nothing
		}
		else {												// Timer is active and counting
			if (millis() > (timerState + timerPeriod)) {	// Timer has finished
				scanValue = 0;								// Result = 'turn-off delay finished' (0)
			}
			else {											// Timer has not finished
				scanValue = 1;								// Result = 'turn-off delay not finished' (1)
			}
		}
	}
	else {													// Timer input is high (scanValue = 1)
		timerState = millis();								// Set timerState to current time in milliseconds
	}
	return(scanValue);										// Return result (1 = 'pulse On' / 'turn-off delay in progress',
															// 0 = 'not started' / 'finished')
}

unsigned int timerCycle(unsigned long &timer1State, unsigned long timer1Period, unsigned long &timer2State, unsigned long timer2Period) {
	if (scanValue == 0) {									// Enable input is off (scanValue = 0)
		timer2State = 0;									// Ready to start LOW pulse period when enabled
		timer1State = 1;
	}
	else {													// Enabled
		if (timer2State == 0) {								// Low pulse Active
			if (timer1State == 1) {							// LOW pulse period starting
				timer1State = millis();						// Set timerState to current time in milliseconds
			}
			else if (millis() > (timer1State + timer1Period)) {	// Low pulse period has finished
				timer1State = 0;	
				timer2State = 1;							// Ready to start HIGH pulse period
			}
			scanValue = 0;									// Result = 'Pulse LOW' (0)
		}
		if (timer1State == 0) {								// High pulse Active
			if (timer2State == 1) {							// HIGH pulse period starting
				timer2State = millis();						// Set timerState to current time in milliseconds
			}
			else if (millis() > (timer2State + timer2Period)) {	// High pulse has finished
				timer2State = 0;	
				timer1State = 1;							// Ready to start LOW pulse period
			}
			scanValue = 1;									// Result = 'Pulse HIGH' (1)
		}
	}
	return(scanValue);
}

// Test whether an analogue input is greater than a second analogue input
unsigned int compareGT(int input) {
	if (scanValue > analogRead(input)) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is greater than a fixed unsigned int value
unsigned int compareGT(unsigned int input) {
	if (scanValue > input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is greater than a fixed unsigned long value
unsigned int compareGT(unsigned long input) {
	if (scanValue > input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is less than a second analogue input
unsigned int compareLT(int input) {
	if (scanValue < analogRead(input)) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is less than a fixed unsigned int value
unsigned int compareLT(unsigned int input) {
	if (scanValue < input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is less than a fixed unsigned long value
unsigned int compareLT(unsigned long input) {
	if (scanValue < input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is equal with a second analogue input
unsigned int compareEQ(int input) {
	if (scanValue  == analogRead(input)) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is equal with a fixed unsigned int value
unsigned int compareEQ(unsigned int input) {
	if (scanValue == input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}

// Test whether an analogue input is equal with a fixed unsigned long value
unsigned int compareEQ(unsigned long input) {
	if (scanValue == input) {
		scanValue = 1;
	}
	else {
		scanValue = 0;
	}
	return(scanValue);
}


// Set a latched output (output pin number supplied as integer)
unsigned int set(int output) {
	scanValue = scanValue | digitalRead(output);		// Self latch by ORing with Output pin
	if (scanValue == 1) {
		digitalWrite(output, HIGH);
	}
	return(scanValue);
}

// Set a latched output (variable supplied as unsigned integer)
unsigned int set(unsigned int &output) {
	scanValue = scanValue | output;		// Self latch by ORing with Output pin
	if (scanValue == 1) {
		output = 1;
	}
	return(scanValue);
}

// Set a latched output (variable supplied as unsigned long)
unsigned int set(unsigned long &output) {
	scanValue = scanValue | output;		// Self latch by ORing with Output pin
	if (scanValue == 1) {
		output = 1;
	}
	return(scanValue);
}

// reset (or clear) a latched output (output pin number supplied as integer)
unsigned int reset(int output) {
	if (scanValue == 1) {
		digitalWrite(output, LOW);
	}
	return(scanValue);
}

// reset (or clear) a latched output (variable supplied as unsigned integer)
unsigned int reset(unsigned int &output) {
	if (scanValue == 1) {
		output = 0;
	}
	return(scanValue);
}

// reset (or clear) a latched output (variable supplied as unsigned long)
unsigned int reset(unsigned long &output) {
	if (scanValue == 1) {
		output = 0;
	}
	return(scanValue);
}

// Up, down, or up-down counter
Counter::Counter(unsigned int pv)	// Counter constructor method
{									// (Default values are for an up counter)
	_pv = pv;						// Set preset value using supplied parameter
	_ct = 0;						// Running count = zero
	_uQ = 0;						// Up counter upper Q output = 0
	_lQ = 1;						// Down counter lower Q output = 1
	_ctUpEdge = 0;					// Prepare rising edge detect for up counter
	_ctDownEdge = 0;				// Prepare rising edge detect for down counter
}

Counter::Counter(unsigned int pv, unsigned int direction)	// Counter constructor method
{									// (Second parameter sets default direction)
	_pv = pv;						// Set preset value using supplied parameter
	if(direction == 0){				// Set start values for an up counter
		_ct = 0;					// Running count = zero
		_uQ = 0;					// Up counter upper Q output = 0
		_lQ = 1;					// Down counter lower Q output = 1
	}
	else {							// Set start values for a down counter
		_ct = _pv;					// Running count = preset value
		_uQ = 1;					// Up counter upper Q output = 1
		_lQ = 0;					// Down counter lower Q output = 0
	}
	_ctUpEdge = 0;					// Prepare rising edge detect for up counter
	_ctDownEdge = 0;				// Prepare rising edge detect for down counter
}

unsigned int Counter::presetValue()	// Return preset value method
{
	return(_pv);					// Return preset value
}	

void Counter::clear()				// Clear counter method
{
	if(scanValue == 1) {			// Enabled if scanValue = 1
		_ct = 0;					// Running count = 0
		_uQ = 0;					// Up counter upper Q output = 0
		_lQ = 1;					// Down counter lower Q output = 1
		_ctUpEdge = 0;				// Prepare rising edge detect for up counter
		_ctDownEdge = 0;			// Prepare rising edge detect for down counter
	}
}

void Counter::preset()				// Preset counter method
{
	if(scanValue == 1) {			// Enabled if scanValue = 1
		_ct = _pv;					// Running count = preset value
		_uQ = 1;					// Up counter upper Q output = 1
		_lQ = 0;					// Down counter lower Q output = 0
		_ctUpEdge = 0;				// Prepare rising edge detect for up counter
		_ctDownEdge = 0;			// Prepare rising edge detect for down counter
	}
}

unsigned int Counter::upperQ()		// Read up counter upper Q output method
{
	if (_uQ == 1){					// Set scanValue = 1 if upper Q = 1
		scanValue = 1;
	}
	else {
		scanValue = 0;				// Otherwise set scanValue = 0
	}
	return(_uQ);					// Return upper Q value
}

unsigned int Counter::lowerQ()		// Read down counter lower Q output method
{
	if (_lQ == 1){					// Set scanValue = 1 if lower Q = 1
		scanValue = 1;
	}
	else {
		scanValue = 0;				// Otherwise set scanValue = 0
	}
	return(_lQ);					// Return lower Q value
}

unsigned int Counter::count()		// Return current count value method
{
	return(_ct);					// Return count value
}

void Counter::countUp()				// Count up method
{
	if (_ct != _pv) {      			// Not yet finished counting so continue
		if (scanValue == 0) {		// clock = 0 so clear counter edge detect
			_ctUpEdge = 0;
		}
		else {						// Clock = 1
			if (_ctUpEdge == 0) {	// Rising edge detected so increment count
				_ctUpEdge = 1;		// Set counter edge
				_ct++;				// Increment count
				if(_ct == _pv) {	// Counter has reached final value
					_uQ = 1;		// Counter upper Q output = 1
					_lQ = 0;		// Counter lower Q output = 0
				}
				if(_ct != _pv){		// Counter is not yet finished
					_uQ = 0;		// Counter upper Q output = 0
					_lQ = 0;		// Counter lower Q output = 0
				}
			}
		}
	}
}

void Counter::countDown()			// Count down method
{
	if (_ct != 0) {					// Not yet finished so continue
		if (scanValue == 0) {		// clock = 0 so clear counter edge detect
			_ctDownEdge = 0;
		}
		else {						// Clock = 1
			if (_ctDownEdge == 0) {	// Rising edge detected so decrement count
				_ctDownEdge = 1;	// Set counter edge
				_ct--; 				// Decrement count
				if(_ct == 0) {		// Counter has reached final value
					_uQ = 0;		// Counter QUp output = 0
					_lQ = 1;		// Counter QDown output = 1
				}
				if(_ct != 0) {		// Counter is not yet finished
					_uQ = 0;		// Counter upper Q output = 0
					_lQ = 0;		// Counter lower Q output = 0
				}
			}
		}
	}
}

// Shift register
Shift::Shift()						// Shift register constructor method
{									// (Register width = 32 bits)
	_sreg = 0;						// Set  the shift register to zero
	_srLeftEdge = 0;				// Prepare rising edge detect for left shift
	_srRightEdge = 0;				// Prepare rising edge detect for right shift
}

Shift::Shift(unsigned int sreg)	    // Shift register constructor method
{									// (Register width = 32 bits)
	_sreg = sreg;					// Set initial value
	_srLeftEdge = 0;				// Prepare rising edge detect for left shift
	_srRightEdge = 0;				// Prepare rising edge detect for right shift
}

unsigned int Shift::bitValue(unsigned int bitno)	// Read a bit at a specified position
{
	if(bitRead(_sreg, bitno) == 1) {
		scanValue = 1;				// Tested bit = 1
	}
	else {
		scanValue = 0;				// Tested bit = 0
	}
	return(scanValue);				// Return tested bit value
}

unsigned int Shift::value()			// Return the current shift register value
{
	return(_sreg);
}

void Shift::reset()					// Reset the shift register if scanValue = 0
{
	if(scanValue == 1){
		_sreg = 0;					// Set  the shift register to zero
		_srLeftEdge = 0;			// Prepare rising edge detect for left shift
		_srRightEdge = 0;			// Prepare rising edge detect for right shift
		}
}

void Shift::inputBit()				// Set the input bit of the shift register
{
	if (scanValue == 0) {			// If scanValue = 0, clear input bit
		_inbit = 0;
	}
	else {							// Otherwise set the input bit
		_inbit = 1;
	}
}

void Shift::shiftRight()			// Shift right method
{
	if (scanValue == 0) {			// clock = 0 so clear shift right edge detect
		_srRightEdge = 0;
	}
	else {							// Clock = 1
		if (_srRightEdge == 0) {	// Rising edge detected so shift right
			_srRightEdge = 1;		// Set shift right edge detect
			_sreg = _sreg >> 1;		// Shift to the right
			if (_inbit == 1) {		// Shift-in new input bit at LHS
				bitSet(_sreg, 15);
			}
		}
	}
}

void Shift::shiftLeft()				// Shift left method
{
	if (scanValue == 0) {			// clock = 0 so clear shift left edge detect
		_srLeftEdge = 0;
	}
	else {							// Clock = 1
		if (_srLeftEdge == 0) {		// Rising edge detected so shift left
			_srLeftEdge = 1;		// Set shift left edge detect
			_sreg = _sreg << 1;		// Shift to the left
			if (_inbit == 1) {		// Shift-in new input bit at RHS
				bitSet(_sreg, 0);
			}
		}
	}
}

// Single-bit Software Stack
Stack::Stack()						// Stack constructor method
{									// (Register width = 32 bits)
	_sreg = 0;						// Set the stack to zero
}

void Stack::push()					// Push scanValue bit onto the stack method
{
	_sreg = _sreg >> 1;				// Shift stack 1-bit to the right
	if (scanValue == 1) {			// Shift-in scanValue bit at LHS
		bitSet(_sreg, 31);
	}
	else {
		bitClear(_sreg, 31);
	}
}

void Stack::pop()					// Pop scanValue bit from the stack method
{
	scanValue = bitRead(_sreg, 31);	// Set scanValue to leftmost bit of stack
	_sreg = _sreg << 1;				// Shift stack 1-bit to the left
}

void Stack::orBlock()				// OR scanValue with value Popped from stack method
{
	scanValue = scanValue | bitRead(_sreg, 31);	// OR scanValue with top of stack
	_sreg = _sreg << 1;				// Shift stack 1-bit to the left
}

void Stack::andBlock()				// AND scanValue with value Popped from stack method
{
	scanValue = scanValue & bitRead(_sreg, 31);	// AND scanValue with top of stack
	_sreg = _sreg << 1;				// Shift stack 1-bit to the left
}

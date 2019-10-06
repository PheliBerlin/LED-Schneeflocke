#ifndef xmasStern_h
#define xmasStern_h

#include "Arduino.h"

class xmasStern
{
	public:
		xmasStern(byte latchPin, byte clockPin, byte dataPin);
 
		// Nur die einzelnen Farben ansteuren
		void weiss();
		void rot();
		void gruen();
		void gelb();
		
		// Effekte	
		void umlauflinks(int speed);
		void umlaufrechts(int speed);
		void sparkle(int speed);
		void viererrunde(int speed);
		void gelberring(int runden, int speed);
		void gruenerring(int runden, int speed);
		void ring(int runden, int speed);
		void spitze(byte spitze, int dauer);
		
		// Alle LED ausschalten
		void aus();
        
	private:
		byte _latchPin, _clockPin, _dataPin;
		byte _leds[30][2];
		void senden(byte wert1, byte wert2);
		void shiftOut_neu(byte wert);
                
};

#endif 
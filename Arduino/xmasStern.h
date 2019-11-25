#ifndef xmasStern_h
#define xmasStern_h

#include "Arduino.h"

class xmasStern
{
	public:
		xmasStern(byte latchPin, byte clockPin, byte dataPin);
 
		// Arduino delay ersetzen
		void sternDelay(unsigned long zeit);
		
		// Nur die einzelnen Farben ansteuren
		void weiss();
		void rot();
		void gruen();
		void gelb();
		
		// Effekte	
		void umlaufLinks(int speed);
		void umlaufrechts(int speed);
		void sparkle(int speed);
		void viererrunde(int speed);
		void gelberring(int runden, int speed);
		void gruenerring(int runden, int speed);
		void ring(int runden, int speed);
		void spitze(byte spitze, int dauer);
		void eineLED(byte nummer);
		void eineLEDaus(byte nummer);
		void umlaufAlleRechts(int speed);
		void umlaufAlleLinks(int speed);
		void feuerWerk(int speed);
		void tickTack(byte spitze1, byte spitze2, byte speed);
		
		
		// Alle LED ausschalten
		void aus();
		
		// Alle LED anschalten
		void an();
        
	private:
		byte _latchPin, _clockPin, _dataPin;
		byte _leds[30][2];
		void senden(byte wert1, byte wert2);
		void shiftOut_neu(byte wert);
		
                
};

#endif 
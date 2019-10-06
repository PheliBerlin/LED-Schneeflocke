#include "Arduino.h"
#include "xmasStern.h"


xmasStern::xmasStern(byte latchPin, byte clockPin, byte dataPin)
{
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);	
	
	_latchPin = latchPin;
	_clockPin = clockPin;
	_dataPin = dataPin;
	
	// Die einzelnen Pins am Stern deklarieren
	// Jede Zeile eine Spitze
	// rot, gelb, grün, weiß, grün, geld (Spitze im Uhreigersinn)
	byte zaehler = 0;
	for (byte i = 0; i < 5; i++)
	{
		for (byte n = 0; n < 6; n++)
		{
			_leds[zaehler][0] = 128 >> i;
			_leds[zaehler][1] = 128 >> n;
			zaehler += 1;
		}
	}
	aus();
}

void xmasStern::shiftOut_neu(byte wert)
{
  byte i;

  for (i = 0; i < 8; i++)
  {
		//digitalWrite(dataPin, !!(val & (1 << i)));
    if (  ( !!(wert & (1 << i)) ) == HIGH )
      PORTA |= (1 << _dataPin);
    else PORTA &= ~(1 << _dataPin);

    //digitalWrite(clockPin, HIGH);
    PORTA |= (1 << _clockPin);
    
    //digitalWrite(clockPin, LOW);
    PORTA &= ~(1 << _clockPin); 
  }
}



void xmasStern::senden(byte wert1, byte wert2)
{
	// latchPin auf LOW damit
	// die LED beim Senden nicht blinken

	//digitalWrite(latchPin, LOW);
	PORTA &= ~(1 << _latchPin);
	
	// Erst das zweite Register, dann das erste
	shiftOut_neu(wert2);
	shiftOut_neu(wert1);
	
	//digitalWrite(latchPin, HIGH);
	PORTA |= (1 << _latchPin);	
}



// Nur die einzelnen Farben ansteuren
void xmasStern::weiss() {
  senden(0b11111000, 0b00010000);
}

void xmasStern::rot() {
  senden(0b11111000, 0b10000000);
}

void xmasStern::gruen()
{
  senden(0b11111000, 0b00101000);
}

void xmasStern::gelb()
{
  senden(0b11111000, 0b01000100);
}



// Alle LED ausschalten
void xmasStern::aus()
{
  senden(0, 0);
}


// Effekte
void xmasStern::umlauflinks(int speed)
{
  byte ic1, ic2;

  for (byte spitze = 1; spitze < 6; spitze++)
  {
    ic1 = 256 >> spitze;

    for ( byte lampe = 1; lampe < 7; lampe++)
    {
      ic2 = 256 >> lampe;
      senden(ic1, ic2);
      delay(speed);
    }
  }
}
void xmasStern::umlaufrechts(int speed)
{
  byte ic1, ic2;

  for (byte spitze = 1; spitze < 6; spitze++)
  {
    ic1 = 4 << spitze;

    for ( byte lampe = 1; lampe < 7; lampe++)
    {
      ic2 = 2 << lampe;
      senden(ic1, ic2);
      delay(speed);
    }
  }
}
void xmasStern::sparkle(int speed) // speed = 250-300 sieht gut aus
{
  weiss(); delay(speed);
  gruen(); delay(speed);
  gelb(); delay(speed);
  rot(); delay(speed);
  gelb(); delay(speed);
  gruen(); delay(speed);
}
void xmasStern::viererrunde(int speed) // speed = 30-40 sieht gut aus
{
  byte led1, led2, led3, led4;

  for ( led1 = 0; led1 < 30; led1++)
  {
    led2 = led1 + 1;
    led2 = (led2 == 30 ? 0 : led2);
    led3 = led1 + 2;
    led3 = (led3 == 30 ? 0 : led3);
    led3 = (led3 == 31 ? 1 : led3);
    led4 = led1 + 3;
    led4 = (led4 == 30 ? 0 : led4);
    led4 = (led4 == 31 ? 1 : led4);
    led4 = (led4 == 32 ? 2 : led4);

    for (int i = 0; i < speed; i++)
    {
      senden(_leds[led1][0], _leds[led1][1]);
      //delay(1);
      senden(_leds[led2][0], _leds[led2][1]);
      //delay(1);
      senden(_leds[led3][0], _leds[led3][1]);
      //delay(1);
      senden(_leds[led4][0], _leds[led4][1]);
      //delay(1);
    }
  }
}
void xmasStern::gelberring(int runden, int speed)
{
  for (byte n = 0; n < runden ; n++)
  {
    senden(0b11111000, 0b01000000);
    delay(speed);
    senden(0b11111000, 0b00000100);
    delay(speed);
  }
}
void xmasStern::gruenerring(int runden, int speed)
{
  for (byte n = 0; n < runden ; n++)
  {
    senden(0b11111000, 0b00001000);
    delay(speed);
    senden(0b11111000, 0b00100000);
    delay(speed);
  }
}
void xmasStern::ring(int runden, int speed)
{
  for (byte n = 0; n < runden ; n++)
  {
    senden(0b11111000, 0b11010000);
    delay(speed);
    senden(0b11111000, 0b10100100);
    delay(speed);
    senden(0b11111000, 0b01011000);
    delay(speed);
    senden(0b11111000, 0b00101100);
    delay(speed);
  }
}
void xmasStern::spitze(byte spitze, int dauer)
{
  if (spitze > 4) return;

  for ( int i = 0; i < dauer; i++)
  {
    senden( 128 >> spitze, 0b01111100);
    delay(2);
    rot();
    delay(5);
  }
}



















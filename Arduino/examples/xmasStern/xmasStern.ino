/*
    Mein kleiner Weihnachtsstern für den Schreibtisch
    www.pheli.de

    Für die Steuerung des Sternes wird ein ATtiny84 genommen, der über die Arduino Umgebung programmiert wird.
    Als Frequenz habe ich die internen 8MHz des ATtiny84 genommen.
*/


#include <xmasStern.h>

/*  Pinbelegung für den Weihnachtsstern am 74HC595
      ST_CP  ->  3
      SH_CP  ->  2
      DS     ->  1
*/

xmasStern stern(3, 2, 1);


void setup() {
  // Nichts zu tun
}

void loop() {

  /*

     Alle eingebauen Funktionen, die sich natürlich beliebig kombinieren und wiederholen lassen.

  */

  // Alle LED ausschalten
  // Ohne Argumente
  // void aus();
  //
  // stern.aus();


  // Die einzelnen Farbringe lassen sich einzelnd schalten.
  // Ohne Argumente
  // void weiss();
  // void rot();
  // void gruen();
  // void gelb();
  //
  stern.weiss(); delay(150);
  stern.gruen(); delay(150);
  stern.gelb(); delay(150);
  stern.rot(); delay(150);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // LED gegen den Uhrzeigersinn Umlaufen lassen.
  // Als Argument wird die Geschwindigkeit übergeben, je kleiner, desto schneller der LED Wechsel.
  // void umlauflinks(int speed);
  //
  stern.umlauflinks(80);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // LED mit dem Uhrzeigersinn Umlaufen lassen.
  // Als Argument wird die Geschwindigkeit übergeben, je kleiner, desto schneller der LED Wechsel.
  // void umlaufrechts(int speed);
  //
  stern.umlaufrechts(80);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Die einzelnen Farbringe werden von außen nach innne und wieder nach außen geschaltet.
  // Als Argument wird die Geschwindigkeit übergeben, je kleiner, desto schneller der LED Wechsel.
  // void sparkle(int speed);
  //
  stern.sparkle(180);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Eine Reihe von 4 LED umläuft den Stern gegen den Uhrzeigersinn.
  // Als Argument wird die Geschwindigkeit übergeben, je kleiner, desto schneller der LED Wechsel.
  // void viererrunde(int speed);
  //
  stern.viererrunde(40);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Die gelben LED stellen eine Drehung dar. Je nach Betrachter gegen oder mit dem Uhrzeigersinn.
  // Als Argument werden die Anzahl der Runden und die Geschwindigkeit übergeben, je kleiner die Geschwindigkeit, desto schneller der LED Wechsel.
  // void gelberring(int runden, int speed);
  //
  stern.gelberring(10, 150);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Die grünen LED stellen eine Drehung dar. Je nach Betrachter gegen oder mit dem Uhrzeigersinn.
  // Als Argument werden die Anzahl der Runden und die Geschwindigkeit übergeben, je kleiner die Geschwindigkeit, desto schneller der LED Wechsel.
  // void gruenerring(int runden, int speed);
  //
  stern.gruenerring(10, 100);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Es wird ein Umlaufen der LED zu simulieren. Je nach gegebener Geschwindigkeit sieht der Effekt auch wie zufälliges Blinken aus.
  // Als Argument werden die Anzahl der Runden und die Geschwindigkeit übergeben, je kleiner die Geschwindigkeit, desto schneller der LED Wechsel.
  // void ring(int runden, int speed);
  //
  stern.ring(2, 250);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);


  // Es wird eine der fünf Spitzen und der rote Ring angeschaltet. Werden die Spitzen nacheinander angeschaltet, kann ein Umlauf dargestellt werden.
  // Als Argument werden die Nummer (0-4) der Spitze und die Leuchtdauer übergeben.
  // void spitze(byte spitze, int dauer);
  //
  stern.spitze(0, 100);
  stern.spitze(1, 100);
  stern.spitze(2, 100);
  stern.spitze(3, 100);
  stern.spitze(4, 100);

  // Um die Effekte zur Demonstration zeitlich zu trennen.
  stern.aus();delay(1500);
}

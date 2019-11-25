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

  stern.tickTack(2, 3, 70);

  stern.spitze(4, 70);
  stern.spitze(0, 70);
  stern.spitze(1, 70);
  stern.spitze(2, 70);
  stern.spitze(3, 70);

  stern.an();

  stern.sternDelay(600);

  stern.feuerWerk(150);

  stern.sparkle(250);
  stern.sparkle(250);

  stern.umlaufLinks(80);
  stern.viererrunde(80);

}

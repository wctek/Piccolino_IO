/*
  Blink 16 I/O port expander
  Turns on an LED on for one second, then off for one second, repeatedly.

  This sketch was made to use with the 16 I/O port expander for Piccolino.

  To blink a LED without 16 I/O port expander, just use the default 'Blink'
  example sketch provided by the Arduino IDE.
 */

#include <Wire.h>
#include <Piccolino_IO.h>

Piccolino_IO pe;
int pin = 0;

void setup() {
  pe.begin();
}

void loop() {
  pe.pinMode(pin, OUTPUT); // no need really since the default is output

  while (1) {
    pe.digitalWrite(pin, HIGH);
    delay(1000);
    pe.digitalWrite(pin, LOW);
    delay(1000);
  }
}

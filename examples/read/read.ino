/*
  Digital read 16 I/O port expander
  Reads a digital input on a pin, prints the result to the serial monitor.

  This sketch was made to use with the 16 I/O port expander for Piccolino.
  For details about the Piccolino, please visit http://www.piccolino.rocks/

  To read a digital input without 16 I/O port expander, just use the default
  'DigitalReadSerial' example sketch provided by the Arduino IDE.
 */

#include <Wire.h>
#include <Piccolino_IO.h>

Piccolino_IO pe;
int pin = 0;

void setup() {
  pe.begin();
  Serial.begin(9600);
}

void loop() {
  pe.pinMode(pin, INPUT);

  while (1) {
    Serial.print("Pin = ");
    Serial.println(pe.digitalRead(pin));
    delay(200);
  }
}

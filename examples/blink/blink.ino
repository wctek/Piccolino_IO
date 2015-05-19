#include <Wire.h>
#include <Piccolino_IO.h>

Piccolino_IO pe;

void setup()
{
  pe.begin();  
}

void loop()
{
   
  pe.pinMode(0,OUTPUT); // no need really since the default is output
  
  while(1)
  {
    pe.digitalWrite(0,HIGH);
    delay(200);
    pe.digitalWrite(0,LOW);
    delay(200);
  }
  
}
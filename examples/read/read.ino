#include <Wire.h>
#include <Piccolino_IO.h>

Piccolino_IO pe;

void setup()
{
  // put your setup code here, to run once:
  pe.begin();
  Serial.begin(9600);
    
}

void loop()
{
   
  pe.pinMode(0,INPUT); 
  
  while(1)
  {
    Serial.print("Pin 0 = ");
    Serial.println(pe.digitalRead(0));
    delay(200);
  }
  
}
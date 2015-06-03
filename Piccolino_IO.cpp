//#include <avr/pgmspace.h>

/*************************************************************
* This library supports the PCA9555 IC device on the         *
* Piccolino micro                                            *
*                                                            *
* Written by Alex Sardo - wctek.com                          *
*************************************************************/
#include <avr/pgmspace.h>
#include <Arduino.h>
#include <Wire.h>
#include "Piccolino_IO.h"

Piccolino_IO::Piccolino_IO() {
	// nothing here now -- all done in 'begin'
}

// init PCA9555 -- call it as begin() or begin(PCA9555 addr (0x20-0x27)
void Piccolino_IO::begin(uint8_t addr, uint8_t intaddr) {
  
  _io_addr=addr;
  _io_int=intaddr;

  Wire.begin(); 

  _iowrite(CMD_CP0,0x00); //configure PORT0 as output
  _iowrite(CMD_CP1,0x00); //configure PORT1 as output
  _iowrite(CMD_PI0,0x00); //configure PORT0 normal polarity
  _iowrite(CMD_PI1,0x00); //configure PORT1 normal polarity
  _iowrite(CMD_WR0,0x00); //configure PORT0 all off
  _iowrite(CMD_WR1,0x00); //configure PORT0 all off  
}

// i2c write shortcut
void Piccolino_IO::_iowrite (uint8_t cmd, uint8_t data)
{
  Wire.beginTransmission(_io_addr);
  Wire.write(cmd);
  Wire.write(data); 
  Wire.endTransmission();
}

// i2c read shortcut
uint8_t Piccolino_IO::_ioread(uint8_t cmd)
{
    Wire.beginTransmission(_io_addr);
    Wire.write(cmd); 
    Wire.endTransmission();
    Wire.requestFrom((int)_io_addr, 1);
    return Wire.read();
}

// sets pin (0 - 15) for input or output 
void Piccolino_IO::pinMode(uint8_t pin, char mode)
{
   uint8_t dir,p;
   p=pin&0x7;
  
   if(pin<8) 
    dir = _ioread(CMD_CP0);
    else 
    dir = _ioread(CMD_CP1);
  

  if (mode == INPUT)
    dir |= 1 << p; 
  else 
    dir &= ~(1 << p);
  
  if(pin<8)
    _iowrite(CMD_CP0,dir);
  else
    _iowrite(CMD_CP1,dir);

}
 
// change state of pin (0 - 15)
void Piccolino_IO::digitalWrite(uint8_t pin, char data)
{
   uint8_t io,p;

   p=pin&0x7;
  
   //read current port conf
   if(pin<8)
    io = _ioread(CMD_WR0); 
    else
    io = _ioread(CMD_WR1);
  

  if (data == HIGH)
    io |= 1 << p; 
  else 
    io &= ~(1 << p);
  
  if(pin<8)
    _iowrite(CMD_WR0,io);
  else
    _iowrite(CMD_WR1,io);

}

// change state of port (0 - 1)
void Piccolino_IO::portWrite(uint8_t port, uint8_t data)
{
  if(!port)
    _iowrite(CMD_WR0,data);
  else
    _iowrite(CMD_WR1,data);
}

// read state of port (0 - 1)
uint8_t Piccolino_IO::portRead(uint8_t port)
{
	uint8_t io;

   if(!port)
    io = _ioread(CMD_RD0);
   else 
    io = _ioread(CMD_RD1);
  
  return io;
}


// read state of pin (0 - 15)
uint8_t Piccolino_IO::digitalRead(uint8_t pin)
{
   uint8_t io,p;

   p=pin&0x7;
  
   if(pin<8)
    io = _ioread(CMD_RD0);
   else 
    io = _ioread(CMD_RD1);
  

  return (io >> p) & 0x1;
}
 
// invert mode of pin (0 - 15)
void Piccolino_IO::pinInvert(uint8_t pin, char mode)
{
   uint8_t pi,p;

   p=pin&0x7;
  
   if(pin<8)
    pi = _ioread(CMD_PI0);
   else
    pi = _ioread(CMD_PI1);  

  if (mode == INVERT)
    pi |= 1 << p; 
  else 
    pi &= ~(1 << p);
  
  if(pin<8)
    _iowrite(CMD_PI0,pi);
  else
    _iowrite(CMD_PI1,pi);

}
 
Piccolino_IO::~Piccolino_IO() {
  // nothing here now -- all done in 'begin'
}



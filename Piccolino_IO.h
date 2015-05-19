
/*
Piccolino I2C 16 Digital I/O extender support library
Written by A.Sardo (wctek.com) - 9 May 2015
*/

#ifndef _PICCOLINO_IO_H
#define _PICCOLINO_IO_H

#define CMD_RD0 0x00 
#define CMD_RD1 0x01 
#define CMD_WR0 0x02 
#define CMD_WR1 0x03 
#define CMD_PI0 0x04 
#define CMD_PI1 0x05 
#define CMD_CP0 0x06 
#define CMD_CP1 0x07 

#define INVERT 1
#define NORMAL 0

class Piccolino_IO {
public:

  Piccolino_IO();
  ~Piccolino_IO();

  void begin(uint8_t addr=0x20, uint8_t interrupt=0);
  void digitalWrite(uint8_t pin, char mode);
  uint8_t digitalRead(uint8_t pin);
  void portWrite(uint8_t port, uint8_t data);
  uint8_t portRead(uint8_t port);
  void pinMode(uint8_t pin, char mode);
  void pinInvert(uint8_t pin, char mode);
  
private:
	uint8_t _io_addr, _io_int;
	void _iowrite(uint8_t cmd, uint8_t data);
	uint8_t _ioread(uint8_t cmd);
};

#endif
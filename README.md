# Piccolino_IO
16 I/O port expander for Piccolino

Individual set/reset up to 16 bits one at the time or 8 at the time (port-write). Use standard `digitalWrite` and `digitalRead` commands.

Commands:

- `begin()`
  start the object. Call it on its own or with an address (default addr is 0x20)
  
- `void digitalWrite(uint8_t pin, char mode);`
  sets pin to HIGH/LOW
  
- `uint8_t digitalRead(uint8_t pin);`
  reads pin
  
- `void portWrite(uint8_t port, uint8_t data);`
  sets all 8 pins of port "port" to either HIGH/LOW or combination.
  
- `uint8_t portRead(uint8_t port);`
  read port "port" pins.
  
- `void pinMode(uint8_t pin, char mode);`
  sets pin for INPUT or OUTPUT
  
- `void pinInvert(uint8_t pin, char mode);`
  invert pin value on read (0 will become 1 and 1 will become 0)
  
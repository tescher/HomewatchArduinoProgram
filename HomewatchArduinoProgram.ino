/*
 * EEPROM Programming for sensors
 *
 * Stores values read from analog input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later by another sketch.
 */

#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;

void setup()
{
  char mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0xE3, 0x86 };
  char server[] = "www.escherhomewatch.com";
  char controller[] = "BasementArduino";
  
  int i = 0;
  
  // Write out the magic number
  EEPROM.write(0, 0xFE);
  EEPROM.write(1, 0xEF);
  
  // Write out the MAC address
  for (i=2; i<8; i++) {
    EEPROM.write(i, mac[i-2]);
  }
  
  // Write out the server
  do {
    EEPROM.write(i, server[i - 8]);
  } while ((server[i++ - 8]) != 0x00);
  
  // Write out the controller ID
  int currentPtr = i;
  do {
    EEPROM.write(i, controller[i - currentPtr]);
  } while ((controller[i++ - currentPtr]) != 0x00);
}

void loop()
{
}

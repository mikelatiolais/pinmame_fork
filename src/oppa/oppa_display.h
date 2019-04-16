#ifndef INC_OPPA_DISPLAY
#define INC_OPPA_DISPLAY 1
typedef unsigned char  UINT8;

#include <wiringPi.h>
#include <wiringShift.h>
#include <wiringPiSPI.h>

#define OPPA_NUM_DMD_FRAMES 3
#define pinDisplayEnable 26 // DMD pin 1
#define pinRowData  22 // One pin 3
#define pinRowClock 21 // DMD pin 5
#define pinColLatch 23 // DMD pin 7
#define pinDotClock 14 // DMD pin 9
#define pinDotData  12// DMD pin 11
#define OPPA_NUM_OF_BYTES 512 // 4096 / 8 bits
#define OPPA_NUM_OF_ROWS 32

void oppaInitDMD();
void oppaInitDMDSPI();
void oppaBlankDMD();
void oppaUpdateDMD(UINT8 *dotData);
void oppaUpdateDMDSPI(UINT8 *dotData);
void shiftOutSlow(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);

#endif /* INC_OPPA_DISPLAY */

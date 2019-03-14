#ifndef INC_OPPA_DISPLAY
#define INC_OPPA_DISPLAY
typedef unsigned char  UINT8;

#include <wiringPi.h>
#include <wiringShift.h>

#define OPPA_NUM_DMD_FRAMES 3
#define pinDisplayEnable 5 // DMD pin 1
#define pinRowData  6 // One pin 3
#define pinRowClock 13 // DMD pin 5
#define pinColLatch 19 // DMD pin 7
#define pinDotClock 10 // DMD pin 9
#define pinDotData  11 // DMD pin 11
#define OPPA_NUM_OF_BYTES 512 // 4096 / 8 bits
#define OPPA_NUM_OF_ROWS 32

// Display functions
void procDMDInit(void);
void procClearDMD(void);
void procDrawDot(int x, int y, int color);
void procDrawSegment(int x, int y, int seg);
void procFillDMDSubFrame(int frameIndex, UINT8 *dotData, int length);
void procReverseSubFrameBytes(int frameIndex);
void procUpdateDMD(void);
void procUpdateAlphaDisplay(UINT16 *top, UINT16 *bottom);
void procDisplayText(char *top, char *bottom);

void oppaInitDMD();
void oppaUpdateDMD(UINT8 *dotData);

#endif /* INC_OPPA_DISPLAY */

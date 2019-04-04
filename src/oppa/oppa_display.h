#ifndef INC_OPPA_DISPLAY
#define INC_OPPA_DISPLAY 1
typedef unsigned char  UINT8;

#include <wiringPi.h>
#include <wiringShift.h>

#define OPPA_NUM_DMD_FRAMES 3
#define pinDisplayEnable 26 // DMD pin 1
#define pinRowData  22 // One pin 3
#define pinRowClock 21 // DMD pin 5
#define pinColLatch 23 // DMD pin 7
#define pinDotClock 14 // DMD pin 9
#define pinDotData  12// DMD pin 11
#define OPPA_NUM_OF_BYTES 512 // 4096 / 8 bits
#define OPPA_NUM_OF_ROWS 32

// Display functions
/*
void procDMDInit(void);
void procClearDMD(void);
void procDrawDot(int x, int y, int color);
void procDrawSegment(int x, int y, int seg);
void procFillDMDSubFrame(int frameIndex, UINT8 *dotData, int length);
void procReverseSubFrameBytes(int frameIndex);
void procUpdateDMD(void);
void procUpdateAlphaDisplay(UINT16 *top, UINT16 *bottom);
void procDisplayText(char *top, char *bottom);
*/

void oppaInitDMD();
void oppaUpdateDMD(UINT8 *dotData);

/* The definition of renderDMDFrame
void renderDMDFrame(UINT64 gen, UINT16 width, UINT16 height, UINT8 *currbuffer, UINT8 doDumpFrame, const char* GameName, UINT32 noOfRawFrames, UINT8 *rawbuffer) {

        dmd_width = width; // store for DeInit
        dmd_height = height;
        dmd_hasDMD = true;
...
*/


#endif /* INC_OPPA_DISPLAY */

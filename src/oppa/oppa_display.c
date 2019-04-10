#include "oppa_display.h"
#include <stdio.h>

UINT8 oppadmd[OPPA_NUM_DMD_FRAMES][4096];
static const int CHANNEL = 1;

/* Set up initial DMD pin configuration */
void oppaInitDMD() {
  printf("In oppa display init\n");
  wiringPiSetup();
  pinMode(pinDisplayEnable, OUTPUT);
  pinMode(pinRowData, OUTPUT);
  pinMode(pinRowClock, OUTPUT);
  pinMode(pinColLatch, OUTPUT);
  pinMode(pinDotClock, OUTPUT);
  pinMode(pinDotData, OUTPUT);

  /* Drive everything low to start */
  digitalWrite(pinDisplayEnable, LOW);
  digitalWrite(pinRowData, LOW);
  digitalWrite(pinRowClock, HIGH);
  digitalWrite(pinColLatch, LOW);
  digitalWrite(pinDotClock, LOW);
  digitalWrite(pinDotData, LOW);
}

/* Set up initial DMD pin configuration */
void oppaInitDMDSPI() {
  int fd;

  printf("In init SPI\n");
  wiringPiSetup();
  pinMode(pinDisplayEnable, OUTPUT);
  pinMode(pinRowData, OUTPUT);
  pinMode(pinRowClock, OUTPUT);
  pinMode(pinColLatch, OUTPUT);
  //pinMode(pinDotClock, OUTPUT);
  //pinMode(pinDotData, OUTPUT);

  /* Drive everything low to start */
  digitalWrite(pinDisplayEnable, LOW);
  digitalWrite(pinRowData, LOW);
  digitalWrite(pinRowClock, HIGH);
  digitalWrite(pinColLatch, LOW);
  //digitalWrite(pinDotClock, LOW);
  //digitalWrite(pinDotData, LOW);

  /* Set up SPI */
  fd = wiringPiSPISetup(1, 500000);
}

/* Take in array and update the DMD directly */
void oppaUpdateDMD(UINT8 *dotData) {
  //printf("In update DMD\n");
 
  int row; 
  for(row = 0; row < OPPA_NUM_OF_ROWS; row++) {
    int index;
    /* From Vishay doc: Once each frame the ROW DATA must be asserted to synchronize the column serial data with the beginning row */
    /* Latch the row of data */
    digitalWrite(pinColLatch, LOW);
    for(index = 0; index < 16; index++) {
      shiftOutSlow(pinDotData,pinDotClock,LSBFIRST,dotData[(row*16) + index]); 
      //shiftOut(pinDotData,pinDotClock,LSBFIRST,3); 
      //delayMicroseconds(40);
    }
    if(row == 0) {
      digitalWrite(pinRowData, HIGH);
    } else {
      digitalWrite(pinRowData, LOW);
    }


    /* Turn off the display while we latch in the this row */
    digitalWrite(pinDisplayEnable, LOW);  
    digitalWrite(pinColLatch, HIGH);


    /* Advance the row pointer */
    digitalWrite(pinRowClock, LOW);   
    /* Minimum 1us dip */
    //delayMicroseconds(10);  
    digitalWrite(pinRowClock, HIGH);

    /* Reenable display */
    digitalWrite(pinDisplayEnable, HIGH); 
    //delayMicroseconds(1);
  }
}

/* Take in array and update the DMD directly */
void oppaUpdateDMDSPI(UINT8 *dotData) {
  int result;

  //printf("In update SPI\n");
  int row; 
  for(row = 0; row < OPPA_NUM_OF_ROWS; row++) {
    int index;
    int result;
    /* From Vishay doc: Once each frame the ROW DATA must be asserted to synchronize the column serial data with the beginning row */
    /* Latch the row of data */
    digitalWrite(pinColLatch, LOW);
    result = wiringPiSPIDataRW(1, dotData, 16);
    //for(index = 0; index < 16; index++) {
      //shiftOut(pinDotData,pinDotClock,LSBFIRST,dotData[(row*16) + index]); 
      //shiftOut(pinDotData,pinDotClock,LSBFIRST,3); 
      //delayMicroseconds(40);
    //}
    if(row == 0) {
      digitalWrite(pinRowData, HIGH);
    } else {
      digitalWrite(pinRowData, LOW);
    }


    /* Turn off the display while we latch in the this row */
    digitalWrite(pinDisplayEnable, LOW);  
    digitalWrite(pinColLatch, HIGH);


    /* Advance the row pointer */
    digitalWrite(pinRowClock, LOW);   
    /* Minimum 1us dip */
    //delayMicroseconds(10);  
    digitalWrite(pinRowClock, HIGH);

    /* Reenable display */
    digitalWrite(pinDisplayEnable, HIGH); 
    //delayMicroseconds(1);
  }
}

void shiftOutSlow(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
     uint8_t i;

     for (i = 0; i < 8; i++)  {
           if (bitOrder == LSBFIRST)
                 digitalWrite(dataPin, !!(val & (1 << i)));
           else
                 digitalWrite(dataPin, !!(val & (1 << (7 - i))));

           digitalWrite(clockPin, HIGH);
           delayMicroseconds(1);
           digitalWrite(clockPin, LOW);
     }
}


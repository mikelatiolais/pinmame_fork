#include "oppa_display.h"
#include <stdio.h>

UINT8 oppadmd[OPPA_NUM_DMD_FRAMES][4096];

/* Set up initial DMD pin configuration */
void oppaInitDMD() {
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
  digitalWrite(pinRowClock, LOW);
  digitalWrite(pinColLatch, LOW);
  digitalWrite(pinDotClock, LOW);
  digitalWrite(pinDotData, LOW);
}

/* Take in array and update the DMD directly */
void oppaUpdateDMD(UINT8 *dotData) {
  printf("In update DMD\n");
 
  int row; 
  for(row = 0; row < OPPA_NUM_OF_ROWS; row++) {
    int index;
    for(index = 0; index < 16; index++) {
      shiftOut(pinDotData,pinDotClock,MSBFIRST,dotData[(row*16) + index]); 
    }

    /* Latch the row of data */
    digitalWrite(pinColLatch, HIGH);
    delayMicroseconds(100);  
    digitalWrite(pinColLatch, LOW);

    /* Turn off the display while we latch in the this row */
    digitalWrite(pinDisplayEnable, LOW);  

    /* From Vishay doc: Once each frame the ROW DATA must be asserted to synchronize the column serial data with the beginning row */
    if(row == 0) { 
      digitalWrite(pinRowData, HIGH);
      delayMicroseconds(10);  
    } else {
      digitalWrite(pinRowData, LOW);
      delayMicroseconds(10);  
    }
    /* Advance the row pointer */
    digitalWrite(pinRowClock, LOW);   
    /* Minimum 1us dip */
    delayMicroseconds(10);  
    digitalWrite(pinRowClock, HIGH);

    /* Reenable display */
    digitalWrite(pinDisplayEnable, HIGH); 
    delayMicroseconds(100);
  }
}

/* Initialize the OPPA controller */
void oppaInit() {
  
}

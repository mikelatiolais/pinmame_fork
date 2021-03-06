#include "oppa_display.h"
#include <stdio.h>
#include <pthread.h>

UINT8 oppadmd[OPPA_NUM_DMD_FRAMES][4096];
static const int CHANNEL = 1;
/* Threads for OPPA */
/* dmd_thread will draw threads based on interprocess communication */
pthread_t dmd_thread;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


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

  /* Start DMD thread */
  
}

void oppaBlankDMD() {
  digitalWrite(pinDisplayEnable, LOW);
}

/* Take in array and update the DMD directly */
void oppaUpdateDMDold(UINT8 *dotData) {
  //printf("In update DMD\n");
 
  int row; 
  for(row = 0; row < OPPA_NUM_OF_ROWS; row++) {
    int index;
    /* From Vishay doc: Once each frame the ROW DATA must be asserted to synchronize the column serial data with the beginning row */
    /* Latch the row of data */
    digitalWrite(pinColLatch, LOW);
    /* 128 dots / 8 (size of byte) = 16 */ 
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
    delayMicroseconds(0);  
    digitalWrite(pinRowClock, HIGH);

    /* Reenable display */
    digitalWrite(pinDisplayEnable, HIGH); 
    delayMicroseconds(2);  

  }
}

/* Take in array and update the DMD directly */
void oppaUpdateDMD(UINT8 *dotData) {
  //printf("In update DMD\n");
 
  int row; 
  /* Row data - This signal is the first line marker for the scan.
     This input should be held high to correspond to the first row
     of pixel data 
  */
  digitalWrite(pinRowData, HIGH);
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
    delayMicroseconds(0);  
    digitalWrite(pinRowClock, HIGH);

    /* Reenable display */
    digitalWrite(pinDisplayEnable, HIGH); 
    delayMicroseconds(2);  

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


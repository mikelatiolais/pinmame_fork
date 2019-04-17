#ifndef INC_OPPA_MAIN
#define INC_OPPA_MAIN
typedef unsigned char  UINT8;

#include <wiringPi.h>
#include <wiringShift.h>
#include <wiringSerial.h>

/*
// Gameitem functions
void procSetSwitchStates(void);
void procDriveLamp(int num, int state);
void procDriveCoilDirect(int num, int state);
void procDriveCoil(int num, int state);
void procGetSwitchEvents(void);
void procInitializeCoilDrivers(void);
void procCheckActiveCoils(void);
void procConfigureDefaultSwitchRules(void);
void procConfigureDriverDefaults(void);
void procFlipperRelay(int state);
void procFullTroughDisablesFlippers(void);
void procConfigureFlipperSwitchRules(int enabled);
void procConfigureSwitchRules(int enabled);
void procConfigureInputMap(void);
void procKickbackCheck(int num);
void procConfigureRGBLamps(void);
void procDisableAuxBus(void);
void AddIgnoreCoil(int num);
*/

/* Initialize the oppa board */
void oppa_init();

/* Get current physical switch states */
void oppa_getSwitches();

/* Update LEDs */
void oppa_setLEDs();

/* Clear LEDs */
void oppa_resetLEDs();

/* Set solenoids */
void oppa_setSolenoid();

/* Reset solenoids */
void oppa_resetSolenoids();

/* Set GI String */
void oppa_setGIString();

/* Serial Protocol */

/* READ_BANK_CMD - read one bank(8 bits) from the OPPA board */
/* 1 byte argument - ID of bank to read                      */
#define READ_BANK_CMD  b'\x01'

/* GET_BANK_CFG_CMD - Read number of banks connected to controller */
#define READ_BANK_CFG_CMD  b'\x02'

/* GI_BANK_LIGHT_CMD - Light a whole GI bank */
#define GI_BANK_LIGHT_CMD  b'\x01'

/* READ_BANK_CMD - read one bank(8 bits) from the OPPA board */
#define GI_BANK_BLINK_CMD  b'\x01'

/* RESET_CMD - Clears OPPA switch states and stops all LED and solenoid activity except for GI */
#define RESET_CMD  b'\x04'

#define GO_BOOT_CMD  b'\x05'
#define CFG_SOL_CMD  b'\x06'
#define KICK_SOL_CMD  b'\x07'
#define CFG_INP_CMD  b'\x09'
#define SAVE_CFG_CMD  b'\x0b'
#define ERASE_CFG_CMD  b'\x0c'
#define CHNG_NEO_CMD  b'\x0f'
#define CHNG_NEO_COLOR  b'\x10'
#define CHNG_NEO_COLOR_TBL  b'\x11'
#define SET_NEO_COLOR_TBL  b'\x12'
#define INCAND_CMD  b'\x13'
#define CFG_IND_SOL_CMD  b'\x14'
#define CFG_IND_INP_CMD  b'\x15'
#define SET_IND_NEO_CMD  b'\x16'
#define SET_SOL_INP_CMD  b'\x17'
#define UPGRADE_OTHER_BRD  b'\x18'
#define READ_MATRIX_INP  b'\x19'
#define INV_CMD  b'\xf0'
#define ILLEGAL_CMD  b'\xfe'
#define EOM_CMD  b'\xff'



#define WING_SOL  b'\x01'
#define WING_INP  b'\x02'
#define WING_INCAND  b'\x03'
#define WING_SW_MATRIX_OUT  b'\x04'
#define WING_SW_MATRIX_IN  b'\x05'
#define WING_NEO  b'\x06'
#define WING_HI_SIDE_INCAND  b'\x07'
#define NUM_G2_INP_PER_BRD  32
#define CFG_INP_STATE  b'\x00'
#define CFG_INP_FALL_EDGE  b'\x01'
#define CFG_INP_RISE_EDGE  b'\x02'
#define CFG_BYTES_PER_SOL  3
#define INIT_KICK_OFFSET  1
#define DUTY_CYCLE_OFFSET  2
#define NUM_G2_SOL_PER_BRD  16
#define CFG_SOL_DISABLE  b'\x00'
#define CFG_SOL_USE_SWITCH  b'\x01'
#define CFG_SOL_AUTO_CLR  b'\x02'
#define CFG_SOL_ON_OFF  b'\x04'
#define CFG_SOL_DLY_KICK  b'\x08'
#define CFG_SOL_USE_MTRX_INP  b'\x10'
#define CFG_SOL_CAN_CANCEL  b'\x20'
#define CFG_SOL_INP_REMOVE  b'\x80'
#define NUM_COLOR_TBL  32
#define INCAND_ROT_LEFT  b'\x00'
#define INCAND_ROT_RIGHT  b'\x01'
#define INCAND_LED_ON  b'\x02'
#define INCAND_LED_OFF  b'\x03'
#define INCAND_BLINK_SLOW  b'\x04'
#define INCAND_BLINK_FAST  b'\x05'
#define INCAND_BLINK_OFF  b'\x06'
#define INCAND_SET_ON_OFF  b'\x07'
#define INCAND_SET_CMD  b'\x80'
#define INCAND_SET_ON  b'\x01'
#define INCAND_SET_BLINK_SLOW  b'\x02'
#define INCAND_SET_BLINK_FAST  b'\x04'

#endif /* INC_OPPA_MAIN */

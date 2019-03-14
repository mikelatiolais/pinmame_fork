#ifndef INC_OPPA_MAIN
#define INC_OPPA_MAIN
typedef unsigned char  UINT8;

#include <wiringPi.h>
#include <wiringShift.h>


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

void oppa_init();

#endif /* INC_OPPA_MAIN */

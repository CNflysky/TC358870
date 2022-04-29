#ifndef _TC358870_PANEL_H_
#define _TC358870_PANEL_H_

#define LT070ME05000
//#define TPM0551002P
//#define VVX10F034N00

#include "tc358870_gpio.h"
#include "tc358870_i2c.h"
#define Waitx1ms(x) HAL_Delay(x)
#define Waitx1us(x) HAL_Delay(1)

extern void RS1();
extern void RS3();
extern void panel_backlight_setup();
void RS_Int();
#endif
#ifndef _TC358870_PANEL_H_
#define _TC358870_PANEL_H_

#define LT070ME05000
// #define TPM0551002P

#include "tc358870_i2c.h"
#define Waitx1ms(x) HAL_Delay(x)
#define Waitx1us(x) HAL_Delay(1)
void RS1();
void RS_Int();
#endif
#ifndef _LED_H
#define _LED_H

#include "types.h"
#include "gpio.h"

#define LED_ON(n)    Set_Bit(GPMDAT, n, 0)
#define LED_OFF(n)   Set_Bit(GPMDAT, n, 1)
void LED_Init(void);

#endif








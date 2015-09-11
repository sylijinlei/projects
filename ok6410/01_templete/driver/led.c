#include "led.h"
#include "gpio.h"
#include "types.h"
void LED_Init(void)
{	
	Set_4Bit(GPMCON, 0, 1);
	Set_4Bit(GPMCON, 1, 1);
	Set_4Bit(GPMCON, 2, 1);
	Set_4Bit(GPMCON, 3, 1);

}


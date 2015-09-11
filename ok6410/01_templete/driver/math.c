#include "math.h"
#include "types.h"

u8 htoc(u8 c)
{
		if(c >= 0 && c <=9)
			return c+0x30;
		else
			return c+0x61-10;
	
}
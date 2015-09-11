#include "gpio.h"
#include "uart.h"
#include "types.h"
#include "led.h"
#include "math.h"
#include "stdio.h"
#include "nand.h"

void delay(int i)
{
    volatile int j, k;
    for(; i > 0; i--)
    {	
        for(j = 0; j < 60; j++)
            for(k = 0; k < 30; k++);
    }

}

int main()
{
    
    UART_Init();
    LED_Init();
    LED_ON(0);
    LED_OFF(1);
    LED_ON(2);
    LED_ON(3);
    while (1)
    {
        nand_test();
    }

    return 0;
}

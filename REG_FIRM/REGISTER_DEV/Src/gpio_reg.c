#include "gpio_reg.h"



void GPIO_init()
{
	Clock_init();
	PC->PU |= (1<<26);
	/* Configure for PA5 */
	PA->MODE |= (1<<10);
	PA->TYPE &= ~(1<<5);
	PA->SPEED |= (1<<10);
	/* Configure for PC13 */
	PC->MODE |= (1<<26);
	PC->TYPE &= ~(1<<13);
	PC->SPEED |= (1<<26);
}







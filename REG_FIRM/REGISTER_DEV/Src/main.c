/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "clock_reg.h"
#include "gpio_reg.h"


int main(void)
{
    /* Loop forever */
	GPIO_init();
	/* Clear I/O state*/
	PA->OUT |= (1<<5);
	PC->OUT |= (1<<13);
	while(1)
	{
		PC->OUT ^= (1<<13);
		Delay_ms(200);
	}
}
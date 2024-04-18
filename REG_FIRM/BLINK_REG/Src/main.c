/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kyuubi
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
#include <stdio.h>
//#include

#define PERIPH_BASE 0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE_ADDR (AHB1PERIPH_BASE + 0x3800UL)
#define RCC_CR_REG_OFFSET 0x00UL
#define RCC_CFGR_REG_OFFSET 0x08UL
#define RCC_CR_REG_ADDR (RCC_BASE_ADDR + RCC_CR_REG_OFFSET)
#define RCC_CFGR_REG_ADDR (RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET)

#define GPIOA_BASE_ADDR (AHB1PERIPH_BASE + 0x000UL)
#define GPIOC_BASE_ADDR (AHB1PERIPH_BASE + 0x800UL)

#define RCC_AHB1ENR_ADDR (RCC_BASE_ADDR + 0x30UL)





uint32_t *pRccCrReg = (uint32_t *) RCC_CR_REG_ADDR;
uint32_t *pRccCfgrReg = (uint32_t *) RCC_CFGR_REG_ADDR;
uint32_t *pRccAhb1enrReg = (uint32_t *) RCC_AHB1ENR_ADDR;

typedef struct
{
	volatile uint32_t CR;
	uint32_t RV1[11];
	volatile uint32_t AHB1;
	volatile uint32_t AHB2;
	uint32_t RV2[2];
	volatile uint32_t APB1;
	volatile uint32_t APB2;
}RCC_OFF;

#define RCC		((RCC_OFF *) RCC_BASE_ADDR)

typedef struct
{
	volatile uint32_t MODE; /* GPIO port mode reg    Offset: 0x00*/
	volatile uint32_t TYPE; /* output type 			Offset: 0x04*/
	volatile uint32_t SPEED; /* output speed			Offset: 0x08*/
	volatile uint32_t PU;   /* pull up/pull down 			Offset: 0x0C*/
	volatile uint32_t IN;   /* input data 			Offset: 0x10*/
	volatile uint32_t OUT;  /* output data		Offset: 0x14*/
	volatile uint32_t BSRR;  /* bit set/reset 			Offset: 0x18*/
}GPIO_OFF;

#define PA		((GPIO_OFF *) GPIOA_BASE_ADDR)
#define PC		((GPIO_OFF *) GPIOC_BASE_ADDR)

void Clock_init()
{
	RCC->CR |= (1<<0);
	RCC->AHB1 |= (1<<0) | (1<<2);
}

void Delay(uint32_t time)
{
	uint32_t i;
	while(time--)
	{
		for(i=0;i<1000;i++);
	}
}

void GPIO_init()
{
	Clock_init();

	PC->PU |= (1<<26);

	PA->MODE |= (1<<10);
	PA->TYPE &= ~(1<<5);
	PA->SPEED |= (1<<10);

	PC->MODE |= (1<<26);
	PC->TYPE &= ~(1<<13);
	PC->SPEED |= (1<<26);




}


int main(void)
{
//	/* HSEON = 1 */
//	*pRccCrReg |= (1<<16);
//	while(!(*pRccCrReg & (1<<17)));
//	/* Select HSE as system clock */
//	*pRccCfgrReg |= (1<<0);
//	//Enable GPIO A,C Clock
//	*pRccAhb1enrReg |= (1<<0) | (1<<2) ;

	Clock_init();
	GPIO_init();

	PA->OUT |= (1<<5);
	PC->OUT |= (1<<13);


    /* Loop forever */
	while(1)
	{
		PC->OUT ^= (1<<13);
		Delay(1000);
	}
}

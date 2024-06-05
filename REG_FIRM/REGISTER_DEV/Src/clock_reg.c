#include "clock_reg.h"

uint32_t *pRccCrReg = (uint32_t *) RCC_CR_ADDR;
uint32_t *pRccCfgrReg = (uint32_t *) RCC_CFGR_ADDR;
uint32_t *pRccAhb1enrReg = (uint32_t *) RCC_AHB1ENR_ADDR;
uint32_t *pRccAhb2enrReg = (uint32_t *) RCC_AHB2ENR_ADDR;
uint32_t *pRccApb1enrReg = (uint32_t *) RCC_APB1ENR_ADDR;
uint32_t *pRccApb2enrReg = (uint32_t *) RCC_APB2ENR_ADDR;

void Clock_init()
{
	/*Turn off HSI*/
	RCC->CR |= (1<<0);
	/* Select HSE as system clock*/
	RCC->CR |= (1<<16);
	/*Enable clock for GPIOA, GPIOB and GPIOC*/
	RCC->AHB1 |= (1<<0) | (1<<1) | (1<<2);
}

void Delay_ms(uint32_t time)
{
	uint32_t i;
	while(time--)
	{
		for(i=0; i<1000; i++);
	}
}

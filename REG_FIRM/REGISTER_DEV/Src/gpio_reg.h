#ifndef _GPIO_REG_H_
#define _GPIO_REG_H_

#include "clock_reg.h"

#define GPIO_BASE_ADDR 0x40020000UL

#define GPIOA_BASE_ADDR (GPIO_BASE_ADDR + 0x00UL)
#define GPIOB_BASE_ADDR (GPIO_BASE_ADDR + 0x400UL)
#define GPIOC_BASE_ADDR (GPIO_BASE_ADDR + 0x800UL)
#define GPIOD_BASE_ADDR (GPIO_BASE_ADDR + 0xC00UL)

typedef struct
{
		volatile uint32_t MODE; /* GPIO port mode reg    Offset: 0x00*/
		volatile uint32_t TYPE; /* output type 			Offset: 0x04*/
		volatile uint32_t SPEED; /* output speed			Offset: 0x08*/
		volatile uint32_t PU;   /* pull up/pull down 			Offset: 0x0C*/
		volatile uint32_t IN;   /* input data 			Offset: 0x10*/
		volatile uint32_t OUT;  /* output data		Offset: 0x14*/
		volatile uint32_t BSRR;  /* bit set/reset 			Offset: 0x18*/
		volatile uint32_t LCK;
		volatile uint32_t AFRL;
		volatile uint32_t AFRH;
}GPIO_OFF;

#define PA		((GPIO_OFF *) GPIOA_BASE_ADDR)
#define PB		((GPIO_OFF *) GPIOB_BASE_ADDR)
#define PC		((GPIO_OFF *) GPIOC_BASE_ADDR)
#define PD		((GPIO_OFF *) GPIOD_BASE_ADDR)


void GPIO_init(void);





#endif

#ifndef _UART_REG_H_
#define _UART_REG_H_

#include <stdint.h>

#define APB2_BUS_ADDR		0x40010000UL

#define USART1_ADDR_OFFSET	0x1000UL
#define USART1_ADDR			(APB2_BUS_ADDR + USART1_ADDR_OFFSET)

#define UART_MODE_MASTER	(1<<3)
#define UART_MODE_SLAVE 	(1<<2)

typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}UART_OFF;

#define UART1		((UART_OFF *) USART1_ADDR)

void uart1_init(uint8_t Mode);
void GPIOA_tx_rx_uart1(void);
void uart1_send_data(uint8_t *TxBuffer, uint8_t length);
void uart1_recv_data(uint8_t *RxBuffer, uint8_t length);

#endif

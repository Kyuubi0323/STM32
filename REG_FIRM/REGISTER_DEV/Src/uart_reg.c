#include "uart_reg.h"
#include "gpio_reg.h"
#include "clock_reg.h"

void uart1_init(uint8_t Mode)
{
	uint32_t usartdiv;
	uint32_t M_part, F_part;
	/*Enable Clock for USART1 */
	Clock_init();
	GPIOA_tx_rx_uart1();
	/* Enable TX-Master or RX-Slave */
	UART1->CR1 |= Mode;
	/* bit M - 8 bits Data */
	UART1->CR1 &= ~(1<<12);
	/* Implement the code to enable the parity control */
	UART1->CR1 &= ~( 1 << 10);
	/* Setup Baudrate - 9600, CLK = 16MHz
		 * Mantissa =
		 * Fraction = */
	/* OVER8 = 0 -> Oversampling by 16 */
	UART1->CR1 &= ~(1 << 15);
	usartdiv = ((25 * 16000000) / (4 * 9600));
	M_part = usartdiv / 100;
	F_part = (usartdiv - (M_part * 100));
	F_part = ((( F_part * 16)+ 50) / 100) & ((uint8_t)0x0F);
	UART1->BRR |= F_part;
	UART1->BRR |= (M_part << 4);


	/* bit UE - Enable UART */
	UART1->CR1 |= (1 << 13);

}
void GPIOA_tx_rx_uart1(void)
{
	/* set PA9 as uart1 Tx */
	PA->MODE |= (0x2 << 18); //alternate
	PA->TYPE &= ~(0x1 << 9); //push pull
	PA->PU |= (0x1 << 9); //pull up
	PA->AFRH |= (0x7 << 4); //alternate set up
}

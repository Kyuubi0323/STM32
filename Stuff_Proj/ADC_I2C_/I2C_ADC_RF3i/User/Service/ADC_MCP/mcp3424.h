#ifndef _MCP3424_H_
#define _MCP3424_H_

#include "stm32f1xx_hal.h"

/* would be good to have explanation of what each variable does.*/
I2C_HandleTypeDef*	pI2CHandle;
UART_HandleTypeDef* pUARTHandle;

uint8_t ADCdatarecv[5] = {0};

uint16_t MCP3424add = 0b0000000001101000;
uint32_t ADCval = 0;
int Resolution = 12;
/* Configuration
 * Once  the  conversion  is completed, RDY bit is toggled to ‘0’
 * and the result is placed   at   the   output   data   register.
 * The device  clears  the  data  ready  flag  (RDY  bit =0)  when the conversion is completed.
 * The device sets the readyflag bit (RDY bit =1),
 *  if the latest conversion result has been read by the Master.
 *  Setting RDY bit in continuous mode does not affect anything
 * Continuous Conversion
 * channel 1
 * Sample rate 12bits(240 SPS)
 * x1 GAIN
 */
uint8_t configSet = 0b10010000;

void MCP3424_Init(I2C_HandleTypeDef* pI2C, UART_HandleTypeDef* pUART);

#endif /* MCP3424_H_ */


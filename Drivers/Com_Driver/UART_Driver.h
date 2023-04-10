/*
 * UART_Driver.h
 *
 *  Created on: Apr 10, 2023
 *      Author: conti
 */

#ifndef COM_DRIVER_UART_DRIVER_H_
#define COM_DRIVER_UART_DRIVER_H_

#include "stm32f4xx_hal.h"

#define UART_TIMEOUT				1U

void UART_Error_Handler(void);

void UART_Init(void);



#endif /* COM_DRIVER_UART_DRIVER_H_ */

/*
 * Communication_Driver.c
 *
 *  Created on: Apr 12, 2023
 *      Author: BRG
 */

#include "Communication_Driver.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_uart.h"
#include <string.h>

UART_HandleTypeDef UART_Handler;


//---------------------------------------------------<Communication Driver PRIVATE>---------------------------------------------------------

void UART2_Configuration(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); /* Enable clock to PORTA - UART2 pins PA2 and PA3 */
	__HAL_RCC_USART2_CLK_ENABLE(); /* Enable clock to UART2 module */

	GPIO_InitTypeDef UART2_GPIO_Handler; /*Create GPIO_InitTypeDef struct instance */
	UART2_GPIO_Handler.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	UART2_GPIO_Handler.Mode = GPIO_MODE_AF_PP;
	UART2_GPIO_Handler.Pull = GPIO_PULLUP;
	UART2_GPIO_Handler.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	UART2_GPIO_Handler.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &UART2_GPIO_Handler);

	//UART Configuration

	UART_Handler.Instance = USART2;
	UART_Handler.Init.BaudRate = 115200;
	UART_Handler.Init.Mode = UART_MODE_TX_RX;
	UART_Handler.Init.WordLength = UART_WORDLENGTH_8B;
	UART_Handler.Init.StopBits = UART_STOPBITS_1;
	UART_Handler.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&UART_Handler);
}

//---------------------------------------------------</Communication Driver PRIVATE>---------------------------------------------------------

void Communication_Driver_Init(void){
	UART2_Configuration();
}

void Communication_Driver_Log_To_Pc(char* message)
{
	HAL_UART_Transmit(&UART_Handler, (uint8_t *)message, strlen(message), 10);
}

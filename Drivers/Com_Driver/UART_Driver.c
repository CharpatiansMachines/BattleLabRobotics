/*
 * UART_Driver.c
 *
 *  Created on: Apr 10, 2023
 *      Author: conti
 */


#include "UART_Driver.h"

UART_HandleTypeDef huart1;

void UART_Test (void)
{
	char lu8_status[10]="Init Done";

	UART_Init();

	HAL_UART_Transmit(&huart1, (uint8_t*)lu8_status, sizeof(lu8_status), UART_TIMEOUT);
}


/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void UART_Error_Handler(void)
{
	while (1)
	{
		/*ERROR*/
	}
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void UART_Init(void)
{
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart1) != HAL_OK)
	{
		UART_Error_Handler();
	}
}

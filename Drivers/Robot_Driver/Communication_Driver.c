/*
 * Communication_Driver.c
 *
 *  Created on: Apr 12, 2023
 *      Author: BRG
 */

#include "Communication_Driver.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_uart.h"


#include "usb_device.h"
#include "usbd_cdc_if.h"

#include <string.h>

UART_HandleTypeDef UART_Handler;
ADC_HandleTypeDef hTrimpots_adc;
uint8_t Communication_Driver_Trimpots_Data[4];


//---------------------------------------------------<Communication Driver PRIVATE>---------------------------------------------------------

void Trimpots_ADC_INIT()
{

	 ADC_ChannelConfTypeDef sConfig = {0};

	  /* USER CODE BEGIN ADC1_Init 1 */

	  /* USER CODE END ADC1_Init 1 */

	  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	  */
	  hTrimpots_adc.Instance = ADC1;
	  hTrimpots_adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	  hTrimpots_adc.Init.Resolution = ADC_RESOLUTION_12B;
	  hTrimpots_adc.Init.ScanConvMode = ENABLE;
	  hTrimpots_adc.Init.ContinuousConvMode = ENABLE;
	  hTrimpots_adc.Init.DiscontinuousConvMode = DISABLE;
	  hTrimpots_adc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hTrimpots_adc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hTrimpots_adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hTrimpots_adc.Init.NbrOfConversion = 2;
	  hTrimpots_adc.Init.DMAContinuousRequests = ENABLE;
	  hTrimpots_adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  if (HAL_ADC_Init(&hTrimpots_adc) != HAL_OK)
	  {

	  }

	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_14;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hTrimpots_adc, &sConfig) != HAL_OK)
	  {

	  }

	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_15;
	  sConfig.Rank = 2;
	  if (HAL_ADC_ConfigChannel(&hTrimpots_adc, &sConfig) != HAL_OK)
	  {

	  }
}

//---------------------------------------------------</Communication Driver PRIVATE>---------------------------------------------------------

void Communication_Driver_Init(void){
	MX_USB_DEVICE_Init();
	Trimpots_ADC_INIT();
}
void Communication_Drive_Read_Trimpots(void)
{
	HAL_ADC_Start_DMA(&hTrimpots_adc, (uint32_t *)Communication_Driver_Trimpots_Data, 4);
	HAL_Delay(1);
    HAL_ADC_Stop(&hTrimpots_adc);
}

uint8_t Communication_Driver_Log_To_Pc(char *message)
{
//	uint8_t status;
//	do{
//		status = CDC_Transmit_FS((uint8_t*)message, strlen(message) );
//	}while(status == USBD_BUSY);
	while(CDC_Transmit_FS((uint8_t*)message, strlen(message) ) == USBD_BUSY);

	return 1;
}

void Communication_Driver_Test_Log_To_Pc(void){
	Communication_Driver_Init();
	while(1)
	{
		Communication_Drive_Read_Trimpots();
		char s[100] = "";
		sprintf(s,"%d %d\r\n",Communication_Driver_Trimpots_Data[0],Communication_Driver_Trimpots_Data[1]);
		Communication_Driver_Log_To_Pc(s);
		Communication_Driver_Log_To_Pc("------------------------------------------------------\r\n");
		HAL_Delay(500);
	}
}

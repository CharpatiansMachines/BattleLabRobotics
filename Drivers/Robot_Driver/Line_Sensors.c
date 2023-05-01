/*
 * LineDetection.c
 *
 *  Created on: Apr 10, 2023
 *      Author: BRG
 */
#include "Line_Sensors.h"
#include "stm32f4xx_hal_adc.h"
//#include "stm32f4xx_hal_gpio.h"

#define SENSORS_GPIO GPIOA

#define SENSOR_FRONTL_PIN GPIO_PIN_6
#define SENSOR_FRONTR_PIN GPIO_PIN_1
#define SENSOR_BACKL_PIN GPIO_PIN_2
#define SENSOR_BACKR_PIN GPIO_PIN_3

#define SENSORS_FRONT_ADC ADC2
#define SENSORS_BACK_ADC ADC3

#define SENSOR_FRONTL_CHANNEL ADC_CHANNEL_6
#define SENSOR_FRONTR_CHANNEL ADC_CHANNEL_1
#define SENSOR_BACKL_CHANNEL ADC_CHANNEL_2
#define SENSOR_BACKR_CHANNEL ADC_CHANNEL_3

//#define

uint8_t u8_Line_Sensors_data;

///---------------------------------------------------<Enemy Sensors PRIVATE>---------------------------------------------------------
ADC_HandleTypeDef hFront_ADC = {};
ADC_HandleTypeDef hBack_ADC = {};

static void configure_adc_for_line(ADC_HandleTypeDef *hadc,ADC_TypeDef *adc){

	hadc->Instance = ADC1;
	hadc->Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	hadc->Init.Resolution = ADC_RESOLUTION_12B;
	hadc->Init.ScanConvMode = DISABLE;
	hadc->Init.ContinuousConvMode = DISABLE;
	hadc->Init.DiscontinuousConvMode = DISABLE;
	hadc->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc->Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc->Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc->Init.NbrOfConversion = 1;
	hadc->Init.DMAContinuousRequests = DISABLE;
	hadc->Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	if (HAL_ADC_Init(hadc) != HAL_OK)
	{
		Error_Handler();
	}
}


static uint32_t read_2_ADC_Simultaneous(ADC_HandleTypeDef *hadc1,ADC_HandleTypeDef *hadc2,uint32_t channel1,uint32_t channel2){
	ADC_ChannelConfTypeDef channel1_conf = {0};
	channel1_conf.Channel = channel1;
	channel1_conf.Rank = 1;
	channel1_conf.SamplingTime = ADC_SAMPLETIME_3CYCLES;

	ADC_ChannelConfTypeDef channel2_conf = {0};
	channel2_conf.Channel = channel2;
	channel2_conf.Rank = 1;
	channel2_conf.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	if (HAL_ADC_ConfigChannel(&hadc1, &channel1_conf) != HAL_OK)
	{
	Error_Handler();
	}
	if (HAL_ADC_ConfigChannel(&hadc1, &channel2_conf) != HAL_OK)
	{
		Error_Handler();
	}

	HAL_ADC_Start(&hadc1);
	HAL_ADC_Start(&hadc2);

	if(HAL_ADC_PollForConversion(&hadc1, 5) == HAL_OK && HAL_ADC_PollForConversion(&hadc2, 5) == HAL_OK){
		uint32_t value1 = HAL_ADC_GetValue(&hadc1);
		uint32_t value2 = HAL_ADC_GetValue(&hadc1);
		return value1 << 16 | value2;
	}else{
		return 0;
	}


}

void interpreate_data(uint32_t data, uint8_t mask)
{

}
///---------------------------------------------------</Enemy Sensors PRIVATE>---------------------------------------------------------


void Line_Sensors_Init(void){
	configure_adc_for_line(&hFront_ADC, SENSORS_FRONT_ADC);
	configure_adc_for_line(&hBack_ADC, SENSORS_BACK_ADC);


}
uint8_t Line_Sensors_Read(void){
	uint32_t firstValue =  read_2_ADC_Simultaneous(&hFront_ADC, &hBack_ADC, SENSOR_FRONTL_CHANNEL, SENSOR_BACKL_CHANNEL);
	uint32_t secondValue = read_2_ADC_Simultaneous(&hFront_ADC, &hBack_ADC, SENSOR_FRONTR_CHANNEL, SENSOR_BACKR_CHANNEL);

	uint32_t frontL = firstValue >> 16;
	uint32_t backL = firstValue & 0x0000FFFFU;
	uint32_t frontR = secondValue >> 16;
	uint32_t backR = secondValue & 0x0000FFFFU;

	return 0;
}

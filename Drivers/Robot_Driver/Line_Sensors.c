/*
 * LineDetection.c
 *
 *  Created on: Apr 10, 2023
 *      Author: BRG
 */
#include "Line_Sensors.h"
#include "stm32f4xx_hal_adc.h"
#include <strings.h>
#include <stdio.h>




///---------------------------------------------------<Enemy Sensors PRIVATE>---------------------------------------------------------
#define LINE_SENSORS_OUTPUT_SIZE 8
#define LINE_SENSORS_NUMBER 4

#define SENNSOR_FRONTL_OFFSET 0x00    //A1
#define SENNSOR_FRONTR_OFFSET 0x01    //A2
#define SENNSOR_BACKL_OFFSET 0x02     //A3
#define SENNSOR_BACKR_OFFSET 0x03    //A6

#define IS_WHITE_FILTER 100
#define IS_BLACK_FILTER 150


uint8_t sensorsOutput[LINE_SENSORS_OUTPUT_SIZE];
ADC_HandleTypeDef hLine_Sensors_ADC;



/**
 *
 * @param sensor_output
 * @return 1 for white 0 for black or 2 for nothing
 */
uint8_t output_to_value(uint8_t sensor_output){
	if(sensor_output >= IS_BLACK_FILTER)
		return 0;
	if(sensor_output <= IS_WHITE_FILTER)
		return 1;

	return 2;
}

/**
 * wait until all values are white or all values are black
 * @param sensor_offset
 * @return 1 for white and 0 for black
 */
uint8_t check_sensor_wait_for_all_values(uint8_t sensor_offset){
	uint8_t all_the_same = 0;
	uint8_t firstValue;
	while(all_the_same == 0)
	{
		firstValue = output_to_value(sensorsOutput[sensor_offset]);
		if(firstValue == 2)
			continue;

		all_the_same = 1;
		for(uint8_t i = sensor_offset + LINE_SENSORS_NUMBER; i < LINE_SENSORS_OUTPUT_SIZE; i+= LINE_SENSORS_NUMBER){
			if(output_to_value(sensorsOutput[i]) != firstValue)
			{
				all_the_same = 0;
				break;
			}
		}
	}
	return firstValue;

}

///---------------------------------------------------</Enemy Sensors PRIVATE>---------------------------------------------------------


void Line_Sensors_Init(void)
{


	  ADC_ChannelConfTypeDef sConfig = {0};
	  hLine_Sensors_ADC.Instance = ADC2;
	  hLine_Sensors_ADC.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	  hLine_Sensors_ADC.Init.Resolution = ADC_RESOLUTION_8B;
	  hLine_Sensors_ADC.Init.ScanConvMode = ENABLE;
	  hLine_Sensors_ADC.Init.ContinuousConvMode = ENABLE;
	  hLine_Sensors_ADC.Init.DiscontinuousConvMode = DISABLE;
	  hLine_Sensors_ADC.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hLine_Sensors_ADC.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hLine_Sensors_ADC.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hLine_Sensors_ADC.Init.NbrOfConversion = 4;
	  hLine_Sensors_ADC.Init.DMAContinuousRequests = ENABLE;
	  hLine_Sensors_ADC.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  if (HAL_ADC_Init(&hLine_Sensors_ADC) != HAL_OK)
	  {

	  }

	  sConfig.Channel = ADC_CHANNEL_1;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hLine_Sensors_ADC, &sConfig) != HAL_OK)
	  {

	  }

	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_2;
	  sConfig.Rank = 2;
	  if (HAL_ADC_ConfigChannel(&hLine_Sensors_ADC, &sConfig) != HAL_OK)
	  {

	  }

	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_3;
	  sConfig.Rank = 3;
	  if (HAL_ADC_ConfigChannel(&hLine_Sensors_ADC, &sConfig) != HAL_OK)
	  {

	  }

	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  sConfig.Channel = ADC_CHANNEL_6;
	  sConfig.Rank = 4;
	  if (HAL_ADC_ConfigChannel(&hLine_Sensors_ADC, &sConfig) != HAL_OK)
	  {

	  }
}
uint8_t Line_Sensors_Read(void)
{

	HAL_ADC_Start_DMA(&hLine_Sensors_ADC, (uint32_t *)sensorsOutput, LINE_SENSORS_OUTPUT_SIZE);
	uint8_t Line_Sensors_data = 0;
	Line_Sensors_data |= check_sensor_wait_for_all_values(SENNSOR_FRONTL_OFFSET);
	Line_Sensors_data |= check_sensor_wait_for_all_values(SENNSOR_FRONTR_OFFSET) << 1;
	Line_Sensors_data |= check_sensor_wait_for_all_values(SENNSOR_BACKL_OFFSET)  << 2;
	Line_Sensors_data |= check_sensor_wait_for_all_values(SENNSOR_BACKR_OFFSET)  << 3;
	HAL_ADC_Stop_DMA(&hLine_Sensors_ADC);

	return Line_Sensors_data;
}

void Line_Sensors_Test_Sensors_Output(uint8_t (*log_function)(char *))
{
	Line_Sensors_Init();
	HAL_ADC_Start_DMA(&hLine_Sensors_ADC, (uint32_t *)sensorsOutput, LINE_SENSORS_OUTPUT_SIZE);
	while(1)
	{
		char s[100] = "";
		(* log_function)("Sensors 0 values : ");
		for(int i = 0 ; i < LINE_SENSORS_OUTPUT_SIZE ; i+= LINE_SENSORS_NUMBER)
		{
			sprintf(s, "%d ,", (int)sensorsOutput[i]);
			(* log_function)(s);
		}
		(* log_function)("\r\n");

		(* log_function)("Sensors 1 values : ");
		for(int i = 1 ; i < LINE_SENSORS_OUTPUT_SIZE ; i+= LINE_SENSORS_NUMBER)
		{
			sprintf(s, "%d ,", (int)sensorsOutput[i]);
			(* log_function)(s);
		}
		(* log_function)("\r\n");

		(* log_function)("Sensors 2 values : ");
		for(int i = 2 ; i < LINE_SENSORS_OUTPUT_SIZE ; i+= LINE_SENSORS_NUMBER)
		{
			sprintf(s, "%d ,", (int)sensorsOutput[i]);
			(* log_function)(s);
		}
		(* log_function)("\r\n");

		(* log_function)("Sensors 3 values : ");
		for(int i = 3 ; i < LINE_SENSORS_OUTPUT_SIZE ; i+= LINE_SENSORS_NUMBER)
		{
			sprintf(s, "%d ,", (int)sensorsOutput[i]);
			(* log_function)(s);
		}
		(* log_function)("\r\n");
		(* log_function)("-------------------------------------------\r\n");

		HAL_Delay(300);
	}
}
void Line_Sensors_Test(uint8_t (*log_function)(char *))
{
	Line_Sensors_Init();
	while(1)
	{
		char s[100] = "";
		uint8_t Line_Sensors_data = Line_Sensors_Read();
		sprintf(s, "%d ------ %d\r\n\r\n%d ------ %d\r\n",
				Line_Sensors_data & LINE_DETECTION_FRONTL_MASK,
				Line_Sensors_data & LINE_DETECTION_FRONTR_MASK,
				Line_Sensors_data & LINE_DETECTION_BACKL_MASK,
				Line_Sensors_data & LINE_DETECTION_BACKR_MASK
		);
		(* log_function)(s);

		(* log_function)("-------------------------------------------\r\n\r\n");

		HAL_Delay(300);
	}


}

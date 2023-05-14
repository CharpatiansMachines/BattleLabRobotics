/*
 * motor_drv.c
 *
 *  Created on: Apr 5, 2023
 *      Author: paul.contis
 *
 *      Naming conventions:
 *
 *      |   VARIABLE TYPE  |      8 BITS     |      16 BITS     |     32 BITS      |
 *      |------------------|-----------------|------------------|------------------|
 *      | local variables  | lu8_VaribleName | lu16_VaribleName | lu32_VaribleName |
 *      | global variables | gu8_VaribleName | gu16_VaribleName | gu32_VaribleName |
 *      | static variables | su8_VaribleName | su16_VaribleName | su32_VaribleName |
 *
 *
 *          typedef Name_t
 *
 */

/*==============================================================================*/
/*                     INCLUDE - Required dependencies                          */
/*==============================================================================*/
#include "motor_driver.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>

/*==============================================================================*/
/*                                Local Define                                  */
/*==============================================================================*/


/*==============================================================================*/
/*                             Global Variables                                 */
/*==============================================================================*/

UART_HandleTypeDef h_motor_uart;

/*==============================================================================*/
/*                                  Macro                                       */
/*==============================================================================*/

//TODO

/*==============================================================================*/
/*                       Private Functions Declaration                          */
/*==============================================================================*/


uint8_t motor_power_to_motor_input(int8_t motor_command,int8_t is_right_motor){
	float convert = 100 + motor_command;
	if(is_right_motor){
		if(motor_command <= 0){
			convert = 100 + motor_command;
			convert = convert * 64/100 + 128;
		}else{
			convert = motor_command;
			convert = convert * 63/100 + 192;

		}
	}else{
		convert = 100 + motor_command;
		convert = convert * 126/200 + 1;
	}
	return (uint8_t) convert;
}


/*==============================================================================*/
/*                             API Implementation                               */
/*==============================================================================*/

void Motor_Driver_Init(void)
{

	  h_motor_uart.Instance = USART3;
	  h_motor_uart.Init.BaudRate = 38400;
	  h_motor_uart.Init.WordLength = UART_WORDLENGTH_8B;
	  h_motor_uart.Init.StopBits = UART_STOPBITS_1;
	  h_motor_uart.Init.Parity = UART_PARITY_NONE;
	  h_motor_uart.Init.Mode = UART_MODE_TX_RX;
	  h_motor_uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	  h_motor_uart.Init.OverSampling = UART_OVERSAMPLING_16;
	  HAL_HalfDuplex_Init(&h_motor_uart);

}


void Motor_Driver_Change_Power(int8_t left_motor_power,int8_t right_motor_power)
{
	uint8_t motor_input_left_right[2];
	motor_input_left_right[0] = motor_power_to_motor_input(left_motor_power, 0);
	motor_input_left_right[1] = motor_power_to_motor_input(right_motor_power, 1);

	//Transmit Three Times
	HAL_UART_Transmit(&h_motor_uart, motor_input_left_right, 2, 100);
	HAL_UART_Transmit(&h_motor_uart, motor_input_left_right, 2, 100);
	HAL_UART_Transmit(&h_motor_uart, motor_input_left_right, 2, 100);
}

void Motor_Driver_Change_Left_Power(int8_t left_motor_power)
{
	uint8_t motor_input;
	motor_input = motor_power_to_motor_input(left_motor_power, 0);

	//Transmit Three Times
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
}

void Motor_Driver_Change_Right_Power(int8_t right_motor_power)
{
	uint8_t motor_input;
	motor_input = motor_power_to_motor_input(right_motor_power, 1);

	//Transmit Three Times
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
	HAL_UART_Transmit(&h_motor_uart, &motor_input, 1, 100);
}

void Motor_Driver_Test_Conversion(uint8_t (*log_function)(char *))
{
	HAL_Delay(1000);
	for(int8_t i = -100; i <= 100; i ++){
		char s[50] = "";
		uint8_t motor_input_left = motor_power_to_motor_input(i, 0);
		uint8_t motor_input_right = motor_power_to_motor_input(i, 1);
		sprintf(s,"Power = %d, motor input = %d %d\r\n",i,motor_input_left,motor_input_right);
		(*log_function)(s);
	}
	while(1)
	{
		//left

		HAL_Delay(10000);

	}
}

void Motor_Driver_Motor_Test(uint8_t (*log_function)(char *))
{
	Motor_Driver_Init();
	while(1){
		/// Change Power TOGHETHER TEST
		Motor_Driver_Change_Power(100, 100);
		HAL_Delay(3000);
		Motor_Driver_Change_Power(0, 0);
		HAL_Delay(1000);
		Motor_Driver_Change_Power(-100, -100);
		HAL_Delay(3000);
		Motor_Driver_Change_Power(0, 0);
		HAL_Delay(1000);

		for(int8_t i = -100; i <= 100; i ++){
			char s[50] = "";
			sprintf(s,"power = %d\r\n",i);
			Motor_Driver_Change_Left_Power(i);
			Motor_Driver_Change_Left_Power(-i);
			(*log_function)(s);
			HAL_Delay(50);
		}
		Motor_Driver_Change_Power(0, 0);
		HAL_Delay(3000);






	}

}





/********************************************************************************/




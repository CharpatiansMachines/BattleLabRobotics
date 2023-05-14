/*
 * motor_driver.h
 *
 *  Created on: Apr 6, 2023
 *      Author: paul.contis
 */

#ifndef INC_MOTOR_DRIVER_H_
#define INC_MOTOR_DRIVER_H_

/*==============================================================================*/
/*                     INCLUDE - Required dependencies                          */
/*==============================================================================*/

#include "stdint.h"
#include "stm32f4xx.h"

/*==============================================================================*/
/*                                API Declarations                              */
/*==============================================================================*/
void Motor_Driver_Init(void);

/**
 *
 * @param left_motor_power anything between [-100,100] (-100 for maximum backward, 100 for maxim forward, linear interpolation between them)
 * @param right_motor_power anything between [-100,100] (-100 for maximum backward, 100 for maxim forward, linear interpolation between them)
 */
void Motor_Driver_Change_Power(int8_t left_motor_power,int8_t right_motor_power);

/**
 *
 * @param left_motor_power anything between [-100,100] (-100 for maximum backward, 100 for maxim forward, linear interpolation between them)
 */
void Motor_Driver_Change_Left_Power(int8_t left_motor_power);
/**
 *
 * @param right_motor_power anything between [-100,100] (-100 for maximum backward, 100 for maxim forward, linear interpolation between them)
 */
void Motor_Driver_Change_Right_Power(int8_t right_motor_power);


void Motor_Driver_Test_Conversion(uint8_t (*log_function)(char *));

void Motor_Driver_Motor_Test(uint8_t (*log_function)(char *));




#endif /* INC_MOTOR_DRIVER_H_ */

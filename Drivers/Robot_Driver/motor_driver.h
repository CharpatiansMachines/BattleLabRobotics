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
/*==============================================================================*/
/*                                API Declarations                              */
/*==============================================================================*/
void Drv_Init (void);

void Drv_MotorMove_Fwd(uint8_t lu8_instance, uint8_t lu8_power);
void Drv_MotorMove_Bck(uint8_t lu8_instance , uint8_t lu8_power);

void Drv_Both_MotMove_Fwd(uint8_t lu8_ltMotorPower, uint8_t lu8_rtMotorPower);
void Drv_Both_MotMove_Bck(uint8_t lu8_ltMotorPower, uint8_t lu8_rtMotorPower);

void Drv_Both_MotMove_Indep(uint8_t lu8_ltMotorPower, uint8_t lu8_ltMotorDir, uint8_t lu8_rtMotorPower, uint8_t lu8_rtMotorDir);

void Drv_Deinit (void);

#endif /* INC_MOTOR_DRIVER_H_ */

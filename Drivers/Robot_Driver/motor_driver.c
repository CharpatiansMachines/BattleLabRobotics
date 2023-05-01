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

/*==============================================================================*/
/*                                Local Define                                  */
/*==============================================================================*/
#define LEFT_MOTOR 					0U
#define RIGHT_MOTOR 				1U
#define BOTH_MOTORS                 2U

#define FORWARDS 					1U
#define BACKWARD					0U



/*==============================================================================*/
/*                             Global Variables                                 */
/*==============================================================================*/

//TODO

/*==============================================================================*/
/*                                  Macro                                       */
/*==============================================================================*/

//TODO

/*==============================================================================*/
/*                       Private Functions Declaration                          */
/*==============================================================================*/

//TODO



/*==============================================================================*/
/*                             API Implementation                               */
/*==============================================================================*/

//TODO
/**
 * @brief
 * @param none
 */
void Drv_Init (void)
{
	//TODO
}
/********************************************************************************/

/**
 *
 * @param lu8_instance
 * @param lu8_power
 */
void Drv_MotorMove_Fwd(uint8_t lu8_instance, uint8_t lu8_power)
{
	//TODO;
}
/********************************************************************************/

/**
 *
 * @param lu8_instance
 * @param lu8_power
 */
void Drv_MotorMove_Bck(uint8_t lu8_instance, uint8_t lu8_power)
{
	//TODO;
}
/********************************************************************************/

/**
 *
 * @param lu8_ltMotorPower
 * @param lu8_rtMotorPower
 */
void Drv_Both_MotorMove_Fwd(uint8_t lu8_ltMotorPower, uint8_t lu8_rtMotorPower)
{
	//TODO;
}
/********************************************************************************/

/**
 *
 * @param lu8_ltMotorPower
 * @param lu8_rtMotorPower
 */
void Drv_Both_MotorMove_Bck(uint8_t lu8_ltMotorPower, uint8_t lu8_rtMotorPower)
{
	//TODO;
}

/**
 *
 * @param lu8_ltMotorPower
 * @param lu8_ltMotorDir
 * @param lu8_rtMotorPower
 * @param lu8_rtMotorDir
 */
void Drv_Both_MotMove_Indep(uint8_t lu8_ltMotorPower, uint8_t lu8_ltMotorDir, uint8_t lu8_rtMotorPower, uint8_t lu8_rtMotorDir)
{
	//TODO;
}
/********************************************************************************/



/**
 * @brief
 * @param none
 */
void Drv_Deinit (void)
{
	//TODO
}
/********************************************************************************/




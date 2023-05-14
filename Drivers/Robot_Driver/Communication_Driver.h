/*
 * Communication_Driver.h
 *
 *  Created on: Apr 12, 2023
 *      Author: BRG
 */

#ifndef COM_DRIVER_COMMUNICATION_DRIVER_H_
#define COM_DRIVER_COMMUNICATION_DRIVER_H_

#include "stdint.h"


#define COMMUNICATION_DRIVER_BUFFER_SIZE 1024
#define COMMUNICATION_DRIVER_TRIMPOTS_NO 2

typedef enum{
	STOP_FIGHT = 0x00,
	START_FIGHT = 0x01,
}Fight_Command;

typedef enum {
	PRINT_COMMAND = 0x00,
	FROMTAL_ATACK_STRATEGY = 0x01,
}Action_Command;


extern char Communication_Driver_Buffer[COMMUNICATION_DRIVER_BUFFER_SIZE];
extern uint8_t Communication_Driver_Trimpots_Data[4];

/**
 * reinitialize Communication_Driver_Buffer
 * initialize pins
 */
void Communication_Driver_Init(void);

/**
 * Transmit to PC the message
 * @param message string
 */
uint8_t Communication_Driver_Log_To_Pc(char *message);

/**
 * Log to buffer without override
 * @param message string
 */
uint8_t Communication_Driver_Log_To_Buffer(char* message);

/**
 * Read a strategy command
 * @return the command
 */
Action_Command Communication_Driver_Read_Action_Command(void);

/**
 * Read Start Stop Command
 * @return
 */
Fight_Command Communication_Driver_Read_Fight_Command(void);


void Communication_Drive_Read_Trimpots(void);


//////////////////////////////////////////////////// Test Function ////////////////////////
void Communication_Driver_Test_Log_To_Pc(void);







#endif /* COM_DRIVER_COMMUNICATION_DRIVER_H_ */

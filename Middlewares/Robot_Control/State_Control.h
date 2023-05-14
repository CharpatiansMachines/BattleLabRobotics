/*
 * State_Control.h
 *
 *  Created on: May 12, 2023
 *      Author: BRG
 */

#ifndef STATE_CONTROL_H_
#define STATE_CONTROL_H_
#include "EnemyPosition.h"

extern uint8_t State_Control_curentEnemyPosition;
extern uint8_t State_Control_robotPosition;

void State_Control_Init(void);
void State_Control_Recalculate_States(void);




#endif /* STATE_CONTROL_H_ */

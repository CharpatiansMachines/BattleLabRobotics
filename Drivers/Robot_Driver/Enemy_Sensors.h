/*
 * EnemyDetection.h
 *
 *  Created on: Apr 10, 2023
 *      Author: BRG
 */

#ifndef ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_
#define ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_

#include "stdint.h"
#include "stm32f4xx.h"
#include "EnemyPosition.h"

/**
 * Each Enemy Position has an unique id in range [0 (ENEMY_POSITIONS_STATES_NO - 1)] of type uint8_t
 *  See ./datasheet/EnemyPositionDiagram.png for more details
 */

/** ?
 * Must be called before using EnemyDetection Drive4r
 * Make Configuration for sensors pins and initialize all static variable
 */
void Enemy_Sensors_Init(void);

/** ?
 * Must be called how often after the configuration is done.
 * This function take information from sensors and each sensor vote for one or more possible enemy positions
 * @param sensors_votes must have MAX_POSSIBLE_POSITIONS size.
 * Function will fill frequency vector : For each frequency[i] = number of sensors who voted for EnemyPosition that has id i
 * Use Enemy_Position_From_Number function to calculate position of i
 * @return number of sensors that detected something
 */
uint8_t Enemy_Sensors_Take_Sensors_Votes(int8_t sensors_votes[]);

/////////////////////////////////////////////////////////////// Test Functions//////////////////////////////////////////////

void Enemy_Sensors_Test(uint8_t (*log_function)(char *));







#endif /* ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_ */

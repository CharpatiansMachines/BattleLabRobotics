/*
 * EnemyDetection.h
 *
 *  Created on: Apr 10, 2023
 *      Author: BRG
 */

#ifndef ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_
#define ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_

#include "stdint.h"

/**
 *  * See ./datasheet/EnemyPositionDiagram.png for more details
 */

#define MAX_POSSIBLE_POSITIONS 36  // number of states of enemy position


/**
 * Enemy Position
 * Each Enemy Position has an unique id in range [0 (MAX_POSSIBLE_POSITIONS - 1)] of type uint8_t
 */

typedef struct _EnemyPosition {
   uint8_t u8_horizontal_orientation:2; // 0 left, 1 center, 2 right
   uint8_t u8_vertical_orientation:2;   // 0 back, 1 center, 2 right
   uint8_t u8_proximity:2;             // 0 - impact, 1 - cross, 2 - medium, 3 - far
} EnemyPosition;

/** ?
 * Must be called before using EnemyDetection Drive4r
 * Make Configuration for sensors pins and initialize all static variable
 */
void Enemy_Sensors_Init(void);

/** ?
 * Must be called how often after the configuration is done.
 * This function take information from sensors and each sensor vote for one or more possible enemy positions
 * @param frequency must have MAX_POSSIBLE_POSITIONS size.
 * Function will fill frequency vector : For each frequency[i] = number of sensors who voted for EnemyPosition that has id i
 * Use Enemy_Position_From_Number function to calculate position of i
 */
void Enemy_Sensors_Take_Possible_Positions(uint8_t frequency[]);

/** ?
 * @param pos1 an enemy position
 * @param pos2 an enemy position
 * @return the distance between pos1 & pos2 Enemy Positions
 */
uint8_t Enemy_Position_Distance(EnemyPosition pos1, EnemyPosition pos2);

/** ?
 * For each position create an unique id between 0 and (MAX_POSSIBLE_POSITIONS -1)
 * @param enemyPosition
 * @return the unique id of enemyPosition
 */
uint8_t Enemy_Position_To_Number(EnemyPosition enemyPosition);

/** ?
 * @param enemyPosition
 * @return Enemy Position corresponding to unique id of enemyPosition parameter
 */
EnemyPosition Enemy_Position_From_Number(uint8_t enemyPosition);






#endif /* ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_ */

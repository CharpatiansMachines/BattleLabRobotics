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
 * Enemy Position
 * Each Enemy Position has an unique id in range [0 (MAX_POSSIBLE_POSITIONS - 1)] of type uint8_t
 *  See ./datasheet/EnemyPositionDiagram.png for more details
 */

#define MAX_POSSIBLE_POSITIONS 36  // number of states of enemy position
typedef struct _EnemyPosition {
   uint8_t u8_horizontal_orientation:2; // 0 left, 1 center, 2 right
   uint8_t u8_vertical_orientation:2;   // 0 front, 1 center, 2 back
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
void Enemy_Sensors_Take_Possible_Positions(uint8_t lu8_frequency[]);

/** ?
 * @param enemyPosition1 an enemy position
 * @param enemyPosition2 an enemy position
 * @return the distance between enemyPosition1 & enemyPosition2
 */

uint8_t Enemy_Position_Distance(EnemyPosition enemyPosition1, EnemyPosition enemyPosition2);

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
EnemyPosition Enemy_Position_From_Number(uint8_t lu8_enemyPosition);


/**
 * Enemy Position id examples:
 * horizontal_orientation vertical_orientation proximity -> id
 * 0 0 0 -> 0
 * 0 0 1 -> 1
 * 0 0 2 -> 2
 * 0 0 3 -> 3
 * 0 1 0 -> 4
 * 0 1 1 -> 5
 * 0 1 2 -> 6
 * 0 1 3 -> 7
 * 0 2 0 -> 8
 * 0 2 1 -> 9
 * 0 2 2 -> 10
 * 0 2 3 -> 11
 * 1 0 0 -> 12
 * 1 0 1 -> 13
 * 1 0 2 -> 14
 * 1 0 3 -> 15
 * 1 1 0 -> 16
 * 1 1 1 -> 17
 * 1 1 2 -> 18
 * 1 1 3 -> 19
 * 1 2 0 -> 20
 * 1 2 1 -> 21
 * 1 2 2 -> 22
 * 1 2 3 -> 23
 * 2 0 0 -> 24
 * 2 0 1 -> 25
 * 2 0 2 -> 26
 * 2 0 3 -> 27
 * 2 1 0 -> 28
 * 2 1 1 -> 29
 * 2 1 2 -> 30
 * 2 1 3 -> 31
 * 2 2 0 -> 32
 * 2 2 1 -> 33
 * 2 2 2 -> 34
 * 2 2 3 -> 35
 */






#endif /* ENEMY_SENSOURS_DRIVER_ENEMY_SENSOURS_H_ */

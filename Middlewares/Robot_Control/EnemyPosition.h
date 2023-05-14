/*
 * EnemyPosition.h
 *
 *  Created on: May 14, 2023
 *      Author: BRG
 */

#ifndef ROBOT_CONTROL_ENEMYPOSITION_H_
#define ROBOT_CONTROL_ENEMYPOSITION_H_

#include "stdint.h"

#define ENEMY_POSITIONS_STATES_NO 33  //max number of states of enemy position
#define ENEMY_POSITIONS_NOT_KNOWN 32
typedef struct _EnemyPosition {
   int8_t direction;			 // 0 - 12 for proximity 0 or 1, 0 - 5 for proximity 2
   int8_t proximity;             // 0 - cross/impact, 1 - medium, 2 - far, 3 for we don't know
} EnemyPosition;

/** ?
 * @param enemyPosition1 an enemy position
 * @param enemyPosition2 an enemy position
 * @return the distance between enemyPosition1 & enemyPosition2
 */
uint8_t Enemy_Position_To_Number(EnemyPosition enemyPosition);

/** ?
 * @param enemyPosition
 * @return Enemy Position corresponding to unique id of enemyPosition parameter
 */
EnemyPosition Enemy_Position_From_Number(uint8_t enemyPositionId);


uint8_t Enemy_Position_Probably_The_Next_Position(uint8_t positionId,uint8_t next_positionId);

uint8_t Enemy_Position_Is_Closer(uint8_t position1Id, uint8_t position2Id);

void Enemy_Position_Test(uint8_t (*log_function)(char *));

#endif /* ROBOT_CONTROL_ENEMYPOSITION_H_ */

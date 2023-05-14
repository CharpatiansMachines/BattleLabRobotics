/*
 * EnemyPosition.c
 *
 *  Created on: May 14, 2023
 *      Author: BRG
 */
#include "EnemyPosition.h"
#include <stdlib.h>
#include <stdio.h>

#define DIRESTIONS_NO 13

uint8_t Enemy_Position_To_Number(EnemyPosition enemyPosition)
{
	if(enemyPosition.proximity == 3)
		return ENEMY_POSITIONS_NOT_KNOWN;
	if(enemyPosition.proximity == 2){
		if(enemyPosition.direction > 6)
			enemyPosition.direction -= 2;
		enemyPosition.direction = enemyPosition.direction >> 1; // direction / 2
	}
	return enemyPosition.proximity * DIRESTIONS_NO + enemyPosition.direction;
}

EnemyPosition Enemy_Position_From_Number(uint8_t enemyPositionId)
{
	EnemyPosition enemyPosition;
	if(enemyPositionId >= ENEMY_POSITIONS_NOT_KNOWN)
	{
		enemyPosition.proximity = 3;
		return enemyPosition;
	}

	enemyPosition.proximity = enemyPositionId / DIRESTIONS_NO;
	enemyPosition.direction = enemyPositionId % DIRESTIONS_NO;
	if(enemyPosition.proximity == 2){
		if(enemyPosition.direction > 2)
			enemyPosition.direction++;
		enemyPosition.direction = enemyPosition.direction << 1; // direction * 2
		}

	return enemyPosition;
}


uint8_t Enemy_Position_Probably_The_Next_Position(uint8_t positionId,uint8_t next_positionId)
{
	if(positionId == next_positionId)
		return 1;
	EnemyPosition position = Enemy_Position_From_Number(positionId);
	EnemyPosition next_position = Enemy_Position_From_Number(next_positionId);

	if(position.proximity == 3){
		if(next_position.proximity >= 2 || next_position.direction == 0 || next_position.direction == 12)
			return 2;
		else
			return 0;
	}
	int proximity_diff = position.proximity - next_position.proximity;

	if(proximity_diff == 0 || proximity_diff == 1){

		int direction_diff = position.direction - next_position.direction;
		if(abs(direction_diff) <= 2){
			return 2;
		}
	}
	return 0;
}
uint8_t Enemy_Position_Is_Closer(uint8_t position1Id, uint8_t position2Id){
	EnemyPosition position1 = Enemy_Position_From_Number(position1Id);
	EnemyPosition position2 = Enemy_Position_From_Number(position2Id);
	if(position1.proximity < position2.proximity)
		return 1;
	return 0;
}
void Enemy_Position_Test(uint8_t (*log_function)(char *))
{
	for(uint8_t enemy_position_id = 0; enemy_position_id < ENEMY_POSITIONS_STATES_NO; enemy_position_id++){
		EnemyPosition enemy_position = Enemy_Position_From_Number(enemy_position_id);
		uint8_t enemy_position_id2 = Enemy_Position_To_Number(enemy_position);
		char s[250] = "";
		sprintf(s,"epid = %d, ep = D=%d P=%d, epid2 =%d\r\n",enemy_position_id,enemy_position.direction,enemy_position.proximity,enemy_position_id2);
		if((*log_function)(s) == 0)
			return;
	}

	for(uint8_t ep1 = 0; ep1 < ENEMY_POSITIONS_STATES_NO; ep1++){
		(*log_function)("---------------------------------------\r\n");
		for(uint8_t ep2 = 0; ep2 < ENEMY_POSITIONS_STATES_NO; ep2++){
			char s[250] = "";
			uint8_t p = Enemy_Position_Probably_The_Next_Position(ep1, ep2);
			if(p != 0)
			{
				sprintf(s,"ep = %d %d probability = %d\r\n",ep1,ep2,p);
				(*log_function)(s);
			}

		}
	}

}

/*
 * State_Control.c
 *
 *  Created on: May 12, 2023
 *      Author: BRG
 */

#include "State_Control.h"
#include "Line_Sensors.h"
#include "Enemy_Sensors.h"

// See enemy position in Enemy_Sensours
uint8_t State_Control_curentEnemyPosition;
uint8_t State_Control_lastEnemyPosition;
uint8_t State_Control_robotPosition;


///---------------------------------------------------<State Control PRIVATE>---------------------------------------------------------


uint8_t get_Most_Voted_Positions(int8_t sensors_votes[], uint8_t most_voted_positions[])
{
	uint8_t nr_of_most_voted = 0;
	uint8_t max_votes = 0;
	for(uint8_t i = 0; i <= ENEMY_POSITIONS_STATES_NO; i++){
		if(sensors_votes[i] > max_votes)
		{
			most_voted_positions[0] = i;
			nr_of_most_voted = 1;
			max_votes = sensors_votes[i];
		}else if(sensors_votes[i] == max_votes)
		{
			most_voted_positions[nr_of_most_voted ++] = i;
		}

	}
	return nr_of_most_voted;
}

void vote_current_enemy_positions(int8_t sensors_votes[], uint8_t most_voted_positions[], uint8_t most_voted_positions_no)
{
	for(uint8_t i = 0; i <= most_voted_positions_no; i++){
		sensors_votes[most_voted_positions[i]] += Enemy_Position_Probably_The_Next_Position(State_Control_curentEnemyPosition, most_voted_positions[i]);
	}

}


///---------------------------------------------------</State Control PRIVATE>---------------------------------------------------------

void State_Control_Init(void)
{
	State_Control_lastEnemyPosition = 7; // 0 1 3
	State_Control_curentEnemyPosition = 7;
}

void State_Control_Recalculate_States(void)
{
	State_Control_robotPosition = Line_Sensors_Read();

	int8_t sensors_votes[ENEMY_POSITIONS_STATES_NO];
	uint8_t voting_sensors_no = Enemy_Sensors_Take_Sensors_Votes(sensors_votes);
	if(voting_sensors_no == 0){
		return;
	}
	uint8_t most_voted_positions[ENEMY_POSITIONS_STATES_NO];
	uint8_t most_voted_positions_no = get_Most_Voted_Positions(sensors_votes, most_voted_positions);
	vote_current_enemy_positions(sensors_votes,most_voted_positions,most_voted_positions_no);

	uint8_t max_votes = 0;
	uint8_t best_position;
	for(uint8_t i = 0; i <= most_voted_positions_no; i++){
		uint8_t position = most_voted_positions[i];
		uint8_t votes = sensors_votes[position];
		if(votes > max_votes){
			max_votes = votes;
			best_position = position;
		}else if(votes == max_votes && Enemy_Position_Is_Closer(position,best_position))
		{
			best_position = position;
		}

	}
	State_Control_lastEnemyPosition = State_Control_curentEnemyPosition;
	State_Control_curentEnemyPosition = best_position;
}





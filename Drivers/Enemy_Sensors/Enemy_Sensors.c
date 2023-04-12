



#include "Enemy_Sensors.h"
#define NUMBER_OF_SENSORS 8              // number of sensors


//---------------------------------------------------<Enemy Sensors PRIVATE>---------------------------------------------------------


uint16_t readSensors(void){
	return 0;
}

//---------------------------------------------------</Enemy Sensors PRIVATE>---------------------------------------------------------


void Enemy_Sensors_Init(void)
{

}

void Enemy_Sensors_Take_Possible_Positions(uint8_t frequency[])
{
	uint16_t sensors = readSensors();
	//sensor 0
	if(sensors | 0x0001){
		frequency[12]++; // 1 0 0
		frequency[13]++; // 1 0 1
		frequency[14]++; // 1 0 2
		frequency[15]++; // 1 0 3
		frequency[16]++; // 1 0 4
	}
	//sensor 1
	if(sensors | 0x0002){
		frequency[12]++; // 1 0 0
		frequency[13]++; // 1 0 1
		frequency[14]++; // 1 0 2
		frequency[15]++; // 1 0 3
		frequency[16]++; // 1 0 4
	}
	//...
}

uint8_t Enemy_Position_Distance(EnemyPosition enemyPosition1, EnemyPosition enemyPosition2)
{
	return 0;
}


uint8_t Enemy_Position_To_Number(EnemyPosition enemyPosition)
{
	return 	enemyPosition.u8_horizontal_orientation * 12 +
			enemyPosition.u8_vertical_orientation << 2+
			enemyPosition.u8_proximity;
}


EnemyPosition Enemy_Position_From_Number(uint8_t lu8_enemyPosition)
{
	EnemyPosition enemyPosition;
	enemyPosition.u8_horizontal_orientation = lu8_enemyPosition / 12;
	lu8_enemyPosition = lu8_enemyPosition % 12;

	enemyPosition.u8_vertical_orientation = lu8_enemyPosition >> 2;
	enemyPosition.u8_proximity = lu8_enemyPosition % 4;

	return enemyPosition;
}

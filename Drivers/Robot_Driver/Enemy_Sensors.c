#include "Enemy_Sensors.h"
#include "stm32f4xx_hal_gpio.h"
#include <strings.h>
#include <stdio.h>

#define NUMBER_OF_SENSORS 8              // number of sensors

#define SENSOR_0_1_GPIO GPIOA
#define SENSOR_0_PIN GPIO_PIN_0
#define SENSOR_1_PIN GPIO_PIN_1




///---------------------------------------------------<Enemy Sensors PRIVATE>---------------------------------------------------------

/**
 * Bit i is the value corresponding to sensor i
 * @return for each sensor 1 if detects something and 0 else
 */
uint32_t readSensors(void){
	return 0;
}

///---------------------------------------------------</Enemy Sensors PRIVATE>---------------------------------------------------------


void Enemy_Sensors_Init(void)
{
	GPIO_InitTypeDef sensor_initTypeDef = {0};
	sensor_initTypeDef.Mode = GPIO_MODE_INPUT;
	sensor_initTypeDef.Speed = GPIO_SPEED_LOW;
	sensor_initTypeDef.Pull = GPIO_NOPULL;

	// initializa sensors 0 and 1
	sensor_initTypeDef.Pin = SENSOR_0_PIN | SENSOR_1_PIN;
	HAL_GPIO_Init(SENSOR_0_1_GPIO, &sensor_initTypeDef);

}

uint8_t Enemy_Sensors_Take_Possible_Positions(uint8_t lu8_frequency[]){
	for(uint8_t i = 0; i <= NUMBER_OF_SENSORS;i++){
		lu8_frequency[i] = 0;
	}
	uint32_t sensors_values = readSensors();
	uint8_t number_of_active_sensors = 0;

	///Sensor 0
	if(sensors_values & 0x01){
		number_of_active_sensors++;
		lu8_frequency[0]++;          /// 0 0 0

	}
	///Sensor 1
	if(sensors_values & 0x02){
		number_of_active_sensors++;

	}
	///Sensor 2
	if(sensors_values & 0x04){
		number_of_active_sensors++;

	}
	///Sensor 3
	if(sensors_values & 0x08){
		number_of_active_sensors++;

	}
	///Sensor 4
	if(sensors_values & 0x10){
		number_of_active_sensors++;
	}
	///Sensor 5
	if(sensors_values & 0x20){
		number_of_active_sensors++;
	}
	///Sensor 6
	if(sensors_values & 0x40){
		number_of_active_sensors++;
	}
	///Sensor 7
	if(sensors_values & 0x80){
		number_of_active_sensors++;
	}
	return number_of_active_sensors;
}

uint8_t Enemy_Position_Distance(EnemyPosition enemyPosition1, EnemyPosition enemyPosition2)
{
	return 0;
}


uint8_t Enemy_Position_To_Number(EnemyPosition enemyPosition)
{
	return 	(enemyPosition.u8_horizontal_orientation * 12) +
			(enemyPosition.u8_vertical_orientation << 2) +
			(enemyPosition.u8_proximity);
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

void Enemy_Sensors_Test(uint8_t (*log_function)(char *))
{
//	while(1)
//	{
//		uint8_t data[ENEMY_POSITIONS_STATES_NO];
//		Enemy_Sensors_Take_Possible_Positions(data);
		int nr = 0;

		const int MATRIX_SIZE = 9;
		for(int y = 0 ; y < MATRIX_SIZE; y++){
			for(int x = 0; x < MATRIX_SIZE;x++){
				if( (x != 4 || y != 4) &&
						(x == 4 || y == 4 || x == y || (x + y ==8))){
					int ox = x / 4 + (x > 4 && x < 8);
					int oy =  y / 4 + (y > 4 && y < 8);

					int p;
					int dx = 4 - x;
					if(dx < 0)
						dx*=-1;
					int dy = 4 - y;
					if(dy < 0)
						dy*=-1;
					if(dx > dy)
						p = dx -1;
					else
						p = dy -1;
					char s[250] = "";
					sprintf(s,"%d ",0);
					(*log_function)(s);
				}else{
					(*log_function)("  ");
				}
			}
			(*log_function)("\r\n");
		}


//	}
}
void Enemy_Position_Test(uint8_t (*log_function)(char *))
{
	for(uint8_t enemy_position_id = 0; enemy_position_id < ENEMY_POSITIONS_STATES_NO; enemy_position_id++){
		EnemyPosition enemy_position = Enemy_Position_From_Number(enemy_position_id);
		uint8_t enemy_position_id2 = Enemy_Position_To_Number(enemy_position);
		char s[250] = "";
		sprintf(s,"epid = %d, ep = H=%d V=%d P=%d, epid2 =%d\r\n",enemy_position_id,enemy_position.u8_horizontal_orientation,enemy_position.u8_vertical_orientation,enemy_position.u8_proximity,enemy_position_id2);
		if((*log_function)(s) == 0)
			return;
	}

}

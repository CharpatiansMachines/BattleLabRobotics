#include "Enemy_Sensors.h"
#include "stm32f4xx_hal_gpio.h"
#include <strings.h>
#include <stdio.h>
#include "EnemyPosition.h"

#define NUMBER_OF_SENSORS 8              // number of sensors

#define SENSOR_0_1_GPIO GPIOA
#define SENSOR_0_PIN GPIO_PIN_0
#define SENSOR_1_PIN GPIO_PIN_1


#define FIRST_VOTE 7
#define SECOND_VOTE 6
#define THIRD_VOTE 4





///---------------------------------------------------<Enemy Sensors PRIVATE>---------------------------------------------------------

/**
 * Bit i is the value corresponding to sensor i
 * @return for each sensor 1 if detects something and 0 else
 */
uint32_t readSensors(void){
	return (1 << 2) | (1 << 3) | (1 << 4);
}

uint8_t getSensorsVotes(uint32_t semsorsOutput, int8_t lu8_frequency[]){
	for(uint8_t i = 0; i <= ENEMY_POSITIONS_STATES_NO;i++){
			lu8_frequency[i] = 0;
		}
		uint32_t sensors_values = readSensors();
		uint8_t number_of_active_sensors = 0;

		///Sensor 0
		if(sensors_values & 0x01){
			number_of_active_sensors++;
			lu8_frequency[0] += FIRST_VOTE;       ///
			lu8_frequency[13] += FIRST_VOTE;       /// center line
			lu8_frequency[26] += FIRST_VOTE;       ///

			lu8_frequency[1] += SECOND_VOTE;       ///
			lu8_frequency[14] += SECOND_VOTE;       ///

			lu8_frequency[2] += THIRD_VOTE;       ///

		}
		///Sensor 1
		if(sensors_values & 0x02){
			number_of_active_sensors++;

			lu8_frequency[1] += SECOND_VOTE;       ///
			lu8_frequency[14] += SECOND_VOTE;       ///

			lu8_frequency[2] += FIRST_VOTE;       ///
			lu8_frequency[15] += FIRST_VOTE;       /// center line
			lu8_frequency[27] += FIRST_VOTE;       ///

			lu8_frequency[3] += SECOND_VOTE;       ///
			lu8_frequency[16] += SECOND_VOTE;       ///

			lu8_frequency[4] += THIRD_VOTE;       ///

		}
		///Sensor 2
		if(sensors_values & 0x04){
			number_of_active_sensors++;

			lu8_frequency[2] += THIRD_VOTE;       ///

			lu8_frequency[3] += SECOND_VOTE;       ///
			lu8_frequency[16] += SECOND_VOTE;       ///

			lu8_frequency[4] += FIRST_VOTE;       ///
			lu8_frequency[17] += FIRST_VOTE;       /// center line
			lu8_frequency[28] += FIRST_VOTE;       ///

			lu8_frequency[5] += SECOND_VOTE;       ///
			lu8_frequency[18] += SECOND_VOTE;       ///

			lu8_frequency[6] += THIRD_VOTE;       ///
		}
		///Sensor 3
		if(sensors_values & 0x08){
			number_of_active_sensors++;

			lu8_frequency[3] += THIRD_VOTE;       ///
			lu8_frequency[18] += THIRD_VOTE;       ///

			lu8_frequency[4] += SECOND_VOTE;       ///
			lu8_frequency[19] += SECOND_VOTE;       ///

			lu8_frequency[5] += FIRST_VOTE;       ///
			lu8_frequency[20] += FIRST_VOTE;       /// center line


			lu8_frequency[6] +=  SECOND_VOTE;       ///
			lu8_frequency[21] += SECOND_VOTE;       ///
			lu8_frequency[29] += SECOND_VOTE;       ///

			lu8_frequency[7] += THIRD_VOTE;       ///

		}
		///Sensor 4
		if(sensors_values & 0x10){
			number_of_active_sensors++;
			lu8_frequency[5] += THIRD_VOTE;        ///

			lu8_frequency[6] += SECOND_VOTE;       ///
			lu8_frequency[17] += SECOND_VOTE;      ///
			lu8_frequency[28] += SECOND_VOTE;      ///

			lu8_frequency[7] += FIRST_VOTE;        ///
			lu8_frequency[18] += FIRST_VOTE;       /// center line


			lu8_frequency[8] += SECOND_VOTE;       ///
			lu8_frequency[19] += SECOND_VOTE;      ///

			lu8_frequency[9] += THIRD_VOTE;        ///
			lu8_frequency[20] += THIRD_VOTE;        ///
		}
		///Sensor 5
		if(sensors_values & 0x20){
			number_of_active_sensors++;
			lu8_frequency[6] += THIRD_VOTE;       ///

			lu8_frequency[7] += SECOND_VOTE;       ///
			lu8_frequency[20] += SECOND_VOTE;       ///

			lu8_frequency[8] += FIRST_VOTE;       ///
			lu8_frequency[21] += FIRST_VOTE;       /// center line
			lu8_frequency[29] += FIRST_VOTE;       ///

			lu8_frequency[9] += SECOND_VOTE;       ///
			lu8_frequency[22] += SECOND_VOTE;       ///

			lu8_frequency[10] += THIRD_VOTE;       ///
		}
		///Sensor 6
		if(sensors_values & 0x40){
			number_of_active_sensors++;

			lu8_frequency[8] += THIRD_VOTE;       ///

			lu8_frequency[9] += SECOND_VOTE;       ///
			lu8_frequency[22] += SECOND_VOTE;       ///

			lu8_frequency[10] += FIRST_VOTE;       ///
			lu8_frequency[23] += FIRST_VOTE;       /// center line
			lu8_frequency[30] += FIRST_VOTE;       ///

			lu8_frequency[11] += SECOND_VOTE;       ///
			lu8_frequency[24] += SECOND_VOTE;       ///
		}
		///Sensor 7
		if(sensors_values & 0x80){
			number_of_active_sensors++;

			lu8_frequency[10] += THIRD_VOTE;       ///

			lu8_frequency[11] += SECOND_VOTE;       ///
			lu8_frequency[24] += SECOND_VOTE;       ///

			lu8_frequency[12] += FIRST_VOTE;       ///
			lu8_frequency[25] += FIRST_VOTE;       /// center line
			lu8_frequency[31] += FIRST_VOTE;       ///
		}
		return number_of_active_sensors;

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

uint8_t Enemy_Sensors_Take_Sensors_Votes(int8_t lu8_frequency[]){
	return getSensorsVotes(readSensors(), lu8_frequency);
}




void Enemy_Sensors_Test(uint8_t (*log_function)(char *))
{

	Enemy_Sensors_Init();

	uint32_t semsorsOutput = readSensors();

	int8_t data[ENEMY_POSITIONS_STATES_NO];
	getSensorsVotes(semsorsOutput, data);

	char s[100];
	sprintf(s,"s0 = %d, s1 = %d, s2 = %d, s3 = %d, s4 = %d, s5 = %d, s6 = %d, s7 = %d\r\n\r\n",
			(int) semsorsOutput & 0x01,
			(int) semsorsOutput & 0x02,
			(int) semsorsOutput & 0x04,
			(int) semsorsOutput & 0x08,
			(int) semsorsOutput & 0x10,
			(int) semsorsOutput & 0x20,
			(int) semsorsOutput & 0x40,
			(int) semsorsOutput & 0x80);
	(*log_function)(s);





	(*log_function)(" 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |\r\n");
	//layer 2
	for(int ep = 26 ; ep < 29; ep++){
		int8_t d = data[ep];
		if(d < 10)
			sprintf(s," %d  |    |",d);
		else
			sprintf(s," %d |    |",d);
		(*log_function)(s);
	}
	(*log_function)("    |    |");
	for(int ep = 29 ; ep < 32; ep++){
		int8_t d = data[ep];
		if(d < 10)
			sprintf(s," %d  |    |",d);
		else
			sprintf(s," %d |    |",d);
		(*log_function)(s);
	}
	(*log_function)("\r\n");

	//layer 1
	for(int ep = 13 ; ep < 26; ep++){
		int8_t d = data[ep];
		if(d < 10)
			sprintf(s," %d  |",d);
		else
			sprintf(s," %d |",d);
		(*log_function)(s);
	}
	(*log_function)("\r\n");

	//layer 0
	for(int ep = 0 ; ep < 13; ep++){
		int8_t d = data[ep];
		if(d < 10)
			sprintf(s," %d  |",d);
		else
			sprintf(s," %d |",d);
		(*log_function)(s);
	}
	(*log_function)("\r\n");


	(*log_function)("------------------------------------------------------------------\r\n\r\n\r\n");
	HAL_Delay(1000);



}

/*
 * LineDetection.h
 *
 *  Created on: Apr 10, 2023
 *      Author: BRG
 */

#ifndef LINEDETECTION_LINEDETECTION_H_
#define LINEDETECTION_LINEDETECTION_H_

#include "stdint.h"
#include "stm32f4xx.h"

#define LINE_DETECTION_FRONTL_MASK 0x01
#define LINE_DETECTION_FRONTR_MASK 0x02
#define LINE_DETECTION_BACKL_MASK 0x04
#define LINE_DETECTION_BACKR_MASK 0x08

/**?
 *
 */
void Line_Sensors_Init(void);

/** ?
 * Must be called how often after the configuration is done
 * @return measurement read from line sensors.
 * Use LINE_DETECTION_MASKS
 */
uint8_t Line_Sensors_Read(void);

void Line_Sensors_Test_Sensors_Output(uint8_t (*log_function)(char *));
void Line_Sensors_Test(uint8_t (*log_function)(char *));




#endif /* LINEDETECTION_LINEDETECTION_H_ */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PC14_OSC32_IN_Pin GPIO_PIN_14
#define PC14_OSC32_IN_GPIO_Port GPIOC
#define PC15_OSC32_OUT_Pin GPIO_PIN_15
#define PC15_OSC32_OUT_GPIO_Port GPIOC
#define PH0_OSC_IN_Pin GPIO_PIN_0
#define PH0_OSC_IN_GPIO_Port GPIOH
#define PH1_OSC_OUT_Pin GPIO_PIN_1
#define PH1_OSC_OUT_GPIO_Port GPIOH
#define Trimpot_0_Pin GPIO_PIN_4
#define Trimpot_0_GPIO_Port GPIOC
#define Trimpot_1_Pin GPIO_PIN_5
#define Trimpot_1_GPIO_Port GPIOC
#define ENEMY_SENSOR_9_Pin GPIO_PIN_9
#define ENEMY_SENSOR_9_GPIO_Port GPIOD
#define ENEMY_SENSOR_8_Pin GPIO_PIN_10
#define ENEMY_SENSOR_8_GPIO_Port GPIOD
#define DIP_SWITCH_3_Pin GPIO_PIN_12
#define DIP_SWITCH_3_GPIO_Port GPIOD
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define DIP_SEITCH_1_Pin GPIO_PIN_11
#define DIP_SEITCH_1_GPIO_Port GPIOC
#define DIP_SWITCH_2_Pin GPIO_PIN_12
#define DIP_SWITCH_2_GPIO_Port GPIOC
#define ENEMY_SENSOR_0_Pin GPIO_PIN_0
#define ENEMY_SENSOR_0_GPIO_Port GPIOD
#define ENEMY_SENSOR_1_Pin GPIO_PIN_1
#define ENEMY_SENSOR_1_GPIO_Port GPIOD
#define ENEMY_SENSOR_2_Pin GPIO_PIN_2
#define ENEMY_SENSOR_2_GPIO_Port GPIOD
#define ENEMY_SENSOR_3_Pin GPIO_PIN_3
#define ENEMY_SENSOR_3_GPIO_Port GPIOD
#define ENEMY_SENSOR_4_Pin GPIO_PIN_4
#define ENEMY_SENSOR_4_GPIO_Port GPIOD
#define ENEMY_SENSOR_5_Pin GPIO_PIN_5
#define ENEMY_SENSOR_5_GPIO_Port GPIOD
#define ENEMY_SENSOR_6_Pin GPIO_PIN_6
#define ENEMY_SENSOR_6_GPIO_Port GPIOD
#define ENEMY_SENSOR_7_Pin GPIO_PIN_7
#define ENEMY_SENSOR_7_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

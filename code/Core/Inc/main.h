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
#include "stm32l0xx_hal.h"

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
#define C10_Pin GPIO_PIN_2
#define C10_GPIO_Port GPIOA
#define C9_Pin GPIO_PIN_3
#define C9_GPIO_Port GPIOA
#define C8_Pin GPIO_PIN_4
#define C8_GPIO_Port GPIOA
#define C7_Pin GPIO_PIN_5
#define C7_GPIO_Port GPIOA
#define C6_Pin GPIO_PIN_6
#define C6_GPIO_Port GPIOA
#define C5_Pin GPIO_PIN_7
#define C5_GPIO_Port GPIOA
#define C4_Pin GPIO_PIN_0
#define C4_GPIO_Port GPIOB
#define L2_Pin GPIO_PIN_1
#define L2_GPIO_Port GPIOB
#define L1_Pin GPIO_PIN_2
#define L1_GPIO_Port GPIOB
#define C3_Pin GPIO_PIN_8
#define C3_GPIO_Port GPIOA
#define C2_Pin GPIO_PIN_9
#define C2_GPIO_Port GPIOA
#define C1_Pin GPIO_PIN_10
#define C1_GPIO_Port GPIOA
#define C11_Pin GPIO_PIN_5
#define C11_GPIO_Port GPIOB
#define L4_Pin GPIO_PIN_6
#define L4_GPIO_Port GPIOB
#define L3_Pin GPIO_PIN_7
#define L3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

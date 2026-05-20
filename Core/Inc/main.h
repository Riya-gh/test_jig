/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define DI6_Pin GPIO_PIN_13
#define DI6_GPIO_Port GPIOC
#define DI7_Pin GPIO_PIN_14
#define DI7_GPIO_Port GPIOC
#define DI8_Pin GPIO_PIN_15
#define DI8_GPIO_Port GPIOC
#define DI9_Pin GPIO_PIN_0
#define DI9_GPIO_Port GPIOF
#define DI10_Pin GPIO_PIN_1
#define DI10_GPIO_Port GPIOF
#define AI1_Pin GPIO_PIN_0
#define AI1_GPIO_Port GPIOA
#define AI2_Pin GPIO_PIN_1
#define AI2_GPIO_Port GPIOA
#define AI3_Pin GPIO_PIN_2
#define AI3_GPIO_Port GPIOA
#define AI4_Pin GPIO_PIN_3
#define AI4_GPIO_Port GPIOA
#define AI5_Pin GPIO_PIN_4
#define AI5_GPIO_Port GPIOA
#define AI6_Pin GPIO_PIN_5
#define AI6_GPIO_Port GPIOA
#define AI7_Pin GPIO_PIN_6
#define AI7_GPIO_Port GPIOA
#define AI8_Pin GPIO_PIN_7
#define AI8_GPIO_Port GPIOA
#define DO11_Pin GPIO_PIN_0
#define DO11_GPIO_Port GPIOB
#define DO1_Pin GPIO_PIN_1
#define DO1_GPIO_Port GPIOB
#define DO2_Pin GPIO_PIN_2
#define DO2_GPIO_Port GPIOB
#define DO3_Pin GPIO_PIN_10
#define DO3_GPIO_Port GPIOB
#define DO4_Pin GPIO_PIN_11
#define DO4_GPIO_Port GPIOB
#define DO5_Pin GPIO_PIN_12
#define DO5_GPIO_Port GPIOB
#define DO6_Pin GPIO_PIN_13
#define DO6_GPIO_Port GPIOB
#define DI1_Pin GPIO_PIN_15
#define DI1_GPIO_Port GPIOB
#define DO7_Pin GPIO_PIN_8
#define DO7_GPIO_Port GPIOA
#define DO8_Pin GPIO_PIN_9
#define DO8_GPIO_Port GPIOA
#define DO13_Pin GPIO_PIN_6
#define DO13_GPIO_Port GPIOC
#define DO14_Pin GPIO_PIN_7
#define DO14_GPIO_Port GPIOC
#define DO9_Pin GPIO_PIN_10
#define DO9_GPIO_Port GPIOA
#define DO10_Pin GPIO_PIN_15
#define DO10_GPIO_Port GPIOA
#define DI2_Pin GPIO_PIN_2
#define DI2_GPIO_Port GPIOD
#define DI3_Pin GPIO_PIN_3
#define DI3_GPIO_Port GPIOD
#define DO12_Pin GPIO_PIN_3
#define DO12_GPIO_Port GPIOB
#define DI4_Pin GPIO_PIN_4
#define DI4_GPIO_Port GPIOB
#define DI5_Pin GPIO_PIN_7
#define DI5_GPIO_Port GPIOB
#define UART_TX_Pin GPIO_PIN_8
#define UART_TX_GPIO_Port GPIOB
#define UART_RX_Pin GPIO_PIN_9
#define UART_RX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

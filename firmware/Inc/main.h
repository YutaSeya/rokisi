/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_ll_adc.h"
#include "stm32f4xx_ll_dma.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_tim.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

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
#define ain2_Pin LL_GPIO_PIN_13
#define ain2_GPIO_Port GPIOC
#define ain1_Pin LL_GPIO_PIN_14
#define ain1_GPIO_Port GPIOC
#define bin1_Pin LL_GPIO_PIN_15
#define bin1_GPIO_Port GPIOC
#define bin2_Pin LL_GPIO_PIN_0
#define bin2_GPIO_Port GPIOC
#define l3gd20_cs_Pin LL_GPIO_PIN_2
#define l3gd20_cs_GPIO_Port GPIOC
#define mpu_cs_Pin LL_GPIO_PIN_3
#define mpu_cs_GPIO_Port GPIOC
#define led_right_Pin LL_GPIO_PIN_10
#define led_right_GPIO_Port GPIOB
#define pushsw1_Pin LL_GPIO_PIN_11
#define pushsw1_GPIO_Port GPIOB
#define enc_left_cs_Pin LL_GPIO_PIN_12
#define enc_left_cs_GPIO_Port GPIOB
#define led1_Pin LL_GPIO_PIN_6
#define led1_GPIO_Port GPIOC
#define led2_Pin LL_GPIO_PIN_7
#define led2_GPIO_Port GPIOC
#define led3_Pin LL_GPIO_PIN_8
#define led3_GPIO_Port GPIOC
#define led4_Pin LL_GPIO_PIN_9
#define led4_GPIO_Port GPIOC
#define led_left_Pin LL_GPIO_PIN_8
#define led_left_GPIO_Port GPIOA
#define fled_blue_Pin LL_GPIO_PIN_11
#define fled_blue_GPIO_Port GPIOA
#define fled_green_Pin LL_GPIO_PIN_12
#define fled_green_GPIO_Port GPIOA
#define fled_red_Pin LL_GPIO_PIN_13
#define fled_red_GPIO_Port GPIOA
#define enc_right_cs_Pin LL_GPIO_PIN_2
#define enc_right_cs_GPIO_Port GPIOD
#define pushsw2_Pin LL_GPIO_PIN_7
#define pushsw2_GPIO_Port GPIOB
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

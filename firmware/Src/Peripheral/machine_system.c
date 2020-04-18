/**
 * @file machine_system.h
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#include "machine_system.h"

#include "encoder.h"
#include "machine_io.h"
#include "motor.h"
#include "sensor.h"
#include "l3gd20.h"
#include "mpu6500.h"

#include <stdio.h>

/**
 * @brief initialize IMU(L3GD20 and MPU6500)
 * @details
 * The behavior depends on the setting of the 
 * variable defined at the beginning of this file.
 * You check _USE_L3GD20 and _USE_MPU6500.
 * If MCU judge to faile initialize, MCU do infinite loop 
 * and output error message for uart. 
 */
void IMU_Init(void)
{
  
  SPI3_Starat();

  uint8_t l3gd20_check = 0;
  uint8_t mpu6500_check = 0;
  #if _USE_L3GD20
    l3gd20_check = L3GD20_Init();
    if(l3gd20_check == 0){
      l3gd20_check = L3GD20_Init();
      if(l3gd20_check == 0 && _USE_MPU6500 == 0){
        while(1){
          printf("L3GD20 initialize error\r");
        }
      }
    }
  #endif

  #if _USE_MPU6500
    mpu6500_check = MPU6500_Init();
    if(mpu6500_check == 0){
      mpu6500_check = MPU6500_Init();
      if(mpu6500_check == 0 && l3gd20_check == 0){
        while(1){
          printf("MPU6500 initialize error\r");
        }
      }
    }
  #endif
}

/**
 * @brief initialize Peripheral 
 */
void machine_init(void)
{
  // printf buffer clear
  setbuf(stdout, NULL);

  // turn off UI LED
  setFullColorLed(0x00);
  setUILed(0x00);
  setSideSensorUILed(0x00);

  // enable ADC2
  ADC2_Start();

  // enable ADC1
  ADC1_Start();

  // enable SPI1, SPI2(encoder)
  SPI1_Starat();
  SPI2_Starat();

  // enable TIM4(motor pwm output)
  TIM4_Start();

  // light LED and off LED
  setFullColorLed(0x07);
  setUILed(0x0f);
  setSideSensorUILed(0x03);
  LL_mDelay(300);
  setFullColorLed(0x00);
  setUILed(0x00);
  setSideSensorUILed(0x00);

  // enable IMU
  IMU_Init();

  // enable TIM5 interrupt
  LL_TIM_EnableIT_UPDATE(TIM5);
  LL_TIM_ClearFlag_UPDATE(TIM5);
	LL_TIM_EnableCounter(TIM5);
}
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
#include "mpu6500.h"

#include "interrupt.h"

#include <stdio.h>


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
  ADC_StopConvertion();

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
  SPI3_Starat();
  uint8_t mpu6500_check = 0;

  mpu6500_check = MPU6500_Init();
  if(mpu6500_check == 0){
    mpu6500_check = MPU6500_Init();
    if(mpu6500_check == 0){
      while(1){
        printf("MPU6500 initialize error\r");
      }
    }
  }

  if(mpu6500_check == 0){
    printf("MPU6500 error\r\n");
  } else {
    printf("MPU6500 OK\r\n");
  }

  // enable TIM5 interrupt
  LL_TIM_EnableIT_UPDATE(TIM5);
  LL_TIM_ClearFlag_UPDATE(TIM5);
	LL_TIM_EnableCounter(TIM5);

  LL_mDelay(100);

}

void test_case(void)
{

  MPU6500_StartCalibration();
  LL_mDelay(300);

  printf("\r\n");

  while(getPushSW2() == 0){
    printf("mpu gyro z = %5.5f\r", gyro_z);
  }
  printf("\r\n");

  while(getPushSW1() == 0){
    printf("get batt voltage = %5.5f\r", batt_voltage);
  }
  printf("\r\n");

  // start AD convertion
  ADC_StartConvertion(); 

  while(getPushSW2() == 0){
    showADC();
  }
}

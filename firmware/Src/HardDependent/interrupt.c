/**
 * @file interrupt.c
 * @author yuta S.
 * @date 2020/4/19
 * @version 0.1
 */ 

#include "interrupt.h"

#include "config.h"

#include "sensor.h"
#include "mpu6500.h"
#include "encoder.h"
#include "motor.h"

#include "machine_io.h"

float batt_voltage;
float gyro_z;

/**
 * @brief callback function
 * @details
 *  This function call TIM5_IRQHandler(void).
 */
void interrputProcess(void)
{
  // update peripheral data
  // ADC 
  batt_voltage = getBatteryVoltage();
  checkADCProcess();

  // IMU
  if(MPU6500_GetStatus() == 1){
    gyro_z = MPU6500_GetGyroZ();
  } else {
    MPU6500_CalibrateSensor();
  }
}
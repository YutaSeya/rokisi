/**
 * @file mpu6500.h
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#ifndef __MPU6500_H
#define __MPU6500_H

#include "imu.h"

#if _USE_MPU6500

uint8_t MPU6500_Init(void);
void MPU6500_StartCalibration(void);
void MPU6500_CalibrateSensor(void);
uint8_t MPU6500_GetStatus(void);
float MPU6500_GetGyroZ(void);
float MPU6500_GetAccelX(void);
float MPU6500_GetAccelY(void);

#endif

#endif /* __MPU6500_H */
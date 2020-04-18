/**
 * @file imu.h
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#ifndef __IMU_H
#define __IMU_H

#include "spi.h"

/// L3GD20 use(1) or do not use(0)
#define _USE_L3GD20 1
/// MPU6500 use(1) or do not use(0)
#define _USE_MPU6500 1
/// select l3gd20
#define SELECT_L3GD20 0
/// select mpu6500
#define SELECT_MPU6500 1

/// number of calibration
#define NUMBER_CALIBRATION 256

void SPI3_Starat(void);
void SPI3_Communication(uint8_t *tx_data, uint8_t *rx_data, uint8_t length, uint8_t select);

#endif /* __IMU_H */
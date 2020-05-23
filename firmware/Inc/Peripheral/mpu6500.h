/**
 * @file mpu6500.h
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#ifndef __MPU6500_H
#define __MPU6500_H

#include "spi.h"

void SPI3_Starat(void);
void SPI3_Communication(uint8_t *tx_data, uint8_t *rx_data, uint8_t length);

uint8_t MPU6500_Init(void);
void MPU6500_StartCalibration(void);
void MPU6500_CalibrateSensor(void);
uint8_t MPU6500_GetStatus(void);
float MPU6500_GetGyroZ(void);
float MPU6500_GetAccelX(void);
float MPU6500_GetAccelY(void);

#endif /* __MPU6500_H */
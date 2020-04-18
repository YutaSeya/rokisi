/**
 * @file l3gd20.h
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#ifndef __L3GD20_H
#define __L3GD20_H

#include "imu.h"

#if _USE_L3GD20

uint8_t L3GD20_Init(void);
void L3GD20_StartCalibration(void);
void L3GD20_CalibrateGyroZ(void);
uint8_t L3GD20_GetStatus(void);
float L3GD20_GetGyroZ(void);

#endif

#endif /* __L3GD20_H */
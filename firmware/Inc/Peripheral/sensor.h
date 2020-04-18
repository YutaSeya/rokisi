/**
 * @file sensor.h
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#ifndef __SENSOR_H
#define __SENSOR_H

#include "adc.h"

void ADC2_Start(void);
float getBatteryVoltage(void);
void ADC1_Start(void);
void ADC1_StopConvertion(void);
void ADC1_StartConvertion(void);
void ADC1_DMA2_TransferComplete_Callback(void);

#endif /* __SENSOR_H */
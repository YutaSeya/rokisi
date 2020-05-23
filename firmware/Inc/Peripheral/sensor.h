/**
 * @file sensor.h
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#ifndef __SENSOR_H
#define __SENSOR_H

#include "adc.h"

///3.3 / 1024.0 * ( 10000.0 + 3300.0 ) / 3300.0
#define BATT_CONVERTION_CONST 0.01298828125f

void ADC2_Start(void);
float getBatteryVoltage(void);
void ADC1_Start(void);
void ADC1_DMA2_StartConvertion(void);
void ADC_StartConvertion(void);
void ADC_StopConvertion(void);
void checkADCProcess(void);
void ADC1_DMA2_TransferComplete_Callback(void);
void showADC(void);

#endif /* __SENSOR_H */
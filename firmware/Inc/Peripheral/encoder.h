/**
 * @file encoder.h
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#ifndef __ENCODER_H
#define __ENCODER_H

#include "spi.h"

void SPI1_Starat(void);
void SPI2_Starat(void);
uint16_t MA700Right_getEncoderData(void);
uint16_t MA700Left_getEncoderData(void);
void updateEncoder(float *left, float *right);

#endif /* __ENCODER_H */
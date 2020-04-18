/**
 * @file motor.h
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#ifndef __MOTOR_H
#define __MOTOR_H

#include "tim.h"

void TIM4_Start(void);
void controlMotor(int32_t left, int32_t right);

#endif /* __MOTOR_H */
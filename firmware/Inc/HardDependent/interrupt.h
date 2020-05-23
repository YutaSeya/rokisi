/**
 * @file interrupt.h
 * @author yuta S.
 * @date 2020/4/19
 * @version 0.1
 */ 

#ifndef __INTERRUPT_H
#define __INTERRUPT_H

extern float batt_voltage;
extern float gyro_z;

void interrputProcess(void);

#endif /* __INTERRUPT_H */
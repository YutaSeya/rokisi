/**
 * @file machine_io.h
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#ifndef __MACHINE_IO_H
#define __MACHINE_IO_H

#include "gpio.h"

void setFullColorLed(uint8_t light);
void setUILed(uint8_t light);
void setSideSensorUILed(uint8_t light);
uint8_t getPushSW1(void);
uint8_t getPushSW2(void);

#endif /* __MACHINE_IO_H */
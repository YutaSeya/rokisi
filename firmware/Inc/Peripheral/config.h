/**
 * @file config.h
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#ifndef __CONFIG_H
#define __CONFIG_H

#include "main.h"

// my pi
#define PI 3.14159265358979f 

/// control cycle
#define dt 0.001f 

/// gear ration(80/20)
#define GEAR_RATION 4.0f

/// machine tread(mm)
#define MACHINE_TREAD 99.0f

/// machine weight(kg)
#define MACHINE_WEIGHT 0.10f

/// machine wheel radious(mm)
#define MACHINE_WHEEL_RADIUS 13.5f

#endif /* __CONFIG_H */
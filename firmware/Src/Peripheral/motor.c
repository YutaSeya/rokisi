/**
 * @file motor.c
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#include "motor.h"

/**
 * @brief start TIM4 and enable outputs
 */ 
void TIM4_Start(void)
{
  LL_TIM_EnableAllOutputs(TIM4);

  LL_TIM_EnableCounter(TIM4);
}

/**
 * @brief TIM4 set pwm 
 * @param left left motor pwm 
 * @param right right motor pwm
 * @details
 *  This function has input value limit.
 *  input value 0 <= left , right <= 799
 *  Safety measure
 *  if input value > 799 then value = 799
 */ 
void TIM4_SetPWM(uint32_t left, uint32_t right)
{
  if(left > 799) left = 799;
  if(right > 799) right = 799;
  LL_TIM_OC_SetCompareCH3(TIM4, right);
  LL_TIM_OC_SetCompareCH4(TIM4, left);

  LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH3);
  LL_TIM_CC_DisableChannel(TIM4, LL_TIM_CHANNEL_CH4);

  LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH3);
  LL_TIM_CC_EnableChannel(TIM4, LL_TIM_CHANNEL_CH4);
}

/**
 * @brief control motor CW,CCW and outputs pwm. 
 * @param left left motor pwm
 * @param right right motor pwm
 */ 
void controlMotor(int32_t left, int32_t right)
{
  if(left < 0){
    left = -1 * left;
    LL_GPIO_ResetOutputPin(bin1_GPIO_Port, bin1_Pin);
    LL_GPIO_SetOutputPin(bin2_GPIO_Port, bin2_Pin);
  } else {
    LL_GPIO_SetOutputPin(bin1_GPIO_Port, bin1_Pin);
    LL_GPIO_ResetOutputPin(bin2_GPIO_Port, bin2_Pin);
  }

  if(right < 0){
    right = -1 * right;
    LL_GPIO_ResetOutputPin(ain1_GPIO_Port, ain1_Pin);
    LL_GPIO_SetOutputPin(ain2_GPIO_Port, ain2_Pin);
  } else {
    LL_GPIO_SetOutputPin(ain1_GPIO_Port, ain1_Pin);
    LL_GPIO_ResetOutputPin(ain2_GPIO_Port, ain2_Pin);
  }

  TIM4_SetPWM(left, right);
}
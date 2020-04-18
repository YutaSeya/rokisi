/**
 * @file machine_io.c
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#include "machine_io.h"

/**
 * @brief set full color led light pattern
 * @param light specify led for each bit
 * @details 
 * lower 3bits
 * |blue |green| red |
 * |-----|-----|-----|
 * |  4  |  2  |  1  |
 */
void setFullColorLed(uint8_t light)
{
  uint8_t red = (~light & 0x01);
  uint8_t green = (~light & 0x02) >> 1;
  uint8_t blue = (~light & 0x04) >> 2;

  if(red == 1) LL_GPIO_ResetOutputPin(fled_red_GPIO_Port, fled_red_Pin);
  else LL_GPIO_SetOutputPin(fled_red_GPIO_Port, fled_red_Pin);

  if(green == 1) LL_GPIO_ResetOutputPin(fled_green_GPIO_Port, fled_green_Pin);
  else LL_GPIO_SetOutputPin(fled_green_GPIO_Port, fled_green_Pin);

  if(blue == 1) LL_GPIO_ResetOutputPin(fled_blue_GPIO_Port, fled_blue_Pin);
  else LL_GPIO_SetOutputPin(fled_blue_GPIO_Port, fled_blue_Pin);
}

/**
 * @brief set UI led light pattern
 * @param light specify led for each bit
 * @details 
 * lower 4bits
 * |led4 |led3 |led2 |led1 |
 * |-----|-----|-----|-----|
 * |  8  |  4  |  2  |  1  |
 */
void setUILed(uint8_t light)
{
  uint8_t led1 = (~light & 0x01);
  uint8_t led2 = (~light & 0x02) >> 1;
  uint8_t led3 = (~light & 0x04) >> 2;
  uint8_t led4 = (~light & 0x08) >> 3;

  if(led1 == 1) LL_GPIO_ResetOutputPin(led1_GPIO_Port, led1_Pin);
  else LL_GPIO_SetOutputPin(led1_GPIO_Port, led1_Pin);

  if(led2 == 1) LL_GPIO_ResetOutputPin(led2_GPIO_Port, led2_Pin);
  else LL_GPIO_SetOutputPin(led2_GPIO_Port, led2_Pin);

  if(led3 == 1) LL_GPIO_ResetOutputPin(led3_GPIO_Port, led3_Pin);
  else LL_GPIO_SetOutputPin(led3_GPIO_Port, led3_Pin);

  if(led4 == 1) LL_GPIO_ResetOutputPin(led4_GPIO_Port, led4_Pin);
  else LL_GPIO_SetOutputPin(led4_GPIO_Port, led4_Pin);
}

/**
 * @brief set side sensor circuits ui led light pattern
 * @param light specify led for each bit
 * @details 
 * lower 2bits
 * |right|left |
 * |-----|-----|
 * |  2  |  1  |
 */
void setSideSensorUILed(uint8_t light)
{
  uint8_t left = (~light & 0x01);
  uint8_t right = (~light & 0x02) >> 1; 

  if(left == 1) LL_GPIO_ResetOutputPin(led_left_GPIO_Port, led_left_Pin);
  else LL_GPIO_SetOutputPin(led_right_GPIO_Port, led_right_Pin);

  if(right == 1) LL_GPIO_SetOutputPin(led_right_GPIO_Port, led_right_Pin);
  else LL_GPIO_SetOutputPin(led_right_GPIO_Port, led_right_Pin);
}

/**
 * @brief get push switch1 data
 * @return 1 : On, 0: Off 
 * @details 
 */
uint8_t getPushSW1(void)
{
  return (uint8_t)LL_GPIO_IsInputPinSet(pushsw1_GPIO_Port, pushsw1_Pin);
}

/**
 * @brief get push switch2 data
 * @return 1 : On, 0: Off 
 * @details 
 */
uint8_t getPushSW2(void)
{
  return (uint8_t)LL_GPIO_IsInputPinSet(pushsw2_GPIO_Port, pushsw2_Pin);
}

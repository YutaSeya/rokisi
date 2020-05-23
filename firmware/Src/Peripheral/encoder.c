/**
 * @file encoder.c
 * @author yuta S.
 * @date 2020/4/13
 * @version 0.1
 */ 

#include "encoder.h"
#include "config.h"

#define MA700_MAX_COUNT 4090
#define MA700_HALF_COUNT 2044

int16_t left_previous = 0;
int16_t right_previous = 0;

float prev_left_vel = 0.0f;
float prev_right_vel = 0.0f;

/**
 * @brief SPI1 Enable
 * @details
 *  enable SPI1 and set SPI1 enc right cs high.
 */
void SPI1_Starat(void)
{
  LL_SPI_Enable(SPI1);
  LL_GPIO_SetOutputPin(enc_right_cs_GPIO_Port, enc_right_cs_Pin);
}

/**
 * @brief Performs SPI1 communication
 * @param tx_data write data array 
 * @param rx_data read data array 
 * @param length communication length
 * @details 
 *  Tx_data and rx_data arrays need the same size as length,
 *  because SPI communication is full duplex communication.
 */
void SPI1_Communication(uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
  uint8_t count = length;

  LL_GPIO_ResetOutputPin(enc_right_cs_GPIO_Port, enc_right_cs_Pin);

  if(LL_SPI_IsActiveFlag_RXNE(SPI1) == SET) LL_SPI_ReceiveData8(SPI1);

  if(LL_SPI_IsEnabled(SPI1) == RESET) LL_SPI_Enable(SPI1);

  while(count > 0){
    LL_SPI_TransmitData8(SPI1, *tx_data++);
    while(LL_SPI_IsActiveFlag_TXE(SPI1) == RESET);
    while(LL_SPI_IsActiveFlag_RXNE(SPI1) == RESET);
    *rx_data++ = LL_SPI_ReceiveData8(SPI1);
    count--;
  }

  LL_GPIO_SetOutputPin(enc_right_cs_GPIO_Port, enc_right_cs_Pin);
  
}


/**
 * @brief SPI2 Enable
 * @details
 *  enable SPI2 and set SPI2 enc left cs high.
 */
void SPI2_Starat(void)
{
  LL_SPI_Enable(SPI2);
  LL_GPIO_SetOutputPin(enc_left_cs_GPIO_Port, enc_left_cs_Pin);
}

/**
 * @brief Performs SPI2 communication
 * @param tx_data write data array 
 * @param rx_data read data array 
 * @param length communication length
 * @details 
 *  Tx_data and rx_data arrays need the same size as length,
 *  because SPI communication is full duplex communication.
 */
void SPI2_Communication(uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
  uint8_t count = length;

  LL_GPIO_ResetOutputPin(enc_left_cs_GPIO_Port, enc_left_cs_Pin);

  if(LL_SPI_IsActiveFlag_RXNE(SPI2) == SET) LL_SPI_ReceiveData8(SPI2);

  if(LL_SPI_IsEnabled(SPI2) == RESET) LL_SPI_Enable(SPI2);

  while(count > 0){
    LL_SPI_TransmitData8(SPI2, *tx_data++);
    while(LL_SPI_IsActiveFlag_TXE(SPI2) == RESET);
    while(LL_SPI_IsActiveFlag_RXNE(SPI2) == RESET);
    *rx_data++ = LL_SPI_ReceiveData8(SPI2);
    count--;
  }

  LL_GPIO_SetOutputPin(enc_left_cs_GPIO_Port, enc_left_cs_Pin);
  
}

/**
 * @brief get encoder value for right MA700 
 * @return 12bit encoder data
 */
uint16_t MA700Right_getEncoderData(void)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];
  uint16_t data = 0;

  tx_data[0] = 0x00;
  tx_data[1] = 0x00;

  SPI1_Communication(tx_data, rx_data, 2);

  data = (uint16_t)( (uint16_t)(rx_data[0] << 4) | (uint16_t)(rx_data[1] & 0x0C) );

  return data;
}

/**
 * @brief get encoder value for left MA700 
 * @return 12bit encoder data
 */
uint16_t MA700Left_getEncoderData(void)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];
  uint16_t data = 0;

  tx_data[0] = 0x00;
  tx_data[1] = 0x00;

  SPI2_Communication(tx_data, rx_data, 2);

  data = (uint16_t)( (uint16_t)(rx_data[0] << 4) | (uint16_t)(rx_data[1] & 0x0C) );

  return data;
}

/**
 * @brief update encoder value and get physical quantity data
 * @param left left speed(mm/s)
 * @param right right speed(mm/s)
 */
void updateEncoder(float *left, float *right)
{
  int16_t left_now = 0;
  int16_t right_now = 0;
  int16_t left_count = 0;
  int16_t right_count = 0;
  float left_omega = 0.0f;
  float right_omega = 0.0f;
  float left_now_vel = 0.0f;
  float right_now_vel = 0.0f;

  left_now = MA700Left_getEncoderData();
  right_now = MA700Right_getEncoderData();

  left_count = left_now - left_previous;
  right_count = right_now - right_previous;

  left_previous = left_now;
  right_previous = right_now;

  if(left_count > MA700_HALF_COUNT){
    left_count -= MA700_MAX_COUNT;
  } else if(left_count < -MA700_HALF_COUNT){
    left_count += MA700_MAX_COUNT;
  }

  if(right_count > MA700_HALF_COUNT){
    right_count -= MA700_MAX_COUNT;
  } else if(right_count < -MA700_HALF_COUNT){
    right_count += MA700_MAX_COUNT;
  }

  // calculate wheel omega

  // 回転方向によってプラスマイナスの設定が必要 
  left_omega = (float)(-left_count * 2.0f / MA700_MAX_COUNT * PI / dt);
  right_omega = (float)(right_count * 2.0f / MA700_MAX_COUNT * PI / dt);

  left_now_vel = left_omega * MACHINE_WHEEL_RADIUS;
  right_now_vel = right_omega * MACHINE_WHEEL_RADIUS;

  *left = (left_now_vel + prev_left_vel) / 2.0f;
  *right = (right_now_vel + prev_right_vel) / 2.0f;

  prev_left_vel = left_now_vel;
  prev_right_vel = right_now_vel;
  

}
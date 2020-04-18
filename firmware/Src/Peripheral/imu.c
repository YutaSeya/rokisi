/**
 * @file imu.c
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 
#include "imu.h"

/**
 * @brief SPI3 Enable
 * @details
 *  enable SPI3 and set SPI3 IMU CS Pin high.
 */
void SPI3_Starat(void)
{
  LL_SPI_Enable(SPI3);
  LL_GPIO_SetOutputPin(mpu_cs_GPIO_Port, mpu_cs_Pin);
  LL_GPIO_SetOutputPin(l3gd20_cs_GPIO_Port, l3gd20_cs_Pin);
}

/**
 * @brief Performs SPI3 communication
 * @param tx_data write data array 
 * @param rx_data read data array 
 * @param length communication length
 * @param select L3GD20 or MPU6500
 * @details 
 *  Tx_data and rx_data arrays need the same size as length,
 *  because SPI communication is full duplex communication.
 *  select 0:L3GD20, 1:MPU6500
 */
void SPI3_Communication(uint8_t *tx_data, uint8_t *rx_data, uint8_t length, uint8_t select)
{
  uint8_t count = length;

  if(select == SELECT_L3GD20){
    LL_GPIO_ResetOutputPin(l3gd20_cs_GPIO_Port, l3gd20_cs_Pin);
  } else {
    LL_GPIO_ResetOutputPin(mpu_cs_GPIO_Port, mpu_cs_Pin);
  }

  if(LL_SPI_IsActiveFlag_RXNE(SPI3) == SET) LL_SPI_ReceiveData8(SPI3);

  if(LL_SPI_IsEnabled(SPI3) == RESET) LL_SPI_Enable(SPI3);

  while(count > 0){
    LL_SPI_TransmitData8(SPI3, *tx_data++);
    while(LL_SPI_IsActiveFlag_TXE(SPI3) == RESET);
    while(LL_SPI_IsActiveFlag_RXNE(SPI3) == RESET);
    *rx_data++ = LL_SPI_ReceiveData8(SPI3);
    count--;
  }

  LL_GPIO_SetOutputPin(l3gd20_cs_GPIO_Port, l3gd20_cs_Pin);
  LL_GPIO_SetOutputPin(mpu_cs_GPIO_Port, mpu_cs_Pin);
  
}



/**
 * @file l3gd20.c
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#include "l3gd20.h"
#include "main.h"

#if _USE_L3GD20

/**
 * @enum L3GD20_DEF
 * @brief 
 *  define L3GD20 use data.
 */ 
enum L3GD20_DEF
{
  L3GD20_WHO_AM_I = 0xD4,
  L3GD20_POWER_ON = 0x0F,
  L3GD20_SET_2000DPS = 0x20,
  L3GD20_REG_WHO_AM_I = 0x0F,
  L3GD20_REG_CTRL_REG1 = 0x20,
  L3GD20_REG_CTRL_REG4 = 0x23,
  L3GD20_REG_X_LOW = 0x28,
  L3GD20_REG_X_HIGH,
  L3GD20_REG_Y_LOW,
  L3GD20_REG_Y_HIGH,
  L3GD20_REG_Z_LOW,
  L3GD20_REG_Z_HIGH,
};

#define L3GD20_FACTOR 0.070f

uint16_t cnt_l3gd20_calibration = 0;
uint8_t l3gd20_status = 1;
float l3gd20_gyro_z_offset = 0.0f;

/**
 * @brief Write byte to l3gd20
 * @param reg set register
 * @param val set write value 
 */
void L3GD20_WriteByte(uint8_t reg, uint8_t val)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];

  tx_data[0] = reg & 0x7F;
  tx_data[1] = val;

  SPI3_Communication(tx_data, rx_data, 2, SELECT_L3GD20); 
}

/**
 * @brief read byte to l3gd20
 * @param reg set register
 * @return read register byte. 
 */
uint8_t L3GD20_ReadByte(uint8_t reg)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];

  tx_data[0] = reg | 0x80;
  tx_data[1] = 0x00;

  SPI3_Communication(tx_data, rx_data, 2, SELECT_L3GD20); 

  return rx_data[1];
}

/**
 * @brief initialize l3gd20 
 * @return success(1) or failed(0)
 */
uint8_t L3GD20_Init(void)
{
  uint8_t who_am_i = 0;
  // check who am i
  who_am_i = L3GD20_ReadByte(L3GD20_REG_WHO_AM_I);

  if(who_am_i != L3GD20_WHO_AM_I){
    LL_mDelay(10);
    who_am_i = L3GD20_ReadByte(L3GD20_REG_WHO_AM_I);
    if(who_am_i != L3GD20_WHO_AM_I) return 0;
  }

  L3GD20_WriteByte(L3GD20_REG_CTRL_REG1, L3GD20_POWER_ON);
  LL_mDelay(10);
  L3GD20_WriteByte(L3GD20_REG_CTRL_REG4, L3GD20_SET_2000DPS);
  LL_mDelay(10);

  return 1;
}

/**
 * @brief start l3gd20 sensor calibration
 */
void L3GD20_StartCalibration(void)
{
  cnt_l3gd20_calibration = 0;
  l3gd20_status = 0;
  l3gd20_gyro_z_offset = 0.0f;
}

/**
 * @brief calibrate l3gd20 sensor
 * @details
 *  This function is called by interrupt handling. 
 */
void L3GD20_CalibrateGyroZ(void)
{
  int16_t data = 0;

  data = (int16_t)( ((int16_t)L3GD20_ReadByte(L3GD20_REG_Z_HIGH) << 8) | ((int16_t)L3GD20_ReadByte(L3GD20_REG_Z_LOW)) );

  if(cnt_l3gd20_calibration < NUMBER_CALIBRATION){
    l3gd20_gyro_z_offset += (float)data;
    cnt_l3gd20_calibration++;
  } else {
    l3gd20_gyro_z_offset = (float)(l3gd20_gyro_z_offset/NUMBER_CALIBRATION);
    l3gd20_status = 1;
  }
}

/**
 * @brief get l3gd20 status
 * @return ready(1) or calibrate(0)
 */
uint8_t L3GD20_GetStatus(void)
{
  return l3gd20_status;
}

/**
 * @brief get l3gd20 gyro z
 * @return omega (deg/sec)
 */
float L3GD20_GetGyroZ(void)
{
  int16_t data = 0;
  float gyro = 0.0f;

  data = (int16_t)( ((int16_t)L3GD20_ReadByte(L3GD20_REG_Z_HIGH) << 8) | ((int16_t)L3GD20_ReadByte(L3GD20_REG_Z_LOW)) );
  gyro = (float)((data-l3gd20_gyro_z_offset) * L3GD20_FACTOR);
  return gyro;  
}

#endif
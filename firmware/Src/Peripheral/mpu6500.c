/**
 * @file mpu6500.c
 * @author yuta S.
 * @date 2020/4/12
 * @version 0.1
 */ 

#include "mpu6500.h"

#if _USE_MPU6500

/**
 * @enum MPU6500_DEF
 * @brief 
 *  define MPU6500 use data.
 */ 
enum MPU6500_DEF
{
  MPU6500_WHO_AM_I = 0x70,
  MPU6500_POWER_ON = 0x00,
  MPU6500_CONFIG = 0x00,
  MPU6500_GYRO_CONFIG = 0x18,
  MPU6500_ACCEL_CONFIG = 0x10,
  MPU6500_REG_WHO_AM_I = 0x75,
  MPU6500_REG_PWR_MGMT_1 = 0x6B,
  MPU6500_REG_CONFIG = 0x1A,
  MPU6500_REG_GYRO_CONFIG = 0x1B,
  MPU6500_REG_ACCEL_CONFIG = 0x1C,
  MPU6500_REG_ACCEL_XOUT_H = 0x3B,
  MPU6500_REG_ACCEL_XOUT_L = 0x3C,
  MPU6500_REG_ACCEL_YOUT_H = 0x3D,
  MPU6500_REG_ACCEL_YOUT_L = 0x3E,
  MPU6500_REG_ACCEL_ZOUT_H = 0x3F,
  MPU6500_REG_ACCEL_ZOUT_L = 0x40,
  MPU6500_REG_GYRO_XOUT_H = 0x43,
  MPU6500_REG_GYRO_XOUT_L = 0x44,
  MPU6500_REG_GYRO_YOUT_H = 0x45,
  MPU6500_REG_GYRO_YOUT_L = 0x46,
  MPU6500_REG_GYRO_ZOUT_H = 0x47,
  MPU6500_REG_GYRO_ZOUT_L = 0x48,
};

#define MPU6500_GYRO_FACTOR 16.4f
#define MPU6500_ACCEL_FACTOR 0.00239257812f

uint16_t cnt_mpu_calibration = 0;
uint8_t mpu_status = 1;

float mpu6500_gyro_z_offset = 0.0f;
float mpu6500_accel_x_offset = 0.0f;
float mpu6500_accel_y_offset = 0.0f;

/**
 * @brief Write byte to mpu-6500
 * @param reg set register
 * @param val set write value 
 */
void MPU6500_WriteByte(uint8_t reg, uint8_t val)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];

  tx_data[0] = reg & 0x7F;
  tx_data[1] = val;

  SPI3_Communication(tx_data, rx_data, 2, SELECT_MPU6500); 
}

/**
 * @brief read byte to mpu-6500
 * @param reg set register
 * @return read register byte. 
 */
uint8_t MPU6500_ReadByte(uint8_t reg)
{
  uint8_t tx_data[2];
  uint8_t rx_data[2];

  tx_data[0] = reg | 0x80;
  tx_data[1] = 0x00;

  SPI3_Communication(tx_data, rx_data, 2, SELECT_MPU6500); 

  return rx_data[1];
}

/**
 * @brief initialize mpu-6500
 * @return success(1) or failed(0)
 */
uint8_t MPU6500_Init(void)
{
  uint8_t who_am_i = 0;
  who_am_i = MPU6500_ReadByte(MPU6500_REG_WHO_AM_I);
  if(who_am_i != MPU6500_WHO_AM_I){
    LL_mDelay(10);
    who_am_i = MPU6500_ReadByte(MPU6500_REG_WHO_AM_I);
    if(who_am_i != MPU6500_WHO_AM_I) return 0;
  }

  MPU6500_WriteByte(MPU6500_REG_PWR_MGMT_1, MPU6500_POWER_ON);
  LL_mDelay(10);
  MPU6500_WriteByte(MPU6500_REG_CONFIG, MPU6500_CONFIG);
  LL_mDelay(10);
  MPU6500_WriteByte(MPU6500_REG_GYRO_CONFIG, MPU6500_GYRO_CONFIG);
  LL_mDelay(10);
  MPU6500_WriteByte(MPU6500_REG_ACCEL_CONFIG, MPU6500_ACCEL_CONFIG);
  LL_mDelay(10);
  
  return 1;
}

/**
 * @brief start mpu-6500 sensor calibration
 */
void MPU6500_StartCalibration(void)
{
  cnt_mpu_calibration = 0;
  mpu_status = 0;

  mpu6500_gyro_z_offset = 0.0f;
  mpu6500_accel_x_offset = 0.0f;
  mpu6500_accel_y_offset = 0.0f;
}

/**
 * @brief calibrate mpu-6500 sensor
 * @details
 *  This function is called by interrupt handling. 
 */
void MPU6500_CalibrateSensor(void)
{
  int16_t gyro = 0;
  int16_t accel_x = 0;
  int16_t accel_y = 0;

  gyro = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_GYRO_ZOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_GYRO_ZOUT_L)) );

  accel_x = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_XOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_XOUT_L)) );
  accel_y = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_YOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_YOUT_L)) );

  if (cnt_mpu_calibration < NUMBER_CALIBRATION){
    mpu6500_gyro_z_offset += (float)gyro;
    mpu6500_accel_x_offset += (float)accel_x;
    mpu6500_accel_y_offset += (float)accel_y;
    cnt_mpu_calibration++;
  } else {
    mpu6500_gyro_z_offset = (float)(mpu6500_gyro_z_offset / NUMBER_CALIBRATION);
    mpu6500_accel_x_offset = (float)(mpu6500_accel_x_offset / NUMBER_CALIBRATION);
    mpu6500_accel_y_offset = (float)(mpu6500_accel_y_offset / NUMBER_CALIBRATION);
    mpu_status = 1;
  }
}

/**
 * @brief get mpu-6500 status
 * @return ready(1) or calibrate(0)
 */
uint8_t MPU6500_GetStatus(void)
{
  return mpu_status;
}

/**
 * @brief get mpu-6500 gyro z
 * @return omega (deg/sec)
 */
float MPU6500_GetGyroZ(void)
{
  int16_t gyro = 0;
  float omega = 0.0f;

  gyro = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_GYRO_ZOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_GYRO_ZOUT_L)) );
  omega = (float)( (gyro-mpu6500_gyro_z_offset) / MPU6500_GYRO_FACTOR);
  
  return omega;
}

/**
 * @brief get mpu-6500 accel x 
 * @return omega (m/sec^2)
 */
float MPU6500_GetAccelX(void)
{
  int16_t data = 0;
  float accel = 0.0f;
  data = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_XOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_XOUT_L)) );
  accel = (float)((data - mpu6500_accel_x_offset) / MPU6500_ACCEL_FACTOR );
  return accel;
}

/**
 * @brief get mpu-6500 accel y 
 * @return omega (m/sec^2)
 */
float MPU6500_GetAccelY(void)
{
  int16_t data = 0;
  float accel = 0.0f;
  data = (int16_t)( ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_YOUT_H) << 8) | ((int16_t)MPU6500_ReadByte(MPU6500_REG_ACCEL_YOUT_L)) );
  accel = (float)((data - mpu6500_accel_x_offset) / MPU6500_ACCEL_FACTOR );
  return accel;
}

#endif
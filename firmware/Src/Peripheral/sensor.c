/**
 * @file sensor.c
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#include "sensor.h"

///3.3f / 1024.0f * ( 10000.0f + 3300.0f ) / 1000.0f
#define BATT_CONVERTION_CONST 0.04286132812f

#define ADC_CONVERT_DATA_BUFFR_SIZE		((uint32_t)12)

uint16_t adcConvertData[ADC_CONVERT_DATA_BUFFR_SIZE];

/// enable convertion : 1, disable convertion : 0
uint8_t adc1_status = 0;

/**
 * @brief start ADC2
 */
void ADC2_Start(void)
{
  LL_ADC_Enable(ADC2);
}

/**
 * @brief convertion ADC2 and caluclate battery voltage
 * @return battery voltage
 */
float getBatteryVoltage(void)
{
  uint16_t data = 0;
  float voltage = 0.0f;
  LL_ADC_REG_StartConversionSWStart(ADC2);
  while(LL_ADC_IsActiveFlag_EOCS(ADC2) == RESET);
  LL_ADC_ClearFlag_EOCS(ADC2);
  data = LL_ADC_REG_ReadConversionData10(ADC2);
  voltage = (float)(BATT_CONVERTION_CONST * data);
  return voltage;
}

/**
 * @brief start ADC1 and enable DMA TC IT
 */
void ADC1_Start(void)
{
  LL_ADC_Enable(ADC1);
  LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_0);
}

/**
 * @brief start ADC1 DMA Convertion
 */
void ADC1_StartConvertion(void)
{
  adc1_status = 1;

	LL_DMA_DisableStream(DMA2,LL_DMA_STREAM_0);

	LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_0,
	                      LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
	                      (uint32_t)&adcConvertData, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);


	LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_0, ADC_CONVERT_DATA_BUFFR_SIZE);

	LL_DMA_EnableStream(DMA2,LL_DMA_STREAM_0);

	LL_ADC_REG_StartConversionSWStart(ADC1);

}

/**
 * @brief stop ADC1 DMA Convertion
 */
void ADC1_StopConvertion(void)
{
  adc1_status = 0;
}

/**
 * @brief update sensor function
 */
void updateLineSensor(void)
{

  // user code begin

  /* you write sensor sensing here
    sensor data stored adcConvertData array and 
    the order is STM32CubeMX settings ADC RANK. */
  
  // user code end
  

}

/**
 * @brief callback function
 * @details
 *  This function call DMA2_Stream0_IRQHandler(void).
 *  clear EOCS flag and update sensor
 */
void ADC1_DMA2_TransferComplete_Callback(void)
{  
  // clear EOCS Flag
	LL_ADC_ClearFlag_EOCS(ADC1);
  // update line sensor value
  updateLineSensor();
  // When converting continuously
  if(adc1_status == 1){
    ADC1_StartConvertion();
  }
}
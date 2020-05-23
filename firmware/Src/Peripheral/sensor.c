/**
 * @file sensor.c
 * @author yuta S.
 * @date 2020/4/15
 * @version 0.1
 */ 

#include "sensor.h"
#include "machine_io.h"

#include <stdio.h>

#define NO_CONVERTION 0
#define CONVERTION 1
#define LEFT 2
#define RIGHT 3
#define CONVERTION_REDEAY 4

#define ADC_CONVERT_DATA_SIZE		((uint32_t)8)

// local varaiable

/// adc convertion data
uint16_t adc_convert_data[ADC_CONVERT_DATA_SIZE];
/// adc convertion left data
uint16_t adc_convert_left[ADC_CONVERT_DATA_SIZE];
/// adc convertion right data
uint16_t adc_convert_right[ADC_CONVERT_DATA_SIZE];

/// enable convertion : 1, disable convertion : 0
uint8_t adc_status = 0;


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
void ADC1_DMA2_StartConvertion(void)
{
	LL_DMA_DisableStream(DMA2,LL_DMA_STREAM_0);

	LL_DMA_ConfigAddresses(DMA2, LL_DMA_STREAM_0,
	                      LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
	                      (uint32_t)&adc_convert_data, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);


	LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_0, ADC_CONVERT_DATA_SIZE);

	LL_DMA_EnableStream(DMA2,LL_DMA_STREAM_0);

	LL_ADC_REG_StartConversionSWStart(ADC1);

}

/**
 * @brief start ADC1 Convertion
 */
void ADC_StartConvertion(void)
{
  adc_status = CONVERTION_REDEAY;
}

/**
 * @brief stop ADC1 Convertion
 */
void ADC_StopConvertion(void)
{
  adc_status = NO_CONVERTION;
}

/**
 * @brief perform sensor sensing
 * @details
 */
void sensingLineSensor(void)
{
  /* you write something */
}

/**
 * @brief update sensor function
 */
void updateLineSensor(void)
{
  volatile uint16_t i = 0;
  if(adc_status == LEFT){
    // FETA、左のサイドセンサを点灯
    LL_GPIO_ResetOutputPin(fet_side_left_GPIO_Port, fet_side_left_Pin);
    LL_GPIO_ResetOutputPin(feta_GPIO_Port, feta_Pin);
    // FETB、右のサイドセンサを点灯
    LL_GPIO_SetOutputPin(fet_side_right_GPIO_Port, fet_side_right_Pin);
    LL_GPIO_SetOutputPin(fetb_GPIO_Port, fetb_Pin);
    // AD変換の処理時間をまつ
    for(i = 0; i < 250; i++);
    // 光らせたときのデータを取得する
    for(i = 0; i < ADC_CONVERT_DATA_SIZE; i++){
      adc_convert_left[i] = adc_convert_data[i];
    }
    adc_status = RIGHT;
    ADC1_DMA2_StartConvertion();
  } else if(adc_status == RIGHT){
    // FETB、右のサイドセンサを消灯
    LL_GPIO_ResetOutputPin(fet_side_right_GPIO_Port, fet_side_right_Pin);
    LL_GPIO_ResetOutputPin(fetb_GPIO_Port, fetb_Pin);    
    // 光らせたときのデータを取得する
    for(i = 0; i < ADC_CONVERT_DATA_SIZE; i++){
      adc_convert_right[i] = adc_convert_data[i];
    }
    // センサの情報をセンシングする
    sensingLineSensor();
    adc_status = CONVERTION_REDEAY;
  }
}

/**
 * @brief check ADC1 DMA Convertion
 */
void checkADCProcess(void)
{
  volatile int i;
  
  if(adc_status == CONVERTION_REDEAY){
    // AD変換の処理時間をまつ
    for(i = 0; i < 500; i++);
    adc_status = LEFT;
    ADC1_DMA2_StartConvertion();
  }
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

}

/**
 * @brief print adc show data
 */
void showADC(void)
{
  // you right printf and check adc_convert_left/right
}
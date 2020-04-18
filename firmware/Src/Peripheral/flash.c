/**
 * @file flash.c
 * @author yuta S.
 * @date 2020/4/18
 * @version 0.1
 */ 

#include "flash.h"
#include <string.h>

//1byteずつの書き込み
#define FLASH_TYPEPROGRAM_BYTE  0x00000000U
//0x1011 <<3 より 0x1011000
#define FLASH_SENTOR11					0x58  

// flash use address ( sector11 )
const uint32_t start_address = 0x80E0000; //sentor11 start address
const uint32_t end_adress = 0x80FFFFF;

/**
 * @brief wait for FLASH processing 
 */
void FLASH_WaitBusy(void)
{
	while( ( (FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY) == 1 );
}

/**
 * @brief erase FLASH Sector11
 */
void FLASH_Erease(void)
{
	FLASH->CR |= FLASH_CR_SER;
	FLASH->CR |= FLASH_SENTOR11 & FLASH_CR_SNB_Msk;
	FLASH->CR |= FLASH_CR_STRT;
	FLASH_WaitBusy();
}

/**
 * @brief write byte to specified address 
 * @param uint32_t address
 * @param uint8_t write data
 */
void FLASH_WriteByte(uint32_t address, uint8_t data)
{

	FLASH->CR &= ~(FLASH_CR_PSIZE);

	FLASH->CR |= FLASH_TYPEPROGRAM_BYTE;
	FLASH->CR |= FLASH_CR_PG;

	*(__IO uint8_t*)address = data;

	FLASH_WaitBusy();

	FLASH->CR &= ~(FLASH_CR_PG);
}

/**
 * @brief sector erase and write data (setting size)
 * @param uint32_t start address
 * @param uint8_t *write data
 * @param uint32_t wirte size
 * @details 
 *  e.g
 *  You defined structure.
 *  for example,
 *  typedef struct 
 *  {
 *    int age;
 *    char name[16];
 *  }Human;
 *  
 *  Human a;
 *  a.age = 17;
 *  a.name = "sora";
 *  
 *  FLASH_WriteData(start_address, (uint8_t*)&a, sizeof(Human));
 */
void FLASH_WriteData(uint32_t address, uint8_t* data, uint32_t size)
{
	FLASH_Unlock();
	
	FLASH_Erease();

	do {
		FLASH_WriteByte(address, *data);
	}while(++address, ++data, --size);

	FLASH_Lock();
}

/**
 * @brief write data (setting size)
 * @param uint32_t start address
 * @param uint8_t *write data
 * @param uint32_t write size
 * @details
 *  The use condition is that the specified address has been erased.
 *  e.g
 *  You defined structure.
 *  for example,
 *  typedef struct 
 *  {
 *    int age;
 *    char name[16];
 *  }Human;
 *  
 *  Human a;
 *  a.age = 17;
 *  a.name = "sora";
 *  
 *  FLASH_WriteData(start_address, (uint8_t*)&a, sizeof(Human));
 * 
 *  Human b;
 *  b.age = 40;
 *  b.name = "maou"
 * 
 *  FLASH_AddWriteData(start_address + sizeof(Human), (uint8_t*)&b, sizeof(Human));
 */
void FLASH_AddWriteData(uint32_t address, uint8_t* data, uint32_t size)
{
	FLASH_Unlock();

	do {
		FLASH_WriteByte(address, *data);
	}while(++address, ++data, --size);

	FLASH_Lock();
	
}

/**
 * @brief read data to specified address 
 * @param uint32_t address
 * @param uint8_t *read data
 * @param uint32_t read size
 * @details
 *  e.g
 *  You defined structure.
 *  for example,
 *  typedef struct 
 *  {
 *    int age;
 *    char name[16];
 *  }Human;
 *  
 *  Human a;
 * 
 *  FLASH_ReadData(start_address, (uint8_t*)&a, sizeof(Human));
 */
void FLASH_ReadData(uint32_t address, uint8_t* data, uint32_t size)
{
  memcpy(data, (uint8_t*)address, size);
}
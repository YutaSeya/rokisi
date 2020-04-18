/**
 * @file flash.h
 * @author yuta S.
 * @date 2020/4/18
 * @version 0.1
 */ 

#ifndef __FLASH_H
#define __FLASH_H

#include "main.h"

#define FLASH_KEY1               0x45670123U
#define FLASH_KEY2               0xCDEF89ABU

// flash use address ( sector11 )
extern const uint32_t start_address; //sentor11 start address
extern const uint32_t end_adress;

__STATIC_INLINE void FLASH_Lock(void)
{
	FLASH->CR |= FLASH_CR_LOCK;

}

__STATIC_INLINE void FLASH_Unlock(void)
{
	FLASH->KEYR =  FLASH_KEY1;
	FLASH->KEYR =  FLASH_KEY2;
}

void FLASH_WriteData(uint32_t address, uint8_t* data, uint32_t size);
void FLASH_AddWriteData(uint32_t address, uint8_t* data, uint32_t size);
void FLASH_ReadData(uint32_t address, uint8_t* data, uint32_t size);

#endif /* __FLASH_H */
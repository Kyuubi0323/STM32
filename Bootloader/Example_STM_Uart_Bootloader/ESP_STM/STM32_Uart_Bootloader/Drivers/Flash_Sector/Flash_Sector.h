/*
 * Flash_Sector.h
 *
 *  Created on: Dec 16, 2023
 *      Author: Kyuubi
 */

#ifndef FLASH_SECTOR_FLASH_SECTOR_H_
#define FLASH_SECTOR_FLASH_SECTOR_H_

#include "stdint.h"

uint32_t Flash_Write_Data (uint32_t StartSectorAddress, uint32_t *Data, uint16_t numberofwords);

void Flash_Read_Data (uint32_t StartSectorAddress, uint32_t *RxBuf, uint16_t numberofwords);

void Convert_To_Str (uint32_t *Data, char *Buf);

void Flash_Write_NUM (uint32_t StartSectorAddress, float Num);

float Flash_Read_NUM (uint32_t StartSectorAddress);


#endif /* FLASH_SECTOR_FLASH_SECTOR_H_ */

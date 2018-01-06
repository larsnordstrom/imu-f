#include "includes.h"
#include "flash.h"

FLASH_EraseInitTypeDef eraseInitStruct;

void erase_flash(uint32_t beginAddress, uint32_t endAddress)
{
    uint32_t pageError = 0;
    HAL_FLASH_Unlock();

    eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    eraseInitStruct.PageAddress = beginAddress;
    eraseInitStruct.NbPages = (endAddress - beginAddress) / FLASH_PAGE_SIZE;

    if (HAL_FLASHEx_Erase(&eraseInitStruct, &pageError) != HAL_OK)
    {
        while (1)
        {
            //TODO add error handler
        }
    }
}
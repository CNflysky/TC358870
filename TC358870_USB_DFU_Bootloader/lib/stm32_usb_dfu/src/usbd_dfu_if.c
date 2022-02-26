/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : usbd_dfu_if.c
 * @brief          : Usb device for Download Firmware Update.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_dfu_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
 * @brief Usb device.
 * @{
 */

/** @defgroup USBD_DFU
 * @brief Usb DFU device module.
 * @{
 */

/** @defgroup USBD_DFU_Private_TypesDefinitions
 * @brief Private types.
 * @{
 */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
 * @}
 */

/** @defgroup USBD_DFU_Private_Defines
 * @brief Private defines.
 * @{
 */

#define FLASH_DESC_STR "@Internal Flash   /0x08000000/22*1Ka,42*01Kg"

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
 * @}
 */

/** @defgroup USBD_DFU_Private_Macros
 * @brief Private macros.
 * @{
 */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
 * @}
 */

/** @defgroup USBD_DFU_Private_Variables
 * @brief Private variables.
 * @{
 */

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
 * @}
 */

/** @defgroup USBD_DFU_Exported_Variables
 * @brief Public variables.
 * @{
 */

extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */

/**
 * @}
 */

/** @defgroup USBD_DFU_Private_FunctionPrototypes
 * @brief Private functions declaration.
 * @{
 */

static uint16_t MEM_If_Init_FS(void);
static uint16_t MEM_If_Erase_FS(uint32_t Add);
static uint16_t MEM_If_Write_FS(uint8_t *src, uint8_t *dest, uint32_t Len);
static uint8_t *MEM_If_Read_FS(uint8_t *src, uint8_t *dest, uint32_t Len);
static uint16_t MEM_If_DeInit_FS(void);
static uint16_t MEM_If_GetStatus_FS(uint32_t Add, uint8_t Cmd, uint8_t *buffer);

/* USER CODE BEGIN PRIVATE_FUNCTIONS_DECLARATION */

/* USER CODE END PRIVATE_FUNCTIONS_DECLARATION */

/**
 * @}
 */

#if defined(__ICCARM__) /* IAR Compiler */
#pragma data_alignment = 4
#endif
__ALIGN_BEGIN USBD_DFU_MediaTypeDef USBD_DFU_fops_FS __ALIGN_END = {
    (uint8_t *)FLASH_DESC_STR, MEM_If_Init_FS,  MEM_If_DeInit_FS,
    MEM_If_Erase_FS,           MEM_If_Write_FS, MEM_If_Read_FS,
    MEM_If_GetStatus_FS};

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  Memory initialization routine.
 * @retval USBD_OK if operation is successful, MAL_FAIL else.
 */
uint16_t MEM_If_Init_FS(void) {
  /* USER CODE BEGIN 0 */
  HAL_FLASH_Unlock();
  return (USBD_OK);
  /* USER CODE END 0 */
}

/**
 * @brief  De-Initializes Memory
 * @retval USBD_OK if operation is successful, MAL_FAIL else
 */
uint16_t MEM_If_DeInit_FS(void) {
  /* USER CODE BEGIN 1 */
  HAL_FLASH_Lock();
  return (USBD_OK);
  /* USER CODE END 1 */
}

/**
 * @brief  Erase sector.
 * @param  Add: Address of sector to be erased.
 * @retval 0 if operation is successful, MAL_FAIL else.
 */
uint16_t MEM_If_Erase_FS(uint32_t Add) {
  uint32_t PageError = 0;
  FLASH_EraseInitTypeDef f;

  f.TypeErase = FLASH_TYPEERASE_PAGES;
  f.PageAddress = Add;
  f.NbPages = 1;

  if (HAL_FLASHEx_Erase(&f, &PageError) != HAL_OK) return 1;
  return (USBD_OK);
  /* USER CODE END 2 */
}

/**
 * @brief  Memory write routine.
 * @param  src: Pointer to the source buffer. Address to be written to.
 * @param  dest: Pointer to the destination buffer.
 * @param  Len: Number of data to be written (in bytes).
 * @retval USBD_OK if operation is successful, MAL_FAIL else.
 */
uint16_t MEM_If_Write_FS(uint8_t *src, uint8_t *dest, uint32_t Len) {
  for (uint32_t i = 0; i < Len; i += 4) {
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (uint32_t)(dest + i),
                          *(uint32_t *)(src + i)) == HAL_OK) {
      if (*(uint32_t *)(src + i) != *(uint32_t *)(dest + i)) return 2;
    } else
      return 1;
  }
  return (USBD_OK);
}

/**
 * @brief  Memory read routine.
 * @param  src: Pointer to the source buffer. Address to be written to.
 * @param  dest: Pointer to the destination buffer.
 * @param  Len: Number of data to be read (in bytes).
 * @retval Pointer to the physical address where data should be read.
 */
uint8_t *MEM_If_Read_FS(uint8_t *src, uint8_t *dest, uint32_t Len) {
  /* Return a valid address to avoid HardFault */
  uint32_t i = 0;
  uint8_t *psrc = src;

  for (i = 0; i < Len; i++) dest[i] = *psrc++;
  /* Return a valid address to avoid HardFault */
  return (uint8_t *)(dest);
  /* USER CODE END 4 */
}

/**
 * @brief  Get status routine
 * @param  Add: Address to be read from
 * @param  Cmd: Number of data to be read (in bytes)
 * @param  buffer: used for returning the time necessary for a program or an
 * erase operation
 * @retval USBD_OK if operation is successful
 */
uint16_t MEM_If_GetStatus_FS(uint32_t Add, uint8_t Cmd, uint8_t *buffer) {
  /* USER CODE BEGIN 5 */
  switch (Cmd) {
    case DFU_MEDIA_PROGRAM:
      buffer[1] = (uint8_t)FLASH_PROGRAM_TIME;
      buffer[2] = (uint8_t)(FLASH_PROGRAM_TIME << 8);
      buffer[3] = 0;
      break;

    case DFU_MEDIA_ERASE:
    default:
      buffer[1] = (uint8_t)FLASH_ERASE_TIME;
      buffer[2] = (uint8_t)(FLASH_ERASE_TIME << 8);
      buffer[3] = 0;
      break;
  }
  return 0;
  return (USBD_OK);
  /* USER CODE END 5 */
}

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */

/**
 * @}
 */

/**
 * @}
 */

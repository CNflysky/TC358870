#ifndef _TC358870_MSP_C_
#define _TC358870_MSP_C_
#include <stm32f1xx_hal.h>
#include <system_stm32f1xx.h>

#include "tc358870_gpio.h"
#define VECT_TAB_BASE_ADDRESS FLASH_BASE
#define VECT_TAB_OFFSET 0x5800U

void HAL_MspInit(void);
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);
void HAL_UART_MspInit(UART_HandleTypeDef* huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart);
void SystemClock_Config(void);
void SysTick_Handler(void);
void USB_LP_CAN1_RX0_IRQHandler(void);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);
#endif
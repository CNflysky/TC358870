#ifndef _TC358870_MSP_C_
#define _TC358870_MSP_C_
#include <stm32f1xx_hal.h>
#include <system_stm32f1xx.h>

void HAL_MspInit(void);
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);
void HAL_UART_MspInit(UART_HandleTypeDef* huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart);
void SystemClock_Config(void);
void SysTick_Handler(void);
void USB_LP_CAN1_RX0_IRQHandler(void);
#endif
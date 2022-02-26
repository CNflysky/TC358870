#include <stm32f1xx_hal.h>

#include "usb_device.h"

typedef void (*pFunction)(void);

extern PCD_HandleTypeDef hpcd_USB_FS;
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    __disable_irq();
    while (1) {
    }
  }
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
    __disable_irq();
    while (1) {
    }
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
    __disable_irq();
    while (1) {
    }
  }
}

static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void SysTick_Handler(void) { HAL_IncTick(); }
void USB_LP_CAN1_RX0_IRQHandler(void) { HAL_PCD_IRQHandler(&hpcd_USB_FS); }

void HAL_MspInit(void) {
  __HAL_RCC_AFIO_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_AFIO_REMAP_SWJ_DISABLE();
}

void ReEnumerateUSB() {
  GPIO_InitTypeDef gpio = {.Mode = GPIO_MODE_OUTPUT_PP,
                           .Pin = GPIO_PIN_12,
                           .Speed = GPIO_SPEED_FREQ_LOW,
                           .Pull = GPIO_NOPULL};
  HAL_GPIO_Init(GPIOA, &gpio);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
  HAL_Delay(5);
}

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_SET) {
    HAL_Delay(50);
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_SET) {
      /* Test if user code is programmed starting from USBD_DFU_APP_DEFAULT_ADD
       * address */
      if (((*(__IO uint32_t*)USBD_DFU_APP_DEFAULT_ADD) & 0x2FFE0000) ==
          0x20000000) {
        /* Jump to user application */
        uint32_t JumpAddress = *(__IO uint32_t*)(USBD_DFU_APP_DEFAULT_ADD + 4);
        pFunction JumpToApplication = (pFunction)JumpAddress;

        /* Initialize user application's Stack Pointer */
        __set_MSP((*(__IO uint32_t*)USBD_DFU_APP_DEFAULT_ADD));
        JumpToApplication();
      }
    }
  }
  ReEnumerateUSB();
  MX_USB_DEVICE_Init();
  while (1) {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
    HAL_Delay(250);
  }
}

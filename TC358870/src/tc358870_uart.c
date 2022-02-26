#include "tc358870_uart.h"

#include <stdarg.h>
#include <usbd_cdc_if.h>

uint8_t printf_u(const char *format, ...) {
  va_list args;
  uint8_t buff[APP_TX_DATA_SIZE] = {0x00};
  va_start(args, format);
  uint32_t length = vsprintf((char *)buff, format, args);
  vprintf(format, args);
  va_end(args);
  return CDC_Transmit_FS(buff, length);
}

int _write(int file, char *data, int len) {
  HAL_StatusTypeDef status =
      HAL_UART_Transmit(&huart1, (uint8_t *)data, len, 1000);
  return (status == HAL_OK ? len : 0);
}

void MX_USART1_UART_Init(void) {
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK) {
    __disable_irq();
    while (1) {
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
      HAL_Delay(500);
    }
  }
}

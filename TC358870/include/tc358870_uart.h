#ifndef _TC358870_UART_H_
#define _TC358870_UART_H_

#include <stm32f1xx_hal.h>
UART_HandleTypeDef huart1;
void MX_USART1_UART_Init(void);
int _write(int file, char *data, int len);
uint8_t printf_u(const char *format, ...);
#endif
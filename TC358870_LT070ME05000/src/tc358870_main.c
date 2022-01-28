#include <stdio.h>

#include "tc358870_gpio.h"
#include "tc358870_init.h"
#include "tc358870_msp.h"
#include "tc358870_uart.h"

int main() {
  HAL_Init();
  SystemClock_Config();
  MX_USART1_UART_Init();
  printf("Initlizating GPIO...\n");
  MX_GPIO_Init();
  printf("Initlizating I2C...\n");
  MX_I2C1_Init();
  printf("Setting TC358870 address to 0x0F...\n");  // RESET: 0x0F SET: 0x1F
  tc358870_address_control(GPIO_PIN_RESET);
  printf("Resetting TC358870...\n");
  TC358870_Reset();
  tc358870_address_control(GPIO_PIN_SET);
  printf("read chip id = 0x%x\n", i2c1_uh2cd_read16(0x0000));
  printf("Executing RS1 Sequence...\n");
  RS1();
  printf("Executed S1 --- State S1: Stand By\n");

  while (1) {
    RS_Int();
  }
}
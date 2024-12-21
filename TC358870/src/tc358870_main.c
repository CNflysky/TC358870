#include <stdio.h>
#include <system_stm32f1xx.h>

#include "tc358870_msp.h"
#include "tc358870_panel.h"
#include "usb_device.h"

static void ReEnumerateUSB() {
  GPIO_InitTypeDef gpio = {.Mode = GPIO_MODE_OUTPUT_PP,
                           .Pin = GPIO_PIN_12,
                           .Speed = GPIO_SPEED_FREQ_LOW,
                           .Pull = GPIO_NOPULL};
  HAL_GPIO_Init(GPIOA, &gpio);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
  HAL_Delay(5);
}

int main() {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  ReEnumerateUSB();
  MX_USB_DEVICE_Init();
  printf_u("Initlizating I2C1...\n");
  MX_I2C1_Init();
  printf_u("Setting TC358870 address to 0x0F...\n");  // RESET: 0x0F SET: 0x1F
  tc358870_addr_set(GPIO_PIN_RESET);
  printf_u("Resetting TC358870...\n");
  tc358870_reset();
  printf_u("Setting up backlight...\n");
  panel_backlight_setup();
  printf_u("read chip id = 0x%x\n", i2c1_uh2cd_read16(0x0000));
  printf_u("Executing RS1 Sequence...\n");
  RS1();
  printf_u("Executed S1 --- State S1: Stand By\n");
  br = 1;
  while (1) {
    RS_Int();
  }
}
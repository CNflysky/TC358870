#ifndef _TC358870_I2C_H_
#define _TC358870_I2C_H_

#include <stdio.h>
#include <stm32f1xx_hal.h>

#include "tc358870_uart.h"
#define I2C_ADDR 0x0F
I2C_HandleTypeDef hi2c1;
void MX_I2C1_Init(void);
void i2c1_uh2cd_write8(uint16_t addr, uint8_t data);
void i2c1_uh2cd_write16(uint16_t addr, uint16_t data);
void i2c1_uh2cd_write32(uint16_t addr, uint32_t data);
uint8_t i2c1_uh2cd_read8(uint16_t addr);
uint16_t i2c1_uh2cd_read16(uint16_t addr);
uint32_t i2c1_uh2cd_read32(uint16_t addr);

#endif
#include "tc358870_i2c.h"
void MX_I2C1_Init(void) {
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
    __disable_irq();
    while (1) {
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
      HAL_Delay(500);
    }
  }
}

void i2c1_uh2cd_write8(uint16_t addr, uint8_t data) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  // shift address left for 1 bit
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 0xFFFF)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);

  if ((hstatus = HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR << 1, addr, 2, &data, 1,
                                   0xFFFF)) != HAL_OK)
    printf_u("write data failed,hstatus = %d\n", hstatus);
}

void i2c1_uh2cd_write16(uint16_t addr, uint16_t data) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 0xFFFF)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);
  union {
    uint16_t val;
    struct {
      uint8_t msb;
      uint8_t lsb;
    };
  } data_u;
  data_u.val = data;
  uint8_t buffer[2] = {data_u.msb, data_u.lsb};
  if ((hstatus = HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR << 1, addr, sizeof addr,
                                   buffer, sizeof buffer, 0xFFFF)) != HAL_OK)
    printf_u("write data failed,hstatus = %d\n", hstatus);
};

void i2c1_uh2cd_write32(uint16_t addr, uint32_t data) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 0xFFFF)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);
  union {
    uint32_t val;
    struct {
      uint8_t msb;
      uint8_t a;
      uint8_t b;
      uint8_t lsb;
    };
  } data_u;
  data_u.val = data;
  uint8_t buffer[4] = {data_u.msb, data_u.a, data_u.b, data_u.lsb};
  if ((hstatus = HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR << 1, addr, sizeof addr,
                                   buffer, sizeof buffer, 0xFFFF)) != HAL_OK)
    printf_u("write data failed,hstatus = %d\n", hstatus);
};

uint8_t i2c1_uh2cd_read8(uint16_t addr) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  uint8_t data = 0x00;
  // check tc358870 comm
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 10)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);
  // read data
  if ((hstatus = HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR << 1, addr, sizeof addr,
                                  &data, sizeof data, 0xFFFF) != HAL_OK))
    printf_u("read data failed,hstatus = %d\n", hstatus);
  return data;
}

uint16_t i2c1_uh2cd_read16(uint16_t addr) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 10)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);
  uint8_t data[2] = {0x00};
  if ((hstatus = HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR << 1, addr, sizeof addr,
                                  data, sizeof data, 0xFFFF) != HAL_OK))
    printf_u("read data failed,hstatus = %d\n", hstatus);
  union {
    uint16_t val;
    struct {
      uint8_t msb;
      uint8_t lsb;
    };
  } data_u;
  data_u.msb = data[0];
  data_u.lsb = data[1];
  return data_u.val;
}

uint32_t i2c1_uh2cd_read32(uint16_t addr) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR << 1, 5, 0xFFFF)) !=
         HAL_OK)
    printf_u("device not ready,hstatus = %d\n", hstatus);
  union {
    uint32_t val;
    struct {
      uint8_t msb;
      uint8_t a;
      uint8_t b;
      uint8_t lsb;
    };
  } data_u;
  uint8_t buf[4] = {0x00};
  if ((hstatus = HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR << 1, addr, sizeof addr, buf,
                                  sizeof buf, 0xFFFF)) != HAL_OK)
    printf_u("read data failed,hstatus = %d\n", hstatus);
  data_u.msb = buf[0];
  data_u.a = buf[1];
  data_u.b = buf[2];
  data_u.lsb = buf[3];
  return data_u.val;
}
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

void i2c_write(uint16_t addr, void *data, size_t data_len) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  while ((hstatus = HAL_I2C_IsDeviceReady(&hi2c1, I2C_ADDR, 5, 0xFFFF)) !=
         HAL_OK)
    printf_u("i2c1: device not ready,hstatus = %d\n", hstatus);
  union {
    uint16_t val;
    struct {
      uint8_t lsb;
      uint8_t msb;
    };
  } data_u;
  uint8_t buf[data_len];

  switch (data_len) {
    case sizeof(uint8_t):
      buf[0] = *(uint8_t *)data;
      break;
    case sizeof(uint16_t):
      data_u.val = *(uint16_t *)data;
      buf[0] = data_u.lsb;
      buf[1] = data_u.msb;
      break;
    case sizeof(uint32_t): {
      union {
        uint32_t val;
        struct {
          uint8_t lsb;
          uint8_t a;
          uint8_t b;
          uint8_t msb;
        };
      } data_u;
      data_u.val = *(uint32_t *)data;
      buf[0] = data_u.lsb;
      buf[1] = data_u.a;
      buf[2] = data_u.b;
      buf[3] = data_u.msb;
    } break;
  }

  if ((hstatus = HAL_I2C_Mem_Write(&hi2c1, I2C_ADDR, addr, sizeof addr, buf,
                                   sizeof buf, 0xFFFF)) != HAL_OK)
    printf_u("i2c1: write data failed,hstatus = %d\n", hstatus);
}

void i2c_read(uint16_t addr, void *dst, size_t dst_len) {
  HAL_StatusTypeDef hstatus = HAL_ERROR;
  union {
    uint16_t val;
    struct {
      uint8_t lsb;
      uint8_t msb;
    };
  } data_u;
  data_u.val = addr;
  uint8_t buf[dst_len];
  memset(buf, 0x00, dst_len);
  if ((hstatus = HAL_I2C_Mem_Read(&hi2c1, I2C_ADDR, addr, sizeof addr, buf,
                                  sizeof buf, 0xFFFF) != HAL_OK))
    printf_u("i2c1: read data failed,hstatus = %d\n", hstatus);
  switch (dst_len) {
    case sizeof(uint8_t):
      memcpy(dst, &buf[0], dst_len);
      break;
    case sizeof(uint16_t):
      data_u.lsb = buf[0];
      data_u.msb = buf[1];
      memcpy(dst, &data_u.val, dst_len);
      break;
    case sizeof(uint32_t): {
      union {
        uint32_t val;
        struct {
          uint8_t lsb;
          uint8_t a;
          uint8_t b;
          uint8_t msb;
        };
      } data_u;
      data_u.lsb = buf[0];
      data_u.a = buf[1];
      data_u.b = buf[2];
      data_u.msb = buf[3];
      memcpy(dst, &data_u.val, dst_len);
    } break;
  }
}

inline void i2c1_uh2cd_write8(uint16_t addr, uint8_t data) {
  i2c_write(addr, &data, sizeof data);
}

inline void i2c1_uh2cd_write16(uint16_t addr, uint16_t data) {
  i2c_write(addr, &data, sizeof data);
}

inline void i2c1_uh2cd_write32(uint16_t addr, uint32_t data) {
  i2c_write(addr, &data, sizeof data);
}

inline uint8_t i2c1_uh2cd_read8(uint16_t addr) {
  uint8_t ret = 0;
  i2c_read(addr, &ret, sizeof(ret));
  return ret;
}

inline uint16_t i2c1_uh2cd_read16(uint16_t addr) {
  uint16_t ret = 0;
  i2c_read(addr, &ret, sizeof(ret));
  return ret;
}

inline uint32_t i2c1_uh2cd_read32(uint16_t addr) {
  uint32_t ret = 0;
  i2c_read(addr, &ret, sizeof(ret));
  return ret;
}
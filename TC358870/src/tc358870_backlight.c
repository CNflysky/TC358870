#include "tc358870_backlight.h"

inline void panel_backlight_setup() {
#ifdef CMD_BACKLIGHT
  GPIO_InitTypeDef GPIO_InitStruct = {.Pin = PanelBL_Pin,
                                      .Mode = GPIO_MODE_OUTPUT_PP,
                                      .Pull = GPIO_NOPULL,
                                      .Speed = GPIO_SPEED_FREQ_LOW};
  HAL_GPIO_Init(PanelBL_GPIO_Port, &GPIO_InitStruct);
#elif defined PWM_BACKLIGHT
  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_Base_Init(&htim2);

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig);

  HAL_TIM_PWM_Init(&htim2);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig);

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 950;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
  HAL_TIM_MspPostInit(&htim2);
#endif
}

inline void panel_backlight_enable() {
#ifdef CMD_BACKLIGHT
  HAL_GPIO_WritePin(PanelBL_GPIO_Port, PanelBL_Pin, GPIO_PIN_SET);
#elif defined PWM_BACKLIGHT
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 200);
#endif
}

inline void panel_backlight_disable() {
#ifdef CMD_BACKLIGHT
  HAL_GPIO_WritePin(PanelBL_GPIO_Port, PanelBL_Pin, GPIO_PIN_RESET);
#elif defined PWM_BACKLIGHT
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 0);
  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
#endif
}

inline void panel_backlight_set_brightness_level(uint8_t br) {
#ifdef CMD_BACKLIGHT
  uint16_t reg = 0x0000;
  switch (br) {
    case 1:
      reg = 0x3351;
      break;
    case 2:
      reg = 0x6651;
      break;
    case 3:
      reg = 0x9951;
      break;
    case 4:
      reg = 0xcc51;
      break;
    case 5:
      reg = 0xff51;
      break;
    default:
      reg = 0x9951;
      break;
  }
  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, reg);
#elif defined PWM_BACKLIGHT
  uint16_t pwm = 0;
  switch (br) {
    case 1:
      pwm = 200;
      break;
    case 2:
      pwm = 400;
      break;
    case 3:
      pwm = 600;
      break;
    case 4:
      pwm = 800;
      break;
    case 5:
      pwm = 999;
      break;
    default:
      pwm = 600;
      break;
  }
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, pwm);
#endif
}

inline void panel_backlight_set_brightness(uint16_t br) {
#ifdef CMD_BACKLIGHT
  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, (br << 8) | 0x51);
#elif defined PWM_BACKLIGHT
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, br);
#endif
}

void HAL_GPIO_EXTI_Callback(uint16_t gpio) {
  switch (gpio) {
    case DOWNLOAD_Pin:
      (br > 4) ? br = 1 : br++;
      break;
  }
}

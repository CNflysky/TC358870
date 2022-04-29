#include "tc358870_backlight.h"
void panel_cmd_backlight_setup() {
  GPIO_InitTypeDef GPIO_InitStruct = {.Pin = PanelBL_Pin,
                                      .Mode = GPIO_MODE_OUTPUT_PP,
                                      .Pull = GPIO_NOPULL,
                                      .Speed = GPIO_SPEED_FREQ_LOW};
  HAL_GPIO_Init(PanelBL_GPIO_Port, &GPIO_InitStruct);
}

void panel_cmd_backlight_enable() {
  HAL_GPIO_WritePin(PanelBL_GPIO_Port, PanelBL_Pin, GPIO_PIN_SET);
}

void panel_cmd_backlight_disable() {
  HAL_GPIO_WritePin(PanelBL_GPIO_Port, PanelBL_Pin, GPIO_PIN_RESET);
}

void panel_cmd_backlight_set_brightness(uint8_t br) {
  i2c1_uh2cd_write16(0x0504, 0x0015);
  i2c1_uh2cd_write16(0x0504, (br << 8) | 0x51);
}

void panel_pwm_backlight_setup() {
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
}

void panel_pwm_backlight_enable() {
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 200);
}
void panel_pwm_backlight_disable() {
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, 0);
  HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
}
void panel_pwm_backlight_set_brightness(uint16_t br) {
  __HAL_TIM_SetCompare(&htim2, TIM_CHANNEL_2, br);
}
#include "tc358870_gpio.h"

void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PanelBL_Pin | PanelRST_Pin | PanelPWR_Pin,
                    GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, NS4150_Pin | INT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, USR_LED_Pin | TC35RST_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PanelBL_Pin PanelRST_Pin PanelPWR_Pin */
  GPIO_InitStruct.Pin = PanelBL_Pin | PanelRST_Pin | PanelPWR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : NS4150_Pin USR_LED_Pin TC35RST_Pin */
  GPIO_InitStruct.Pin = NS4150_Pin | USR_LED_Pin | TC35RST_Pin | INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void TC358870_Reset() {
  HAL_GPIO_WritePin(TC35RST_GPIO_Port, TC35RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(200);
  HAL_GPIO_WritePin(TC35RST_GPIO_Port, TC35RST_Pin, GPIO_PIN_SET);
  HAL_Delay(100);
}

void board_led_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, state);
}

void panel_power_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(PanelPWR_GPIO_Port, PanelPWR_Pin, state);
}

void panel_backlight_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(PanelBL_GPIO_Port, PanelBL_Pin, state);
}

void panel_reset_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(PanelRST_GPIO_Port, PanelRST_Pin, state);
}

void tc358870_address_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(INT_GPIO_Port, INT_Pin, state);
}
void board_audio_control(GPIO_PinState state) {
  HAL_GPIO_WritePin(NS4150_GPIO_Port, NS4150_Pin, state);
}
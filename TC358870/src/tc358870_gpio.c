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
  HAL_GPIO_WritePin(GPIOB, USR_LED_Pin | TC358870_RST_Pin, GPIO_PIN_SET);


  /*Configure GPIO pins : PanelBL_Pin PanelRST_Pin PanelPWR_Pin */
  GPIO_InitStruct.Pin = PanelPWR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PanelBL_Pin PanelRST_Pin PanelPWR_Pin */
  GPIO_InitStruct.Pin = PanelRST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : NS4150_Pin USR_LED_Pin TC358870_RST_Pin */
  GPIO_InitStruct.Pin = NS4150_Pin | USR_LED_Pin | TC358870_RST_Pin | INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : DOWNLOAD_Pin */
  GPIO_InitStruct.Pin = DOWNLOAD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(DOWNLOAD_GPIO_Port, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 15, 15);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void tc358870_reset() {
  HAL_GPIO_WritePin(TC358870_RST_GPIO_Port, TC358870_RST_Pin, GPIO_PIN_RESET);
  HAL_Delay(200);
  HAL_GPIO_WritePin(TC358870_RST_GPIO_Port, TC358870_RST_Pin, GPIO_PIN_SET);
  HAL_Delay(100);
}

inline void usr_led_set(GPIO_PinState state) {
  HAL_GPIO_WritePin(USR_LED_GPIO_Port, USR_LED_Pin, state);
}

inline void panel_power_set(GPIO_PinState state) {
  HAL_GPIO_WritePin(PanelPWR_GPIO_Port, PanelPWR_Pin, state);
}

inline void panel_rst_set(GPIO_PinState state) {
  HAL_GPIO_WritePin(PanelRST_GPIO_Port, PanelRST_Pin, state);
}

inline void tc358870_addr_set(GPIO_PinState state) {
  HAL_GPIO_WritePin(INT_GPIO_Port, INT_Pin, state);
}

inline void board_audio_set(GPIO_PinState state) {
  HAL_GPIO_WritePin(NS4150_GPIO_Port, NS4150_Pin, state);
}
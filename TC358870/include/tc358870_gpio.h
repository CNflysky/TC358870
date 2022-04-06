#ifndef _TC358870_GPIO_H_
#define _TC358870_GPIO_H_

#include <stm32f1xx_hal.h>

#define PanelBL_Pin GPIO_PIN_1
#define PanelBL_GPIO_Port GPIOA
#define PanelRST_Pin GPIO_PIN_2
#define PanelRST_GPIO_Port GPIOA
#define PanelPWR_Pin GPIO_PIN_3
#define PanelPWR_GPIO_Port GPIOA
#define NS4150_Pin GPIO_PIN_0
#define NS4150_GPIO_Port GPIOB
#define USR_LED_Pin GPIO_PIN_15
#define USR_LED_GPIO_Port GPIOB
#define TC35RST_Pin GPIO_PIN_9
#define TC35RST_GPIO_Port GPIOB
#define INT_Pin GPIO_PIN_8
#define INT_GPIO_Port GPIOB

void MX_GPIO_Init(void);
void TC358870_Reset();
void board_led_control(GPIO_PinState state);
void panel_power_control(GPIO_PinState state);
void panel_backlight_control(GPIO_PinState state);
void tc358870_address_control(GPIO_PinState state);
void panel_reset_control(GPIO_PinState state);
void board_audio_control(GPIO_PinState state);

#endif
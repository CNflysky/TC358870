#ifndef _TC358870_GPIO_H_
#define _TC358870_GPIO_H_

#include <stm32f1xx_hal.h>

#define DOWNLOAD_Pin GPIO_PIN_15
#define DOWNLOAD_GPIO_Port GPIOC
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
#define INT_Pin GPIO_PIN_8
#define INT_GPIO_Port GPIOB
#define TC358870_RST_Pin GPIO_PIN_9
#define TC358870_RST_GPIO_Port GPIOB

void MX_GPIO_Init(void);
void tc358870_reset();
void usr_led_set(GPIO_PinState state);
void panel_power_set(GPIO_PinState state);
void tc358870_addr_set(GPIO_PinState state);
void panel_rst_set(GPIO_PinState state);
void board_audio_set(GPIO_PinState state);

#endif
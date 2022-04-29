#ifndef _TC358870_BACKLIGHT_H_
#define _TC358870_BACKLIGHT_H_
#include "tc358870_gpio.h"
#include "tc358870_i2c.h"
#include "tc358870_msp.h"
TIM_HandleTypeDef htim2;
void panel_cmd_backlight_setup();
void panel_cmd_backlight_enable();
void panel_cmd_backlight_disable();
void panel_cmd_backlight_set_brightness(uint8_t br);

void panel_pwm_backlight_setup();
void panel_pwm_backlight_enable();
void panel_pwm_backlight_disable();
void panel_pwm_backlight_set_brightness(uint16_t br);
#endif
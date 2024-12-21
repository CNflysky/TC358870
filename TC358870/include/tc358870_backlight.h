#ifndef _TC358870_BACKLIGHT_H_
#define _TC358870_BACKLIGHT_H_
#include "tc358870_gpio.h"
#include "tc358870_i2c.h"
#include "tc358870_msp.h"

#define CMD_BACKLIGHT
// #define PWM_BACKLIGHT

uint8_t br;

TIM_HandleTypeDef htim2;
void panel_backlight_setup();
void panel_backlight_enable();
void panel_backlight_disable();
void panel_backlight_set_brightness_level(uint8_t br);
void panel_backlight_set_brightness(uint16_t br);
#endif
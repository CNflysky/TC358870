# TC358870_Drivers
Various display drivers for the TC358870XBG HDMI to MIPI bridge.  
Simplified Chinese: [Here](https://github.com/CNflysky/TC358870_Drivers/blob/main/README_zh.md)

# Hardware
Hardware : [Link](https://github.com/zengcym/HDMI-To-MIPI).  
Please note a problem on PCB: **there are no external pull-up resistors on I2C bus.** If you want use drivers in this repository,you need to mount two 1K resistors on I2C bus between 3.3v, or use bitbanging I2C.  
MCU: STM32F103C8T6    

# Software
Use VSCode + PlatformIO as compiler, STM32Cube HAL library as SDK.

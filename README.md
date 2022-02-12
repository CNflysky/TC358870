# TC358870_Drivers
Various display drivers for the TC358870XBG HDMI to MIPI bridge.  
Simplified Chinese: [Here](https://github.com/CNflysky/TC358870_Drivers/blob/main/README_zh.md)

# Hardware
Hardware : [Link](https://github.com/zengcym/HDMI-To-MIPI).  
Please note a issue on PCB: **there are no external pull-up resistors on I2C bus.** If you want use drivers in this repository,you need to mount two 1K pull-up resistors on the I2C bus, or use bitbanging I2C.  
MCU: STM32F103C8T6    

# Software
VSCode + PlatformIO as IDE, STM32CubeHAL library as SDK.

# Supported Panels
| Part Number | Size | Resolution | Interface | Connector | 
| ---- | ---- | --- | --- | --- |
|LT070ME05000| 7' Inch| WUXGA(1920*1200)| MIPI 4 Lane | 31P Connector |

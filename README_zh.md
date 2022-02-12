# TC358870_Drivers
一些TC358870XBG HDMI转MIPI桥接器的驱动程序。  

# 硬件
本项目硬件基于zengcym的硬件: [链接](https://github.com/zengcym/HDMI-To-MIPI)。  
注意：该电路板存在一个问题,**I2C总线上没有外置上拉电阻**。如果想要使用本工程的代码，需要在板子上加两个1K上拉电阻，或者使用软件模拟I2C。  
MCU使用STM32F103C8T6。  

# 软件
软件方面，使用PlatformIO作为IDE，STM32Cube HAL库作为SDK。

# 适配屏幕
| 料号 | 尺寸 | 分辨率 | 接口 | 连接器 | 
| ---- | ---- | --- | --- | --- |
|LT070ME05000| 7' Inch| WUXGA(1920*1200)| MIPI 4 Lane | 31P 连接器 |

# TC358870_Drivers
一些TC358870XBG HDMI转MIPI桥接器的驱动程序。  

# 硬件
本项目硬件基于zengcym的硬件: [链接](https://github.com/zengcym/HDMI-To-MIPI)。  
我设计了一个改进版的硬件：在I2C1上加了上拉电阻，加了一个外接按键作为DFU下载使用，也引出了I2C2作为触摸驱动使用(触摸功能暂未实现)。  
板子放在`Hardware`文件夹里了。
MCU使用STM32F103C8T6。  
板子设计使用的是立创EDA专业版。
![design](https://github.com/CNflysky/TC358870_Drivers/raw/main/images/board.png)
![2d](https://github.com/CNflysky/TC358870_Drivers/raw/main/images/2d.png)
![PCBA](https://github.com/CNflysky/TC358870_Drivers/raw/main/images/PCBA.jpg)

# 软件
软件方面，使用VScode + PlatformIO作为IDE，STM32Cube HAL库作为SDK。

# 适配屏幕
| 料号 | 尺寸 | 分辨率 | 接口 | 连接器 | 备注 |
| ---- | ---- | --- | --- | --- | --- |
| LT070ME05000 | 7' Inch| WUXGA(1920*1200)| MIPI 4 Lane | 31P 连接器 |
|TPM0551002P | 5.5' Inch | FHD(1920*1080) | MIPI 4 Lane | 39P 连接器 | 触摸芯片:Synaptics S3351 |
|VVX10F034N00 | 10.1' Inch | WUXGA(1920*1200) | MIPI 4 Lane | 51P 连接器 | 默认显示模式:横屏 |

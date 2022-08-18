# TC358870_Drivers
一些TC358870XBG HDMI转MIPI桥接器的驱动程序。  

# 硬件
本项目硬件基于zengcym的硬件: [链接](https://github.com/zengcym/HDMI-To-MIPI)。  
我设计了一个改进版的硬件：在I2C1上加了上拉电阻，加了一个外接按键作为DFU下载使用，也引出了I2C2作为触摸驱动使用(触摸功能暂未实现)。  
板子放在`Hardware`文件夹里了。
MCU使用STM32F103C8T6。  
板子设计使用的是立创EDA专业版。
![board](https://user-images.githubusercontent.com/48781081/185403061-dfd3fd86-fc98-4fd3-a1ca-e4b5496c8ae1.png)
![2d](https://user-images.githubusercontent.com/48781081/185403119-4ca9f16e-12c6-49be-99d0-8bc7e5a23e32.png)
![PCBA](https://user-images.githubusercontent.com/48781081/185403195-b15e27f5-cf48-46b7-87d2-ff140f1092de.jpg)

# 软件
软件方面，使用VScode + PlatformIO作为IDE，STM32Cube HAL库作为SDK。

# 选择屏幕
打开`TC358870/include/tc358870_panel.h`,取消相应的注释即可。  
```c
#define LT070ME05000
// #define TPM0551002P
```
# 编译并上传
下载VSCode编辑器(百度一下)  
打开VSCode,安装PlatformIO插件，然后等它装完（可能得一会）。  
Clone(或者下载)本仓库，先打开TC358870_USB_DFU_Bootloader,编译并上传到板子上(可能您需要使用JLink或者是STLink来上传)。  
然后使用一根Type-C线，把板子连上电脑，先按下用户按键(靠近HDMI端口那个按键)，再按下reset键，之后松开手。  
然后USR_LED会开始闪烁，这就表示板子进入了DFU下载模式。  
回到VSCode，打开TC358870，编译并下载。  
复位板子（按下reset按键），USR_LED灯会熄灭，这是正常现象。  
之后把板子HDMI连接上电脑，电脑会发现新硬件，进入显示设置里面，可以看见出现了一个'Toshiba UH2D'设备，这代表芯片工作正常。  
拔下板子，连接好屏幕，再插回电脑，如果一切正常的话，屏幕上就可以显示桌面了。  

# 适配屏幕
| 料号 | 尺寸 | 分辨率 | 接口 | 连接器 | 备注 |
| ---- | ---- | --- | --- | --- | --- |
| LT070ME05000 | 7' Inch| WUXGA(1920*1200)| MIPI 4 Lane | 31P 连接器 |
|TPM0551002P | 5.5' Inch | FHD(1920*1080) | MIPI 4 Lane | 39P 连接器 | 触摸芯片:Synaptics S3351 |
|VVX10F034N00 | 10.1' Inch | WUXGA(1920*1200) | MIPI 4 Lane | 51P 连接器 | 默认显示模式:横屏 |

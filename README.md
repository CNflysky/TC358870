# TC358870_Drivers
Various display drivers for the TC358870XBG HDMI to MIPI bridge.  
Simplified Chinese: [Here](https://github.com/CNflysky/TC358870_Drivers/blob/main/README_zh.md)

# Hardware
Hardware : based on zengcym's hardware: [Link](https://github.com/zengcym/HDMI-To-MIPI).  
I have a modified version of this board: Added I2C1 pull-up resistors, added an user button(for USB DFU) and wired out I2C2 pin as touch I2C bus(not implemented yet).  
It has not been tested yet,when I have finished it,I will upload it into this repository.  
MCU: STM32F103C8T6    

# Software
VSCode + PlatformIO as IDE, STM32CubeHAL library as SDK.  

# Choose Panel
Open `TC358870/include/tc358870_panel.h`,choose your panel by uncomment the following line:  
```c
#define LT070ME05000
// #define TPM0551002P
```  
# Compile and Upload
Download VScode Editor(Just Google it)  
Open VSCode,install PlatformIO plugin,and wait it finishes(This may take a while).  
Clone(or download) this repository,open TC358870_USB_DFU first,complie and upload to your board.  
TODO  

# Supported Panels
| Part Number | Size | Resolution | Interface | Connector | Note |
| ---- | ---- | --- | --- | --- | --- |
|LT070ME05000| 7' Inch| WUXGA(1920*1200)| MIPI 4 Lane | 31P Connector ||
|TPM0551002P | 5.5' Inch | FHD(1920*1080) | MIPI 4 Lane | 39P Connector | TP:Synaptics S3351 |

# DFRobot_URM09
- [English Version](./README.md)

这是一款开放式双探头超声波测距模块，通信方式为I2C,采用Gravity标准PH2.0-4P立式贴片座接口。该模块兼容arduino、树莓派等各种3.3V或5V逻辑电平的主控板。模块自带温度补偿，平整墙面的有效测距量程为2–500cm，分辨率为1cm，误差约为±1%。 设计150cm、300cm、500cm 三个测距量程可供程序选择切换，更短的量程设置会带来更短的测距周期和更低的测距灵敏度，用户可根据实际使用需求灵活设置。

可以广泛应用于户外环境中，尤其适用于温差变化较快的环境。是机器人自动避障行走，汽车倒车报警器、门铃、警戒报警器、地铁安全线提示、银行及取款机的一米线提示等等项目的绝佳选择。<br>
本款测距模块体积小，环境适用性强，精度高，测量范围广，即插即用，方便快捷。

![正反面svg效果图](resources\images\SEN0304_WIKI_Cover.jpg)


## 产品链接（https://www.dfrobot.com.cn/goods-1905.html）

    SKU：SEN0304

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

有效测距量程为2–500cm，分辨率为1cm，误差约为±1%。

150cm、300cm、500cm 三个测距量程，主动测量和被动测量可供程序选择切换。

可以修改I2C设备地址，防止多个设备的冲突。

## 库安装
这里提供两种使用本库的方法：
1.打开Arduino IDE,在状态栏中的Tools--->Manager Libraries 搜索"DFRobot_MGC3130"并安装本库.
2.首先下载库文件,将其粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.

## 方法

```C++
  /**
   * @fn begin
   * @brief 初始化i2c
   * @param address i2c设备号（1-127）我们没有传入设备号时，设备号为0x11
   * @return 返回bool 类型，用以表示初始化的状态
   * @retval true 初始化成功
   * @retval false 初始化失败
   */
  bool begin(uint8_t address = 0x11);

  /**
   * @fn setModeRange
   * @brief Set mode and measure distance 
   * @param range is measured range
   * @n     MEASURE_RANG_500    Ranging from 500 
   * @n     MEASURE_RANG_300    Ranging from 300 
   * @n     MEASURE_RANG_150    Ranging from 150 
   * @param mode is measurement mode, automatic measurement and passive measurement. 
   * @n     MEASURE_MODE_AUTOMATIC    automatic mode
   * @n     MEASURE_MODE_PASSIVE      passive mode
   * @return None
   */
  void setModeRange(uint8_t range, uint8_t mode);

  /**
   * @fn measurement
   * @brief 测量距离，被动模式下发送测量命令
   * @return None
   */
  void measurement(void);

  /**
   * @fn getTemperature
   * @brief 获取温度值
   * @return 温度值 单位（摄氏度）
   */
  float getTemperature(void);

  /**
   * @fn getDistance
   * @brief 读取距离
   * @return 距离值 单位（厘米）
   * @n 增加的数值是实际温度的10倍
   * @n 例如:读出值为0x00fe，则实际温度为0x00fe / 10 = 25.4
   * @return None
   */
  int16_t getDistance(void);

  /**
   * @fn scanDevice
   * @brief 扫描i2c设备
   * @return 扫描状态
   * @retval -1 没有扫描到设备
   * @retval other iic address
   */
  int16_t scanDevice(void);
  
  /**
   * @fn getI2CAddress
   * @brief 获取 i2c 设备地址号
   * @return i2c 设备地址号
   */
  uint8_t getI2CAddress(void);

  /**
   * @fn modifyI2CAddress
   * @brief 修改 i2c 设备地址
   * @param address i2c设备地址号（1-127）
   * @return None
   */
  void modifyI2CAddress(uint8_t address);
```

## 兼容性

| 主板        | 通过 | 未通过 | 未测试 | 备注 |
| ----------- | :--: | :----: | :----: | ---- |
| Arduino uno |  √   |        |        |      |
| Mega2560    |  √   |        |        |      |
| Leonardo    |  √   |        |        |      |
| ESP32       |  √   |        |        |      |
| micro:bit   |      |        |   √    |      |


## 历史

- 2019/06/25 - V1.0.0 版本
- 2020/05/30 - V1.1.0 版本
- 2021/09/30 - V1.2.0 版本

## 创作者

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
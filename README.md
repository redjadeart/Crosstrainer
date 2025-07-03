# 💡 INTERACTIVE LIGHT SYSTEM WITH CROSSTRAINER

An Arduino-based interactive project that visualizes user movement and interaction on a crosstrainer using 30 LEDs, a capacitive touch sensor (MPR121), and a motion sensor (MPU6050).

---

## 🎯 Objective

The goal is to combine motion detection and touch interaction with dynamic lighting to provide intuitive and motivational feedback during physical exercise.

---

## 🤯 Scenarios

### ✋ Scenario 1: Touching the Crosstrainer Handles

* The system includes 30 LEDs — 15 on the left, 15 on the right.
* When the user touches the small handles of the crosstrainer:

  * → The LEDs light up one by one from back to front.
  * → The effect continues until all 30 LEDs are turned on.

### 🏃 Scenario 2: Movement During Training

* When the user is actively moving on the crosstrainer:

  * → Only one LED is lit at any given time.
  * → The position of the lit LED reflects the leaning or motion amplitude.
  * → It changes dynamically in response to user movement.

---

## 🛠 Implementation

* 💻 **Microcontroller:** Elegoo MEGA2560 R3
* 🧭 **Motion Sensor:** MPU6050 (Accelerometer + Gyroscope)
* 🙋 **Touch Sensor:** Adafruit MPR121 (Capacitive Touch, 12 Inputs)
* 🔦 **LEDs:** 30 standard LEDs connected to digital pins D22–D51
* ⚡ **Power Supply:** 5V external power recommended (if using all LEDs simultaneously)

---

## 📄 Required Libraries

Make sure to install these libraries via the Arduino Library Manager:

* [`Adafruit_MPR121`](https://github.com/adafruit/Adafruit_MPR121) — for capacitive touch input
* [`MPU6050`](https://github.com/jrowberg/i2cdevlib) — for motion and tilt detection
* `Wire.h` — for I2C communication (built-in)

---

## 📁 Project Structure

```text
Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
│   └── system_overview.jpg
```

```
📌 Note
This project uses only the MEGA2560 as the main controller.
The Arduino UNO R4 WiFi was used during early tests, but is no longer part of the final setup.
```

---

## ✅ Future Improvements (Optional)

* Replace standard LEDs with WS2812B addressable LED strip for better animation control.
* Add OLED display to show real-time sensor data or exercise stats.
* Implement BLE/WiFi logging (e.g. using ESP32) for tracking training sessions.
* Add enclosure and buttons for user modes.

---

# 💡 交互式灯光系统与椭圆机

一个基于 Arduino 的互动项目，使用 30 个 LED、电容触摸传感器（MPR121）和运动传感器（MPU6050），将用户在椭圆机上的动作和交互进行可视化。

---

## 🎯 项目目标

该项目旨在将动作检测与触摸交互结合，通过动态灯光效果在锻炼过程中提供直观且具有激励性的反馈。

---

## 🤯 使用场景

### ✋ 场景一：触摸椭圆机把手

* 系统包含 30 个 LED —— 左边 15 个，右边 15 个。
* 当用户触摸椭圆机的小把手时：

  * → LED 会从后往前依次点亮。
  * → 效果持续进行，直到 30 个 LED 全部点亮。

### 🏃 场景二：训练过程中的运动

* 当用户在椭圆机上积极运动时：

  * → 任意时刻仅有一个 LED 被点亮。
  * → 点亮的 LED 位置反映出倾斜程度或运动幅度。
  * → 它会根据用户动作动态变化。

---

## 🛠 系统实现

* 💻 **微控制器：** Elegoo MEGA2560 R3  
* 🧭 **运动传感器：** MPU6050（加速度计 + 陀螺仪）  
* 🙋 **触摸传感器：** Adafruit MPR121（电容触摸，12 个输入）  
* 🔦 **LED：** 30 个标准 LED，连接至数字引脚 D22–D51  
* ⚡ **电源：** 建议使用 5V 外部电源（若同时点亮所有 LED）

---

## 📄 所需库

请通过 Arduino 库管理器安装以下库：

* [`Adafruit_MPR121`](https://github.com/adafruit/Adafruit_MPR121) — 用于电容触摸输入  
* [`MPU6050`](https://github.com/jrowberg/i2cdevlib) — 用于动作和倾斜检测  
* `Wire.h` — 用于 I2C 通信（内置）

---

## 📁 项目结构

```text
Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
│   └── system_overview.jpg
```

```
📌 注意  
本项目仅使用 MEGA2560 作为主控制器。  
Arduino UNO R4 WiFi 曾用于早期测试，但不包含在最终配置中。
```

---

## ✅ 未来改进（可选）

* 用 WS2812B 可寻址 LED 灯带替换标准 LED，以实现更佳动画控制。  
* 添加 OLED 显示屏，用于显示实时传感器数据或锻炼统计信息。  
* 实现 BLE/WiFi 日志记录功能（例如使用 ESP32）以跟踪训练过程。  
* 添加外壳和按钮以支持用户模式切换。

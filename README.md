💡 Interactive Light System with Crosstrainer

An Arduino-based interactive project that visualizes user movement and interaction on a crosstrainer using 30 LEDs, a capacitive touch sensor (MPR121), and a motion sensor (MPU6050).

🎯 Objective

The goal is to combine movement detection with responsive lighting to create intuitive and motivating feedback during training.

🤯 Scenarios

✋ Scenario 1: Touching the Crosstrainer Handles

There are 30 LEDs, 15 on each side.

When the user touches the small side handles:

→ The LEDs light up sequentially from back to front.

→ Until all 30 are illuminated.

🏃 Scenario 2: Movement on the Crosstrainer

When the user is actively training:

→ Only one LED is active at a time.

→ Its position depends on the user's leaning/movement.

→ The LED changes dynamically as the user moves.

🛠 Implementation

💻 Controller: Elegoo MEGA2560 R3

🧭 Motion Sensor: MPU6050

🙋 Touch Sensor: Adafruit MPR121

🔦 LEDs: 30 connected to D22–D51

⚡ Power: 5V external power supply recommended

📄 Libraries

Adafruit_MPR121 — for capacitive touch input

MPU6050 by jrowberg — for acceleration and angle sensing

Wire.h — for I2C communication

📁 Project Structure

Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
    └── [Your wiring photos here]

📌 Note

This project uses only the MEGA2560 as the main controller. The Arduino UNO R4 WiFi was used during early tests, but is no longer part of the final setup.

💡 跨步机交互式灯光系统（中文）

这是一个基于 Arduino 的互动装置项目，通过 30 颗 LED、电容式触摸传感器（MPR121）和运动传感器（MPU6050）将用户在椭圆机（Crosstrainer）上的动作与交互反馈可视化。

🎯 项目目标

通过将运动感知与动态灯光反馈相结合，为运动者提供一种直观且具有激励作用的训练反馈方式。

🤯 场景说明

✋ 场景 1：触摸扶手

系统共有 30 颗 LED，左右各 15 颗。

当用户触碰 Crosstrainer 的小扶手：

→ LED 灯会从后向前依次点亮；

→ 最终 30 颗灯全部亮起。

🏃 场景 2：训练动作反馈

当用户开始运动训练：

→ 系统始终仅亮起 1 颗 LED；

→ LED 的位置会根据用户身体的倾斜或移动幅度进行变化；

→ 实现动态灯光反馈。

🛠 技术实现

💻 主控板： Elegoo MEGA2560 R3

🧭 动作传感器： MPU6050

🙋 触摸传感器： Adafruit MPR121

🔦 LED 灯： 通过 D22–D51 引脚驱动的 30 颗 LED

⚡ 供电建议： 推荐外部 5V 稳定电源供电

📄 使用库

Adafruit_MPR121 — 用于电容触摸输入

MPU6050 by jrowberg — 用于加速度与角度感知

Wire.h — 用于 I2C 通信

📁 项目结构

Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
    └── [模块连线照片]

📌 说明

项目最终仅使用 MEGA2560 主控板。早期测试曾使用 Arduino UNO R4 WiFi，但已 不再使用。

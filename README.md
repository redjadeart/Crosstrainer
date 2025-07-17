# 💡 RELAIS-STEUERUNG MIT TOUCH & PITCH

Ein Arduino-basiertes System zur interaktiven Steuerung von 15 Relaispaaren über einen Bewegungssensor (MPU6050) und ein kapazitives Touchmodul (MPR121).
---

## 🎯 Projektziel

Kombination von Bewegungserkennung und Berührungsinteraktion zur Steuerung einer symmetrischen Relaismatrix – ideal für kinetische Skulpturen, Lichtinstallationen oder interaktive Geräte.

---

## 🤯 Anwendungsszenarien

### ✋ Touch-Modus

→ Bei aktiver Berührung (z. B. durch eine leitfähige Oberfläche)
→ Das System aktiviert mehrere Relaispaare symmetrisch, basierend auf dem Neigungswinkel
→ Spiegelartige Steuerung von Relais links und rechts

### 🏃 Bewegungsmodus (Standard)

→ Bei keiner Berührung
→ Aktiviert ein einziges Relaispaar, abhängig vom Pitch-Winkel
→ Reagiert dynamisch auf Bewegung
→ Nach 30 Sekunden Inaktivität: Alle Relais werden automatisch deaktiviert

---

## 🛠 Komponenten

* Arduino MEGA 2560 oder Uno
* MPU6050 (Beschleunigung + Gyroskop)
* MPR121 kapazitiver Touchsensor
* 30 digitale Ausgänge für 15 Relaispaare (Pins D22–D51)
* 5V externe Stromversorgung empfohlen

---

## 📦 Bibliotheken

Bitte über den Library Manager installieren:
* Adafruit_MPU6050
* Adafruit_MPR121
* Adafruit_Sensor
* Wire.h

---

## 📁 Projektstruktur

```text
pitch_touch_relais/
├── README.md
├── src/
│   └── pitch_touch_relais.ino
├── images/
│   └── system_diagram.jpg (optional)
```

```
📌 Hinweise
* Pitch-Werte werden über einen gleitenden Mittelwert geglättet
* Touch-Erkennung beinhaltet eine Verzögerung zur Entprellung
* Inaktivitäts-Timeout: System deaktiviert alle Relais nach 30s ohne Bewegung
```

---

## ✅ Erweiterungsmöglichkeiten

* LED-Streifen (z. B. WS2812B) zur visuellen Darstellung
* OLED-Display zur Anzeige von Status & Winkeln
* Integration von ESP32 für Bluetooth- oder WLAN-Kommunikation
* Gehäuse zur Nutzung als fertiges Interaktionsobjekt

---

# 💡 继电器控制系统：基于触控与倾斜角度的交互式 Arduino 项目

本项目通过 MPU6050 运动传感器与 MPR121 电容触摸传感器，实现对 15 对继电器的智能控制与交互响应。

---

## 🎯 项目目标

结合“身体倾斜角度”与“触摸输入”，控制对称排列的继电器组。适用于动态雕塑、灯光装置或其他互动硬件。

---

## 🤯 使用场景

### ✋ 触摸模式

→ 当用户触摸传感器（例如握住金属把手）
→ 系统进入“对称激活”模式，根据倾斜角点亮多个继电器对
→ 左右继电器呈镜像方式依次开启

### 🏃 常规模式

→ 没有触摸输入时，系统根据倾斜角激活一个继电器对
→ 实时响应用户姿态变化
→ 若 30 秒内无显著变化，系统将自动关闭全部继电器（节能 + 安全）

---

## 🛠 使用元件

* Arduino MEGA 2560 / Uno 
* MPU6050 三轴加速度/陀螺仪传感器
* MPR121 电容触摸模块
* 数字输出控制 30 个继电器（D22–D51）
* 推荐使用 5V 外接电源


---

## 📦 所需库文件

可通过 Arduino 库管理器安装：

* Adafruit_MPU6050
* Adafruit_MPR121
* Adafruit_Sensor
* Wire.h

---

## 📁 项目结构

```text
pitch_touch_relais/
├── README.md
├── src/
│   └── pitch_touch_relais.ino
├── images/
│   └── system_diagram.jpg（可选）

```

```
📌 注意事项
倾角（Pitch）值经过平滑处理以避免抖动
触摸输入有防抖延迟，避免误触发
若 30 秒内无动作，自动关闭所有继电器
```

---

## ✅ 未来改进（可选）

* 使用 WS2812B 替代继电器，实现灯光效果
* 增加 OLED 显示屏用于状态与角度显示
* 使用 ESP32 实现蓝牙/WiFi 控制与数据传输 
* 外壳封装，构建完整交互装置

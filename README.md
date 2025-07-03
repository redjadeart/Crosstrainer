# 💡 INTERACTIVE LIGHT SYSTEM WITH CROSSTRAINER

An Arduino-based interactive project that visualizes user movement and interaction on a crosstrainer using 30 LEDs, a capacitive touch sensor (MPR121), and a motion sensor (MPU6050).

---

## 🎯 Objective

The goal is to combine movement detection with responsive lighting to create intuitive and motivating feedback during training.

---

## 🤯 Scenarios

### ✋ Scenario 1: Touching the Crosstrainer Handles

- There are 30 LEDs, 15 on each side.
- When the user touches the small side handles:
  - → The LEDs light up sequentially from back to front.
  - → Until all 30 are illuminated.

### 🏃 Scenario 2: Movement on the Crosstrainer

- When the user is actively training:
  - → Only one LED is active at a time.
  - → Its position depends on the user's leaning/movement.
  - → The LED changes dynamically as the user moves.

---

## 🛠 Implementation

- 💻 **Controller:** Elegoo MEGA2560 R3  
- 🧭 **Motion Sensor:** MPU6050  
- 🙋 **Touch Sensor:** Adafruit MPR121  
- 🔦 **LEDs:** 30 connected to D22–D51  
- ⚡ **Power:** 5V external power supply recommended  

---

## 📄 Libraries

- `Adafruit_MPR121` — for capacitive touch input  
- `MPU6050` by jrowberg — for acceleration and angle sensing  
- `Wire.h` — for I2C communication  

---

## 📁 Project Structure

```text
Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
    └── [Your wiring photos here]

📌 Note
This project uses only the MEGA2560 as the main controller. The Arduino UNO R4 WiFi was used during early tests, but is no longer part of the final setup.

# 💡 INTERACTIVE LIGHT SYSTEM WITH CROSSTRAINER

An Arduino-based interactive project that visualizes user movement and interaction on a crosstrainer using 30 LEDs, a capacitive touch sensor (MPR121), and a motion sensor (MPU6050).

---

## 🎯 Objective

The goal is to combine motion detection and touch interaction with dynamic lighting to provide intuitive and motivational feedback during physical exercise.

---

## 🤯 Scenarios

### ✋ Scenario 1: Touching the Crosstrainer Handles

- The system includes 30 LEDs — 15 on the left, 15 on the right.
- When the user touches the small handles of the crosstrainer:
  - → The LEDs light up one by one from back to front.
  - → The effect continues until all 30 LEDs are turned on.

### 🏃 Scenario 2: Movement During Training

- When the user is actively moving on the crosstrainer:
  - → Only one LED is lit at any given time.
  - → The position of the lit LED reflects the leaning or motion amplitude.
  - → It changes dynamically in response to user movement.

---

## 🛠 Implementation

- 💻 **Microcontroller:** Elegoo MEGA2560 R3  
- 🧭 **Motion Sensor:** MPU6050 (Accelerometer + Gyroscope)  
- 🙋 **Touch Sensor:** Adafruit MPR121 (Capacitive Touch, 12 Inputs)  
- 🔦 **LEDs:** 30 standard LEDs connected to digital pins D22–D51  
- ⚡ **Power Supply:** 5V external power recommended (if using all LEDs simultaneously)

---

## 📄 Required Libraries

Make sure to install these libraries via the Arduino Library Manager:

- [`Adafruit_MPR121`](https://github.com/adafruit/Adafruit_MPR121) — for capacitive touch input  
- [`MPU6050`](https://github.com/jrowberg/i2cdevlib) — for motion and tilt detection  
- `Wire.h` — for I2C communication (built-in)

---

## 📁 Project Structure

```text
Crosstrainer/
├── README.md
├── src/
│   └── crosstrainer_light_system.ino
├── images/
│   └── system_overview.jpg
📌 Notes
This system uses one GPIO pin per LED. Therefore, the MEGA2560 is chosen for its large number of digital pins.

All LEDs should be connected with current-limiting resistors (e.g. 220Ω).

Sensors (MPU6050 & MPR121) are connected via I2C:

SDA → Pin 20

SCL → Pin 21

You can adjust the LED animation speed and motion-to-LED mapping in the code.

If LED flickering occurs during training mode, consider adding smoothing or low-pass filtering on the accelerometer input.

The project was originally prototyped with an Arduino UNO R4 WiFi, but the final implementation uses only the MEGA2560 due to pin count and stability.


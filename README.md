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

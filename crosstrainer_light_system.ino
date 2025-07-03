// ============================================
// Interaktives Lichtsystem mit Crosstrainer
// Author: Lin Zhu / redjadeart
// Platform: Elegoo MEGA2560 R3 + MPU6050 + MPR121 + 30 LEDs
// ============================================

#include <Wire.h>
#include <Adafruit_MPR121.h>
#include <MPU6050.h>

// -------- LED 设置 / LED Configuration --------
const int ledPins[30] = {
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,   // 左边 / Left side
  37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51    // 右边 / Right side
};

// -------- 传感器定义 / Sensor Definitions --------
Adafruit_MPR121 touchSensor = Adafruit_MPR121();
MPU6050 mpu;

// -------- 状态变量 / State Variables --------
bool scenario1_active = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // 初始化 MPU6050 / Initialize motion sensor
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
  } else {
    Serial.println("MPU6050 ready.");
  }

  // 初始化 MPR121 触摸传感器 / Initialize touch sensor
  if (!touchSensor.begin(0x5A)) {
    Serial.println("MPR121 not found!");
    while (1);
  } else {
    Serial.println("MPR121 ready.");
  }

  // 设置 LED 引脚 / Initialize LED pins
  for (int i = 0; i < 30; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  touchSensor.read();

  // 检测是否有任一触摸点 / Detect any touch on the sensor
  bool touched = false;
  for (int i = 0; i < 12; i++) {
    if (touchSensor.touched() & (1 << i)) {
      touched = true;
      break;
    }
  }

  if (touched) {
    runScenario1();
    scenario1_active = true;
  } else {
    scenario1_active = false;
    runScenario2();
  }

  delay(50);
}

// ---------------
// 场景1: 依次点亮所有灯 / Light up LEDs sequentially
// ---------------
void runScenario1() {
  for (int i = 0; i < 30; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(80);
  }
}

// ---------------
// 场景2: 根据动作控制灯的位置 / Map movement to LED position
// ---------------
void runScenario2() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // 使用 x 轴加速度映射灯泡位置 / Use X-axis acceleration to select LED index
  int ledIndex = map(ax, -17000, 17000, 0, 29);
  ledIndex = constrain(ledIndex, 0, 29);

  // 点亮指定灯，关闭其余 / Light up one LED, turn off others
  for (int i = 0; i < 30; i++) {
    digitalWrite(ledPins[i], i == ledIndex ? HIGH : LOW);
  }
}


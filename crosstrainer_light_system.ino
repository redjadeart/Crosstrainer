#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_MPR121.h"
#include <math.h>

Adafruit_MPU6050 mpu;
Adafruit_MPR121  cap = Adafruit_MPR121();

// Touch‑Hysterese
bool  invertiert = false;

// Pitch‑Glättung
const int FILTER_SIZE = 10;
float pitchBuffer[FILTER_SIZE];
int   bufferIndex   = 0;
bool  bufferFilled  = false;

// Timeout
unsigned long lastPitchChangeTime = 0;
float         lastPitchForTimeout = 0;
bool          systemActive        = true;
const unsigned long TIMEOUT_DURATION = 30000;   // 30 s
const float         PITCH_THRESHOLD  = 1.0;     // 1 °

void setup() {
  Serial.begin(115200);

  if (!mpu.begin()) { Serial.println("MPU6050 nicht gefunden!"); while (1); }
  if (!cap.begin(0x5A)) { Serial.println("MPR121 nicht gefunden!"); while (1); }

  for (int p = 22; p <= 51; p++) { pinMode(p, OUTPUT); digitalWrite(p, LOW); }

  lastPitchChangeTime = millis();
  Serial.println("System gestartet");
}

void loop() {
  /* ---------- MPU6050 ---------- */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float rawPitch = atan2(a.acceleration.x,
                         sqrt(a.acceleration.y * a.acceleration.y +
                              a.acceleration.z * a.acceleration.z)) * 180.0 / PI;

  /* ---------- Pitch glätten ---------- */
  pitchBuffer[bufferIndex] = rawPitch;
  bufferIndex = (bufferIndex + 1) % FILTER_SIZE;
  if (bufferIndex == 0) bufferFilled = true;

  float pitch = 0;
  int   n     = bufferFilled ? FILTER_SIZE : bufferIndex;
  for (int i = 0; i < n; i++) pitch += pitchBuffer[i];
  pitch /= n;

  pitch = constrain(pitch, -8.0, 22.0);
  int idx = map(pitch, -8, 22, 0, 14);   // 0…14

  /* ---------- Timeout‑Überwachung ---------- */
  if (fabs(pitch - lastPitchForTimeout) > PITCH_THRESHOLD) {
    lastPitchChangeTime = millis();
    systemActive        = true;
    lastPitchForTimeout = pitch;
  }
  if (millis() - lastPitchChangeTime > TIMEOUT_DURATION) {
    if (systemActive) { systemActive = false; Serial.println("Timeout → alles aus"); }
  }

  /* ---------- Touch‑Hysterese ---------- */
  uint16_t tVal = cap.filteredData(0);
  if (invertiert && tVal > 60)          invertiert = false;
  else if (!invertiert && tVal < 40)    invertiert = true;

  /* ---------- Relais‑Steuerung ---------- */
  for (int i = 0; i < 15; i++) {
    int rPin        = 22 + (i * 2);                  // rechts direkt
    int rPinMirror  = 22 + ((14 - i) * 2);           // rechts gespiegelt
    int lPin        = 23 + (i * 2);                  // links direkt
    int lPinMirror  = 23 + ((14 - i) * 2);           // links gespiegelt

    if (!systemActive) {                    // Timeout: alles aus
      digitalWrite(rPin, LOW);  digitalWrite(lPin, LOW);
    }
    else if (invertiert) {                  // Touch‑Modus: mehrere, gespiegelt
      if (i <= idx) {
        digitalWrite(rPin, HIGH); digitalWrite(lPinMirror, HIGH);
      } else {
        digitalWrite(rPin, LOW);  digitalWrite(lPinMirror, LOW);
      }
    }
    else {                                  // Normal‑Modus: EIN Paar, gegensinnig (jetzt umgekehrt!)
      if (i == idx) {
        digitalWrite(rPinMirror, HIGH);  // rechts gespiegelt
        digitalWrite(lPin,       HIGH);  // links direkt
      } else {
        digitalWrite(rPinMirror, LOW);
        digitalWrite(lPin,       LOW);
      }
    }
  }

  /* ---------- Debug ---------- */
  Serial.print("Pitch "); Serial.print(pitch, 2);
  Serial.print("°, Touch "); Serial.print(tVal);
  Serial.print(", Modus ");  Serial.print(invertiert ? "Invertiert" : "Normal");
  Serial.print(", Aktiv ");  Serial.println(systemActive ? "Ja" : "Nein");

  delay(20);
}

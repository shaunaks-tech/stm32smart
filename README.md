# 🕶️ STM32F411 Gesture-Controlled Smartglasses (WIP)

This project aims to build **embedded smartglasses powered by an STM32F411 (Blackpill)** that can recognize hand or head gestures using an **MPU6050 accelerometer + gyroscope sensor**, provide haptic/LED feedback, and communicate with a smartphone over Bluetooth.

The system will run **TinyML (TensorFlow Lite Micro)** models directly on the MCU for real-time gesture classification.  
The project is developed using **CMSIS (Cortex Microcontroller Software Interface Standard)** directly — avoiding HAL for full control, better performance, and lower memory usage. Initial tests verify GPIO output (e.g., blinking PC13) and proper clock configuration using only register-level code.

---

## Project Goals

- **Gesture Recognition** (MPU6050 + TinyML inference)
- **MPU6050 Sensor Data Capture** (I2C interface)
- **Bluetooth Communication** (HC-05 / BLE UART to phone)
- **Haptic/LED Feedback System**
- **Battery-Powered Operation with Power Optimization**
- Optional: Extend to other sensors (e.g., touch, light)

---

## Current Status

| Component         | Status     |
|------------------|------------|
| CMSIS Setup       |  Working |
| Clock Config (84 MHz via HSE + PLL) |  Working |
| GPIO Control      | Blinking PC13 |
| I2C + MPU6050     | 🔜 Next |
| Data Logging via UART | 🔜 Planned |
| TinyML Model Training | 🔜 Planned |
| ML Inference Deployment | 🔜 Planned |
| BLE UART          | 🔜 Planned |
| Haptic Feedback   | 🔜 Planned |

---

## 🛠️ Framework

The project is built using:

- **CMSIS (no STM32 HAL)**
- **PlatformIO** with `framework = cmsis`
- Direct register-level control for:
  - Clock setup
  - GPIO initialization
  - I2C + MPU6050 interface
  - UART + BLE communication

This approach provides:
- Lower memory footprint
- Higher execution speed
- Greater flexibility and insight into hardware behavior

---

## 📁 File Overview

| File             | Purpose |
|------------------|---------|
| `src/main.c`     | Entry point, sets up internal clock and peripherals |
| `src/clock.c`    | CMSIS-only 84 MHz HSE PLL configuration |
| `src/i2c.c`      | I2C1 configuration for MPU6050 |
| `src/mpu6050.c`  | MPU6050 sensor data acquisition |
| `src/ml_model.c` | TinyML inference code (planned) |
| `platformio.ini` | PlatformIO config (CMSIS + STM32F411) |
| `README.md`      | Project overview, goals, and status |

---

## Getting Started

1. Install [PlatformIO](https://platformio.org/install) in VSCode
2. Clone this repository:
   ```bash
   git clone https://github.com/shaunaks-tech/stm32smart.git
   cd stm32smart

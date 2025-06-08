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

| Component               | Status         |
|------------------------|----------------|
| CMSIS Setup            |  Working     |
| Clock Config (84 MHz)  |  Working     |
| GPIO Control (PC13)    |  Working     |
| I2C1 Setup             |  Completed   |
| MPU6050 Init + Config  |  Next Step   |
| UART Logging           |  Planned     |
| TinyML Model Training  |  Planned     |
| ML Inference Deployment|  Planned     |
| BLE UART               |  Planned     |
| Haptic Feedback        |  Planned     |

> I2C1 peripheral has been successfully initialized and confirmed working via address scanning.
> Next: Configure the MPU6050 by waking it from sleep and reading sensor data.

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

| File             | Purpose                             |
|------------------|-------------------------------------|
| `src/main.c`     | Entry point, sets up clock + UART   |
| `src/clock.c`    | CMSIS-only 84 MHz PLL config        |
| `src/i2c.c`      | I2C1 config + address scanning      |
| `src/mpu6050.c`  | 🔜 WIP: Sensor config + data read   |
| `src/ml_model.c` | 🔜 TinyML inference (planned)       |
| `platformio.ini` | PlatformIO config (CMSIS + F411)    |
| `README.md`      | Project overview                    |

---

## Getting Started

1. Install [PlatformIO](https://platformio.org/install) in VSCode  
2. Clone this repository:
   ```bash
   git clone https://github.com/shaunaks-tech/stm32smart.git
   cd stm32smart

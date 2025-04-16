# 🕶️ STM32F411 Voice-Controlled Smartglasses (WIP)

This project aims to build **embedded smartglasses powered by an STM32F411 (Blackpill)** that can recognize voice commands, provide haptic/LED feedback, and communicate with a smartphone over Bluetooth.

The project is developed using **CMSIS (Cortex Microcontroller Software Interface Standard)** directly — avoiding HAL for full control, better performance, and lower memory usage. Initial tests verify GPIO output (e.g., blinking the onboard LED on PC13) and proper clock configuration using only register-level code.

---

## 🎯 Project Goals

- **Voice Command Recognition** (TinyML, TensorFlow Lite Micro)
- **Microphone Audio Capture** (INMP441 via I2S + DMA)
- **Bluetooth Communication** (HC-05 / BLE UART to phone)
- **Haptic/LED Feedback System**
- **Battery-Powered Operation with Power Optimization**
- Optional: GPS-assisted navigation via phone app

---

## ✅ Current Status

| Component         | Status     |
|------------------|------------|
| CMSIS Setup       | ✅ Working |
| Clock Config (84 MHz via HSE + PLL) | ✅ Working |
| GPIO Control      | ✅ Blinking PC13 |
| Voice Pipeline    | 🔜 Planned |
| I2S Mic + DMA     | 🔜 Planned |
| BLE UART          | 🔜 Planned |
| ML Inference      | 🔜 Planned |

---

## 🛠️ Framework

The project is built using:

- **CMSIS (no STM32 HAL)**
- **PlatformIO** with `framework = cmsis`
- Direct register-level control for:
  - Clock setup
  - GPIO initialization
  - Future peripherals (I2S, UART, DMA)

This approach provides:
- Lower memory footprint
- Higher execution speed
- Greater flexibility and insight into hardware behavior

---

## 📁 File Overview

| File             | Purpose |
|------------------|---------|
| `src/main.c`     | Entry point, sets up internal clock and toggles GPIO |
| `src/clock.c`    | CMSIS-only 84 MHz HSE PLL configuration |
| `platformio.ini` | PlatformIO config (CMSIS + STM32F411) |
| `README.md`      | Project overview, goals, and status |

---

## 🚀 Getting Started

1. Install [PlatformIO](https://platformio.org/install) in VSCode
2. Clone this repository:
   ```bash
   git clone https://github.com/shaunaks-tech/stm32smart.git
   cd stm32smart
3. Connect your STM32F411 via DFU bootloader or ST-Link
4. pio run --target upload



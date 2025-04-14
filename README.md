# 🕶️ STM32F411 Voice-Controlled Smartglasses (WIP)

This project aims to build **embedded smartglasses powered by an STM32F411 (Blackpill)** that can recognize voice commands, provide haptic/LED feedback, and communicate with a smartphone over Bluetooth.

Currently, the project uses the **STM32 HAL (Hardware Abstraction Layer)** framework via **PlatformIO** for rapid prototyping and peripheral setup. Initial tests involve GPIO control (e.g., LED blinking on PA5) to verify proper clock config and GPIO setup.

---

##  Project Goals

-  **Voice Command Recognition** (TinyML, TensorFlow Lite Micro)
-  **Microphone Audio Capture** (INMP441 via I2S + DMA)
-  **Bluetooth Communication** (HC-05 / BLE UART to phone)
-  **Haptic/LED Feedback System**
-  **Battery-Powered Operation with Power Optimization**
-  Optional: GPS-assisted navigation via phone app

---

## Current Status

| Component       | Status     |
|----------------|------------|
| STM32 HAL Setup| ✅ Working |
| GPIO Control    | ✅ Blinking PA5 |
| Voice Pipeline  | 🔄 Planned |
| I2S Mic + DMA   | 🔄 Planned |
| BLE UART        | 🔄 Planned |
| ML Inference    | 🔄 Planned |

---

##  Framework

Currently using **STM32 HAL** via PlatformIO for:
- Simpler peripheral setup
- Access to high-level drivers (I2S, DMA, UART, etc.)
- Faster iteration during prototyping

---

##  Future Plan: CMSIS Transition

Once prototyping is complete, the project may migrate to **bare-metal CMSIS** for:
- Lower memory footprint
- Finer control over timing
- Greater optimization for embedded ML workloads

---

## 📁 File Overview

| File | Purpose |
|------|---------|
| `src/main.c`       | Entry point (currently tests GPIO/HAL) |
| `platformio.ini`   | PlatformIO configuration (HAL + STM32F411CEU6) |
| `README.md`        | Project overview, goals, and status |

---

##  Getting Started

1. Install PlatformIO in VSCode
2. Clone this repo into your dev folder
3. Plug in your STM32F411 via ST-Link or USB bootloader (DFU)
4. Build and flash:
   ```bash
   pio run --target upload

# 🔧 STM32F411 HAL Blinky – PlatformIO Project

This is a minimal STM32F411 project using **PlatformIO** with the **STM32Cube HAL (Hardware Abstraction Layer)** framework. The current implementation toggles the PA5 pin (commonly connected to an onboard LED) every 500ms using `HAL_GPIO_TogglePin()` and `HAL_Delay()`.

## 🚀 Features

- ✅ Configures system clock using `SystemClock_Config()`
- ✅ Initializes HAL and GPIOA
- ✅ Blinks PA5 using HAL functions
- ✅ Runs on Blackpill STM32F411CEU6 (Cortex-M4 @ 100MHz)

## 📁 File Overview

| File | Purpose |
|------|---------|
| `main.c` | Main application loop (HAL-based GPIO toggle) |
| `platformio.ini` | PlatformIO project config (defines board, framework, flags) |

## 🧠 Framework

This project currently uses the **STM32Cube HAL** framework for faster setup and easier peripheral configuration. HAL provides a high-level abstraction over register-level access.

### Why HAL?
- Great for rapid prototyping
- Easier to configure complex peripherals like I2S, DMA, UART, etc.
- Built-in support for SysTick, delay, and peripheral initialization

---

## 🔄 Future Plans

In the future, this project may transition to **CMSIS-only**, to:
- Reduce code size
- Gain low-level control over peripheral registers
- Optimize for speed and embedded AI workloads

The transition would involve:
- Replacing HAL functions with direct register manipulation (via CMSIS headers)
- Adding a custom linker script and startup files
- Removing HAL initialization and drivers

---

## 🧰 Getting Started

1. Install PlatformIO (in VSCode)
2. Clone or download this repo
3. Connect your STM32F411 board via ST-Link or DFU
4. Run:
   ```bash
   pio run --target upload

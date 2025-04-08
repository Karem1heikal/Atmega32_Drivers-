# AVR-Drivers  🚀


This repository is here to help you with all the Atmega32 ready-to-use drivers across various layers for your projects. All you have to do is determine which driver is needed for your application.

## 📑 Table of Contents
- [Introduction](#avr-drivers)
- [Repo Contents](#repo-contents)
- [Installation](#installation)
- [Libraries Layer](#libraries-layer)
- [MCAL Layer](#mcal-layer)
- [HAL Layer](#hal-layer)
- [RTOS Layer](#rtos-layer)
- [Contributing](#contributing)

## 📦 Repo Contents
There are 4 layers added to this repo:
1. **Libraries** layer 📚: Contains all the standardization files.
2. **MCAL** (Microcontroller Abstraction Layer) 🔌: Handles almost all controller-related peripherals.
3. **HAL** (Hardware Abstraction Layer) 🖧: Manages sensors and external hardware.
4. **RTOS** layer ⏱️: Supports task creation and applying RTOS to your project.

---

##  🛠️ Installation
To use these drivers in your project, clone the repository and include the desired drivers in your build.

```bash
git clone https://github.com/AbdelrahmanAtef01/AVR-Drivers.git
```

### Libraries Layer 📚
- `Std Types File`: Contains all embedded standard types.
- `Bit Math File`: Includes bit handling methods.

### MCAL Layer 🔌
- `DIO Driver`: Manages digital input/output.
- `ADC Driver`: Handles analog inputs.
- `Timers’ Driver`: Supports all three timers for counters, timers, or PWM generation.
- `WDT Driver`: Manages the Watchdog Timer.
- `USART Driver`: Handles external communication using UART protocol.
- `SPI Driver`: Manages external communication using SPI protocol.
- `I2C Driver`: Supports external communication via the I2C protocol.
- `Global Interrupt Driver`: Manages global interrupts.
- `External Interrupt Driver`: Handles external interrupts.

### HAL Layer 🖧
- `LED Handler`: Controls LED usage.
- `LCD Handler`: Manages LCD usage.
- `Switch Handler`: Reads switch inputs.
- `Relay Handler`: Manages relay control.
- `Keypad Handler`: Reads keypad inputs.
- `7-Segment Handler`: Controls 7-segment displays.
- `LM35 Handler`: Reads temperatures using the LM35 sensor.
- `M16P Handler`: Plays sounds using the M16P module.
- `Motor Handler`: Controls motors.
- `Stepper Motor Handler`: Manages stepper motor control.

### RTOS Layer ⏱️
- **src**: Contains RTOS source code files.
- **include**: Contains headers for all RTOS components.
- **API**: Provides files for including components, drivers, creating tasks, and more.

---

> **Note**: These drivers were developed during a learning process and include various configuration methods, different interrupt handling techniques (polling and actual ISR), etc. They are all working and tested but may not follow the best architectural practices yet. Contributions and modifications are welcome to help us build a powerful, well-architected resource. 👀

### 🤝 Contributing
Contributions are welcome! Here’s how you can help:

1. **Fork** the repository to create your own copy.
2. Create a **new branch** for your changes.
```bash
git checkout -b feature-branch
```
3. Make your modifications and test them.
4. **Commit** your changes with a descriptive message.
```bash
git commit -m 'Add new feature'
```
5. **Push** your changes to your forked repository.
```bash
git push origin feature-branch
```
6. Open a **Pull Request** to submit your changes.

Please open an issue to discuss your ideas before creating significant changes. Together, we can improve and expand this resource to benefit the whole community! 🌍

# Battle Bot

A high-power battle robot built using an **Arduino Mega**, **BTS7960 motor drivers**, and **Flysky FS-i6X transmitter/receiver**. Designed for both mobility and attack with a dedicated brushless weapon motor.


![battle1](https://github.com/user-attachments/assets/9818ec9d-281b-4791-9f54-84bcaf80b43e)

![battle2](https://github.com/user-attachments/assets/f5f00844-fc86-48e4-9f56-ac6ba5e703ef)


---

## Components Used
- **Arduino Mega + Shield**
- **2 × BTS7960 43A Motor Drivers**
- **GOOLRC 35A Brushless ESC**
- **Flysky FS-i6X Transmitter & Receiver**
- **DC Motors (for wheels)**
- **Brushless Motor (for weapon)**
- **Step-down voltage converter**
- **Li-ion Batteries**
- **Custom PCBs**

---

## Features
- Dual BTS7960 drivers for high-torque motor control
- Brushless weapon control via ESC
- Wireless joystick control using FS-i6X and PWM channels
- Compact wiring using custom PCBs
- Modular power system with voltage regulation

---

## Control Logic
- Channels from the Flysky receiver control:
  - LPWM/RPWM for wheel direction
  - EN pins for motor enable/disable
  - ESC for weapon motor control
- Arduino Mega processes PWM input signals and converts them to motor commands

---

## Wiring Diagram
---![Flysky_BTS_circuit](https://github.com/user-attachments/assets/2a50ce00-7f6a-4950-ac96-28619fb35e86)


## Future Improvements
- Gyroscope-based stabilization
- Fail-safe mechanism if signal is lost
- Armor redesign for reduced weight

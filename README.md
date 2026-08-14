<div align="center">

# ⚙️ PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs

### AVR / ATmega328P Microprocessor Labs — COMSATS University Islamabad

**By [Ibrar Ahmad](https://github.com/hiibrarahmad)**

[![MCU](https://img.shields.io/badge/MCU-ATmega328P-00c8ff?style=for-the-badge)](#)
[![Simulation](https://img.shields.io/badge/Simulated%20In-Proteus%208%20Professional-22c55e?style=for-the-badge)](#)
[![Toolchain](https://img.shields.io/badge/Toolchain-Atmel%20Studio%20%2F%20AVR--GCC-ff6b35?style=for-the-badge)](#)

[![License](https://img.shields.io/badge/License-GPL--3.0-blue?style=for-the-badge)](LICENSE)

</div>

---

## 🎓 Acknowledgment

All of this work was done in lab, under the supervision of **Khiyam Iftikhar** — [COMSATS University Islamabad](http://ww2.comsats.edu.pk/faculty/FacultyDetails.aspx?Uid=354). He built my true ground in embedded systems. Every project in this repository traces back to what I learned in his course.

---

## 📖 Overview

Nine AVR/ATmega328P projects from the same course and personal-learning period (2021), consolidated into one repository. Each was originally built with **Atmel Studio / AVR-GCC** or the **Arduino IDE**, and simulated in **Proteus 8 Professional**; several were also verified on real breadboard hardware.

| Project | What it does |
|---------|---------------|
| [`Lab-01-Development-Tools/`](Lab-01-Development-Tools) | First exercises across Arduino IDE, AVR Studio, Atmel Studio, and Proteus — direct-register LED blink on PORTB. |
| [`Lab-02-Digital-IO-Ports/`](Lab-02-Digital-IO-Ports) | Digital I/O: Task 1 repeats the Lab-01 blink; Task 2 adds a debounced push button that cycles through 3 LEDs. |
| [`Toggle-LED-Push-Button/`](Toggle-LED-Push-Button) | A push button toggles an LED exactly once per press, regardless of how long it's held. |
| [`Ultrasonic-Sensor-HCSR04/`](Ultrasonic-Sensor-HCSR04) | HC-SR04 ultrasonic distance sensor, measured via Timer1 pulse-width capture, distance printed to a 16x2 LCD. |
| [`Matrix-Keypad/`](Matrix-Keypad) | 3x4 matrix keypad scanner (row/column debounced read), decoded digit written out to drive indicator LEDs. |
| [`7Segment-0-99-Counter/`](7Segment-0-99-Counter) | Two common-anode 7-segment displays driven from lookup tables, counting 0–99. |
| [`Alarm-Clock-ATmega328P/`](Alarm-Clock-ATmega328P) | Full digital alarm clock — Timer1 software RTC, 16x2 LCD, 5 buttons, buzzer, IR-triggered backlight. Also published standalone as [PRJ-FW-4001-2020-ArduinoAVRAlarmClock](https://github.com/hiibrarahmad/PRJ-FW-4001-2020-ArduinoAVRAlarmClock). |
| [`Digital-Clock-Alarm-Stopwatch-Timer/`](Digital-Clock-Alarm-Stopwatch-Timer) | A second, menu-driven take on the same idea: clock, alarm, stopwatch, and countdown timer, all on one LCD with a 3-button interface. |
| [`EEE446-Real-Time-Embedded-Systems/`](EEE446-Real-Time-Embedded-Systems) | Four Arduino-IDE exercises: single 7-segment 0-9 counter, multiplexed 3-digit 000-999 counter, and two 16x2 LCD text-display tasks. |

---

## 🖼️ Real Proteus Captures

<table>
<tr>
<td align="center" width="33%"><img src="7Segment-0-99-Counter/assets/Counter-ProteusSimulation.png" width="100%"/><br/><sub>7-Segment 0–99 Counter</sub></td>
<td align="center" width="33%"><img src="Matrix-Keypad/assets/Keypad-ProteusSimulation.png" width="100%"/><br/><sub>Matrix Keypad</sub></td>
<td align="center" width="33%"><img src="Toggle-LED-Push-Button/assets/ProteusSimulation.png" width="100%"/><br/><sub>Toggle LED / Push Button</sub></td>
</tr>
</table>

<div align="center">
<img src="Alarm-Clock-ATmega328P/assets/AlarmClock-ProteusSimulation.png" width="70%"/><br/>
<sub>Alarm Clock — full schematic</sub>
</div>

---

## 🛠️ Toolchain

- **Atmel Studio 7** / **AVR-GCC** (direct `avr/io.h` register access, no framework) for most projects; **Arduino IDE** for the EEE446 tasks
- **Proteus 8 Professional** for schematic capture and simulation
- Target: **ATmega328P**, 16MHz external crystal

## 📁 Structure

```
PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs/
│
├── Lab-01-Development-Tools/
├── Lab-02-Digital-IO-Ports/{Task1,Task2}/
├── Toggle-LED-Push-Button/
├── Ultrasonic-Sensor-HCSR04/
├── Matrix-Keypad/
├── 7Segment-0-99-Counter/
├── Alarm-Clock-ATmega328P/
├── Digital-Clock-Alarm-Stopwatch-Timer/
├── EEE446-Real-Time-Embedded-Systems/{Task1..Task4}/
└── LICENSE
```

Every `main.c`/`main.ino` (and any helper `.c`/`.h` files) carries its own copyright/purpose header. Build artifacts (`Debug/`, `.hex`, `.elf`, `.map`, etc.) are intentionally not included — only the real source and, where they exist, the real Proteus simulation captures and circuit diagrams.

---

<div align="center">

**PRJ-FW-4002-2021-COMSATS-AVRMicroprocessorLabs**

*AVR Microprocessor Labs · COMSATS University Islamabad · Ibrar Ahmad*

© 2021 Ibrar Ahmad. Licensed under GPL-3.0.

</div>

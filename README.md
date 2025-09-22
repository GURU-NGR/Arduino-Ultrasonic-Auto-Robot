# Arduino-Ultrasonic-Auto-Robot

Arduino project for an autonomous obstacle-avoiding robot car using an ultrasonic sensor and servo motor. The car scans left, right, and straight, then moves in the direction with the most clearance.

---

## 📦 Features

- Autonomous navigation with obstacle detection.
- Ultrasonic sensor scans in three directions using a servo motor.
- Decides movement direction based on available space.
- Provides serial output for monitoring distances and movements.

---

## 🔧 Hardware Requirements

- Arduino Uno (or compatible board)
- SG90 Servo Motor
- Ultrasonic Sensor (HC-SR04)
- L298N Motor Driver or H-bridge setup
- DC Motors with wheels
- Jumper wires
- Power supply for motors

---

## 📌 Wiring

**Ultrasonic Sensor**
| Pin | Arduino |
|-----|---------|
| VCC | 5V      |
| GND | GND     |
| TRIG | 13     |
| ECHO | 12     |

**Servo Motor**
| Wire | Arduino |
|------|---------|
| Signal | 11    |
| VCC    | 5V    |
| GND    | GND   |

**Motors (H-Bridge/L298N)**
| Motor Pin | Arduino |
|-----------|---------|
| ENA       | 6       |
| LN1       | 7       |
| LN2       | 5       |
| ENB       | 3       |
| LN3       | 4       |
| LN4       | 2       |

---

## 📝 Installation

1. Connect all components as per the wiring table.
2. Open Arduino IDE.
3. Copy the `UltraSonic_Auto.ino` code or open the `.ino` file.
4. Upload the code to the Arduino board.
5. Power the motors appropriately.

---

## 🚀 Usage

1. Open the Serial Monitor (baud rate 9600) to view distances and actions.
2. Place the robot on the ground.
3. The robot will automatically scan surroundings and move in the direction with maximum free space.

---

## 💡 Extending the Project

- Integrate IR or Bluetooth control for manual override.
- Add speed control based on distance.
- Integrate with GPS or mapping for more advanced autonomous navigation.

---

## ⚡ License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

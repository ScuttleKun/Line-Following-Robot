# Autonomous Line-Following Robot

## Overview
This repository contains the embedded C/C++ firmware for an autonomous line-following robot. Built on the Arduino platform, the system utilizes a 5-channel Infrared (IR) sensor array for path detection and a state machine architecture to govern navigation logic. The codebase is modular, separating sensor polling, state determination, and motor actuation into distinct hardware abstraction layers.

## Developer
* **Ivan Phung** ## Hardware Components
* **Microcontroller:** Arduino-compatible board (e.g., Uno/Nano)
* **Path Detection:** 5-Channel Analog IR Sensor Array
* **Motor Driver:** H-Bridge Motor Driver (e.g., L298N) controlling two DC motors
* **Obstacle Detection (Test Phase):** HC-SR04 Ultrasonic Sensor

## System Architecture

The robot operates using a continuous sense-decide-actuate loop:
1. **Sense:** The microcontroller polls 5 analog IR sensors.
2. **Process:** The analog readings are thresholded and compressed via bitwise shifting into a single 5-bit integer (e.g., `0b00100` indicates the center sensor is on the line).
3. **State Machine:** The 5-bit pattern is evaluated to determine the robot's current navigational state (`FOLLOW_LINE`, `LOST_LINE`, `CROSSROAD`, `TURN_LEFT`, `TURN_RIGHT`).
4. **Actuate:** The system triggers corresponding PWM signals to the left and right motors to adjust the robot's trajectory.

## Project Structure

| File | Description |
| :--- | :--- |
| `LINE_FOLLOWING_ROBOT.ino` | The main executable sketch. Initializes pins and loops the primary state machine. |
| `cases.c` / `cases.h` | Contains the sensor logic. Maps the 5 analog readings to digital bits and assigns the current navigational state based on predefined binary patterns. |
| `motors.c` / `motors.h` | Motor control abstraction layer. Handles pin state switching (HIGH/LOW) and PWM outputs for forward, turn, and stop operations. |

### Test & Calibration Scripts
The repository also includes standalone scripts used for unit testing individual hardware components prior to integration:
* `IR Sensor Code.ino`: Reads raw analog values from pins A0-A4, calculates equivalent voltages (based on a 3.3V reference), and tests binary thresholding logic.
* `motor-code.ino`: Directly drives the H-bridge pins to test `forward()`, `turnLeft()`, `turnRight()`, and `stopMotors()` functionality.
* `Main Robot Code.ino`: An alternate/legacy implementation using a 3-sensor array and basic voltage thresholding for directional movement.
* `Ultrasonic Sensor Code.ino`: Generates pulses and measures echo response times to calculate distances in centimeters.

## Pin Mapping

*Note: Verify pin assignments in `cases.h` and `motors.h` before flashing, as they may vary depending on the specific Arduino board used.*

**IR Sensors (Left to Right):**
* Sensors 1-5 connected to analog-capable pins (currently configured for pins `2, 3, 4, 5, 6` in `cases.h`, and `A0-A4` in the testing script).

**Motor Driver:**
* **Left Motor:** Direction pins (`L1`, `L2`), Speed control (`L_PWM`)
* **Right Motor:** Direction pins (`R1`, `R2`), Speed control (`R_PWM`)

## Installation & Setup
1. Clone this repository to your local machine.
2. Open `LINE_FOLLOWING_ROBOT.ino` in the Arduino IDE.
3. Ensure `cases.c`, `cases.h`, `motors.c`, and `motors.h` are located in the same sketch directory.
4. Select your Arduino board model and corresponding COM port in the IDE.
5. Compile and upload the firmware to the board.

## Future Development
* **PID Control:** Transition from rigid switch-case directional corrections to a proportional-integral-derivative (PID) algorithm for smoother line tracking.
* **Obstacle Avoidance Integration:** Merge the standalone ultrasonic sensor logic into the main state machine to allow the robot to stop or navigate around objects placed on the track.

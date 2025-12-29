# Virtual TB3

A simple 2D simulation of a TurtleBot3-like differential drive robot using C++ and SFML.

## Features
- Differential drive kinematics.
- Real-time keyboard control.
- Visualization using SFML.
- Velocity feedback display.

## Controls
- **A**: Turn Left / Accelerate Left Wheel.
- **D**: Turn Right / Accelerate Right Wheel.

## Prerequisites
- **C++20** compiler.
- **CMake** (version 3.29 or higher).
- **SFML 3** (System, Window, Graphics components).

## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/elmarismayilov/differential-drive-simulator.git
   ```

2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

3. Configure and build:
   ```bash
   cmake ..
   cmake --build .
   ```

4. Run the application:
   ```bash
   ./virtualtb3
   ```

## Project Structure
- `src/`: Source code (`main.cpp`, `Robot.cpp`).
- `include/`: Header files (`Robot.h`).
- `fonts/`: Assets for text rendering.
- `CMakeLists.txt`: Build configuration.

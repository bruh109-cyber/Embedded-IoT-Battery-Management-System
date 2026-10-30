🔋 Lithium-X4 | Battery Management System (BMS)

A C-based Battery Management System (BMS) simulation designed to demonstrate battery telemetry monitoring, electrical calculations, data type management, voltage analysis, power calculations, and battery status monitoring.

📌 Project Overview

The Lithium-X4 BMS is a C programming project that simulates essential operations of a Battery Management System.

It processes raw battery sensor values, converts them into meaningful electrical measurements, evaluates battery operating conditions, and displays system telemetry through a formatted console dashboard.

The project also demonstrates efficient memory usage and low-level programming concepts using standard C data types.

✨ Features
🔋 Battery voltage monitoring.
⚡ Current measurement and conversion.
📊 Instantaneous power calculation.
🔌 Voltage-based state-of-charge estimation.
🛡️ Overvoltage and undervoltage detection.
🔄 Battery discharging detection.
📈 Battery operating status evaluation.
🔀 Active and passive power bank swapping.
💾 Memory footprint analysis using sizeof().
📟 Formatted BMS telemetry dashboard.
🛠️ Technologies Used
Technology	Purpose
C	Main programming language
stdio.h	Console input/output
stdbool.h	Boolean operations
stdint.h	Fixed-width integer types
GCC	C compiler
⚙️ System Specifications
Parameter	Value
BMS Model	Lithium-X4
Maximum Cell Voltage	4.20 V
Minimum Cell Voltage	3.00 V
Maximum Pack Capacity	100 Ah
Initial Cell Voltage	3.850 V
Initial Current	-12.50 A
Operating Time	15 days
Total Energy Delivered	46,800,000,000 J
Internal Resistance	1.25 mΩ
Battery Health Grade	A
🧮 Electrical Calculations

1. Voltage Conversion

Converts millivolts into volts:

c
actualVoltage = (float)rawVoltageMilliVolts / 1000.0f;


2. Current Conversion

Converts milliamps into amperes:

c
actualCurrent = (float)rawCurrentMilliAmps / 1000.0f;


3. Instantaneous Power

Calculates electrical power:

c
instantaneousPowerWatts = actualVoltage * actualCurrent;


4. Voltage-Based SOC Estimation

Estimates a normalized voltage percentage:

c
stateOfChargePercent =
    (currentOffset / voltageRange) * 100.0f;


Note: This is a simplified voltage-based estimate, not an accurate measurement of battery state of charge.

🚀 Getting Started
Prerequisites
GCC compiler or another C compiler.
Basic knowledge of C programming.
Terminal or command-line interface.
Installation

Clone the repository:

bash
git clone https://github.com/YOUR-USERNAME/Lithium-X4-BMS.git


Navigate to the project directory:

bash
cd Lithium-X4-BMS

Compilation

Compile the source code using GCC:

bash
gcc main.c -o bms

Execution

On Linux/macOS:

bash
./bms


On Windows:

bash
bms.exe

📟 Example Output
text
=== BMS SYSTEM MEMORY FOOTPRINT ===
uint16_t (Voltage): 2 byte(s)
uint32_t (Uptime): 4 byte(s)
uint64_t (Energy): 8 byte(s)
double (Resistance): 8 byte(s)

=== BMS TELEMETRY DASHBOARD [Lithium-X4] ===
Pack Grade: A | System Status Nominal: 1
Active Power Bank (Swapped): Slot #2
Pack Voltage:   3.850 V
Pack Current:   -12.50 A
Power Output:   -48.13 W
State of Charge: 70.8 %
Total Energy Output:46800000000 Joules

📚 C Programming Concepts Demonstrated
Fixed-width integer types (uint8_t, uint16_t, uint32_t, uint64_t).
Signed integer types (int16_t).
Floating-point arithmetic (float and double).
Boolean logic and comparisons.
Type casting.
Variable swapping.
Memory management fundamentals.
Formatted output with printf().
Conditional status evaluation.
🔮 Future Improvements

Potential extensions for this project include:

Real-time battery voltage and current monitoring.
Battery temperature monitoring.
Cell balancing simulation.
Accurate SOC estimation using coulomb counting.
State of Health (SOH) estimation.
Short-circuit and overcurrent protection.
CAN bus communication.
Embedded implementation using STM32 or ESP32.
LCD or graphical telemetry dashboard.
⚠️ Disclaimer

This project is an educational software simulation. It is not a certified Battery Management System and must not be used as a replacement for real battery protection hardware.

👨‍💻 Author

Your Name

GitHub: @YOUR-USERNAME

📄 License

This project is licensed under the MIT License. See the LICENSE file for details.


# Poultry Farm Timer Project

This repository contains the code for a Poultry Farm Timer, designed to automate the egg collection process in chicken cages. The timer controls a linear actuator, ensuring the safe collection of eggs and preventing breakage during the process. The system features a display with a company logo, current time, and an adjustable clock using an RTC module.

## Features

- **Egg Collection Automation:** The linear actuator efficiently collects eggs, preventing breakage during the process.
  
- **Display with Company Logo:** The OLED display showcases the company logo, providing a personalized touch.

- **Real-Time Clock (RTC):** The system employs an RTC module for accurate timekeeping, allowing precise scheduling and control.

- **Adjustable Clock:** Users can easily adjust the clock settings, switching between adjusting hours and minutes.

## Hardware Requirements

- Microcontroller (e.g., Arduino)
- Linear Actuator
- RTC Module
- OLED Display
- Relay Modules
- Buttons for user interaction

## Libraries Used

- Adafruit_GFX
- Adafruit_SSD1306
- RTClib
- NoDelay

## Wiring

Ensure the proper wiring connections for the linear actuator, RTC module, OLED display, and buttons. Connect relay modules to control the linear actuator.

## How to Use

1. **Initialization:**
   - Install the required libraries using the Arduino IDE or your preferred development environment.
   - Upload the provided code to your microcontroller.

2. **Operation:**
   - The system will initialize, displaying the company logo on the OLED screen.
   - Use the buttons to adjust the clock settings (hours and minutes) as needed.
   - The linear actuator will be controlled based on the current time, collecting eggs during specified intervals.
   - The display will show the count of collected eggs and the current time.

3. **Adjustable Clock:**
   - Press the mode button to toggle between adjusting hours and minutes.
   - Use the up and down buttons to increase or decrease the selected value.

4. **Actuator Control:**
   - The actuator is triggered based on specified conditions, collecting eggs during specific time intervals.

5. **Power Saving:**
   - The actuator turns off after the specified interval to conserve power.

## Note

- Customize the bitmap data in `epd_bitmap_poultrypicture` with your own company logo.

Feel free to contribute, report issues, or suggest improvements. Happy egg collecting! 🐔🥚

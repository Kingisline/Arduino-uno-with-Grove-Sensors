# Arduino Uno with Grove sensors


![Image](https://github.com/user-attachments/assets/89997a17-a83b-4dfd-bd04-49e0982331d2)

![Image](https://github.com/user-attachments/assets/4ac9b920-3996-4b91-a212-26d752b2df5d)

![Image](https://github.com/user-attachments/assets/a5c14618-5dcf-4268-a390-763774bcdf16)


## This system:

### 1. Monitors Environmental Parameters: Temperature, light, sound, and vibration.
### 2. Interactive Inputs: Button, touch sensor, rotary sensor for adjustments.
### 3. Feedback and Alerts: Uses RGB LEDs and a buzzer for alerts.
### 4. Display: Outputs data to an RGB LCD.

## Features

### 1. Dynamic Threshold Adjustment:
- The rotary sensor adjusts the thresholds for temperature, light, and sound in real-time.
### 2. Real-Time Data Display:
- The LCD shows temperature and light intensity.

### 3. Alerts:
- High temperature triggers the red LED.
- High light intensity triggers the blue LED.
- High sound intensity triggers the buzzer.
- Vibration triggers the green LED.

### 4. Touch Sensor:
- Used as a manual reset for alerts.

## 5. Button:
- Displays current thresholds on the LCD.

##  Hardware Setup:
- Connect the Grove Base Shield to your Arduino.
- Plug the Grove modules into the appropriate ports as defined in the code:
  - Digital Ports: Touch sensor (D2), button (D3), vibration sensor (D4), buzzer (D5), LEDs (D6, D7, D8).
  - Analog Ports: Temperature sensor (A0), rotary sensor (A1), sound sensor (A2), light sensor (A3).
- Connect the RGB LCD to the I2C port on the Grove shield.

## Power Supply:
A 5V, 1A USB power source is recommended to handle the combined load of all modules and the Arduino.

Let me know if you need further clarification or modifications!

## Video 

[![Watch the video](https://github.com/user-attachments/assets/e7a80e34-3c31-493e-a6b4-8191b19a8883)](https://youtu.be/y1ZDbPk0SzE)

## Social Media

[Instagram](https://www.instagram.com/ppl_call_me_as_bad_capton?igsh=NG1tYmpsYW5jcWY=)
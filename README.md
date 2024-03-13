# Smart Lab and Smart Stairs 

# Table of Contents
Introduction
Hardware Components
Installation
Usage
Features
Mobile App
Contributing
License

### 
---
###

# Introduction
The Smart Lab and Smart Stairs initiative introduces a groundbreaking IoT (Internet of Things) concept by integrating Arduino Uno and an array of sensors to establish smart environments in laboratories and staircases. This endeavor harnesses the potential of automation and sensor technologies to bolster safety, energy efficiency, and convenience in these settings.

The Smart Stairs 
The Smart Stairs feature within the project is engineered to autonomously sense the presence of individuals on the staircase, adjusting the lighting as needed. This functionality relies on a combination of ultrasonic and infrared sensors for precise detection, facilitating efficient management of lighting resources.

The Smart Lab
The Smart Lab module is designed to establish a safe and intelligent setting within the laboratory, utilizing various sensors to monitor both human activity and environmental factors like temperature and humidity. Moreover, it integrates a fire detection mechanism to enhance safety measures. When there's no activity detected, the lighting system switches off automatically, conserving energy. Should temperatures escalate, a DC fan operates as an exhaust to maintain optimal conditions. Additionally, the setup features an alarm system equipped with an MQ-2 smoke sensor to swiftly identify and address any signs of smoke or fire.

# Hardware Components
To build the Smart Lab and Smart Stairs project, you will need the following hardware components:

Arduino Uno
Ultrasonic Sensor
Infrared (IR) Sensor
Passive Infrared (PIR) Sensor
MQ-2 Smoke Sensor
Buzzer
5V DC Fan
HC-05 Bluetooth Module
LCD Display
Temperature and Humidity Sensor

# Installation
Assemble the hardware components according to the provided schematics or customize your own design.
Upload the Arduino code corresponding to each component onto the Arduino Uno board. Refer to the respective directories for the code.
Power up the system and ensure all sensors and components are correctly connected.
Install the mobile app on your Android device. Establish a connection between your device and the HC-05 Bluetooth module to remotely manage and monitor the system.

# Usage
Smart Stairs
Place the ultrasonic and IR sensors in the appropriate positions on the staircase.
When a person approaches the stairs, the lighting will automatically turn on, and it will turn off when no motion is detected.

Smart Lab
Set up the sensors as required in the lab, including the PIR sensor, MQ-2 smoke sensor, temperature, and humidity sensor.
The system will automatically control the lighting, fan, and alert you in case of smoke or fire detection.
The LCD display will show real-time temperature and humidity information.
When no movement is detected, the lights will be turned off to save energy. The DC fan will operate to regulate the temperature if it rises.

# Features
Smart Stairs:
Automatic lighting control based on presence detection using ultrasonic and IR sensors.

Smart Lab:
Automated lighting control within the lab based on occupancy.
Real-time monitoring of temperature and humidity.
Smoke and fire detection with alarm system.
Energy-saving feature: lights turned off when no movement is detected.
Temperature-regulated DC fan for climate control.

Mobile App:
Bluetooth-based mobile app for remote monitoring and control of the system.
Hardware Components

# Mobile App
The mobile app allows you to monitor and control the Smart Lab and Smart Stairs system remotely. Simply connect your Android device to the HC-05 Bluetooth module and use the app to:
Check the status of lights, fan, and sensors.
Turn the lights and fan on/off.
Receive notifications in case of fire or smoke detection.

# Contributing
We welcome contributions from the open-source community. If you have ideas for improvements, bug fixes, or new features, feel free to create a pull request.

# License
This project is open-source and licensed under the MIT License. You are free to use, modify, and distribute this software as per the terms of the license.

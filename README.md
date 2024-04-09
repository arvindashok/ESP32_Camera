# Smart Surveillance System with Motion Detection and Face Recognition

This project implements a smart surveillance system utilizing motion detection technology and face recognition capabilities. It utilizes ESP32 microcontrollers along with a camera module to capture live video footage, detect motion, and recognize faces. The system can be extended to support multiple camera nodes for comprehensive surveillance coverage.

## Objective

The primary objective of this project is to enhance security and minimize human intervention by employing motion-based tracking and face recognition techniques.

## Features

- **Motion Detection**: Passive Infrared (PIR) sensors continuously monitor the surroundings for changes in infrared radiation, indicating motion.
- **Face Recognition**: Captured images are processed using a face recognition script to identify faces.
- **Live Video Streaming**: Access live video feeds via LAN web servers hosted on each ESP32 device.
- **Cloud Integration**: Utilize Firebase for cloud storage of captured images and real-time database for sensor data.
- **Inter-node connection**: Uses sensor data on firebase to trigger actions on other cameras.

## Hardware Components

- **ESP32-CAM**: A compact camera module based on the ESP32 microcontroller, featuring an OV2640 camera and onboard TF card slot.
- **Passive Infrared (PIR) Sensors**: Detect motion within their field of view by monitoring changes in infrared radiation.

## System Operation

1. **Motion Detection**: PIR sensors detect motion and trigger the ESP32 microcontroller to capture images.
2. **Image Processing**: Captured images are stored locally and uploaded to Firebase Storage for cloud storage.
3. **Face Recognition**: A face recognition script analyzes images to identify faces.
4. **Data Monitoring**: Sensor data is uploaded to Firebase Realtime Database for monitoring and analysis.

## Usage

1. **Setup**: Connect the ESP32-CAM module to the WiFi network and configure Firebase credentials.
2. **Operation**: The system will continuously monitor for motion. Upon detection, images are captured, processed, and uploaded to Firebase.

## Code

The code consists of several files:

- **Main Code (main.cpp)**: Implements the core functionality of the surveillance system, including motion detection, image capture, and Firebase integration.
- **Camera Configuration (camera_index.h)**: Defines the camera configuration parameters.
- **Firebase Integration (Firebase_ESP_Client.h)**: Handles communication with the Firebase backend.
- **HTTP Server (esp_http_server.h)**: Manages HTTP server functionality for streaming video and handling requests.

## Setup Instructions

1. Connect the ESP32-CAM module to the appropriate pins and upload the provided code.
2. Configure WiFi credentials and Firebase API keys, email, and password.
3. Mount LittleFS and ensure proper camera initialization.
4. Start the camera server to begin surveillance operations.

## Contributors

- Arvind Ashok
- Aryan Madhan Pillai
- Aravind Anand



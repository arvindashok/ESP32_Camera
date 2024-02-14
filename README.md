<h1>Security surveillance system using ESP32 Cam</h1>

This smart surviellance system provides motion detection based surviellance which uses the ESP32 microscontrollers to stream live video footage and perform face recognition on captured images. This software system can be extended to work with multiple camera nodes. 

The main objective of this project is to enhance protection and security and minimize human interference by providing motion based tracking.

<h4>Hardware Components:</h4>
The ESP32-CAM is a small size, low power consumption camera module based on ESP32. It comes with an OV2640 camera and provides onboard TF card slot. The ESP32-CAM can be widely used in intelligent IoT applications such as wireless video monitoring, WiFi image upload, QR identification, and so on. It is easy to program and comes in built with a wifi and bluetooth module.
Passive Infrared (PIR) sensors are employed to detect motion within their field of view.

<h4>System Operation:</h4>
PIR sensors continuously monitor their surroundings for changes in infrared radiation, indicating motion.
When motion is detected, PIR sensors send signals to the associated ESP32 microcontroller.
The ESP32 microcontroller processes the signal and triggers the connected camera module to capture images. The sensor data is also uploaded to Firebase, this allows other ESP32 microcontrollers in idle mode to monitor this sensor data in Firebase to detect this motion and start capturing footage.
Captured images are then transmitted to a central database for storage and analysis. 
Each individual node also activates and start capturing footage if it detects motion.

A simple face recognition script fetches images from the database to identify faces in the image.
This code currently supports 2 nodes, each with an ESP32 Cam and PIR. It can be further extended to work with multiple nodes. 

Live video feed can be viewed on a LAN web server hosted on each ESP32. Captured images are stored in Firebase Storage. Sensor data of each node is stored using the Real Time Databse in Firebase

<h1>Security surveillance system using ESP32 Cam</h1>

Features include live streaming of video footage within LAN and ability to capture still images. Captured images are uploaded to Firebase.

The main objective of this project is to enhance protection and security and to minimize human interference.
<h4>Hardware Components:</h4>
ESP32 microcontrollers serve as the central processing units, facilitating communication and control within the system.
Passive Infrared (PIR) sensors are employed to detect motion within their field of view.
Camera modules, connected to the ESP32s, capture images upon receiving trigger signals
<h4>System Operation:</h4>
PIR sensors continuously monitor their surroundings for changes in infrared radiation, indicating motion.
When motion is detected, PIR sensors send signals to the associated ESP32 microcontroller.
The ESP32 microcontroller processes the signal and triggers the connected camera module to capture images. The sensor data is also uploaded to Firebase, to allows other ESP32 microcontrollers to detect this motion and start capturing footage.
Captured images are then transmitted to a central database for storage and analysis.

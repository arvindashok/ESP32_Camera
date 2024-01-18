#include "Arduino.h"
#include "WiFi.h"
#include "esp_camera.h"
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#include "driver/rtc_io.h"
#include <LittleFS.h>
#include <FS.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>

const char *ssid = "Vasko";
const char *password = "arv2003!";
#define API_KEY "AIzaSyC0I-KPyRpX0SQhyx0fXn2Ql5tiZvuP3wg"
#define USER_EMAIL "arvind.cs21@bmsce.ac.in"
#define USER_PASSWORD "arv2003!"
#define STORAGE_BUCKET_ID "esp32-cam-7611b.appspot.com"
#define FILE_VIDEO_PATH "/video.avi"
#define BUCKET_VIDEO "/data/video.avi"

#define PWDN_GPIO_NUM 32
#define RESET_GPIO_NUM -1
#define XCLK_GPIO_NUM 0
#define SIOD_GPIO_NUM 26
#define SIOC_GPIO_NUM 27
#define Y9_GPIO_NUM 35
#define Y8_GPIO_NUM 34
#define Y7_GPIO_NUM 39
#define Y6_GPIO_NUM 36
#define Y5_GPIO_NUM 21
#define Y4_GPIO_NUM 19
#define Y3_GPIO_NUM 18
#define Y2_GPIO_NUM 5
#define VSYNC_GPIO_NUM 25
#define HREF_GPIO_NUM 23
#define PCLK_GPIO_NUM 22

boolean recording = false;
unsigned long recordingStartTime;
unsigned long recordingEndTime;

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig configF;

void fcsUploadCallback(FCS_UploadStatusInfo info);

void startRecording() {
  recording = true;
  recordingStartTime = millis();
  recordingEndTime = recordingStartTime + 5000; // Record for 5 seconds
}

void stopRecording() {
  recording = false;
}

void captureVideoSaveLittleFS() {
  if (recording && millis() < recordingEndTime) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
      delay(1000);
      ESP.restart();
    }

    File file = LittleFS.open(FILE_VIDEO_PATH, FILE_APPEND);
    if (!file) {
      Serial.println("Failed to open file in writing mode");
    } else {
      if (file.write(fb->buf, fb->len) != fb->len) {
        Serial.println("Error writing to file");
      }
    }
    file.close();
    esp_camera_fb_return(fb);
  } else {
    stopRecording();
  }
}

void initWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void initLittleFS() {
  if (!LittleFS.begin(true)) {
    Serial.println("An Error has occurred while mounting LittleFS");
    ESP.restart();
  } else {
    delay(500);
    Serial.println("LittleFS mounted successfully");
  }
}

void initCamera() {
  camera_config_t config;
  // Camera configuration...
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    ESP.restart();
  }
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  initLittleFS();
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  initCamera();

  configF.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  configF.token_status_callback = tokenStatusCallback;

  Firebase.begin(&configF, &auth);
  Firebase.reconnectWiFi(true);

  startRecording(); // Start recording immediately
}

void loop() {
  captureVideoSaveLittleFS();
  delay(10);
}

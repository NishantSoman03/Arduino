/*
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"

// Replace with your network credentials
const char* ssid = "Tenda_33DD70";
const char* password = "Nish&Chin0326";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void initSDCard(){
  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

void initWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  initSDCard();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    File root = SD.open("/");
    String fileList = "<html><body><h1>Files on SD Card:</h1><ul>";
    while (true) {
      File entry = root.openNextFile();
      if (!entry) {
        break;
      }
      fileList += "<li><a href='" + String(entry.name()) + "'>" + String(entry.name()) + "</a></li>";
      entry.close();
    }
    fileList += "</ul></body></html>";
    request->send(200, "text/html", fileList);
    root.close();
  });

  server.begin();
}

void loop() {
  
}
*/

 

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"

// Replace with your network credentials
const char* ssid = "Tenda_33DD70";
const char* password = "Nish&Chin0326";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void initSDCard(){
  if(!SD.begin()){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  initWiFi();
  initSDCard();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    File root = SD.open("/");
    String fileList = "<html><body><h1>Files on SD Card:</h1><ul>";
    while (true) {
      File entry = root.openNextFile();
      if (!entry) {
        break;
      }
      fileList += "<li>" + String(entry.name()) + "</li>";
      entry.close();
    }
    fileList += "</ul></body></html>";
    request->send(200, "text/html", fileList);
    root.close();
  });

  server.begin();
}

void loop() {
  
}

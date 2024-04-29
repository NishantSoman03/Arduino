/*
  ESP32 Web Server - STA Mode
  modified on 25 MAy 2019
  by Mohammadreza Akbari @ Electropeak
  Home
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Tenda_33DD70";  // Enter your SSID here
const char* password = "Nish&Chin0326";  //Enter your Password here

const int pulse = 34;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
  //  The on-board Arduion LED
            

WebServer serve(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {
  Serial.begin(9600);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  serve.on("/", handle_root);

  serve.begin();
  Serial.println("HTTP server started");
  delay(100); 
}

void loop() {
  serve.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Web Server with ESP32 - Station Mode &#128522;</h1>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
  serve.send(200, "text/html", HTML);
}
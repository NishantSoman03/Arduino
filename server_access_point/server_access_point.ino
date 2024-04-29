/*
  ESP32 Web Server - AP Mode
  modified on 25 MAy 2019
  by Mohammadreza Akbari @ Electropeak
  Home
*/

#include <WiFi.h>
#include <WebServer.h>

// SSID & Password
const char* ssid = "Electripeak";  // Enter your SSID here
const char* password = "123456789";  //Enter your Password here

// IP Address details
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

const char* ss = "Tata play(301-4) 2.4G";  // Enter your SSID here
const char* pwd = "Tatafiber";  //Enter your Password here
WebServer serve(80);  // Object of WebServer(HTTP port, 80 is defult) 
//this is for wifi conection


void setup() {
  Serial.begin(9600);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ss, pwd);

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
  // Create SoftAP
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);


  Serial.print("Connect to My access point: ");
  Serial.println(ssid);

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}
int x;
void loop() {
  server.handleClient();
  serve.handleClient();
  delay(100);
}

// HTML & CSS contents which display on web server
/*String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Web Server with ESP32 - AP Mode &#128522;</h1>\
<br>\
</body>\
</html>";*/
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1>My First Web Server with ESP32 - AP Mode &#128522;</h1>\
<br>\
<form>\
  <input type=\"checkbox\" name=\"vehicle1\" value=\"Bike\">\
  <label for=\"vehicle1\"> I have a bike</label><br>\
  <input type=\"checkbox\" name=\"vehicle2\" value=\"Car\">\
  <label for=\"vehicle2\"> I have a car</label><br>\
  <input type=\"checkbox\" name=\"vehicle3\" value=\"Boat\" checked>\
  <label for=\"vehicle3\"> I have a boat</label><br><br>\
  <input type=\"submit\" value=\"Submit\">\
</form>\
</body>\
</html>";


// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
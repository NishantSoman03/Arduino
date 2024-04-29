#include <SoftwareSerial.h>

#define RO 10
#define DI 11
#define DE_RE 12

SoftwareSerial master(RO, DI);

void setup() {
  Serial.begin(9600); // Initialize hardware serial
  master.begin(9600); // Initialize software serial
  pinMode(DE_RE, OUTPUT);
  digitalWrite(DE_RE, HIGH);
  Serial.println("Master node is ready");
}

void loop() {
  // Read sensor data
  int sensorValue = analogRead(A0); // Example: Read from analog pin A0

  // Send BPM data to ESP32
  master.write(sensorValue); // Send BPM value
  //master.write("\n"); // Send BPM value
  delay(1000); // Adjust delay based on your sensor sampling rate
}

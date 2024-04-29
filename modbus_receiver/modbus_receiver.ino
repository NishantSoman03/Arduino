# include <SoftwareSerial.h>
#define RO 16
#define DI 17

SoftwareSerial slave (RO,DI);
void setup() { 
  // put your setup code here, to run once:
  Serial.begin(115200);
  slave.begin(9600);
  //pinMode(DE_RE,OUTPUT);
  //digitalWrite(DE_RE,HIGH);
  Serial.println("Slave node is ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (slave.available()){
    int pulse = slave.read();
    int bpm = map(pulse, 0, 255, 60, 180); // Map the 10-bit sensor value to BPM range (60-180 BPM)
    Serial.println(bpm);
  }
}
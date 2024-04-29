#include <Servo.h>
int servoPin = 9;
Servo servo;
int angle = 0;  // servo position in degrees

void setup() {
    servo.attach(servoPin);
}

void loop() {

    // scan from 0 to 180 degrees
    for(angle = 0; angle < 360; angle++) {
        servo.write(angle);
        delay(15);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 360; angle > 0; angle--) {
        servo.write(angle);
        delay(15);
    }
}




xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int const PULSE_SENSOR_PIN = 0;   // 'S' Signal pin connected to A0

int Signal;                // Store incoming ADC data. Value can range from 0-1024
int Threshold = 550;       // Determine which Signal to "count as a beat" and which to ignore.

void setup() {
	pinMode(LED_BUILTIN,OUTPUT);  // Built-in LED will blink to your heartbeat
}

void loop() {

	Signal = analogRead(PULSE_SENSOR_PIN); // Read the sensor value

	Serial.println(Signal);                // Send the signal value to serial plotter

	if(Signal > Threshold){                // If the signal is above threshold, turn on the LED
		digitalWrite(LED_BUILTIN,HIGH);
	} else {
		digitalWrite(LED_BUILTIN,LOW);     // Else turn off the LED
	}
	delay(10);
}
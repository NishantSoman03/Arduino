#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <PulseSensorPlayground.h>
//................................................................................................
int servoPin = 9;
Servo servo;
int angle = 0;  // servo position in degrees
//................................................................................................
int const PULSE_SENSOR_PIN = 0;   // 'S' Signal pin connected to A0

int Signal;                // Store incoming ADC data. Value can range from 0-1024
int Threshold = 550;       // Determine which Signal to "count as a beat" and which to ignore.
//................................................................................................
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
Adafruit_MPU6050 mpu;
void setup(void) {
	Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  pinMode(13,OUTPUT);
  servo.attach(servoPin);

	// Try to initialize!
	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
		  delay(10);
		}
	}
	Serial.println("MPU6050 Found!");

	// set accelerometer range to +-8G
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

	// set gyro range to +- 500 deg/s
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	// set filter bandwidth to 21 Hz
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	delay(1000);
}

void loop() {
	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	/* Print out the values */
	Serial.print("Accn X: ");
	Serial.print(a.acceleration.x);
	Serial.print("  Y: ");
	Serial.print(a.acceleration.y);
	Serial.print(", Z: ");
	Serial.print(a.acceleration.z);
	Serial.println(" m/s^2");

	Serial.print("Rotation X: ");
	Serial.print(g.gyro.x);
	Serial.print(", Y: ");
	Serial.print(g.gyro.y);
	Serial.print(", Z: ");
	Serial.print(g.gyro.z);
	Serial.println(" rad/s");

	Serial.print("Temperature: ");
	Serial.print(temp.temperature);
	Serial.println(" degC");

	Serial.println("");
	delay(100);

  Signal = analogRead(PULSE_SENSOR_PIN); // Read the sensor value

	lcd.setCursor(0,0);
  lcd.print("A heart just Happened!");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BPM : ");
  lcd.print(Signal);

	if(Signal > Threshold){                // If the signal is above threshold, turn on the LED
		for(angle = 0; angle < 360; angle++) {
        servo.write(angle);
        delay(15);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 360; angle > 0; angle--) {
        servo.write(angle);
        delay(15);
    }
	} else {
    lcd.setCursor(0,1);
		lcd.print("Normal Range");
	}
	delay(100);
}

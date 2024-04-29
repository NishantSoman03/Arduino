#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//............................................................................................................
int const PULSE_SENSOR_PIN = 0;   // 'S' Signal pin connected to A0
int Signal;                // Store incoming ADC data. Value can range from 0-1024
int Threshold = 550;       // Determine which Signal to "count as a beat" and which to ignore.
//............................................................................................................
Adafruit_MPU6050 mpu;

void setup(void) {
  lcd.begin(16,2);
  lcd.clear();
	Serial.begin(9600);
  pinMode(13,OUTPUT);  // Built-servo motor will rotate after threshold heartbeat

	// Try to initialize!
	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
		  delay(10);
		}
	}

	// set accelerometer range to +-8G
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

	// set gyro range to +- 500 deg/s
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	// set filter bandwidth to 21 Hz
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

	delay(100);
}

void loop() {
	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	/* Print out the values */
	Serial.print(a.acceleration.x);
	Serial.print(",");
	Serial.print(a.acceleration.y);
	Serial.print(",");
	Serial.print(a.acceleration.z);
	Serial.print(", ");
	Serial.print(g.gyro.x);
	Serial.print(",");
	Serial.print(g.gyro.y);
	Serial.print(",");
	Serial.print(g.gyro.z);
	Serial.println("");

	delay(1000);
}
/*const int soil = A0;
int moist;
void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  moist = analogRead(soil);
  int soilmois = map(moist, 0, 1023, 0, 100);
  Serial.print(moist);
  delay(1000);
}*/
// Define the analog pin for the soil moisture sensor
const int soilMoisturePin = A0;
int analogOutPin = 9;
void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the soil moisture value
  double soilMoistureValue = analogRead(soilMoisturePin);

  // Convert the analog value to percentage (assuming a range of 0-1023)
  //int moisturePercentage = map(soilMoistureValue, 1023,0, 0, 100);
  double smois = 1-(soilMoistureValue/1023);
  double moisturePerc = (smois/0.6);
  
  // Print the soil moisture value and percentage
  Serial.print("Soil Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print("\t Moisture Percentage: ");
  Serial.println(moisturePerc*100);

  // Add a delay to make readings more readable
  delay(1980);
 // The value to be outputted (0 to 255)
  // Generate a ramp signal from 0 to 255 and back to 0 // Write the value to the analog output pin
  delay(10); // Wait for 10 milliseconds
  if (moisturePerc >= 50)
        analogWrite(analogOutPin, 0);
  else
        analogWrite(analogOutPin, 1);
  }
  //for (outputValue = 255; outputValue >= 0; outputValue--) {
    //analogWrite(analogOutPin, outputValue); // Write the value to the analog output pin
    //delay(10); // Wait for 10 milliseconds

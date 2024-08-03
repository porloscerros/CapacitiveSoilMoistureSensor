/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.

  Capacitive Soil Moisture Sensor
  https://arduino-tutorials.net/tutorial/capacitive-soil-moisture-sensor-arduino
*/
#define AOUT_PIN A0
const int dry = 595; // value for dry sensor
const int wet = 250; // value for wet sensor
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);

  int sensorVal = analogRead(AOUT_PIN);
  Serial.print("Moisture: ");
  Serial.println(sensorVal);

  int percentageHumididy = map(sensorVal, wet, dry, 100, 0); 
  Serial.print(percentageHumididy);
  Serial.println("%");

  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

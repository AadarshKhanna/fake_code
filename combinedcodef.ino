// Libraries
#include <Wire.h>
#include <Adafruit_MLX90614.h>

// Constants
#define sensorAnalog A1   // Analog pin connected to the MQ-3 sensor
#define LED 3             // Digital pin connected to the LED
#define buzzer 4          // Digital pin connected to the buzzer
#define threshold 500     // Alcohol level threshold (adjust as needed)

// Global Variables
Adafruit_MLX90614 mlx;

// Setup function
void setup() {
  Serial.begin(9600);    // Initialize serial communication
  pinMode(LED, OUTPUT);  // Set the LED pin as output
  pinMode(buzzer, OUTPUT); // Set the buzzer pin as output
  pinMode(sensorAnalog, INPUT); // Set the MQ-3 sensor pin as input

  Serial.println("Adafruit MLX90614 test");

  mlx.begin();               // Initializing the MLX90614 sensor
}

// Main loop
void loop() {
  // Read alcohol level from the MQ-3 sensor
  int alcoholLevel = analogRead(sensorAnalog);
  Serial.print("Alcohol Level: ");
  Serial.println(alcoholLevel);

  // Read temperature from the MLX90614 sensor
  Serial.print("Ambient = ");
  Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = ");
  Serial.print(mlx.readObjectTempF());
  Serial.println("*F");

  // Generate random value between 80 and 90 for pulse sensor reading
  int pulseValue = random(80, 91);
  Serial.print("Pulse Sensor: ");
  Serial.println(pulseValue);

  // Check if alcohol level is above threshold
  if (alcoholLevel > threshold) {
    digitalWrite(LED, HIGH);    // Turn on the LED
    digitalWrite(buzzer, HIGH); // Turn on the buzzer
  } else {
    digitalWrite(LED, LOW);     // Turn off the LED
    digitalWrite(buzzer, LOW);  // Turn off the buzzer
  }

  delay(2000);  // Wait for 2 seconds before taking another reading
}

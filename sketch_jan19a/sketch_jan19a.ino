// Include necessary libraries
#include <Wire.h>
#include "rgb_lcd.h"

// Define Grove sensor pins (use matching Grove Base Shield ports)
#define TOUCH_SENSOR_PIN 2       // D2
#define TEMP_SENSOR_PIN A0       // A0
#define BUTTON_PIN 3             // D3
#define ROTARY_PIN A1            // A1
#define VIBRATION_SENSOR_PIN 4   // D4
#define SOUND_SENSOR_PIN A2      // A2
#define LIGHT_SENSOR_PIN A3      // A3
#define BUZZER_PIN 5             // D5
#define LED_BLUE_PIN 6           // D6
#define LED_GREEN_PIN 7          // D7
#define LED_RED_PIN 8            // D8

// Create an instance of the RGB LCD
rgb_lcd lcd;

// Thresholds for alerts
float tempThreshold = 220;  // Celsius
int lightThreshold = 500;    // Light intensity
int soundThreshold = 200;    // Sound intensity

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up pins
  pinMode(TOUCH_SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);

  // Initialize the RGB LCD
  lcd.begin(16, 2); // 16 columns and 2 rows
  lcd.setRGB(0, 0, 255); // Default backlight color (blue)

  // Welcome message
  lcd.print("Grove Sensors");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read sensor values
  int tempSensorValue = analogRead(TEMP_SENSOR_PIN);
  float voltage = tempSensorValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0; // Convert to Celsius
  int lightValue = analogRead(LIGHT_SENSOR_PIN);
  int soundValue = analogRead(SOUND_SENSOR_PIN);
  int rotaryValue = analogRead(ROTARY_PIN);
  int touchState = digitalRead(TOUCH_SENSOR_PIN);
  int buttonState = digitalRead(BUTTON_PIN);
  int vibrationState = digitalRead(VIBRATION_SENSOR_PIN);

  // Display temperature and light values on the LCD
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temperature-200, 1); //200 extra
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightValue);

  // Alerts and actions
  // Temperature Alert
  if (temperature-200 > tempThreshold) { //200 extra
    digitalWrite(LED_RED_PIN, HIGH);
    Serial.println("High Temperature Alert!");
  } else {
    digitalWrite(LED_RED_PIN, LOW);
  }

  // Light Alert
  if (lightValue > lightThreshold) {
    digitalWrite(LED_BLUE_PIN, HIGH);
    Serial.println("High Light Alert!");
  } else {
    digitalWrite(LED_BLUE_PIN, LOW);
  }

  // Sound Alert
  if (soundValue > soundThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("High Sound Alert!");
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Vibration Detection
  if (vibrationState == HIGH) {
    digitalWrite(LED_GREEN_PIN, HIGH);
    Serial.println("Vibration Detected!");
  } else {
    digitalWrite(LED_GREEN_PIN, LOW);
  }

  // Adjust thresholds using the rotary sensor
  tempThreshold = map(rotaryValue, 0, 1023, 20, 50);   // Temp threshold (20-50°C)
  lightThreshold = map(rotaryValue, 0, 1023, 300, 1000); // Light threshold (300-1000)
  soundThreshold = map(rotaryValue, 0, 1023, 300, 800);  // Sound threshold (300-800)

  // Touch sensor as a manual reset
  if (touchState == HIGH) {
    Serial.println("Touch Detected: Resetting Alerts.");
    digitalWrite(LED_RED_PIN, LOW);
    digitalWrite(LED_BLUE_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Button to display thresholds
  if (buttonState == HIGH) {
    lcd.clear();
    lcd.print("TThr: ");
    lcd.print(tempThreshold, 1);
    lcd.setCursor(0, 1);
    lcd.print("LThr: ");
    lcd.print(lightThreshold);
    delay(2000);
  }

  // Delay for stability
  delay(2000);
}

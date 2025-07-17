const int potPin = 14;   // Potentiometer connected to analog pin A0 (or GPIO 14 on some boards)
const int ledPin = 12;   // LED connected to digital pin 12 (PWM capable)

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int potValue = analogRead(potPin);  // Read potentiometer value (0–1023)
  int percentage = map(potValue, 0, 1023, 0, 100);  // Convert to percentage (0%–100%)
  int pwmValue = map(potValue, 0, 1023, 0, 255);   // Map to PWM range (0–255)

  analogWrite(ledPin, pwmValue);  // Set LED brightness using PWM

  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print(" | Percentage: ");
  Serial.print(percentage);
  Serial.println("%");

  delay(200);  // Small delay for readability
}

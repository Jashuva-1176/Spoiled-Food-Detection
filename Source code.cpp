const int buzzerPin = D1;          // Buzzer pin
const int mq2Pin = A0;             // Gas sensor MQ2 analog pin

const int threshold = 300;         // Set a realistic threshold value for gas detection

void setup() {
  Serial.begin(9600);              // Initialize serial communication
  
  pinMode(buzzerPin, OUTPUT);      // Set buzzer pin as output
  pinMode(mq2Pin, INPUT);          // Set MQ2 sensor pin as input
}

void loop() {
  int gasValue = analogRead(mq2Pin);  // Read gas sensor value

  Serial.print("Gas value: ");
  Serial.println(gasValue);           // Print gas value to serial monitor

  if (gasValue > threshold) {
    digitalWrite(buzzerPin, HIGH);    // Activate the buzzer
    delay(2000);                      // Buzzer on for 1 second
  } else {
    digitalWrite(buzzerPin, LOW);     // Ensure buzzer is off
  }

  delay(1000);                        // Wait for 1 second before next reading
}

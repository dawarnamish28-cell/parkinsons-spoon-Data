// === Pin Configuration ===
const int sensorPin = A0;   // Soil moisture sensor analog pin
const int relayPin  = 8;    // Relay control pin (D8)

// === Moisture Threshold ===
// Adjust after calibration
int threshold = 700;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);

  // Relay OFF initially
  digitalWrite(relayPin, LOW);

  Serial.println("Automatic Soil Irrigation System (Reversed Logic) Initialized");
}

void loop() {
  int moistureValue = analogRead(sensorPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  // Reversed logic:
  // If soil is dry -> turn OFF pump
  // If soil is moist -> turn ON pump
  if (moistureValue > threshold) {
    Serial.println("Soil is dry. Turning ON water pump.");
    digitalWrite(relayPin, LOW);   // Turn relay OFF
  } else {
    Serial.println("Soil is moist. Turning OFF water pump.");
    digitalWrite(relayPin, HIGH);  // Turn relay ON
  }

  delay(2000);
}

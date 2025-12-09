/*
  ------------------------------------------------------------
  SMART STREET LIGHT AUTOMATION – LDR + RELAY
  Project by: Onkar (Ahilyanagar – Pipeline Road, Dyaneshwar Nagar, Savedi)
  ------------------------------------------------------------
  FUNCTION:
    • Reads brightness using an LDR (Light Dependent Resistor)
    • Automatically switches ON street lights when ambient light is low
    • Automatically switches OFF lights during daytime
  ------------------------------------------------------------
  HARDWARE:
    • LDR connected to A0 (with 10k Ohm resistor)
    • Relay module connected to digital pin 7
    • Relay controls AC streetlight line (USE CAUTION)
  ------------------------------------------------------------
  SAFETY:
    • Relay should be optocoupled (recommended)
    • AC wiring must be handled ONLY by a certified electrician
  ------------------------------------------------------------
*/

int ldrPin = A0;        // Analog input from LDR
int relayPin = 7;       // Digital output to relay
int threshold = 520;    // Adjust based on environment (300–700 range)

// Optional: smoothing filter
int smoothValue(int pin) {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / 10;
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Assume LOW = lights OFF
  Serial.begin(9600);

  Serial.println("Smart Street Light Automation Started");
  Serial.println("------------------------------------");
}

void loop() {
  int ldrValue = smoothValue(ldrPin); // read filtered value

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // NIGHT or DARK CONDITIONS → TURN LIGHTS ON
  if (ldrValue < threshold) {
    digitalWrite(relayPin, HIGH); // turn ON lights
    Serial.println("Street Lights: ON");
  } else {
    digitalWrite(relayPin, LOW);  // turn OFF lights
    Serial.println("Street Lights: OFF");
  }

  Serial.println("------------------------------------");
  delay(500);
}

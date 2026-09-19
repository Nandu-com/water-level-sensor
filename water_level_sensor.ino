const byte LOW_PROBE = 2;
const byte MEDIUM_PROBE = 3;
const byte HIGH_PROBE = 4;

const byte GREEN_LED = 8;
const byte YELLOW_LED = 9;
const byte RED_LED = 10;
const byte BUZZER = 11;

void setup() {
  pinMode(LOW_PROBE, INPUT_PULLUP);
  pinMode(MEDIUM_PROBE, INPUT_PULLUP);
  pinMode(HIGH_PROBE, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);
}

void loop() {
  // With INPUT_PULLUP:
  // LOW means that the probe is touching water.
  bool lowLevel = digitalRead(LOW_PROBE) == LOW;
  bool mediumLevel = digitalRead(MEDIUM_PROBE) == LOW;
  bool highLevel = digitalRead(HIGH_PROBE) == LOW;

  digitalWrite(GREEN_LED, lowLevel);
  digitalWrite(YELLOW_LED, mediumLevel);
  digitalWrite(RED_LED, highLevel);

  if (highLevel) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("HIGH WATER LEVEL - ALARM");
  } else {
    digitalWrite(BUZZER, LOW);

    if (mediumLevel) {
      Serial.println("MEDIUM WATER LEVEL");
    } else if (lowLevel) {
      Serial.println("LOW WATER LEVEL");
    } else {
      Serial.println("NO WATER DETECTED");
    }
  }

  delay(500);
}

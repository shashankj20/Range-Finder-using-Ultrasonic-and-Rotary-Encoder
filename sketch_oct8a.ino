#define TRIG_PIN 7
#define ECHO_PIN 6
#define ROTARY_CLK_PIN 9
#define ROTARY_DT_PIN 10
#define RED_LED_PIN 2
#define GREEN_LED_PIN 3
#define BLUE_LED_PIN 4
#define BUZZER_PIN 8 // Define the buzzer pin

long duration;
int distance;
int minDistance = 10; // Initial detection range (in cm)
int maxDistance = 40; // Maximum detection range (in cm)
int encoderValue = minDistance; // Start with the initial range
int lastEncoderValue = LOW; // Initialize the lastEncoderValue
int lastEncoderChange = LOW; // Initialize the lastEncoderChange
bool encoderInUse = false; // Flag to indicate rotary encoder use

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ROTARY_CLK_PIN, INPUT_PULLUP);
  pinMode(ROTARY_DT_PIN, INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as an output
  Serial.begin(9600);
}

void loop() {
  // Read rotary encoder to expand or compress the detection range.
  int encoderReading = digitalRead(ROTARY_CLK_PIN);
  if (encoderReading != lastEncoderValue) {
    encoderInUse = true; // Rotary encoder is being turned
    if (digitalRead(ROTARY_DT_PIN) != encoderReading) {
      if (lastEncoderChange != encoderReading) {
        encoderValue += 5; // Increase the range by 5 cm (adjust as needed).
      }
    } else {
      if (lastEncoderChange != encoderReading) {
        encoderValue -= 5; // Decrease the range by 5 cm (adjust as needed).
      }
    }
    
    if (encoderValue < minDistance) {
      encoderValue = minDistance; // Limit to the minimum range.
    } else if (encoderValue > maxDistance) {
      encoderValue = maxDistance; // Limit to the maximum range.
    }
    
    lastEncoderChange = encoderReading;
    lastEncoderValue = encoderReading;
  } else {
    encoderInUse = false; // Rotary encoder is not being turned
  }
  
  // Calculate distance using the HCSR04 sensor.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;  // Calculate distance in centimeters.

  // Update LED colors based on distance and detection range.
  if (distance <= encoderValue) {
    digitalWrite(RED_LED_PIN, HIGH);  // Object detected, turn on red LED.
    digitalWrite(GREEN_LED_PIN, LOW);  // Turn off green LED.
    
    // Turn on the buzzer to produce a sound.
    tone(BUZZER_PIN, 1000); // Adjust the frequency as needed.
  } else {
    digitalWrite(RED_LED_PIN, LOW);  // No object detected, turn off red LED.
    digitalWrite(GREEN_LED_PIN, HIGH);  // Turn on green LED.
    
    // Turn off the buzzer.
    noTone(BUZZER_PIN);
  }

  // Control the blue LED based on rotary encoder use.
  digitalWrite(BLUE_LED_PIN, encoderInUse ? HIGH : LOW);

  // Optional: Print the current distance and detection range to Serial Monitor.
  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.print(" | Detection Range (cm): ");
  Serial.println(encoderValue);
  delay(100); // Delay for stability, adjust as needed.
}

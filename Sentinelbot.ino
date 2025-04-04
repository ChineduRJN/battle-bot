#include <SoftwareSerial.h>
#include <IBusBM.h>

SoftwareSerial ibusSerial(9, 11); // RX on pin 9, TX on pin 11
IBusBM ibus;

// Pin definitions for Motor 1 (Left)
#define R_EN1 33
#define L_EN1 32
#define RPWM1 5
#define LPWM1 7

// Pin definitions for Motor 2 (Right)
#define R_EN2 28
#define L_EN2 29
#define RPWM2 3
#define LPWM2 2

void setup() {
  Serial.begin(115200);
  ibus.begin(Serial);
  Serial.println("IBusBM Initialized");

  // Set motor control pins as output
  pinMode(R_EN1, OUTPUT);
  pinMode(L_EN1, OUTPUT);
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  
  // Enable both motors
  digitalWrite(R_EN1, HIGH);
  digitalWrite(L_EN1, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);
  
  Serial.println("Motor pins initialized and enabled.");
}

void loop() {
  // Read iBus signal for steering
  int steering = ibus.readChannel(2); // Read channel 2
  Serial.print("Raw Steering Value: ");
  Serial.println(steering);
  
  // Check if steering value is valid
  if (steering > 0) {
    // Map the steering values to -255 to 255 range
    steering = map(steering, 1000, 2000, -255, 255);
    Serial.print("Mapped Steering Value: ");
    Serial.println(steering);

    // Control logic for motors based on steering
    int motor1Speed = 100 + steering; // Fixed throttle + steering
    int motor2Speed = 100 - steering; // Fixed throttle - steering

    // Debugging motor speeds
    Serial.print("Motor 1 Speed: ");
    Serial.println(motor1Speed);
    Serial.print("Motor 2 Speed: ");
    Serial.println(motor2Speed);

    // Apply deadzone to eliminate small input noise
    if (abs(motor1Speed) < 30) motor1Speed = 0;
    if (abs(motor2Speed) < 30) motor2Speed = 0;

    // Constrain motor speeds within valid range
    motor1Speed = constrain(motor1Speed, -255, 255);
    motor2Speed = constrain(motor2Speed, -255, 255);

    // Control Motor 1 (Left)
    if (motor1Speed > 0) {
      analogWrite(RPWM1, motor1Speed); // Forward
      analogWrite(LPWM1, 0);
      Serial.println("Motor 1 moving forward");
    } else if (motor1Speed < 0) {
      analogWrite(LPWM1, -motor1Speed); // Backward
      analogWrite(RPWM1, 0);
      Serial.println("Motor 1 moving backward");
    } else {
      analogWrite(RPWM1, 0); // Stop
      analogWrite(LPWM1, 0);
      Serial.println("Motor 1 stopped");
    }

    // Control Motor 2 (Right)
    if (motor2Speed > 0) {
      analogWrite(RPWM2, motor2Speed); // Forward
      analogWrite(LPWM2, 0);
      Serial.println("Motor 2 moving forward");
    } else if (motor2Speed < 0) {
      analogWrite(LPWM2, -motor2Speed); // Backward
      analogWrite(RPWM2, 0);
      Serial.println("Motor 2 moving backward");
    } else {
      analogWrite(RPWM2, 0); // Stop
      analogWrite(LPWM2, 0);
      Serial.println("Motor 2 stopped");
    }
  } else {
    Serial.println("Steering value is 0, no movement.");
  }

  delay(100); // Small delay for stability
}

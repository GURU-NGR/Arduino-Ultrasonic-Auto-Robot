#include <Servo.h>

// Ultrasonic sensor pins
const int trigPin = 13;   // Trigger pin of ultrasonic sensor
const int echoPin = 12;   // Echo pin of ultrasonic sensor

// Servo motor pin
const int servoPin = 11;
Servo servo;

// Motor control pins
const int ENB = 3; // Right motor speed control
const int LN4 = 2; // Right motor backward
const int LN3 = 4; // Right motor forward
const int LN2 = 5; // Left motor backward
const int LN1 = 7; // Left motor forward
const int ENA = 6; // Left motor speed control

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("Robot car initialized");

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set motor control pins
  pinMode(ENA, OUTPUT);
  pinMode(LN1, OUTPUT);
  pinMode(LN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(LN3, OUTPUT);
  pinMode(LN4, OUTPUT);

  // Attach servo motor
  servo.attach(servoPin);
  servo.write(90); // Start with the servo facing straight
}

void loop() {
  // Measure distances in three directions
  int distStraight = measureDistance(90);  // Straight
  int distLeft = measureDistance(0);       // Left
  int distRight = measureDistance(180);    // Right

  // Log distances
  Serial.print("Straight: ");
  Serial.print(distStraight);
  Serial.print(" cm, Left: ");
  Serial.print(distLeft);
  Serial.print(" cm, Right: ");
  Serial.print(distRight);
  Serial.println(" cm");

  // Decide direction to move based on max distance
  if (distStraight > distLeft && distStraight > distRight) {
    moveStraight();
  } else if (distLeft > distRight) {
    turnLeft();
  } else {
    turnRight();
  }

  delay(100); // Small delay for stability
}

// Function to measure distance using ultrasonic sensor
int measureDistance(int angle) {
  servo.write(angle);          // Rotate servo to desired angle
  delay(500);                  // Wait for servo to move
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH); // Read echo pulse duration
  int distance = duration * 0.034 / 2;    // Convert to cm
  return distance;
}

// Motor control functions
void moveStraight() {
  Serial.println("Moving straight");
  digitalWrite(LN1, HIGH);
  digitalWrite(LN2, LOW);
  digitalWrite(LN3, LOW);
  digitalWrite(LN4, HIGH);
  analogWrite(ENA, 200); // Left motor speed
  analogWrite(ENB, 200); // Right motor speed
}

void turnLeft() {
  Serial.println("Turning left");
  digitalWrite(LN1, HIGH);
  digitalWrite(LN2, LOW);
  digitalWrite(LN3, HIGH);
  digitalWrite(LN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  delay(500); // Time to complete turn
  stopMotors();
}

void turnRight() {
  Serial.println("Turning right");
  digitalWrite(LN1, LOW);
  digitalWrite(LN2, HIGH);
  digitalWrite(LN3, LOW);
  digitalWrite(LN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  delay(500); // Time to complete turn
  stopMotors();
}

void stopMotors() {
  Serial.println("Stopping motors");
  digitalWrite(LN1, LOW);
  digitalWrite(LN2, LOW);
  digitalWrite(LN3, LOW);
  digitalWrite(LN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

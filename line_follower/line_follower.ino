// Line Following Robot - Tinkercad simulation
// Buttons act as line sensors: pressed (LOW) = sensor sees the black line

// Sensor Inputs (Buttons)
const int LEFT_SENSOR  = 2;
const int RIGHT_SENSOR = 3;

// Left Motor Control Pins
const int MOTOR_L_F = 4;
const int MOTOR_L_B = 5;

// Right Motor Control Pins
const int MOTOR_R_F = 6;
const int MOTOR_R_B = 7;

void setup() {
  pinMode(LEFT_SENSOR, INPUT_PULLUP);
  pinMode(RIGHT_SENSOR, INPUT_PULLUP);

  pinMode(MOTOR_L_F, OUTPUT);
  pinMode(MOTOR_L_B, OUTPUT);
  pinMode(MOTOR_R_F, OUTPUT);
  pinMode(MOTOR_R_B, OUTPUT);
}

void loop() {
  int left  = digitalRead(LEFT_SENSOR);
  int right = digitalRead(RIGHT_SENSOR);

  if (left == HIGH && right == HIGH) {
    // Both on white surface -> drive straight forward
    moveMotors(HIGH, LOW, HIGH, LOW);
  }
  else if (left == LOW && right == HIGH) {
    // Left sensor on line -> turn left (left motor stops)
    moveMotors(LOW, LOW, HIGH, LOW);
  }
  else if (left == HIGH && right == LOW) {
    // Right sensor on line -> turn right (right motor stops)
    moveMotors(HIGH, LOW, LOW, LOW);
  }
  else {
    // Both on line / finish line -> stop
    moveMotors(LOW, LOW, LOW, LOW);
  }
}

void moveMotors(int l1, int l2, int r1, int r2) {
  digitalWrite(MOTOR_L_F, l1);
  digitalWrite(MOTOR_L_B, l2);
  digitalWrite(MOTOR_R_F, r1);
  digitalWrite(MOTOR_R_B, r2);
}

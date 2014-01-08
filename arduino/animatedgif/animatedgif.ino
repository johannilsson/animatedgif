// Pins
int potPinIndex = 0;
int motorIndex = 1;
int breakIndex = 2;
int speedIndex = 2;

int motorPinsA[] = {2, 12, 9, 3};
int motorPinsB[] = {3, 13, 8, 11};

void setup() {
  Serial.begin(9600);
 
  pinMode(motorPinsA[motorIndex], OUTPUT); // Init motor A
  pinMode(motorPinsA[breakIndex], OUTPUT); // Init brake A
  digitalWrite(motorPinsA[breakIndex], LOW); // Disengage the brake for A

  pinMode(motorPinsB[motorIndex], OUTPUT); // Init motor B
  pinMode(motorPinsB[breakIndex], OUTPUT); // Init brake B
  digitalWrite(motorPinsB[breakIndex], LOW); // Disengage the brake for B
}

void loop() {
  handleMotor(motorPinsA);
  handleMotor(motorPinsA);
  delay(1);
}

void handleMotor(int motorPins[]) {
  int motorSpeed = map(analogRead(motorPins[potPinIndex]), 0, 1023, 0, 255);

  digitalWrite(motorPins[motorIndex], HIGH); // Go forward
  analogWrite(motorPins[speedIndex], motorSpeed); // Set speed
}



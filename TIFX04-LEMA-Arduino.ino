// Declare constants for what is connected to which pin on the arduino
// The pin name is printed on the Arduino Board

// Light sensors
const int SENSOR1   = A0;
const int SENSOR2   = A1;
const int SENSOR3   = A2;
const int SENSOR4   = A3;

// Power electronics
const int CHG1      = A4;   // Best not to use TX and RX pins 0 and 1
const int TRIG1     = A5;   // May cause unexpected behavior.
const int CHG2      = 2;
const int TRIG2     = 3;
const int CHG3      = 4;
const int TRIG3     = 5;
const int CHG4      = 6;
const int TRIG4     = 7;
const int CHG5      = 8;
const int TRIG5     = 9;

// I/O
const int BTN       = 10;
const int DMM       = 11;
const int LED       = 13;  // Built in LED


// This code runs once when the Arduino starts
void setup() {
  
  // --- Declare I/O type of pins --- //

  // Light sensors
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);

  // Power electronics
  pinMode(CHG1,  OUTPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(CHG2,  OUTPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(CHG3,  OUTPUT);
  pinMode(TRIG3, OUTPUT);
  pinMode(CHG4,  OUTPUT);
  pinMode(TRIG4, OUTPUT);
  pinMode(CHG5,  OUTPUT);
  pinMode(TRIG5, OUTPUT);
  
  // I/O
  pinMode(BTN, INPUT_PULLUP);
  pinMode(DMM, OUTPUT);
  pinMode(LED, OUTPUT);


  // --- Set initial value of outputs --- //

  // Power electronics
  digitalWrite(CHG1,  LOW);
  digitalWrite(TRIG1, LOW);
  digitalWrite(CHG2,  LOW);
  digitalWrite(TRIG2, LOW);
  digitalWrite(CHG3,  LOW);
  digitalWrite(TRIG3, LOW);
  digitalWrite(CHG4,  LOW);
  digitalWrite(TRIG4, LOW);
  digitalWrite(CHG5,  LOW);
  digitalWrite(TRIG5, LOW);

  // I/O
  digitalWrite(DMM, LOW);
  digitalWrite(LED, LOW);
}

// Wait for a whole number of seconds and blink in the meantime
void delayBlink(int seconds) {
  if (seconds > 0) {
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    delayBlink(seconds-1);
  }
  
}

// This code runs over and over again
// Edit here to change behaviour of LEMA
void loop() {

  // Wait for pushbutton
  while(digitalRead(BTN)) {}

  // Charge 10 seconds
  digitalWrite(CHG1, HIGH);
  delayBlink(10);
  digitalWrite(CHG1, LOW);

  delay(500);

  // Turn on LED and DMM signal
  digitalWrite(LED, HIGH);
  digitalWrite(DMM, HIGH);

  // Wait 3 seconds
  delay(4000);

  // Fire first stage!
  digitalWrite(TRIG1, HIGH);

  // UNCOMMENT THIS CODE WHEN USING 2 PAIRS OF COILS
  /*
  // Wait for sensor to trigger
  while(!digitalRead(SENSOR1)) {}
  // Wait for sensor to untrigger
  while(digitalRead(SENSOR1)) {}

  // Fire second stage!
  digitalWrite(TRIG2, HIGH);
  */

  // Wait 2 seconds to make sure capacitors are discharged
  delay(2000);

  // Turn off LED and DMM signal
  digitalWrite(LED, LOW);
  digitalWrite(DMM, LOW);

  // Turn off all thyristors
  digitalWrite(TRIG1, LOW);
  digitalWrite(TRIG2, LOW);
  digitalWrite(TRIG3, LOW);
  digitalWrite(TRIG4, LOW);
  digitalWrite(TRIG5, LOW);

}

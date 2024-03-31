/** 
Author: Gabriel Tindi
This code is written in Arduino programming language and is intended for an Arduino microcontroller.
*/

// Declare light variables and voice
String voice;
const int RED = 10;
const int GREEN = 9;
const int BLUE = 12;
const int YELLOW = 11;
const int RED0 = 5;
const int GREEN0 = 6;
const int BLUE0 = 8;
const int YELLOW0 = 7;
const int BLUE1 = 3;
const int YELLOW1 = 4;

// Create a function to turn on the lights
void RedOn(){
  digitalWrite(RED, HIGH);
  digitalWrite(RED0, HIGH);
}

void GreenOn(){
  digitalWrite(GREEN, HIGH);
  digitalWrite(GREEN0, HIGH);
}

void BlueOn(){
  digitalWrite(BLUE, HIGH);
  digitalWrite(BLUE0, HIGH);
  digitalWrite(BLUE1, HIGH);
}

void YellowOn(){
  digitalWrite(YELLOW, HIGH);
  digitalWrite(YELLOW0, HIGH);
  digitalWrite(YELLOW1, HIGH);
}
void AllOn() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED0, HIGH);
  digitalWrite(GREEN0, HIGH);
  digitalWrite(BLUE0, HIGH);
  digitalWrite(BLUE1, HIGH);
  digitalWrite(YELLOW0, HIGH);
  digitalWrite(YELLOW1, HIGH);
}

// Turns off the lights
void RedOff(){
  digitalWrite(RED, LOW);
  digitalWrite(RED0, LOW);
}

void GreenOff(){
  digitalWrite(GREEN, LOW);
  digitalWrite(GREEN0, LOW);
}

void BlueOff(){
  digitalWrite(BLUE, LOW);
  digitalWrite(BLUE0, LOW);
  digitalWrite(BLUE1, LOW);
}

void YellowOff(){
  digitalWrite(YELLOW, LOW);
  digitalWrite(YELLOW0, LOW);
  digitalWrite(YELLOW1, LOW);
}

void AllOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED0, LOW);
  digitalWrite(GREEN0, LOW);
  digitalWrite(BLUE0, LOW);
  digitalWrite(BLUE1, LOW);
  digitalWrite(YELLOW0, LOW);
  digitalWrite(YELLOW1, LOW);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         //  initializes the serial communication with a baud rate of 9600. 
  pinMode(RED, OUTPUT);       // sets the pin as output
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED0, OUTPUT);
  pinMode(GREEN0, OUTPUT);
  pinMode(BLUE0, OUTPUT);
  pinMode(YELLOW0, OUTPUT);
}

void loop() {
  // Check if there is data available on the serial port
  while (Serial.available()) {
    // Small delay to allow the serial buffer to fill
    delay(10);

    // Read a character from the serial port
    char c = Serial.read();

    // Print the received character
    Serial.println(c);

    // Break the loop if the newline character is encountered
    if (c == '\n')
      break;

    // Concatenate the received character to the 'voice' variable
    voice += c;
  }

  // Check if the 'voice' variable has received any data
  if (voice.length() > 0) {
    // Print the received voice command
    Serial.println("Received: " + voice);

    // Process different voice commands
    if (voice == "on" || voice == "all") {
      Serial.println("Turning all lights on!");
      AllOn();
    } else if (voice == "off" || voice == "all off") {
      Serial.println("Turning all lights off!");
      AllOff();
    } else if (voice == "red" || voice == "Red on") {
      Serial.println("Turning red lights on!");
      RedOn();
    } else if (voice == "red off") {
      Serial.println("Turning red lights off!");
      RedOff();
    } else if (voice == "green" || voice == "green on") {
      Serial.println("Turning green lights on!");
      GreenOn();
    } else if (voice == "green off") {
      Serial.println("Turning green lights off!");
      GreenOff();
    } else if (voice == "blue" || voice == "blue on") {
      Serial.println("Turning blue lights on!");
      BlueOn();
    } else if (voice == "blue off") {
      Serial.println("Turning blue lights off!");
      BlueOff();
    } else if (voice == "yellow" || voice == "yellow on") {
      Serial.println("Turning yellow lights on!");
      YellowOn();
    } else if (voice == "yellow off") {
      Serial.println("Turning yellow lights off!");
      YellowOff();
    }

    // Reset the 'voice' variable for the next iteration
    voice = "";
  }
}


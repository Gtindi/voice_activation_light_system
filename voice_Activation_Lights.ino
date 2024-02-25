/** 
Author: Gabriel Tindi
This code is written in Arduino programming language and is intended for an Arduino microcontroller.
*/

// Declare light variables and voice
String voice;
const int RED = 6;
const int GREEN = 5;
const int BLUE = 7;
const int YELLOW = 4;

// Create a function to turn on the lights
void RedOn(){
  digitalWrite(RED, HIGH);
}
void GreenOn(){
  digitalWrite(GREEN, HIGH);
}
void BlueOn(){
  digitalWrite(BLUE, HIGH);
}
void YellowOn(){
  digitalWrite(YELLOW, HIGH);
}
void AllOn() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(YELLOW, HIGH);
}

// Turns off the lights
void RedOff(){
  digitalWrite(RED, LOW);
}
void GreenOff(){
  digitalWrite(GREEN, LOW);
}
void BlueOff(){
  digitalWrite(BLUE, LOW);
}
void YellowOff(){
  digitalWrite(YELLOW, LOW);
}
void AllOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         //  initializes the serial communication with a baud rate of 9600. 
  pinMode(RED, OUTPUT);       // sets the pin as output
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
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


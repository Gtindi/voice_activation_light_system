String voice;
const int RED = 6;
const int GREEN = 5;
const int BLUE = 7;
const int YELLOW = 4;

void RedOn(){
  digitalWrite(RED, HIGH);
}
void RedOff(){
  digitalWrite(RED, LOW);
}

void GreenOn(){
  digitalWrite(GREEN, HIGH);
}
void GreenOff(){
  digitalWrite(GREEN, LOW);
}

void BlueOn(){
  digitalWrite(BLUE, HIGH);
}
void BlueOff(){
  digitalWrite(BLUE, LOW);
}

void YellowOn(){
  digitalWrite(YELLOW, HIGH);
}
void YellowOff(){
  digitalWrite(YELLOW, LOW);
}

void AllOn() {
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(YELLOW, HIGH);
}

void AllOff() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    Serial.println(c);
    if (c=='\n')
    break;
    voice += c;
  }
  if (voice.length() > 0) {
    Serial.println("Received: " + voice);
    if (voice == "on" || voice == "all") {
      Serial.println("Turning all lights on!");
      AllOn();
    }
    else if (voice == "off" || voice == "all off") {
      Serial.println("Turning all lights off!");
      AllOff();
    }
    else if (voice == "red" || voice == "Red on") {
      Serial.println("Turning red lights on!");
      RedOn();
    }
    else if (voice == "red off") {
      Serial.println("Turning red lights off!");
      RedOff();
    }
    else if (voice == "green" || voice == "green on") {
      Serial.println("Turning green lights on!");
      GreenOn();
    }
    else if (voice == "green off") {
      Serial.println("Turning green lights off!");
      GreenOff();
    }
    else if (voice == "blue" || voice == "blue on") {
      Serial.println("Turning blue lights on!");
      BlueOn();
    }
    else if (voice == "blue off") {
      Serial.println("Turning blue lights off!");
      BlueOff();
    }
    else if (voice == "yellow" || voice == "yellow on") {
      Serial.println("Turning yellow lights on!");
      YellowOn();
    }
    else if (voice == "yellow off") {
      Serial.println("Turning yellow lights off!");
      YellowOff();
    }
    voice ="";
  }

}

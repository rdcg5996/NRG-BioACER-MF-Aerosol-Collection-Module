// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 9;       // the number of the pushbutton pin
int shaketime = 300; 

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;                // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the pushbutton pin as an pull-up input
  // the pull-up input pin will be HIGH when the switch is open and LOW when the switch is closed.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// Loop for "Button is pressed" or "Button is released"
//void loop() {
//  // read the state of the switch/button:
//  currentState = digitalRead(BUTTON_PIN);
//
//  if(lastState == HIGH && currentState == LOW)
//    Serial.println("The button is pressed");
//  else if(lastState == LOW && currentState == HIGH)
//    Serial.println("The button is released");
//
//  // save the the last state
//  lastState = currentState;
//}

void loop(){
  currentState = digitalRead(BUTTON_PIN);

  // Only do shit when the button is pressed
  if(lastState == HIGH && currentState == LOW){
    Serial.print("The button was pressed! Shaking for ");
    Serial.print(shaketime);
    Serial.println(" milliseconds"); 
    delay(shaketime); 
    Serial.println("Shaking Complete!"); 
  }
  else if(lastState == LOW && currentState == HIGH){
    // Do nothing if the button is released
  }
  lastState = currentState;
}

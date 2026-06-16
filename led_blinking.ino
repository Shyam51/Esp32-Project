const int LED_PIN = 5;
const int PUSH_BUTTON = 3;
int ledstate = LOW;
int lastbuttonstate = LOW;


void setup(){
  pinMode(LED_PIN,OUTPUT);
  pinMode(PUSH_BUTTON,INPUT_PULLUP);
}
void loop(){
  bool buttonstate = digitalRead(PUSH_BUTTON);

  if(buttonstate == HIGH && lastbuttonstate == LOW){
  ledstate =!ledstate;
      digitalWrite(LED_PIN,ledstate);
  }
  lastbuttonstate = buttonstate;
    
  
}

  

/**
  Code to make the keyswitch tester come alive
*/


const int button = 2;

int buttonState = 0;
boolean wasPressed = false;

void setup(){
  
  Serial.begin(9600);
  pinMode(button,INPUT);
      
}

void loop(){
  
  
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    if(wasPressed == false){
      Serial.println("up");
      wasPressed = true;
    }
  } else {
//    Serial.println("down");
    wasPressed = false;
  }  
}


/**
  Code to make the keyswitch tester come alive
*/

// buttons
const int buttonOne = 2;
const int buttonTwo = 3;


// button states
int buttonOneState = 0;
int buttonTwoState = 0;

// meta
boolean wasPressed = false;

void setup(){
  
  Serial.begin(9600);
  pinMode(buttonOne,INPUT_PULLUP);
  pinMode(buttonTwo, INPUT);
      
}

void loop(){
  
  
  buttonOneState = digitalRead(buttonOne);
  
  buttonTwoState = digitalRead(buttonTwoState);
  
  // handle button one
  if(buttonOneState == LOW){
    if(wasPressed == false){
      Serial.println("1");
      wasPressed = true;
    }
  } else {
//    Serial.println("down");
    wasPressed = false;
  }  
  
  // handle button two
  if(buttonTwoState == HIGH){
//    Serial.println("x");
  } else {
//    Serial.println("0");
  }
  
}

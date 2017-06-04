
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
boolean buttonOneWasPressed = false;
boolean buttonTwoWasPressed = false;

void setup(){
  
  Serial.begin(9600);
  pinMode(buttonOne,INPUT_PULLUP);
  pinMode(buttonTwo,INPUT_PULLUP);
      
}

void loop(){
  
  
  buttonOneState = digitalRead(buttonOne);
  
  buttonTwoState = digitalRead(buttonTwo);
  
  // handle button one
  if(buttonOneState == LOW){
    if(buttonOneWasPressed == false){
      Serial.println("1");
      buttonOneWasPressed = true;
    }
  } else {
//    Serial.println("down");
    buttonOneWasPressed = false;
  }  
  
  // handle button two
  if(buttonTwoState == LOW){
    if(buttonTwoWasPressed){
       Serial.println("2");
       buttonTwoWasPressed = true;
    }
  } else {
      buttonTwoWasPressed = false;
  }
  
}

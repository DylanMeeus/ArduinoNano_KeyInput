
/**
  Code to make the keyswitch tester come alive
*/


const int buttons = 5;
const int buttonPins[] = {2,3,4,5,6};


// Each index represents a corresponding pin, e.g buttonPressed[1] is the state of buttonPins[1]
boolean buttonPressed[] = {false,false,false,false,false};

// Output, this also corersponds to the pin in the buttonPins[] like buttonPressed[]
char charOut[] = {'1','2','3','4','5'};

void setup(){
  
  Serial.begin(9600);
  for(int i = 0; i < buttons; i++){
   pinMode(buttonPins[i],INPUT_PULLUP); 
  }
      
}

void loop(){
  for(int i = 0; i < buttons; i++){
    int buttonState = digitalRead(buttonPins[i]);
    if(buttonState == LOW){
      if(!buttonPressed[i]){
        Serial.println(charOut[i]);
        buttonPressed[i] = true;
      }
    } else {
       buttonPressed[i] = false; 
    }
  }
}

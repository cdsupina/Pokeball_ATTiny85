int buttonPin = 2; //declare pins for the button and led
int ledPin = 1;

int pressCount = 0; // make a variable to count the press
int blinkCount = 6; // variable to set the number of blinks when the button is double pressed

unsigned long timeInit;

void setup() {
  //initialize the pins as inputs and outputs and set timeInit to 0
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  timeInit = 0;  
}


void loop() {
  
  if(pressCount == 0){ //if the button has been pressed 0 times
    if(digitalRead(buttonPin)){ //check if button is pressed
      timeInit = millis(); //if pressed store the initial time (millis() is the time from the program's start)
      while(1){ //also start an infinite loop
        if(!digitalRead(buttonPin)){ //if button is released
          pressCount++; //increment the pressCount
          break; //break out of the infinite loop
        }  
      }  
    }  
  }else if(pressCount == 1){ //if button has been pressed once
    if(millis() - timeInit > 500){ //check if it has been half of a second since the button was last pressed
      pressCount = 0; //if it has reset the press count
      digitalWrite(ledPin, HIGH); //turn the led on for 2 seconds
      delay(2000);
      digitalWrite(ledPin, LOW);  
    }else if(digitalRead(buttonPin)){ //if it hasn't been half a second since the button was last pressed, check if it is being pressed again
      while(1){ //if it is start an infinite loop
        if(!digitalRead(buttonPin)){ //check if the button has been released
          pressCount++; //again increment the press count and break out of the loop
          break;  
        }  
      }  
    }  
  }else if(pressCount == 2){ //if the button has been pressed twice
    for(int i=0;i<blinkCount; i++){ //go straight to the blinking action because there is no other option
      delay(500);
      digitalWrite(ledPin,HIGH);
      delay(500);
      digitalWrite(ledPin,LOW);  
    }
    pressCount = 0; //also reset the pressCount
  }
}



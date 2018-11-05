#include <Keyboard.h>
#define BOUNCE_WITH_PROMPT_DETECTION
#include <Bounce2.h>

// Number of buttons
const int numButtons = 2;

// Set pin, character and debouncer for each button
const int btnPins[numButtons] =       {2,        4       };
const char btnKeys[numButtons] =      {'l',      'p'     };
const Bounce debouncers[numButtons] = {Bounce(), Bounce()};

void setup() {
  for (int i=0; i < numButtons; i++){
    debouncers[i].attach(btnPins[i],INPUT_PULLUP);
    debouncers[i].interval(5); // debounce interval in milliseconds
  }
  
  // initialize keyboard:
  Keyboard.begin();
}

void loop() {
  for (int i=0; i < numButtons; i++){
    debouncers[i].update();
    if (debouncers[i].fell()) {
        //Serial.print("INPUT_PULLUP LOW -> Sending KEYDOWN for ");
        //Serial.println(btnKeys[i]);
        Keyboard.press(btnKeys[i]);
    } else if (debouncers[i].rose()){
        //Serial.print("INPUT_PULLUP LOW -> Sending KEYUP for ");
        //Serial.println(btnKeys[i]);
        Keyboard.release(btnKeys[i]);
    }
  }
}

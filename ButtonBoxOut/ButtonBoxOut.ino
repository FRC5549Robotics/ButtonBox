
#include <Joystick.h>

Joystick_ Joystick;

int throttleNum = A0;

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(A0, INPUT_PULLUP);
  
  Joystick.setThrottleRange(0, 255);
  
  // Initialize Joystick Library
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[7] = {0,0,0,0,0,0,0};

void loop() {  
  // Read pin values
  for (int index = 0; index < 7; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  Joystick.setThrottle(analogRead(throttleNum));

  delay(50);
}

/* Button Layout for FRC Deep Space Challenge:
 *  Top Black: Button 1 - Pin 2
 *  Red: Button 2 - Pin 3
 *  Middle Black: Button 3 - Pin 4
 *  Yellow: Button 4 - Pin 5
 *  Bottom Black: Button 5 - Pin 6
 *  Green: Button 6 - Pin 7
 *  Vision Assist Button: Button 7 - Pin 8
 *  
 * Throttle:
 *  Analog - Pin A1
 */

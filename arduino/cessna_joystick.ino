#include <Joystick.h>


int xValue, yValue;

// Constant that maps the phyical pin to the joystick button.
const int toggleSwitchPins[] = {A0, A1, 6, 6, 7,8,9,10,11,12,13};
//const int masterSwitchPins[] = {6};

const int flapsPins[] = {0, 1};

const int ignitionPins[] = {2, 3, 4, 5};


const int toggleSwitchCount = sizeof(toggleSwitchPins) / sizeof(toggleSwitchPins[0]);
const int flapsPinsCount = sizeof(flapsPins) / sizeof(flapsPins[0]);
const int ignitionPinsCount = sizeof(ignitionPins) / sizeof(ignitionPins[0]);

const int buttonCount = toggleSwitchCount * 2 + flapsPinsCount + ignitionPinsCount + 1;

int lastButtonStates[buttonCount];

// Create the Joystick
Joystick_ Joystick =  Joystick_(
    JOYSTICK_DEFAULT_REPORT_ID,
    JOYSTICK_TYPE_JOYSTICK,
    buttonCount,
    0,
    true, 
    true,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false,
    false);


int oppositeDay(int state) {
  return state == HIGH ? LOW : HIGH;
}


void setup() {

  // Initialize  Pins
  for (int i = 0; i < toggleSwitchCount; i++) {
    pinMode(toggleSwitchPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < flapsPinsCount; i++) {
    pinMode(flapsPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < ignitionPinsCount; i++) {
    pinMode(ignitionPins[i], INPUT_PULLUP);
  }



  // Initialize last button states
  for (int i = 0; i < buttonCount; i++) {
    lastButtonStates[i] = -1;
  }


  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);

  // Initialize Joystick Library
  Joystick.begin();

}



void loop() {


  // First buttons are dedicated for toggle switches
  // --------------------------------------------------
  for (int i = 0; i < toggleSwitchCount; i++) {
    // Read pin values
    int buttonNumber = i * 2;
    int currentButtonState = !digitalRead(toggleSwitchPins[i]);
    if (currentButtonState != lastButtonStates[buttonNumber])
    {
      Joystick.setButton(buttonNumber, currentButtonState);
      Joystick.setButton(buttonNumber + 1, oppositeDay(currentButtonState));
      lastButtonStates[buttonNumber] = currentButtonState;
    }
  }


  // Flaps
  // --------------------------------------------------
  for (int i = 0; i < flapsPinsCount; i++) {
    // Read pin values
    int buttonNumber = toggleSwitchCount * 2 + i;
    int currentButtonState = !digitalRead(flapsPins[i]);
    if (currentButtonState != lastButtonStates[buttonNumber])
    {
      Joystick.setButton(buttonNumber, currentButtonState);
      lastButtonStates[buttonNumber] = currentButtonState;
    }
  }



  // Ignition
  // --------------------------------------------------
  int anyOn = 0;
  for (int i = 0; i < ignitionPinsCount; i++) {
    // Read pin values
    int buttonNumber = toggleSwitchCount * 2 + flapsPinsCount + i;

    int currentButtonState = !digitalRead(ignitionPins[i]);
    anyOn += currentButtonState;
    if (currentButtonState != lastButtonStates[buttonNumber])
    {
      Joystick.setButton(buttonNumber, currentButtonState);
      lastButtonStates[buttonNumber] = currentButtonState;
    }
  }

  int buttonNumber = toggleSwitchCount * 2 + flapsPinsCount + ignitionPinsCount;
  int currentButtonState = anyOn > 0 ? 0 : 1;
  if (currentButtonState != lastButtonStates[buttonNumber])
  {
    Joystick.setButton(buttonNumber, currentButtonState);
    lastButtonStates[buttonNumber] = currentButtonState;
  }



  // Throttle and Mixture
  // --------------------------------------------------
  xValue = analogRead(A4);
  yValue = analogRead(A5);

  Joystick.setXAxis(xValue);
  Joystick.setYAxis(yValue);

  delay(50);
}

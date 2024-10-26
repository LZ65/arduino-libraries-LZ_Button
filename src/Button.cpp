#include "Arduino.h"
#include "Button.h"

Button::Button (uint8_t pin)
{
  Init (pin);
}
void Button::Init (uint8_t pin)
{
  nPin = pin;
  pinMode (nPin, INPUT_PULLUP);
  tMillis = millis ();
  pinVal = digitalRead (nPin);
  state = pinVal == HIGH ? btnClosed : btnOpened;
  bStateChanged = 0;
}
ButtonState Button::Update (unsigned long t)
{
  bStateChanged = 0;
  if (t - tMillis >= BTN_ms)
  {
    ButtonState stateNew = state;
    tMillis = t;
    uint8_t pinNew = digitalRead (nPin);
         if (pinNew == LOW  && pinVal == LOW)  stateNew = btnClosed;
    else if (pinNew == LOW  && pinVal == HIGH) stateNew = btnPressed;
    else if (pinNew == HIGH && pinVal == LOW)  stateNew = btnReleased;
    else if (pinNew == HIGH && pinVal == HIGH) stateNew = btnOpened;
    bStateChanged = (stateNew != state) ? 1 : 0;
    state = stateNew;
    pinVal = pinNew;
  }
  return state;
}
ButtonState Button::Update () { return Update (millis ()); }
ButtonState Button::GetNewState () { return bStateChanged ? state : btnUndefined; }


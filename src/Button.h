#ifndef BUTTON_INC
#define BUTTON_INC

#include <inttypes.h>

#define BTN_ms 30
typedef enum { btnPressed=1, btnClosed, btnOpened, btnReleased, btnUndefined } ButtonState;

class Button
{
public:
  Button (uint8_t pin=11);
private:
/*
  uint8_t	mask;
  uint8_t	port;
  volatile uint8_t *ddr;
  volatile uint8_t *inp;
*/
  uint8_t nPin;
  uint8_t pinVal;
  unsigned long tMillis;
  ButtonState  state;
  uint8_t      bStateChanged;
public:  
  void Init (uint8_t pin);
  ButtonState GetState () { return state; }
  ButtonState Update (unsigned long t);
  ButtonState Update ();
  uint8_t IsStateChanged () { return bStateChanged; }
  ButtonState GetNewState ();
};

#endif

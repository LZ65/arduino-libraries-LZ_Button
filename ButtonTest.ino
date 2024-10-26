#include <Button.h>

Button btn1(11);  // button 1 on pin 11
Button btn2(12);  // button 2 on pin 12
int led1 = A0;
int led2 = A1;

void setup ()
{
  pinMode (led1, OUTPUT); digitalWrite (led1, LOW);
  pinMode (led2, OUTPUT); digitalWrite (led2, LOW);
}

void loop ()
{
  btn1.Update ();
  btn2.Update ();
  ButtonState  btnState1 = btn1.GetNewState ();
  ButtonState  btnState2 = btn2.GetNewState ();
  
  if (btnState1 == btnReleased)
  {
    digitalWrite (led1, digitalRead(led1)==HIGH?LOW:HIGH);
  }
  if (btnState2 == btnReleased)
  {
    digitalWrite (led2, digitalRead(led2)==HIGH?LOW:HIGH);
  }
}

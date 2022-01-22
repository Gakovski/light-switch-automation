#include<Servo.h>
Servo Myservo;
int pos;
const int buttonPin = 2;
int buttonState = 0;
boolean on = false;
boolean motorAt90 = 0;

void setup()
{
  pinMode(buttonPin, INPUT);
  Myservo.attach(3);
}

void loop()
{
  Myservo.write(45);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (on == true) {
      on = false;
    } else {
      on = true;
    }
  }

  if (on == true) {
    if (motorAt90 == 0) {
      for (pos = 45; pos < 90; pos++) {
        Myservo.write(pos);
        delay(5);
      }
      motorAt90 = 1;
      for (pos = 90; pos > 45; pos--) {
        Myservo.write(pos);
        delay(5);
      }
    }
  }
  else if (on == false) {
    if (motorAt90 == 1) {
      for (pos = 45; pos > 0; pos--) {
        Myservo.write(pos);
        delay(5);
      }
      motorAt90 = 0;
      for (pos = 0; pos < 45; pos++) {
        Myservo.write(pos);
        delay(5);
      }
    }
  }
}

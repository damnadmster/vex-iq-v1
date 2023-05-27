/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo_claw;  // create servo object to control a servo
Servo myservo_rotate;  // create servo object to control a servo

int pin_claw = A10;  // analog pin used to connect the potentiometer
int pin_rotate = A11;  // analog pin used to connect the potentiometer
int val_claw,val_rotate;    // variable to read the value from the analog pin

void setup() {
  myservo_claw.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo_rotate.attach(6);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val_claw = analogRead(pin_claw);            // reads the value of the potentiometer (value between 0 and 1023)
  val_rotate = analogRead(pin_rotate);            // reads the value of the potentiometer (value between 0 and 1023)
  val_claw = map(val_claw, 1023,0, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo_claw.write(val_claw);                  // sets the servo position according to the scaled value
  val_rotate = map(val_rotate, 1023,0, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo_rotate.write(val_rotate);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

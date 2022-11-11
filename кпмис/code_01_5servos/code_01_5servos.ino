/*
Движение 5-ю сервоприводами
*/

#include <Servo.h>

Servo myservo_claw;  // регистрация объекта контроля сервоприводом - захват
Servo myservo_rotate;  //  регистрация объекта контроля сервоприводом - поворот захвата
Servo myservo_l1;  //  регистрация объекта контроля сервоприводом - "предплечья"
Servo myservo_l2;  //  регистрация объекта контроля сервоприводом - "плечо"
Servo myservo_base;  //  регистрация объекта контроля сервоприводом - поворот манипулятора 

int pin_claw = A10;  // управление регулятором А10
int pin_rotate = A11;  // управление регулятором А11
int pin_l1 = A12;  // управление регулятором А12
int pin_l2 = A13;  // управление регулятором А13
int pin_base = A14;  // управление регулятором А14
int val_claw,val_rotate,val_l1,val_l2,val_base;    // переменная хранения значения поворота серво

void setup() {
  myservo_claw.attach(9);  // подключение серво
  myservo_rotate.attach(8);  // подключение серво
  myservo_l1.attach(7);  // подключение серво
  myservo_l2.attach(6);  // подключение серво
  myservo_base.attach(5);  // подключение серво

}

void loop() {
  val_claw = analogRead(pin_claw);            // чтение значений потенциометра Захвата
  val_rotate = analogRead(pin_rotate);            // чтение значений потенциометра поворот захвата
  val_l1 = analogRead(pin_l1);            // чтение значений потенциометра "предплечья"
  val_l2 = analogRead(pin_l2);            // чтение значений потенциометра "плечо"
  val_base = analogRead(pin_base);            // чтение значений потенциометра поворот манипулятора 

  val_claw = map(val_claw, 1023,0, 50, 150);     // нормализация знаяения относительно поворота ручки
  myservo_claw.write(val_claw);                  // поворот серво 
  
  val_rotate = map(val_rotate, 1023,0, 0, 180);     // нормализация знаяения относительно поворота ручки
  myservo_rotate.write(val_rotate);                  // поворот серво 
  
  val_l1 = map(val_l1, 0,1023, 25, 90);     // нормализация знаяения относительно поворота ручки
  myservo_l1.write(val_l1);                  // поворот серво 

  val_l2 = map(val_l2, 1023,0, 30, 120);     // нормализация знаяения относительно поворота ручки
  myservo_l2.write(val_l2);                  // поворот серво 

  val_base = map(val_base, 1023,0, 0, 180);     // нормализация знаяения относительно поворота ручки
  myservo_base.write(val_base);                  // поворот серво 

  delay(15);                           // пауза на 15 миллисекунд
}

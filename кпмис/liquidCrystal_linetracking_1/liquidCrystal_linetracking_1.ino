//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
//подключение к Мега display I2C , 20,21 порт, вывод тестовой строки
//вывод уровня сигнала на дисплей с линейки 5 датчиков линии
//сигнал 3 = черное
//сигнал 980+ = белое
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();

}


void loop()
{
  lcd.clear();
  int linesensor_0 = analogRead(A0);
  int linesensor_1 = analogRead(A1);
  int linesensor_2 = analogRead(A2);
  lcd.setCursor(0,0);
  lcd.print(String(linesensor_0) + " " + String(linesensor_1) + " " + String(linesensor_2));
  int linesensor_3 = analogRead(A3);
  int linesensor_4 = analogRead(A4);
  lcd.setCursor(0,1);
  lcd.print(String(linesensor_3) + " " + String(linesensor_4));
  delay(200);
  
}

//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
//подключение к Мега 20,21 порт, вывод тестовой строки
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("KPMIS test");
  lcd.setCursor(0,1);
  lcd.print("ver.1");
}


void loop()
{
}

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String teks = "7-0";

void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  lcd.setCursor(5, 0);
  lcd.print("LFC MU");
}

void loop()
{
  for (int pos = 15; pos >= -3; pos--) 
  {
    lcd.setCursor(0, 1);
    lcd.print("                "); 

    if (pos >= 0) {
      lcd.setCursor(pos, 1);
      lcd.print(teks);
    }

    delay(100);
  }
}


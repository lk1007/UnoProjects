#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
boolean prevVal;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);


}

void loop() {
lcd.setCursor(0,0);
int a = analogRead(A4);
if(a <150 )
{
  if(prevVal)
  lcd.clear();
  lcd.print("On");
  prevVal = 0;
}

else
{
  if(prevVal == 0)
  {
    lcd.clear();
  }
  lcd.print("Off");
  prevVal = 1;
}
lcd.setCursor(0,1);
lcd.print(a);


}

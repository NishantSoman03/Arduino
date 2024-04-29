#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 unsigned char specialchar[8]={0x00,0x0A,0x00,0x00,0x11,0x0E,0x00}; 
void setup() {
  lcd.begin(16,2);  
  lcd.clear();  
  lcd.createChar(0, specialchar);   
}
void loop() {
  lcd.setCursor(0,0);   
  lcd.print("Welcome"); 
  lcd.setCursor(0,1);  
  lcd.print("To LINUX HINT"); 
  lcd.write(byte(0));   
}
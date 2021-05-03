/*Created on 24 April 2021 by Altp12 
 * I2C LCD Display text with potentiometer to adjust LCD Brightness
*/

//Include LiquidCrystal_I2C and Wire Library
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C(0x27,20,4);  //Assume the address of LCD is 0x27 and the size of LCD is 20x4, you can adjust it by yourself
   
void setup() {
  Serial.begin(9600);
  lcd.init(); //LCD initialisation
  lcd.backlight();  //Turn on LCD backlight
  lcd.setCursor(0,0); //Set cursor to position (0,0)
  lcd.print("Hello World!");  //You can adjust the text to be printed to LCD
}

void loop() {
  
}

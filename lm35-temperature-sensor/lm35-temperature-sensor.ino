/* Created on 18 May 2021 by lyfetech
 * Measuring temperature using lm35 sensor dan display to the lcd screen
 * The formula for sensor voltage input is Vout = lm35input*Vref/1024
 * The formula to read temp in celcius is Ctemp = Vout/10
 * The formula to read temp in Fahrenheit is Ftemp = Ctemp * 9/5 + 32
 * The formula to read temp in Kelvin id Ktemp = Ctemp + 273.15
 */

#include<LiquidCrystal_I2C.h>

#define lm35Pin A0  //Define lm35 sensor pin

LiquidCrystal_I2C lcd(0x27, 20, 4); //Initialise the lcd screen

float lm35input;  //Variable for sensor analog input 
float Vref=5000; //Variable of the reference voltage to the sensor (I use 5000mV)
float Vout; //Variable of the voltage sensor  
float Ctemp, Ftemp, Ktemp;  //Variable to store 

void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("lm35 sensor");
  lcd.setCursor(0,1);
  lcd.print("Temp in C : ");
  lcd.setCursor(0,2);
  lcd.print("Temp in F : ");
  lcd.setCursor(0,3);
  lcd.print("Temp in K : ");
}

void loop() 
{
  lm35input = analogRead(lm35Pin);  //Read the analog input
  lcd.setCursor(12,1);
  tempPrintC();
  lcd.setCursor(12,2);
  tempPrintF();
  lcd.setCursor(12,3);
  tempPrintK();
  delay(1000);
}

void tempRead()
{
  Vout = (lm35input*(Vref/1024.0)); //Calculate the sensor voltage input
  Ctemp = Vout/10;
  Ftemp = Ctemp*(9/5) + 32;
  Ktemp = Ctemp+273.15;
}

void tempPrintC()
{
  tempRead();
  lcd.print(Ctemp,1);
  lcd.print(char(223));
  lcd.print("C");
}

void tempPrintF()
{
  tempRead();
  lcd.print(Ftemp,1);
  lcd.print(char(223));
  lcd.print("F");
}

void tempPrintK()
{
  tempRead();
  lcd.print(Ktemp,1);
  lcd.print("K");
}

/*Created on 2 May 2021 by Altp
 *Temperature & humidity sensor using DHT11 sensor and display it in LCD
*/

#include<LiquidCrystal_I2C.h>  //Include library for LCD I2C module
#include<DHT.h> //Include DHT sensor library

#define DHT_PIN 2 //Set DHT pin

#define DHT_TYPE DHT11 //Set DHT type

LiquidCrystal_I2C lcd(0x27, 20, 4); //Initialise lcd with address 0x27 for 20x4 LCD

DHT dht(DHT_PIN, DHT_TYPE); //Initialise DHT sensor

void setup() {
  lcd.init(); //Setup the lcd
  lcd.backlight();  //Turn on the backlight
  dht.begin();  //Setup DHT sensor
   
  lcd.setCursor(0,0); //Set the lcd cursor to (0,0)
  lcd.print("DHT 11 sensor");  //Print text
  lcd.setCursor(0,1); //Set the lcd cursor to (0,1)
  lcd.print("Temperature :");  //Print text
  lcd.setCursor(0,2); //Set the lcd cursor to (0,2)
  lcd.print("Humidity :"); //Print text
}

float temp; //variable assign to temperature read
float humid;  //variable assign to humidity read

void loop() {
  celcius();
  //Uncomment line below to show the temperature as Fahrenheit
  //fahrenheit();
  //Uncomment line below to show the temperature as Kelvin
  //kelvin();
  humidity();
}

void celcius()
{
  temp = dht.readTemperature(); //Read the temperature as Celcius
  lcd.setCursor(14,1);  //Set cursor to (14,1)
  lcd.print(temp,1); //Print temperature with 1 decimal digit
  lcd.print((char)223); //Print °
  lcd.print("C"); //Print C
}

void fahrenheit()
{
  temp = dht.readTemperature(); //Read the temperature as Celcius
  temp = dht.convertCtoF(temp); //Convert Celcius to Fahrenheit
  lcd.setCursor(14,1);  //Set cursor to (14,1)
  lcd.print(temp,1); //Print temperature with 1 decimal digit
  lcd.print((char)223); //Print °
  lcd.print("F"); //Print F
}

void kelvin()
{
  temp = dht.readTemperature(); //Read the temperature as Celcius
  temp+=273.15; //convert Celcius to Kelvin 
  lcd.setCursor(14,1);  //Set cursor to (14,1)
  lcd.print(temp,1);  //Print temperature with 1 decimal digit
  lcd.print("K"); //Print K
}

void humidity()
{
  humid = dht.readHumidity(); //Read the humidity as percentage(%) 
  lcd.setCursor(11,2);  //Set cursor to (11,2)
  lcd.print(humid,1);  //Print humidity with 1 decimal digit
  lcd.print("%"); //Print % sign
}

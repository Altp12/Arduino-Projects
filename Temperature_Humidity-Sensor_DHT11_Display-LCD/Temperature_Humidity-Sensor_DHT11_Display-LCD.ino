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
  lcd.print("DHT sensor");  //Print text
  lcd.setCursor(0,1); //Set the lcd cursor to (0,1)
  lcd.print("Temperature : ");  //Print text
  lcd.setCursor(0,2); //Set the lcd cursor to (0,2)
  lcd.print("Humidity : "); //Print text
}

float temp; //variable assign to temperature read
int humid;  //variable assign to humidity read

void loop() {
  temp = dht.readTemperature(); //Read the temperature as Celcius
  
  //Uncomment line below to show the temperature as Fahrenheit
  //temp = dht.convertCtoF(temp); //Convert temperature to Fahrenheit
  
  humid = dht.readHumidity(); //Read the humidity as percentage(%)
  lcd.setCursor(15,1);  //Set cursor to (15,1)
  lcd.print(temp,2); //Print temperature with 2 decimals digit
  lcd.print("\xc2\xb0C"); //Print °C using UTF-8 character encoding 
  lcd.setCursor(12,2);  //Set cursor to (12,2)
  lcd.print(humid);  //Print humidity
  lcd.print("%"); 
}

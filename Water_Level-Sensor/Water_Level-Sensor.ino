/* Created on 13 May 2021
 *  
 * Measure water level sensor
 * Turn on the LED when the sensor reading is above the constraint
 */

//Define pins used
#define LED 5  //LED for warning 
#define W_Sensor A0  //Sensor reading pin
#define Power_Sensor 3 //Power pin to turn on then sensor while reading data

int level;  //Variable to store sensor reading
bool state = false; //State the condition of led 

void setup()
{
 Serial.begin(96s00);
 pinMode(LED, OUTPUT);
 pinMode(Power_Sensor, OUTPUT);
}

void loop()
{
  Waterlevel_read();
  check_level();
  delay(2000);
}

void Waterlevel_read()  //Function to read water level
{
  digitalWrite(Power_Sensor, HIGH);
  level =  analogRead(W_Sensor);
  Serial.print("Water level = ");
  Serial.println(level);
  digitalWrite(Power_Sensor, LOW);
}

void check_level()  //Function to check the height of water, you can calibrate the constraint according to the situation
{
  if(level >= 670 && !state)
  {
    digitalWrite(LED, HIGH);
    state=true;  
  }
  else if(level < 670 && state)
  {
    digitalWrite(LED, LOW);
    state=false;
  }
}

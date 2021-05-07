/* Created on 7 May 2021 by lyfe
 *  Play LED light with Arduino
 *  This code includes 3 projects
 *  1. Turn LED on and off sequentially
 *  2. Aircraft lighting system simulation
 *  3. Race system light
 *  Uncomment one of the code below (default : Turn LED on and off sequentially)
 */


//1. Turn LED on and off sequentially
//define LED pin 
#define LED_RED 10
#define LED_YELLOW 9
#define LED_GREEN 6
#define LED_BLUE 5

void setup()
{
  //set pin mode to output
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

//Turn LED on and off sequentially 
void loop()
{
    digitalWrite(LED_RED, HIGH);
    delay(1000);
    digitalWrite(LED_YELLOW, HIGH);
    delay(1000);
    digitalWrite(LED_GREEN, HIGH);
    delay(1000);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);
    digitalWrite(LED_BLUE, LOW);
    delay(1000);
    digitalWrite(LED_GREEN, LOW);
    delay(1000);
    digitalWrite(LED_YELLOW, LOW);
    delay(1000);
    digitalWrite(LED_RED, LOW);
    delay(1000);
}


//2. Aircraft lighting system simulation
/*
//define LED pin
#define RED_LED 11
#define GREEN_LED 5
#define WHITE_LED 9
#define BEACON_LED 10

void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BEACON_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
}

void loop()
{
  //Choose Airbus/Boeing beacon light (default : Airbus)
  //Airbus_beacon();
  Boeing_beacon(); 
  //Choose Airbus or Boeing Strobe (default : Airbus)
  //Airbus_strobe();
  Boeing_strobe();
}

void Airbus_beacon()
{
  digitalWrite(BEACON_LED, HIGH);
  delay(100);
  digitalWrite(BEACON_LED, LOW);
  delay(500);
}

void Boeing_beacon()
{
  digitalWrite(BEACON_LED, HIGH);
  delay(50);
  digitalWrite(BEACON_LED, LOW);
  delay(800);
}

void Airbus_strobe()
{
  digitalWrite(WHITE_LED, HIGH);
  delay(50);
  digitalWrite(WHITE_LED, LOW);
  delay(100);
  digitalWrite(WHITE_LED, HIGH);
  delay(50);
  digitalWrite(WHITE_LED, LOW);
  delay(300);
}

void Boeing_strobe()
{
  digitalWrite(WHITE_LED,HIGH);
  delay(250);
  digitalWrite(WHITE_LED,LOW);
  delay(200);
}
*/


// 3. Race light system
/*
//define LED pins
#define RED1 2
#define RED2 3
#define RED3 4
#define RED4 5
#define RED5 6
#define GREEN1 7
#define GREEN2 8
#define GREEN3 9
#define GREEN4 10
#define GREEN5 11
#define YELLOW 12

void setup()
{
  pinMode(RED1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(RED3, OUTPUT);
  pinMode(RED4, OUTPUT);
  pinMode(RED5, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(GREEN4, OUTPUT);
  pinMode(GREEN5, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  yellow_flash();
  session_end();
  formation_lap();
  race_start();
}

void loop()
{
  //move the function here if you want to repeat it
}

void race_start()
{
  digitalWrite(RED1, HIGH);
  delay(1000);
  digitalWrite(RED2, HIGH);
  delay(1000);
  digitalWrite(RED3, HIGH);
  delay(1000);
  digitalWrite(RED4, HIGH);
  delay(1000);
  digitalWrite(RED5, HIGH);
  delay(2000);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  digitalWrite(RED4, LOW);
  digitalWrite(RED5, LOW);
}

void session_end()
{
  digitalWrite(RED1, HIGH);
  digitalWrite(RED2, HIGH);
  digitalWrite(RED3, HIGH);
  digitalWrite(RED4, HIGH);
  digitalWrite(RED5, HIGH);
  delay(60000);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  digitalWrite(RED4, LOW);
  digitalWrite(RED5, LOW);
  delay(2000);
}

void formation_lap()
{
  digitalWrite(GREEN1, HIGH);
  digitalWrite(GREEN2, HIGH);
  digitalWrite(GREEN3, HIGH);
  digitalWrite(GREEN4, HIGH);
  digitalWrite(GREEN5, HIGH);
  delay(60000);
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(GREEN4, LOW);
  digitalWrite(GREEN5, LOW);
  delay(2000);
}

void yellow_flash()
{
  for(int i=0;i<10;i++)
  {
    digitalWrite(YELLOW, HIGH);
    delay(1000);
    digitalWrite(YELLOW, LOW);
    delay(1000);
  }  
}
*/

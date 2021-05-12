/*Created on 12 May 2021 
 * Automatic on-off light bulb using photoresistor/ldr
 * We use normally open configuration for relay
 * The relay works with inverted logic
 */
 
//Define pin used
#define ldrPin A0
#define relayPin 3

int light;  //Variable to store photoresistor reading
bool state=false; //Variable to save the state of light bulb

void setup()
{
  pinMode(relayPin, OUTPUT); 
}

void loop()
{
  light = analogRead(ldrPin);
  if(light<=200) turn_on();
  else turn_off();
  delay(1000);
}

void turn_on()  //Function to turn on the relay
{
   if(!state)
   {
     state=true;
     digitalWrite(relayPin, LOW);
   }
}

void turn_off() //Function to turn off the relay
{
  if(state)
    {
      state=false;
      digitalWrite(relayPin, HIGH);
    }
}

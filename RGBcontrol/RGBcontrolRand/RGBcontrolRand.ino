/* The RGB LED works by completing one out of three circuits
   since it has a common Anode(+ve terminal)( longest lead), the colors are
   switched by switching the ground pin among three temrminals.
   since the Arduino has a fixed GND pin which cannnot be changed,
   this sketch simulates ground by setting a pin to LOW (0 Volts).
   (RGB LED's used were bought as part of the makershed ultimate arduino
   microcontrller kit)
*/
unsigned int grd; // references simulated ground pin
unsigned long delay_time; // random time between colors

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  for(grd=2;grd<=4;grd++)
  pinMode(grd, OUTPUT);
  randomSeed(analogRead(3));
  
  
}

void loop()
{
  
    grd = random(2,5); // set ground to a random int b/w 2 and 5
    delay_time = random(0,2500); // delay between color changes will be between 0 and 2.5 seconds 
    
    /* uncomment if statement below to prevent grd being set as pin5
    and thus preventing a possible time period when the LED is off
    */
    
    if(grd == 5)
    {
      digitalWrite(13, HIGH);
      digitalWrite(13, LOW);
    }
    else
    {
      digitalWrite(8, HIGH); // set digital pin 8 as high. connected to common anode (longest pin)
      digitalWrite(grd, LOW);// set grd tow low, to simulate circuit ground
      delay(delay_time);
      digitalWrite(8, LOW);
      digitalWrite(grd, HIGH);
    }
    
}


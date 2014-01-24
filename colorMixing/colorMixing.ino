/* The RGB LED works by completing one out of three circuits
   since it has a common Anode (+ve terminal)( longest lead), the colors are
   switched by switching the ground pin among three temrminals.
   since the Arduino has a fixed GND pin which cannnot be changed,
   this sketch simulates ground by setting a pin to LOW (0 Volts).
   (RGB LED's used were bought as part of the makershed ultimate arduino
   microcontrller kit)
*/
unsigned int led; // pin connected to LED.
unsigned long delay_time; // random time between colors


void setup()
{
  pinMode(6, OUTPUT);
  for(led=9;led<=11;led++) // Set all pins which have a LED color as OUPUT, not strcitly required for PWM pins
  pinMode(led, OUTPUT);
  randomSeed(analogRead(3)); // to improve random() function 
  
  
}

void loop()
{
    
    unsigned int red = random(0,256); // red LED Duty cycle
    unsigned int green = random(0,256); // Green LED Duty cycle 
    unsigned int blue = random(0,256);// Blue LED Duty cycle
    delay_time = random(0,2500); // delay between each iteration of loop() will be between 0 and 2.5 seconds 
    
    /* For some Reason a comon Anode LED requires 255 to be
       subtacted from the dutycycle for colors to show up correctly
    */
    
     analogWrite(9, (255-red));
     analogWrite(10,(255-green));
     analogWrite(11,(255-blue));
     delay(delay_time);
    
    
}


/* subtact 255 from dutycycle logic taken from:
  http://learn.adafruit.com/downloads/pdf/adafruit-arduino-lesson-3-rgb-leds.pdf
  Accessed: 01/23/2014
*/

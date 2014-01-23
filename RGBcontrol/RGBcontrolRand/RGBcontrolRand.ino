/* The RGB LED works by completing one out of three circuits
   since it has a common Cathod (-ve terminal)( longest lead), the colors are
   switched by switching the ground pin among three temrminals.
   since the Arduino has a fixed GND pin which cannnot be changed,
   this sketch simulates ground by setting a pin to LOW (0 Volts).
   (RGB LED's used were bought as part of the makershed ultimate arduino
   microcontrller kit)
*/
int grd;

void setup()
{
  pinMode(8, OUTPUT);
  for(grd=2;grd<=4;grd++)
  pinMode(grd, OUTPUT);
  randomSeed(analogRead(3));
  
  
}

void loop()
{
  
    grd = random(2,5);
    /*if(grd == 5)
    {
      grd = random(2,5);
    }*/
    digitalWrite(8, HIGH);
    digitalWrite(grd, LOW);
    delay(1000);
    digitalWrite(8, LOW);
    digitalWrite(grd, HIGH);
  
}



int grd;

void setup()
{
  pinMode(8, OUTPUT);
  for(grd=2;grd<=4;grd++)
  pinMode(grd, OUTPUT);
  
  
}

void loop()
{
  
  for(grd = 2; grd <= 4;grd++)
  {
    digitalWrite(8, HIGH);
    digitalWrite(grd, LOW);
    delay(2000);
    digitalWrite(8, LOW);
    digitalWrite(grd, HIGH);
  }
}


#include <math.h>
#define PB *((volatile byte*)0x25)
#define DB *((volatile byte*)0x24)
int bpm = 500;
int t = 1;
int potpin = A0;
int met = 10;
double freq = 460;
double T = (pow(1000.0,2)/freq);
void frequency(double freq)
{
  
 T = (pow(1000.0,2)/freq);

  PB = 4; //Pin 10 = 1 000100
  delayMicroseconds(T/2);
  PB = 0; //Pin 10 = 0
  delayMicroseconds(T/2);
}

void setup()
{
  Serial.begin(9600);
  DB = 4;
  pinMode(met,OUTPUT);
}
void loop()
{
  int in = analogRead(potpin);
 Serial.println(in);
 frequency(800);
 //tone(met,440,2000);
 
 //delay(bpm);
//noTone(met);
//delay(bpm);
}

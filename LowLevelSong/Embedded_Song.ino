#include <math.h>
#define PB *((volatile byte*)0x25)
#define DB *((volatile byte*)0x24)
int t = 1;
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
void frequency2(double freq)
{
  

 T = 2272;
  PB = 4;
  delayMicroseconds(T/2);
  PB = 0;
  delayMicroseconds(T/2);

}
void setup()
{
  Serial.begin(9600);
  DB = 4;
}
void loop()
{
 chord(440);

}
void note(int s,int o,float c, int tn) //note(number of half steps, octave, fundemental note, time of note
{int i = 0;
  while(i < 100 * tn)
  {
  frequency(o*pow(2.0,s/12.0)*c);
  i++;
  }
  PB = 0;


 
}
void chord(float c)
{
  note(0,1,c,3*t); // first phrase
  note(3,1,c,t);
  delay(t/4.0);
  note(3,1,c,3*t);
  delay(t);
  note(0,1,c,3*t);
  note(-2,1,c,t);
  delay(t/4.0);
  note(-4,1,c,3.5*t);
  delay(t);
  note(-2,1,c,3*t);
  note(0,1,c,1.5*t);
  note(3,1,c,3*t);
  note(0,1,c,1.5*t);
  note(-2,1,c,3*t);
  delay(6*t);   //end of first phrase
  note(0,1,c,3*t); // second phrase
  note(3,1,c,t);
  delay(t/4.0);
  note(3,1,c,3*t);
  delay(t);
  note(0,1,c,3*t);
  note(-2,1,c,t);
  delay(t/4.0);
  note(-4,1,c,3.5*t);
  delay(t);
  note(-2,1,c,3*t);
  note(0,1,c,1.5*t);
  note(-2,1,c,3*t);
  note(-4,1,c,0.5*t);
  delay(t);
  note(-4,1,c,3*t);
  delay(6*t);  
  
  
}

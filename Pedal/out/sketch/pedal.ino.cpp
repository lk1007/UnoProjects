#include <Arduino.h>
#line 1 "c:\\Users\\Liam Kain\\Personal_Projects\\Practice\\UnoProjects\\Pedal\\pedal\\pedal.ino"
#line 1 "c:\\Users\\Liam Kain\\Personal_Projects\\Practice\\UnoProjects\\Pedal\\pedal\\pedal.ino"
void setup();
#line 8 "c:\\Users\\Liam Kain\\Personal_Projects\\Practice\\UnoProjects\\Pedal\\pedal\\pedal.ino"
void loop();
#line 1 "c:\\Users\\Liam Kain\\Personal_Projects\\Practice\\UnoProjects\\Pedal\\pedal\\pedal.ino"
void setup() {
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(9));
  Serial.println();
  delay(30);
}


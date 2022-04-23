#include <Arduino.h>
#line 1 "c:\\Users\\Liam Kain\\Personal_Projects\\UnoProjects\\RemoteFinder\\RemoteFinder.ino"
int speaker = 3;
#line 2 "c:\\Users\\Liam Kain\\Personal_Projects\\UnoProjects\\RemoteFinder\\RemoteFinder.ino"
void setup();
#line 8 "c:\\Users\\Liam Kain\\Personal_Projects\\UnoProjects\\RemoteFinder\\RemoteFinder.ino"
void loop();
#line 2 "c:\\Users\\Liam Kain\\Personal_Projects\\UnoProjects\\RemoteFinder\\RemoteFinder.ino"
void setup(){
    Serial.begin(9600);
    pinMode(6,INPUT);
    pinMode(3,OUTPUT);
    pinMode(speaker,OUTPUT);
}
void loop(){
    int Data = analogRead(A0);
    Serial.println(Data);
    if(Data > 600){
        delay(10);
        Data = analogRead(A0);
        if(1){
            analogWrite(speaker,225);
            delay(100);
            analogWrite(speaker,155);
            delay(100);
            analogWrite(speaker,0);

        }
    }

    
    delay(100);

    /*if((pulseIn(6, HIGH)) == 0){
        
        }
    } */
    
    

}

# 1 "c:\\Users\\Liam Kain\\Personal_Projects\\UnoProjects\\RemoteFinder\\RemoteFinder.ino"
int speaker = 3;
void setup(){
    Serial.begin(9600);
    pinMode(6,0x0);
    pinMode(3,0x1);
    pinMode(speaker,0x1);
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

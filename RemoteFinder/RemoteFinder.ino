int speaker = 3;
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
#include <string.h>

int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;
int RS = 10; // is 0 if sending command 1 if sending character data
int RW = 11; // 1 if read 0 if write operation
int E = 12; //enable signal

int len(const char * c){
    return strlen(c);
}

void sendByte(byte data){
    for(int i = 2; i <=9; i++){
        int c = data % 2;
        data = data >> 1;
        if(c == 1)
            digitalWrite(i,HIGH);
        else
            digitalWrite(i,LOW);
    }
    enable();
}
void enable(){
    digitalWrite(E,HIGH);
    delay(10);
    digitalWrite(E,LOW);
}

void pinset(int first, int last,int mode){
    for(int i = first; i <= last; i++){
        if(mode == 1)
            digitalWrite(i,HIGH);
        else
            digitalWrite(i,LOW);
    delay(100);
    }
}

void home(){
    digitalWrite(RS,LOW);
    digitalWrite(RW,LOW);
    pinset(4,9,1);
    digitalWrite(D1,HIGH);
    enable();
}

void showCursor(int disp, int curs, int blink){
    digitalWrite(RS,LOW);
    digitalWrite(RW,LOW);
    pinset(6,9,0);
    digitalWrite(D3,HIGH);
    if(disp == 1)
        digitalWrite(D2,HIGH);
    else
        digitalWrite(D2,LOW);
    if(curs == 1)
        digitalWrite(D1,HIGH);
    else
        digitalWrite(D1,LOW);
    if(blink == 1)
        digitalWrite(D0,HIGH);
    else
        digitalWrite(D0,LOW);
    enable();
}
//if curseDir == 1, cursor moves right, if 0, cursor moves left
//if disMove == 1, display moves according to curseDir, if 0, display doesn't move
void setDir(int curseDir, int disMove){
    digitalWrite(RS,LOW);
    digitalWrite(RW,LOW);
    pinset(5,9,0);
    digitalWrite(D2, HIGH);
    if(curseDir = 1)
        digitalWrite(D1,HIGH);
    else   
        digitalWrite(D1,LOW);
    if(disMove == 1)
        digitalWrite(D0,HIGH);
    else
        digitalWrite(D0,LOW);
    enable();
}
//if DL is 1, 8-bit mode. 0 is 4-bit mode
//if N is 1, 2-line mode. 0 is 1-line mode
//if F is 1, 5x11 dots, 0 is 5x8 dots mode
void functionSet(int DL,int N,int F){
    pinset(8,11,HIGH);
    digitalWrite(9,HIGH);
    if(DL == 1)
        digitalWrite(D4,HIGH);
    else
        digitalWrite(D4,LOW);
    if(N == 1)
        digitalWrite(D3,HIGH);
    else
        digitalWrite(D3,LOW);
    if(F == 1)
        digitalWrite(D2,HIGH);
    else
        digitalWrite(D2,LOW);
    enable();
}

void shiftCursor(int isRight){
    pinset(7,11,LOW);
    digitalWrite(D4,HIGH);
    digitalWrite(D3,LOW);
    if(isRight == 1)
        digitalWrite(D2,HIGH);
    else
        digitalWrite(D2,LOW);
    enable();
}

void clearDisp(){
    digitalWrite(RS,LOW);
    digitalWrite(RW,LOW);
    pinset(3,12,0);
    digitalWrite(2,HIGH);
    enable();
}

void setChar(char c){
    digitalWrite(RS,HIGH);
    digitalWrite(RW,LOW);
    sendByte(c);
}
void writeString(const char* s){
    int length = len(s);
    for(int i = 0; i < length; i++){
       setChar(s[i]);
    }
}
void writeNum(int n){
    int d = n;
    int size = 0;
    Serial.print(1);
    while(d > 0){
        size++;
        d /= 10;
    }
    char s[size];
    for(int i = size-1; i >= 0; i--){
        s[i] = n % 10;
    }
    writeString(s);
}

void setup(){
    for(int i = 2; i <= 12; i++){
        pinMode(i,OUTPUT);
    }
    pinMode(13,OUTPUT);
    functionSet(1,1,1);
    setDir(1,0);
    clearDisp();
    showCursor(1,0,1);
    Serial.begin(9600);
}

void loop(){
    writeString("1234");
    delay(2000);
    clearDisp();
}
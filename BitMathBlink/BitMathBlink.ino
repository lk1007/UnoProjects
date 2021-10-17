#define PB *((volatile byte*)0x25)
#define DB *((volatile byte*)0x24)

 

void setup() {
  // put your setup code here, to run once:
DB = DB | (1<<5);
}

void loop() {
  // put your main code here, to run repeatedly:
PB = PB | (1<<5);
delay(4000);
PB = PB &~ (1<<5);
delay(2000);

}

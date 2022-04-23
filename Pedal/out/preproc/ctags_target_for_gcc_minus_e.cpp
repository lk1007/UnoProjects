# 1 "c:\\Users\\Liam Kain\\Personal_Projects\\Practice\\UnoProjects\\Pedal\\pedal\\pedal.ino"
void setup() {
  pinMode(9,0x0);
  pinMode(10,0x0);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(10));
  Serial.print(digitalRead(9));
  Serial.println();
  delay(30);
}

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

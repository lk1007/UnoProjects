/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

#define PB *((volatile byte*)0x25)
#define DB *((volatile byte*)0x24)

void setup() {

	DB = 32;
}

void loop() {

	PB = 0;
	delay(2000);
	PB = 0;
	delay(2000);

}

#include <Arduino.h>

/*
 Name:		tp1.ino
 Created:	4/29/2022 11:55:22 AM
 Author:	dinis
*/

int estadoBotao = 0;

// the setup function runs once when you press reset or power the board
void setup() {
	
	pinMode(2, INPUT);
	pinMode(A0, INPUT);
	for (int i = 3; i < 14; i++)
	{
		pinMode(i, OUTPUT);
	}
	digitalWrite(13, HIGH);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
		
	estadoBotao = digitalRead(2);
	
	if (estadoBotao == HIGH)
	{
		Serial.println("botao on");
		delay(2000);
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		delay(2000);
		digitalWrite(12, LOW);
		digitalWrite(11, HIGH);
		delay(2000);
	}
}
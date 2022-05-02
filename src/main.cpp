#include <Arduino.h>

/*
 Name:		tac-trabalho-pratico-1.ino
 Created:	4/29/2022 11:55:22 AM
 Author:	dinis
*/

int estadoBotao = 0;
int contador = 9;

// the setup function runs once when you press reset or power the board
void setup() {
	
	//inicialização dos pinos
	pinMode(2, INPUT);
	pinMode(A0, INPUT);
	for (int i = 3; i < 14; i++)
	{
		pinMode(i, OUTPUT);
	}

	//semáforo para carros (verde por default)
	digitalWrite(13, HIGH);

	//semáforo para peões (vermelho por default)
	digitalWrite(9, HIGH);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
		
	estadoBotao = digitalRead(2);
	
	if (estadoBotao == HIGH)
	{
		//teste botão
		Serial.println("botao on");

		//semáforo para carros (de verde para vermelho)
		delay(2000);
		digitalWrite(13, LOW);
		digitalWrite(12, HIGH);
		delay(2000);
		digitalWrite(12, LOW);
		digitalWrite(11, HIGH);
		delay(2000);

		//semáforo para peões (de vermelho para verde)
		digitalWrite(9, LOW);
		digitalWrite(10, HIGH);
		
		//delay de 10 segundos com o contador !!DEBUG!!
		for (int i = contador; i >= 0; i--)
		{

			i & 8 ? digitalWrite(7, HIGH) : digitalWrite(7, LOW);
			i & 4 ? digitalWrite(6, HIGH) : digitalWrite(6, LOW);
			i & 2 ? digitalWrite(5, HIGH) : digitalWrite(5, LOW);
			i & 1 ? digitalWrite(4, HIGH) : digitalWrite(4, LOW);

		}

	}

}
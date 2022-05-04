#include <Arduino.h>

void intermitenteLed3 ();

unsigned long tempo = 0;
unsigned long tempoAnteriorLed3 = 0;
unsigned long intervaloLed3 = 500;
int estadoLed3 = 0;

/*
 Name:		tac-trabalho-pratico-1.ino
 Created:	4/29/2022 11:55:22 AM
 Author:	dinis
*/

int estadoBotao = 0;
int contador = 9;
int buzzer = 3;

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

	//alarme intermitente (apagado por default)
	digitalWrite(8, LOW);

	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {

	tempo = millis();
    intermitenteLed3();
		
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
		
		//delay de 10 segundos com o contador
		for (int i = contador; i >= 0; i--)
		{
			Serial.println(i); //teste contador

			i & 8 ? digitalWrite(7, HIGH) : digitalWrite(7, LOW);
			i & 4 ? digitalWrite(6, HIGH) : digitalWrite(6, LOW);
			i & 2 ? digitalWrite(5, HIGH) : digitalWrite(5, LOW);
			i & 1 ? digitalWrite(4, HIGH) : digitalWrite(4, LOW);
			delay(1000);
		}

		//buzzer !!DEBUG!!
		for (int i = 50; i < 401; i++)
		{
			tone(3, i);
			delay(8);
		}
		
		delay(1000);

		for (int i = 400; i > 49; i--)
		{
			tone(3, i);
			delay(2);
		}
		noTone(3);

		//luz vermelha intermitente no semáforo para peões (6 segundos)
		digitalWrite(10, LOW);
		for (int i = 0; i < 6; i++)
		{
			digitalWrite(9, HIGH);
			delay(500);
			digitalWrite(9, LOW);
			delay(500);
		}
		digitalWrite(9, HIGH); //luz vermelha no semáforo para peões
		
		//semáforo para carros (de vermelho para verde)
		digitalWrite(11, LOW);
		digitalWrite(13, HIGH);

	}
}

void intermitenteLed3()
{
    int fotoresistor = analogRead(A0);

	Serial.println(fotoresistor);

    if (tempo % 100 == 0)
    {
        if (fotoresistor <= 45)
        {               
            if (tempo - tempoAnteriorLed3 > intervaloLed3)
            {
                tempoAnteriorLed3 = tempo;
                if (estadoLed3 == 0) estadoLed3 = 1;
                else estadoLed3 = 0;
                digitalWrite(8, estadoLed3);    
            }  
        }
        else digitalWrite(8, LOW);
    }
}
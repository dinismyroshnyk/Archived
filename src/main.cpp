#include <Arduino.h>

void intermitente(); //FEITO
void maquinaEstados();

void setup() //FEITO
{
	//inicialização dos pinos
	pinMode(2, INPUT);
	pinMode(A0, INPUT);
	for (int i = 3; i < 14; i++) pinMode(i, OUTPUT);

	//semáforo para carros (verde por default)
	digitalWrite(13, HIGH);

	//semáforo para peões (vermelho por default)
	digitalWrite(9, HIGH);

	//alarme intermitente (apagado por default)
	digitalWrite(8, LOW);

	Serial.begin(9600);
}

void loop() //FEITO
{   
    intermitente();
    maquinaEstados();
}

void intermitente() //FEITO
{
    static unsigned long tempo = millis();
    int fotoresistor = analogRead(A0);

    Serial.println(fotoresistor);
    
    if (fotoresistor <= 75)
    {               
        if (millis() - tempo >= 500)
        {
            digitalWrite(8, !digitalRead(8));
            tempo = millis();
        }  
    }
    else digitalWrite(8, LOW);
}

void maquinaEstados()
{
    static unsigned long tempo = millis();
    static unsigned long buzzer; //tempo que o buzzer fica ligado

    enum class estadoSemaforo {
        PARADO,
        CARROS,
        PEOES,
        ALARME
    };

    static estadoSemaforo estadoAtual = estadoSemaforo::PARADO;

    switch (estadoAtual)
    {
    case estadoSemaforo::PARADO:    
        if (digitalRead(2) == HIGH)
        {
            tempo = millis();
            estadoAtual = estadoSemaforo::CARROS;
        }    
        break;
    case estadoSemaforo::CARROS:
        if (millis() - tempo >= 2000 && digitalRead(13) == HIGH)
        {
            digitalWrite(13, LOW);
            digitalWrite(12, HIGH);
        }
        if (millis() - tempo >= 4000 && digitalRead(12) == HIGH)
        {
            digitalWrite(12, LOW);
            digitalWrite(11, HIGH);
            estadoAtual = estadoSemaforo::PEOES;
        }        
    break;
    case estadoSemaforo::PEOES:
        static unsigned long tempoContador = 0;
        static int i = 9;
        if (millis() - tempo >= 6000 && digitalRead(11) == HIGH)
        {
            digitalWrite(10, HIGH);
            digitalWrite(9, LOW);

            if (millis() - tempoContador >= 1000 && i >= 0)
            {
                tempoContador = millis();
                Serial.println(i); //teste contador

                i & 8 ? digitalWrite(7, HIGH) : digitalWrite(7, LOW);
                i & 4 ? digitalWrite(6, HIGH) : digitalWrite(6, LOW);
                i & 2 ? digitalWrite(5, HIGH) : digitalWrite(5, LOW);
                i & 1 ? digitalWrite(4, HIGH) : digitalWrite(4, LOW);
                i--;
            }
            if (i < 0) estadoAtual = estadoSemaforo::ALARME;
        }      
    break;
    case estadoSemaforo::ALARME:
        static unsigned long tempoAlarme = 1000;
        digitalWrite(10, LOW);
        if (millis() - tempo >= 16000 && millis() - tempo <= 22000)
        {
            if (millis() - tempoAlarme >= 500)
            {
                tempoAlarme = millis();
                digitalWrite(9, !digitalRead(9));
                for (int i = 50; i < 401; i++)
                {
                    tone(3, i);
                }
            }
        } 
        if (millis() - tempo > 22000)
        {
            digitalWrite(9, HIGH);
            noTone(3);
            digitalWrite(11, LOW);
            digitalWrite(13, HIGH);
            i = 9;
            estadoAtual = estadoSemaforo::PARADO;
        }          
    break;
    default: Serial.println("Erro");
        break;
    }
}
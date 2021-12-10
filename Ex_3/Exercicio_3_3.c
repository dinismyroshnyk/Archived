#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 3.3
int main(){

	//begin_inputs
  int total_segundos;

  printf("Por favor introduza o numero de segundos:");
  scanf("%d",&total_segundos);
	//end_inputs

  int horas,minutos,segundos,segundos_resto;
  int segundos_hora = 60*60;
  int segundos_minuto = 60;

    horas = total_segundos/segundos_hora;
    segundos_resto = total_segundos - horas*segundos_hora;
    minutos = segundos_resto/segundos_minuto;
    segundos_resto = segundos_resto - minutos*segundos_minuto;
    segundos = segundos_resto;

  printf("%d segundos = %d:%d:%d",total_segundos,horas,minutos,segundos);

	return 0;
}

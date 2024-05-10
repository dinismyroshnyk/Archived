#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 3.2
int main(){

//begin_inputs
  int horas,minutos,segundos;
  printf("Por favor digite:\n");
  printf("Horas:");
  scanf("%d",&horas);
  printf("Minutos:");
  scanf("%d",&minutos);
  printf("Segundos:");
  scanf("%d",&segundos);
//end_inputs

  printf("%d:%d:%d = %d segundos",horas,minutos,segundos,horas*3600+minutos*60+segundos);

	return 0;
}

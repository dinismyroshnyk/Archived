#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.4
int main(){

	//begin_inputs

  int total_numeros,num_inicial;

  printf("Introduza o numero inicial: ");
  scanf("%d",&num_inicial);
  printf("\nIntroduza o numero total de numeros: ");
  scanf("%d",&total_numeros);

	//end_inputs

  printf("total_numeros: %d - num_inicial: %d - resultado: ",total_numeros,num_inicial);

  while (total_numeros>0) {

    if ((num_inicial % 3) == 0 && (num_inicial % 5) != 0) {
      printf("%d ",num_inicial);
      total_numeros--;
      num_inicial++;
    } else {
        num_inicial++;
    }

  }

	return 0;
}

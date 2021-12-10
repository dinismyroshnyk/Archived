#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.1
int main(){

	//begin_inputs

  int num_final;

  printf("Introduza um valor: ");
  scanf("%d",&num_final);

	//end_inputs

  int soma,i;
  soma = 0;

  for (i = 0; i <= num_final; i++) {
    soma = soma + i;
  }

  printf("num_final: %d - soma: %d",num_final,soma);

	return 0;
}

#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.7
int main(){

	//begin_inputs

  int num_oper;

  printf("Introduza o numero de operacoes: ");
  scanf("%d",&num_oper);

	//end_inputs

  double pi = 1;

  for (int i = 0; i < num_oper; i++) {
    double denominador = i*2 + 3;
      if (i % 2==0) {
        pi = pi - 1/denominador;
      } else {
        pi = pi + 1/denominador;
      }
  }

  printf("num_oper: %d - PI: %lf",num_oper,pi*4);

	return 0;
}

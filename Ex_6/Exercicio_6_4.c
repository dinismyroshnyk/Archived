#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.4
int fatorial(int numero);
int main(){

	//begin_inputs

  int numero;
  printf("Introduza um numero: ");
  scanf("%d",&numero);

	//end_inputs

  fatorial(numero);
  printf("Fatorial de %d: %d",numero,fatorial(numero));

	return 0;
}

int fatorial(int numero){
  int reserva = numero, fatorial = numero;
  for (int i = reserva; i > 1; i--) {
    reserva--;
    fatorial = fatorial * reserva;
  }
  return fatorial;
}

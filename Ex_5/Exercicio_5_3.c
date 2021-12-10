#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.3
int main(){

	//begin_inputs

  int numero;

  printf("Introduza um numero: ");
  scanf("%d",&numero);

	//end_inputs

  int min=1,max=50;

  printf("numero: %d - multiplos: ",numero);
  while (min<=max) {
    if ((min % numero) == 0) {
      printf("%d ",min);
    }
    min++;
  }

	return 0;
}

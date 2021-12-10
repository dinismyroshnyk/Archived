#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.2
int main(){

	//begin_inputs

  int A,B;

  printf("Introduza 2 muneros inteiros : \n");
  scanf("%d%d",&A,&B);

	//end_inputs

  if (A<=B) {

    int cont=A, produto=1;

    while (A<=B) {
      produto = produto * A;
      A++;
    }

    printf("A: %d - B: %d - produto: %d",cont,B,produto);

  } else {
      printf("entrada invalida");
  }

	return 0;
}

#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.2

float testaTriangulo(float ladoA,float ladoB,float ladoC);

int main(){

	//begin_inputs

  float ladoA,ladoB,ladoC;
  printf("Introduza os lados do triangulo: \n");
  scanf("%f%f%f",&ladoA,&ladoB,&ladoC);

	//end_inputs

  testaTriangulo(ladoA,ladoB,ladoC);

  if (testaTriangulo(ladoA,ladoB,ladoC) == 1) {
    printf("Com os lados %.1f, %.1f e %.1f podemos formar um triangulo",ladoA,ladoB,ladoC);
  } else {
    printf("Com os lados %.1f, %.1f e %.1f nao podemos formar um triangulo",ladoA,ladoB,ladoC);
  }

	return 0;
}

float testaTriangulo(float ladoA,float ladoB,float ladoC){
  if (ladoA < ladoB+ladoC && ladoB < ladoA+ladoC && ladoC < ladoA+ladoB) {
    return 1;
  } else {
    return 0;
  }
}

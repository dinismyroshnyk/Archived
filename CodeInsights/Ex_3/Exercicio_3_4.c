#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 3.4
int main(){

	//begin_inputs

  float graus_f;
  printf("Introduza a temperatura em Fahrenheit: ");
  scanf("%f",&graus_f);

	//end_inputs

  float graus_c = ((graus_f-32)/9)*5;
  printf("%.2fº F = %.1fº C",graus_f,graus_c);

	return 0;
}

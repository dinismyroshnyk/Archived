#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 3.5
int main(){

	//begin_inputs

  float raio;
  float altura;

  printf("Por favor introduza o raio em metros:");
  scanf("%f",&raio);
  printf("Por favor introduza a altura em metros:");
  scanf("%f",&altura);

	//end_inputs

  float pi = 3.14159;
  float volume = pi*raio*raio*altura;

  printf("Volume (r = %.2f, a = %.2f) = %.3f m3",raio,altura,volume);

	return 0;
}

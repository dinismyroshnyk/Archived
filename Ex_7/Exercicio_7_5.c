#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.5
int main(){

	//begin_inputs

  float dados [][2] = { {56, 1.68},
                        {92, 1.70},
                        {63, 1.73},
                        {93, 1.91},
                        {50, 1.75},
                        {45, 1.49} };

  const int num_pessoas = 6;

	//end_inputs

  printf("Peso  Alt     IMC   Classificacao");
  for (int i = 0; i < num_pessoas; i++) {

    float imc = dados[i][0] / (dados[i][1] * dados[i][1]);

    printf("\n%.1f %.2f - %.2f - ",dados[i][0],dados[i][1],imc);
    if (imc <= 18.5) {
      printf("abaixo peso ideal");
    }else if (18.5 < imc && imc < 25){
      printf("peso normal");
    }else if (25 <= imc && imc < 30){
      printf("acima peso ideal");
    }else if (30 <= imc && imc < 35){
      printf("obesidade grau I");
    }else if (35 <= imc && imc < 40){
      printf("obesidade grau II");
    }else if (imc >= 40){
      printf("obesidade grau III");
    }
  }

	return 0;
}

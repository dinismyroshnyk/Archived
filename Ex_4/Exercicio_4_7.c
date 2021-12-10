#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 4.7
int main(){

	//begin_inputs

  float valor_imovel;
  printf("Introduza o valor do imovel: \n");
  scanf("%f",&valor_imovel);

	//end_inputs

  if (valor_imovel<=92407 && valor_imovel>0) {
    printf("valor do imovel: %.2f - IMT: isento",valor_imovel);
  } else {
      if (valor_imovel>92407 && valor_imovel<=126403) {
        printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.02-1848.14);
      } else {
          if (valor_imovel>126403 && valor_imovel<=172348) {
            printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.05-5640.23);
          } else {
              if (valor_imovel>172348 && valor_imovel<=287213) {
                printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.07-9087.22);
              } else {
                  if (valor_imovel>287213 && valor_imovel<=574323) {
                    printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.08-11959.26);
                  } else {
                      if (valor_imovel>574323 && valor_imovel<=1000000) {
                        printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.06);
                      } else {
                          printf("valor do imovel: %.2f - IMT: %.2f",valor_imovel,valor_imovel*0.075);
                      }
                  }
              }
          }
      }
  }

	return 0;
}

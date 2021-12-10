#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.5
int main(){

	//begin_inputs

  int numero;

  printf("Digite um numero: ");
  scanf("%d",&numero);

	//end_inputs

  int divisao,resto,soma=0,num=numero;

  if (numero <= 0 ) {
    printf("numero invalido");
  } else {
      do {

        resto = num % 10;
        soma = soma + resto;
        num = num / 10;

      } while(num>0);
      printf("numero: %d - soma dos digitos: %d",numero,soma);
    }

	return 0;
}

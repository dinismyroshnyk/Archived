#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.3

char minuscula(char caractere);
int letra(char caractere);
int main(){

	//begin_inputs

  char caractere;
  printf("Introduza uma letra: \n");
  caractere = getchar();

	//end_inputs

  letra(caractere);

  if (letra(caractere) == 1) {
    minuscula(caractere);
    printf("caractere %c : letra - minuscula: %c",caractere,minuscula(caractere));
  } else {
    printf("caractere %c : nao letra",caractere);
  }

	return 0;
}

int letra(char caractere){
  if ((caractere>=65 && caractere<=90) || (caractere>=97 && caractere<=122) ) {
    return 1;
  } else {
    return 0;
  }
}

char minuscula(char caractere){
  if (caractere >= 65 && caractere <= 90) {
    return caractere + 32;
  } else {
    return caractere;
  }
}

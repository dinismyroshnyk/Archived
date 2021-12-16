#include <stdio.h>
#include <string.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.3

int meu_strlen(char string[]);

int main(){

	//begin_inputs

  char str[22];
  printf("Excreva algo (maximo 20 carateres):\n");

  fgets(str, 22, stdin);

  str[strlen(str)-1] = 0;

	//end_inputs
  
  printf("string: %s\n",str);
  printf("tamanho(strlen): %d\n",strlen(str));
  printf("tamanho(minha funcao): %d",meu_strlen(str));

	return 0;
}

int meu_strlen(char str[22]){

  int tamanho = 0;
  for (int i = 0; str[i] != 0; i++) {
    tamanho += 1;
  }
  return tamanho;
}

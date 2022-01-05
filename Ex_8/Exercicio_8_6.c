#include <stdio.h>
#include <string.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.6

int contaPalavras(char frase[], char palavra[]);

int main(){

	//begin_inputs

  char str_frase[52], str_palavra[52];

  printf("Excreva algo (maximo 50 carateres): ");
  fgets(str_frase, 52, stdin);
  str_frase[strlen(str_frase)-1] = 0;

  printf("Digite a palavra a pesquisar: ");
  fgets(str_palavra, 52, stdin);
  str_palavra[strlen(str_palavra)-1] = 0;

	//end_inputs

  printf("frase: %s",str_frase);
  printf("\npalavra: %s",str_palavra);
  printf("\nocorrencias: %d",contaPalavras(str_frase,str_palavra));

	return 0;
}


int contaPalavras(char str_frase[], char str_palavra[]){

  int ocorrencias = 0;

  for (int i = 0; i < strlen(str_frase); i++) {

    int temporario = i, verifica;

    for (int j = 0; j < strlen(str_palavra); j++) {
      if (str_frase[i] == str_palavra[j]) {
        i++;
      }
    }

    verifica = i - temporario;

    if (verifica == strlen(str_palavra)) {
      ocorrencias++;
    }

    i = temporario;
  }
  return ocorrencias;
}

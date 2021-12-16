#include <stdio.h>
#include <string.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.1
int main(){

	//begin_inputs

  char str1[22], str2[22];
  printf("Excreva algo (maximo 20 carateres):\n");

  fgets(str1, 22, stdin);
  fgets(str2, 22, stdin);

  str1[strlen(str1)-1] = 0;
  str2[strlen(str2)-1] = 0;

	//end_inputs
  char str1cpy[22], str2cpy[22];

  strcpy(str2cpy, str1);
  strcpy(str1cpy, str2);

  printf("primeiro string: %s - segundo string: %s\n",str1, str2);
  printf("apos a troca\n");
  printf("primeiro string: %s - segundo string: %s\n",str1cpy, str2cpy);

	return 0;
}

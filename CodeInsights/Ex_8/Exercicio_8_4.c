#include <stdio.h>
#include <string.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.4
int main(){

	//begin_inputs

  char str[22];
  printf("Excreva algo (maximo 20 carateres):\n");

  fgets(str, 22, stdin);

  str[strlen(str)-1] = 0;

	//end_inputs

  int letra = 0, num = 0, outro = 0;

  for (int i = 0; str[i] != 0; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
      letra += 1;
    }else if (str[i] >= '0' && str[i] <= '9'){
      num += 1;
    }else outro += 1;
  }

  printf("string: %s\n",str);
  printf("letras: %d - numeros: %d - outros: %d",letra,num,outro);

	return 0;
}

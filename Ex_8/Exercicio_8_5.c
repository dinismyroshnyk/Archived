#include <stdio.h>
#include <string.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.5

int binarioParaDecimal(char str[]);

int main(){

	//begin_inputs

  char str[21];

  printf("Introduza um numero em binario (0 e 1 - max: 20 carateres): \n");
  scanf("%s",str);

	//end_inputs
  if (binarioParaDecimal(str) == -1) {
    printf("binario: %s - entrada invalida\n",str);
  }else{
    printf("binario: %s - decimal: %d\n",str,binarioParaDecimal(str));
  }

	return 0;
}

int binarioParaDecimal(char str[]){

  int decimal = 0, carry = 1;
  for (int i = (strlen(str) - 1); i >= 0; i--) {
    if (str[i] != '0' && str[i] != '1') {
      return -1;
    }else{
      decimal += (str[i] - 48) * carry;
      carry *= 2;
    }
  }
  return decimal;
}

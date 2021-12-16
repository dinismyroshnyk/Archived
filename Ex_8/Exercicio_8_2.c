#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 8.2
int main(){

	//begin_inputs

  printf("Excreva algo (maximo 20 carateres):\n");
  char str[22];

  scanf("%s",str);

	//end_inputs

  printf("antes : %s\n",str);

  for (int i = 0; str[i] != 0; i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] -= 32;
    }
  }

  printf("depois: %s",str);

	return 0;
}

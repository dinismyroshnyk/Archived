#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 5.6
int main(){

	//begin_inputs

  int altura;

  printf("Introduza a altura: ");
  scanf("%d",&altura);

	//end_inputs

  int qnt_num,linha,num = 0;

  for (linha = 1; linha <= altura; linha++) {
    for (qnt_num = 0; qnt_num < linha; qnt_num++) {
      num++;
      printf("%2d ",num);
    }
    printf("\n");
  }
	return 0;
}

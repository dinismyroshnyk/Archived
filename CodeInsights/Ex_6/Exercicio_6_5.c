#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.5

int bissexto(int ano);
int main(){

	//begin_inputs

  int ano;
  printf("Introduza o ano: ");
  scanf("%d",&ano);

	//end_inputs

  if (bissexto(ano)==1) {
    printf("ano: %d - bissexto",ano);
  } else {
      printf("ano: %d - nao bissexto",ano);
  }

	return 0;
}

int bissexto(int ano){
  if ((ano%4 == 0  && ano%100 != 0) || ano%400==0) {
    return 1;
  } else {
    return 0;
  }
}

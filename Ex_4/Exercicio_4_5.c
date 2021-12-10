#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 4.5
int main(){
  
	//begin_inputs

  int A,B,C;
  printf("Digite 3 numeros inteiros: \n");
  scanf("%d%d%d",&A,&B,&C);

	//end_inputs

  A>=B && A>=C ?
    printf("A: %d - B: %d - C: %d - maior: %d",A,B,C,A):
    B>=A && B>=C ?
      printf("A: %d - B: %d - C: %d - maior: %d",A,B,C,B):
        printf("A: %d - B: %d - C: %d - maior: %d",A,B,C,C);

	return 0;
}

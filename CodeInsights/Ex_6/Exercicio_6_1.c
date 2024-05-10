#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.1

int menor(int a, int b, int c);

int main(){

	//begin_inputs

	int A,B,C;
	printf("Digite 3 numeros: \n");
	scanf("%d%d%d",&A,&B,&C);

	//end_inputs

	menor(A,B,C);
	printf("A: %d - B: %d - C: %d - menor: %d",A,B,C,menor(A,B,C));

	return 0;
}

int menor(int a, int b, int c){
	if (a <= b  && a <= c) {
		return a;
	} else {
		if (b <= a && b <= c) {
			return b;
		} else {
			return c;
		}
	}
}

#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.1
int main(){

	//begin_inputs

	const int tamanho = 10;
	int dados[tamanho];

	printf("Insira 10 numeros: \n");

	for (int i = 0; i < tamanho; i++) {
		scanf("%d",&dados[i]);
	}

	//end_inputs

	printf("numeros introduzidos: ");

	int total = 0;

	for (int x = 0; x < tamanho; x++) {
		printf("%d ",dados[x]);
		total += dados[x];
	}

	printf("- media: %.1f",(float)total/tamanho);

	return 0;
}

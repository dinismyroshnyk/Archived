#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.4

void desloca_direita(int a[], int tam);
void imprime(int a[], int tam);

int main(){

	//begin_inputs

  int meuVector[] = {1,2,3,4,5,6};
  const int tamanho = 6;

	//end_inputs

  imprime(meuVector,tamanho);

	return 0;
}

void desloca_direita(int a[], int tam) {

  int ultimo_elemento = a[tam - 1], j;

  for (j = tam - 1; j > 0; j--) {
    a[j] = a[j - 1];
  }

  a[0] = ultimo_elemento;
}

void imprime(int a[],int tam) {

  int i;

  printf("antes : ");
  for (i = 0; i < tam; i++) {
    printf(" %d ",a[i]);
  }

  printf("\ndepois: ");
  desloca_direita(a,tam);
  for (i= 0; i < tam; i++) {
    printf(" %d ",a[i]);
  }
}

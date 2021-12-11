#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.4

void desloca_direita(int meuVector[],int tamanho);
void imprime(int meuVector[],int tamanho);

int main(){

	//begin_inputs

  int meuVector[] = {1,2,3,4,5,6};
  const int tamanho = 6;

	//end_inputs

  imprime(meuVector,tamanho);

	return 0;
}

void desloca_direita(int meuVector[],const int tamanho) {

  int ultimo_elemento = meuVector[tamanho - 1], j;

  for (j = tamanho - 1; j > 0; j--) {
    meuVector[j] = meuVector[j - 1];
  }

  meuVector[0] = ultimo_elemento;
}

void imprime(int meuVector[],const int tamanho) {
  int i;
  printf("antes :");
  for (i = 0; i < tamanho; i++) {
    printf("  %d",meuVector[i]);
  }
  printf("\ndepois:");
  desloca_direita(meuVector,tamanho);
  for (i= 0; i < tamanho; i++) {
    printf("  %d",meuVector[i]);
  }
}

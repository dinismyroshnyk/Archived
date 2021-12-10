#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.2
int main(){

	//begin_inputs

  const int num_alunos = 6;
  int notas[] = {14,12,13,14,15,8};

	//end_inputs


  int media = 0;
  int maior = notas[1];
  int menor = notas[1];

  printf("notas: ");
  for (int i = 0; i < num_alunos; i++) {
    media += notas[i];
    printf("%d ",notas[i]);

    if (maior < notas[i]) {
      maior = notas[i];
    }
    if (menor > notas[i]) {
      menor = notas[i];
    }
  }

  printf("\nmedia: %.1f - maior: %d - menor: %d",(float)media/num_alunos,maior,menor);

	return 0;
}

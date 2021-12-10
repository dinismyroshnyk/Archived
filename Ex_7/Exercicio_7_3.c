#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.3
int main(){

	//begin_inputs

  const int num_votos = 12, num_candidatos = 5;
  int votos[] = {2,4,5,1,2,3,2,2,1,4,5,2};

	//end_inputs

  int cont_votos[num_candidatos];

  for (int i = 0; i < num_candidatos; i++) {
    cont_votos[i] = 0;
  }

  for (int j = 0; j < num_votos; j++) {
    cont_votos[votos[j]-1] += 1;
  }

  for (int x = 0; x < num_candidatos; x++) {
    printf("candidato %d: %d votos\n",x+1,cont_votos[x]);
  }

	return 0;
}

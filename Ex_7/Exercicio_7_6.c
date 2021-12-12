#include <stdio.h>
#define NUM_JOGADORES 6
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 7.6

void somaPontos(int jogos[][NUM_JOGADORES], int pontos[]);
void imprimeTabela(int jogos[][NUM_JOGADORES], int pontos[]);
float percentagemEmpates(int jogos[][NUM_JOGADORES]);

int main(){

	//begin_inputs

  int jogos[][NUM_JOGADORES]={ {0, 1, 2, 0, 1, 2},
                               {1, 0, 2, 1, 1, 1},
                               {0, 0, 0, 2, 2, 2},
                               {2, 1, 0, 0, 1, 2},
                               {1, 1, 0, 1, 0, 0},
                               {0, 1, 0, 0, 2, 0} };

	//end_inputs

  int pontos[NUM_JOGADORES];
  imprimeTabela(jogos,pontos);
	return 0;
}


void somaPontos(int jogos[][NUM_JOGADORES], int pontos[]){

  for (int i = 0; i < NUM_JOGADORES; i++) {
    pontos[i] = 0;
  }

  for (int i = 0; i < NUM_JOGADORES; i++) {
    for (int j = 0; j < NUM_JOGADORES; j++) {
      pontos[i] += jogos[i][j];
    }
  }

}


float percentagemEmpates(int jogos[][NUM_JOGADORES]){

  int empates = 0;

  for (int i = 0; i < NUM_JOGADORES; i++) {
    for (int j = 0; j < NUM_JOGADORES; j++) {
      if (jogos[i][j] == 1) {
        empates += 1;
      }
    }
  }

  int total_jogadores = (NUM_JOGADORES * NUM_JOGADORES) - NUM_JOGADORES;
  float percentEmpates = ((float)empates * 100) / total_jogadores;

  return percentEmpates;
}


void imprimeTabela(int jogos[][NUM_JOGADORES], int pontos[]){

  // Apresenta a 1ºa linha do output em função do número de jogadores
  // Neste exercicio podia ser substituido por
  // printf("         J1 J2 J3 J4 J5 J6  Pontos\n");
  printf("         ");
  for (int i = 0; i < NUM_JOGADORES; i++) {
    printf("J%d ",i + 1);
  }
  printf(" Pontos\n");

  for (int i = 0; i < NUM_JOGADORES; i++) {
    printf("Jogador%d ",i + 1);
    for (int j = 0; j < NUM_JOGADORES; j++) {
      printf(" %d ",jogos[i][j]);
    }
    somaPontos(jogos,pontos);
    printf("  %d\n",pontos[i]);
  }

  printf("Percentagem de empates: %.1f %%",percentagemEmpates(jogos));

}

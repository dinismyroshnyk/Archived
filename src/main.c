#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100

int main(){

	int opcao;
	char descricao[52];
	int importancia;
	int dia,mes,ano;
	int tarefas[MAX_TAREFAS][2];
	int data[MAX_TAREFAS][3];
	char descricaoTarefa[MAX_TAREFAS][52];

	do
	{
		system("cls");

		printf("======================\n");
		printf("    MENU PRINCIPAL\n");
		printf("======================\n\n");
		printf("1 - Inserir tarefas\n");
		printf("2 - Concluir tarefas\n");
		printf("3 - Consultar tarefas\n");
		printf("4 - Guardar os dados\n");
		printf("0 - Sair\n\n");

		printf("Opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 1:
				
				inserirTarefa(descricao, &importancia, &dia, &mes, &ano, tarefas[MAX_TAREFAS][2], data);

				for (int i = 0; i < MAX_TAREFAS; i++)
				{
					tarefas[i][0] = 0;
					tarefas[i][1] = importancia;

					data[i][0] = dia;
					data[i][1] = mes;
					data[i][2] = ano;

					strcpy(descricaoTarefa[i], descricao);

					break;
				}
				
				break;

			case 2: //TESTE TEMPORÁRIO DAS VARIÁVEIS
				//printf("\ndescricao: %s \nimportancia: %d \ndata: %02d/%02d/%04d \n", descricao, importancia, dia, mes, ano);
				for (int i = 0; i < MAX_TAREFAS; i++)
				{
					printf("tarefa %d: %d %d %02d/%02d/%04d %s\n", i+1, tarefas[i][0], tarefas[i][1], dia, mes, ano, descricaoTarefa);
				}
				
				break;

			case 3:

				menuTarefas();

				break;

			case 4:
				/* code */
				break;

			case 0:
				break;

			default: printf("\nOpcao invalida\n");
				break;
		}

		if (opcao != 0)
		{
			printf("\nPressione Enter para voltar ...");
			fflush(stdin);
			getchar();
		}

	} while (opcao != 0);

	return 0;

}

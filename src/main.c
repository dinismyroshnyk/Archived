#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

//VARIÁVEIS GLOBAIS (INÍCIO)
char descricao[52];
int importancia;
int dia,mes,ano;
//VARIÁVEIS GLOBAIS (FIM)

int main(){

	int opcao;

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

				inserirTarefa(descricao, &importancia, &dia, &mes, &ano);

				break;

			case 2:
				printf("\ndescricao: %s \nimportancia: %d \ndata: %02d/%02d/%04d", descricao, importancia, dia, mes, ano);
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

#include "prototipos.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

	int opcao;
	int opcao_sub;

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
				/* code */
				break;

			case 2:
				/* code */
				break;

			case 3:

				menuTarefas(opcao_sub);

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

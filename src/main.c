#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "proto.h"

#define NUM_CLIENTES 5
#define NUM_CONTAS 3

FILE *fclientes, *fpins;

//Estruturas
typedef struct transacao {
	int tipo[3];
	int data[3];
	float montante;
	int local[3];
} transacao;

typedef struct historico{
	transacao transacao;
	struct historico *prox;
} historico;

typedef struct contas {
	int num_conta;
	struct historico movimentos;
} contas;

typedef struct cliente {
	char nome_cliente[20];
	int telefone_cliente;
	char endereco_cliente[20];
	int num_cliente;
	int num_pin;
	struct contas conta[NUM_CONTAS];		
} cliente;

int main()
{
	//Variáveis
	int opcao;
	int num;
	int pin;
	int i; 
	int j;
	cliente cliente[NUM_CLIENTES];
	
	//Menu
	do
	{

		//Ficheiros
		fclientes = fopen("clientes.txt", "rb");
		fpins = fopen("pins.txt", "rb");

		printf("=============================\n");
		printf("Introduza 1 para fazer login \n");
		printf("Introduza 0 para sair \n");
		printf("=============================\n");
		printf("\nOpcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 0: break;
			case 1:
				printf("\nIntroduza o numero do cliente: ");
				scanf("%d", &num);
				printf("Introduza o pin: ");
				scanf("%d", &pin);

				if (num == 0 && pin == 1234)
				{
					//Vaiariaveis Admin
					int opcao_admin;

					printf("\nEfetuado login como administrador \n\n");
					//fclose("clientes.txt");
					//fclose("pins.txt");

					//Menu administrador
					do
					{
						printf("===============================================\n");
						printf("Introduza 1 para editar e criar os dados do cliente especificado\n");
						printf("Introduza 2 para criar ou adicionar uma nova conta ao cliente especificado \n");
						printf("Introduza 3 para realizar consultas \n");
						printf("Introduza 0 para sair \n");
						printf("================================================\n");
						printf("\nOpcao: ");
						scanf("%d", &opcao_admin);
						
						if (opcao_admin != 0)
						{
							printf("\nCliente (entre 1 e %i): ", NUM_CLIENTES);
							scanf("%i", &i);
						}
						
						switch (opcao_admin)
						{
							case 0: break;
							case 1:
								printf("\nIntroduza o nome do cliente: ");
								scanf("%s", cliente[i - 1].nome_cliente);
								printf("\nIntroduza o numero do telefone do cliente: ");
								scanf("%d", &cliente[i - 1].telefone_cliente);
								printf("\nIntroduza o endereco de email do cliente: ");
								scanf("%s", cliente[i - 1].endereco_cliente);
								printf("\nIntroduza o numero do cliente: ");
								scanf("%d", &cliente[i - 1].num_cliente);
								printf("\nIntroduza o pin do cliente: ");
								scanf("%d", &cliente[i - 1].num_pin);							
								break;

							case 2 :

								printf("\nIntroduza o numero da conta a ser criada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &j);
								cliente[i - 1].conta[j - 1].num_conta = j;
								break;

							case 3 :
								printf("\nIntroduza o numero do cliente: ");
								scanf("%d", &cliente[i - 1].num_cliente);
								break;

							default: printf("\nOcorreu um erro, tente novamente! \n");
								break;

						}
					} while (opcao_admin != 0);
				}else
				{
					int opcao_cliente;
					printf("\nEfetuado login como cliente \n\n");
					//fclose("clientes.txt");
					//fclose("pins.txt");
					
					//Menu cliente
					do
					{
						printf("===============================================\n");
						printf("Introduza 1 para depositar numa das contas \n");
						printf("Introduza 2 para leveantar de numa das duas contas \n");
						printf("Introduza 3 para transferir um valor \n");
						printf("Introduza 4 para consultar movimentos \n");
						printf("Introduza 5 para consultar saldo \n");
						printf("Introduza 6 para pedir extrato \n");
						printf("Introduza 0 para sair \n");
						printf("================================================\n");
						printf("\nOpcao: ");
						scanf("%d", &opcao_cliente);

						switch (opcao_cliente)
						{
							case 0: break;
							case 1:
								printf("\nIntroduza o numero da conta a ser depositada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &j);
								printf("\nIntroduza o valor a ser depositado: ");
								scanf("%f", &cliente[i - 1].conta[j - 1].num_conta);
								break;

							case 2:
								printf("\nIntroduza o numero da conta a ser levantada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &j);
								printf("\nIntroduza o valor a ser levantado: ");
								scanf("%f", &cliente[i - 1].conta[j - 1].num_conta);
								break;

							case 3:
								break;

							case 4:
								break;

							case 5:
								break;

							case 6:
								break;

							default: printf("\nOcorreu um erro, tente novamente! \n");
								break;
						}
					} while (opcao_cliente != 0);
				}
				break;

			default: printf("\nOcorreu um erro, tente novamente! \n");
				break;
		}
	} while (opcao != 0);
	

	return (0);
}
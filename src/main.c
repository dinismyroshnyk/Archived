#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "proto.h"

#define NUM_CLIENTES 5
#define NUM_CONTAS 3

FILE *fclientes;

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
	int saldo;
	struct historico movimentos;
} contas;

typedef struct cliente {
	char nome_cliente[20];
	int telefone_cliente;
	char endereco_cliente[20];
	int num_pin;
	int num_cliente;
	struct contas conta[NUM_CONTAS];		
} cliente;

int main()
{
	//Variáveis
	int opcao;
	int num;
	int pin;
	int cli_num; 
	int conta_num;
	cliente cliente[NUM_CLIENTES];

	//Ficheiros
	fclientes = fopen("clientes.bin", "rb");
	if(fclientes == NULL)
	{
		printf("Ficheiro não encontrado\n");
	} else
	{
		for (int i = 0; i < NUM_CLIENTES; i++)
		{
			fread(&cliente[i].nome_cliente, sizeof(cliente[i].nome_cliente), 1, fclientes);
			fread(&cliente[i].telefone_cliente, sizeof(cliente[i].telefone_cliente), 1, fclientes);
			fread(&cliente[i].endereco_cliente, sizeof(cliente[i].endereco_cliente), 1, fclientes);
			fread(&cliente[i].num_pin, sizeof(cliente[i].num_pin), 1, fclientes);
			fread(&cliente[i].num_cliente, sizeof(cliente[i].num_cliente), 1, fclientes);
			for (int j = 0; j < NUM_CONTAS; j++)
			{
				fread(&cliente[i].conta[j].num_conta, sizeof(cliente[i].conta[j].num_conta), 1, fclientes);
				fread(&cliente[i].conta[j].saldo, sizeof(cliente[i].conta[j].saldo), 1, fclientes);
				fread(&cliente[i].conta[j].movimentos, sizeof(cliente[i].conta[j].movimentos), 1, fclientes);
			}			
		}
		fclose(fclientes);
	}

	//Menu
	do
	{
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

					//Menu administrador
					do
					{

						fclientes = fopen("clientes.bin", "ab");

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
							scanf("%i", &cli_num);
						}
						
						switch (opcao_admin)
						{
							case 0: break;
							case 1:
								printf("\nIntroduza o nome do cliente: ");
								scanf("%s", cliente[cli_num - 1].nome_cliente);
								printf("\nIntroduza o numero do telefone do cliente: ");
								scanf("%d", &cliente[cli_num - 1].telefone_cliente);
								printf("\nIntroduza o endereco de email do cliente: ");
								scanf("%s", cliente[cli_num - 1].endereco_cliente);
								printf("\nIntroduza o pin do cliente: ");
								scanf("%d", &cliente[cli_num - 1].num_pin);	
								cliente->num_cliente = cli_num;
								fwrite(cliente, sizeof(cliente), NUM_CLIENTES, fclientes);

								fclose(fclientes);
								break;

							case 2 :

								printf("\nIntroduza o numero da conta a ser criada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
								cliente[cli_num - 1].conta[conta_num - 1].num_conta = conta_num;
								cliente[cli_num - 1].conta[conta_num - 1].saldo = 0;
								fwrite(cliente->conta, sizeof(cliente->conta), NUM_CLIENTES, fclientes);
								fclose(fclientes);				
								break;

							case 3 :
								printf("\nIntroduza o numero do cliente: ");
								
								break;

							default: printf("\nOcorreu um erro, tente novamente! \n");
								break;

						}
					} while (opcao_admin != 0);
				} else
				{
					int opcao_cliente;
					printf("\nEfetuado login como cliente \n\n");

					//Menu cliente
					do
					{
						printf("===================================================\n");
						printf("Introduza 1 para depositar numa das contas \n");
						printf("Introduza 2 para levantar de numa das duas contas \n");
						printf("Introduza 3 para transferir um valor \n");
						printf("Introduza 4 para consultar movimentos \n");
						printf("Introduza 5 para consultar saldo \n");
						printf("Introduza 6 para pedir extrato \n");
						printf("Introduza 0 para sair \n");
						printf("===================================================\n");
						printf("\nOpcao: ");
						scanf("%d", &opcao_cliente);

						switch (opcao_cliente)
						{
							case 0: break;
							case 1:
								printf("\nIntroduza o numero da conta a ser depositada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
								printf("\nIntroduza o valor a ser depositado: ");
								scanf("%f", &cliente[cli_num - 1].conta[conta_num - 1].num_conta);
								fwrite(cliente->conta, sizeof(cliente->conta), NUM_CLIENTES, fclientes);
								fclose(fclientes);
								break;

							case 2:
								printf("\nIntroduza o numero da conta a ser levantada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
								printf("\nIntroduza o valor a ser levantado: ");
								scanf("%f", &cliente[cli_num - 1].conta[conta_num - 1].num_conta);
								fwrite(cliente->conta, sizeof(cliente->conta), NUM_CLIENTES, fclientes);
								fclose(fclientes);

								break;

							case 3:
								printf("\nIntroduza o numero da conta da qual pretende transferir (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
								printf("\nIntroduza o valor a ser transferido: ");
								scanf("%f", &cliente[cli_num - 1].conta[conta_num - 1].num_conta);
								break;

							case 4:
								printf("\nIntroduza o numero da conta a ser consultada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
								break;

							case 5: //FIXME - usar um "for loop"?
								printf("\nSaldo da conta 1: %f", cliente[cli_num - 1].conta[0].num_conta);
								printf("\nSaldo da conta 2: %f", cliente[cli_num - 1].conta[1].num_conta);
								printf("\nSaldo da conta 3: %f", cliente[cli_num - 1].conta[2].num_conta);
								printf("\nSaldo total: %f", cliente[cli_num - 1].conta[0].num_conta + cliente[cli_num - 1].conta[1].num_conta + cliente[cli_num - 1].conta[2].num_conta);
								break;

							case 6:
								printf("\nIntroduza o numero da conta a ser consultada (entre 1 e %i) : ", NUM_CONTAS);
								scanf("%i", &conta_num);
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
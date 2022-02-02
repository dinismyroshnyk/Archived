#ifndef _INSERIR_TAREFAS_
    #define _INSERIR_TAREFAS_

        #include <stdio.h>
        #include <stdlib.h>

        #define MAX_TAREFAS 100

        void inserirTarefa(char descricao[], int *importancia, int *dia, int *mes, int *ano){

            system("cls");
            fflush(stdin);

            while (1)
            {
                printf("Introduza uma breve descricao para a sua tarefa (maximo de 50 caracteres):\n\n");
                printf("Descricao: ");
                fgets(descricao, 52, stdin);
                descricao[strlen(descricao)-1] = 0;

                if (descricao[0] == NULL)
                {
                    system("cls");
                    printf("Tem de adicionar uma descricao ...");
                    fflush(stdin);
                    getchar();
                    system("cls");
                } 
                else
                {

                    while (1)
                    {
                        system("cls");

                        printf("Escolha a importancia da sua tarefa:\n\n1 - Alta\n2 - Media\n3 - Baixa\n\n");
                        printf("Importancia: ");
                        scanf("%d", &*importancia);

                        if (*importancia < 1 || *importancia > 3)
                        {
                            system("cls");
                            printf("Importancia invalida ...\n");
                            fflush(stdin);
                            getchar();
                            fflush(stdin);
                        }
                        else break;
                    }      

                    system("cls");
                    data_limite(&*dia, &*mes, &*ano);
                    break;
                             
                }
            }            
        }

#endif
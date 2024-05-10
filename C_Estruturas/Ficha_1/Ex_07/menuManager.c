#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir matriz\n");
    printf("[2] - Pesquisar número de ocorrências de um valor\n");
    printf("[3] - Pesquisar última ocorrência de um valor\n");
    printf("[4] - Pesquisar primeira ocorrência de um valor\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int userRows = userMatrixRows();
    int userColumns = userMatrixColumns();
    float **matrix1 = createUserMatrix(userRows, userColumns);
    int option;
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: printMatrix(matrix1, userRows, userColumns);
                break;
            case 2: findNumberOfOccurrences(matrix1, userRows, userColumns);
                break;
            case 3: printLastOccurrence(matrix1, userRows, userColumns);
                break;
            case 4: printFirstOccurrence(matrix1, userRows, userColumns);
                break;
            case 0: printf("A sair...\n");
                break;
            default: printf("Opção inválida!\n");
                break;
        }
    } while (option != 0);
}
#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir vetor\n");
    printf("[2] - Ordenar vetor (Não otimizado)\n");
    printf("[3] - Ordenar vetor (Otimizado)\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int option;
    int array_size = arraySize();
    int* array = getUserArray(array_size);
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: printArray(array, array_size);
                break;
            case 2: bubbleSortUnoptimized(array, array_size);
                break;
            case 3: bubbleSortOptimized(array, array_size);
                break;
            case 0: clearScreen();
                break;
            default: invalidOption();
                break;
        }
    } while (option != 0);
}

void insertAnyKey()
{
    printf("Insira qualquer tecla para continuar...");
    getchar();
    fflush(stdin);
}

void invalidOption()
{
    clearScreen();
    printf("Opção inválida!\n");
    insertAnyKey();
}

void arraySorted()
{
    clearScreen();
    printf("Vetor ordenado!\n");
    insertAnyKey();
}
#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir array\n");
    printf("[2] - Indicar o índice do maior elemento\n");
    printf("[3] - Trocar 2 elementos de lugar\n");
    printf("[4] - Ordenar array\n");
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
            case 2: printInedxOfLargestElement(array, array_size);
                break;
            case 3: swapElements(array, array_size);
                break;
            case 4: selectionSort(array, array_size);
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
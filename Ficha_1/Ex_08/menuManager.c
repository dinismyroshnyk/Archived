#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir vetor\n");
    printf("[2] - Pesquisar elemento\n");
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
            case 2: printBinarySearch(array, array_size);
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
    printf("\nInsira qualquer tecla para continuar...");
    getchar();
    fflush(stdin);
}

void invalidOption()
{
    clearScreen();
    printf("Opção inválida!\n");
    insertAnyKey();
}
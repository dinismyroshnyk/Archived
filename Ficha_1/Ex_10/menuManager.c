#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir vetor\n");
    printf("[2] - Inserir elemento num vetor ordenado\n");
    printf("[3] - Ordenar vetor\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int option;
    int array_size = arraySize();
    int* default_array = getDefaultArray();
    int* user_array = getUserArray(array_size);
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: printArray(user_array, array_size, 0);
                break;
            case 2: insertElementInsideSortedArray(default_array);
                break;
            case 3: insertionSort(user_array, array_size);
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
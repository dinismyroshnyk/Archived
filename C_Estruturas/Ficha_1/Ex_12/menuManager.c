#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir vetor\n");
    printf("[2] - Remover elementos repetidos\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int option;
    int original_array_size = arraySize();
    int* original_array = getUserArray(original_array_size);
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: printArray(original_array, original_array_size, 0);
                break;
            case 2: getUniqueArray(original_array, original_array_size);
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
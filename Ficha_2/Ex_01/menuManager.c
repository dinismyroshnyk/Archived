#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void mainMenuText()
{
    system("cls");
    printf("[1] - Imprimir hello world!\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int option;
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: 
                printf("Hello World!\n");
                insertAnyKey();
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
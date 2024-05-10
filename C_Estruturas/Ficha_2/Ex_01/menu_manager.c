#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void main_menu_text()
{
    clear_screen();
    printf("[1] - Criar ficheiro\n");
    printf("[2] - Adicionar dados ao ficheiro\n");
    printf("[3] - Escrever na consola o conteúdo do ficheiro\n");
    printf("[0] - Sair\n");
}

void main_menu()
{
    FILE *file;
    char file_name[50], file_content[1000];
    int option;
    do
    {
        main_menu_text();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: create_file(file, file_name, file_content);
                break;
            case 2: append_data_to_file(file, file_name, file_content);
                break;
            case 3: print_content_to_console(file, file_name);
                break;
            case 0: clear_screen();
                break;
            default: invalid_option();
                break;
        }
    } while (option != 0);
}

void insert_any_key()
{
    printf("Insira qualquer tecla para continuar...");
    getchar();
    fflush(stdin);
}

void invalid_option()
{
    clear_screen();
    printf("Opção inválida!\n");
    insert_any_key();
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include\prototypes.h"

void insert_user_data(char file_name[], char file_content[])
{
    clear_screen();
    printf("Insira o nome do ficheiro: ");
    scanf("%s", file_name);
    fflush(stdin);
    strcat(file_name, ".txt");
    clear_screen();
    printf("Insira o conteúdo do ficheiro: ");
    fgets(file_content, 1000, stdin);
    fflush(stdin);
}

void create_file(FILE *file, char file_name[], char file_content[])
{
    insert_user_data(file_name, file_content);
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1); // to create a file | requires <string.h>
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);                    // in a custom path | and <stdlib.h>
    file = fopen(file_path_name, "w");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao criar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    fwrite(file_content, sizeof(char), strlen(file_content), file);
    fclose(file);
    free(file_path_name);
    clear_screen();
    printf("Ficheiro criado com sucesso!\n");
    insert_any_key();
}

void append_data_to_file(FILE *file, char file_name[], char file_content[])
{
    insert_user_data(file_name, file_content);
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1); // to create a file | requires <string.h>
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);                    // in a custom path | and <stdlib.h>
    file = fopen(file_path_name, "a");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    fwrite(file_content, sizeof(char), strlen(file_content), file);
    fclose(file);
    free(file_path_name);
    clear_screen();
    printf("Dados adicionados com sucesso!\n");
    insert_any_key();
}

void print_content_to_console(FILE *file, char file_name[])
{
    clear_screen();
    printf("Insira o nome do ficheiro: ");
    scanf("%s", file_name);
    fflush(stdin);
    strcat(file_name, ".txt");
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1); // to create a file | requires <string.h>
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);                    // in a custom path | and <stdlib.h>
    file = fopen(file_path_name, "r");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!\n");
        insert_any_key();
        exit(1);
    }
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }
    fclose(file);
    free(file_path_name);
    insert_any_key();
}
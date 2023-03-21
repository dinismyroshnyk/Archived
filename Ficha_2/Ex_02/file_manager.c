#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include\prototypes.h"

void get_file_name(char file_name[])
{
    clear_screen();
    printf("Insira o nome do ficheiro: ");
    scanf("%s", file_name);
    fflush(stdin);
    strcat(file_name, ".txt");
}

void number_of_lines(FILE *file, char file_name[])
{
    get_file_name(file_name);
    int line_counter = 0;
    char c;
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1);
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);
    file = fopen(file_path_name, "r");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    else
    {
        while ((c = fgetc(file)) != EOF)
            if (c == '\n' || c == '\0')
                line_counter++;
    }
    fclose(file);
    free(file_path_name);
    printf("O ficheiro [%s] tem %d linhas.\n", file_name, line_counter);
    insert_any_key();
}

void number_of_words(FILE *file, char file_name[])
{
    get_file_name(file_name);
    int word_counter = 0;
    char current_char, previous_char;
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1);
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);
    file = fopen(file_path_name, "r");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    else
    {
        while ((current_char = fgetc(file)) != EOF)
        {
            if (current_char == ' ' || current_char == '\n' || current_char == '\t' || current_char == '\0')
            {
                if (previous_char != ' ' && previous_char != '\n' && previous_char != '\t' && previous_char != '\0')
                    word_counter++;
            }
            previous_char = current_char;
        }
    }
    fclose(file);
    free(file_path_name);
    printf("O ficheiro [%s] tem %d palavras.\n", file_name, word_counter);
    insert_any_key();
}

void number_of_characters(FILE *file, char file_name[])
{
    get_file_name(file_name);
    int char_counter = 0;
    char c;
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1);
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);
    file = fopen(file_path_name, "r");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    else
    {
        while ((c = fgetc(file)) != EOF)
            if (c != '\n' && c != '\0' && c != ' ' && c != '\t')
                char_counter++;
    }
    fclose(file);
    free(file_path_name);
    printf("O ficheiro [%s] tem %d caracteres.\n", file_name, char_counter);
    insert_any_key();
}

void number_of_user_defined_characters(FILE *file, char file_name[])
{
    get_file_name(file_name);
    int char_counter = 0;
    char c, user_defined_character;
    clear_screen();
    printf("Insira o caracter a procurar: ");
    user_defined_character = getc(stdin);
    fflush(stdin);
    char* file_path_name = malloc (strlen(FILE_DIR) + strlen(file_name) + 1);
    sprintf (file_path_name, "%s%s", FILE_DIR, file_name);
    file = fopen(file_path_name, "r");
    if (file == NULL)
    {
        clear_screen();
        printf("Erro ao encontrar o ficheiro!");
        insert_any_key();
        exit(1);
    }
    else
    {
        while ((c = fgetc(file)) != EOF)
            if (c == user_defined_character)
                char_counter++;
    }
    fclose(file);
    free(file_path_name);
    printf("O ficheiro [%s] tem %d caracteres [%c].\n", file_name, char_counter, user_defined_character);
    insert_any_key();
}
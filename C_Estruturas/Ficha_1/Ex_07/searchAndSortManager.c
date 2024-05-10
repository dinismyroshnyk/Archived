#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

float numberSearch()
{
    float number;
    printf("Introduza o número a pesquisar: ");
    scanf("%f", &number);
    fflush(stdin);
    return number;
}

void findNumberOfOccurrences(float **matrix, int row, int column)
{
    int count = 0;
    float number = numberSearch();
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] == number)
                count++;
    printf("O número %.2f aparece %d vezes na matriz.\n", number, count);
    printf("Pressione qualquer tecla para continuar...");
    getchar();
}

int findLastOccurrence(float **matrix, int row, int column, float number)
{
    for (int i = row - 1; i >= 0; i--)
        for (int j = column - 1; j >= 0; j--)
            if (matrix[i][j] == number)
                {
                    printf("O número %.2f encontra-se pela última vez na posição [%d][%d].\n", number, i, j);
                    return 0;
                }
    return -1;
}

int findFirstOccurrence(float **matrix, int row, int column, float number)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] == number)
                {
                    printf("O número %.2f encontra-se pela primeira vez na posição [%d][%d].\n", number, i, j);
                    return 0;
                }
    return -1;
}

void printLastOccurrence(float **matrix, int row, int column)
{
    float number = numberSearch();
    int position = findLastOccurrence(matrix, row, column, number);
    if (position == -1)
        printf("O número %.2f não existe na matriz.\n", number);
    printf("Pressione qualquer tecla para continuar...");
    getchar();
}

void printFirstOccurrence(float **matrix, int row, int column)
{
    float number = numberSearch();
    int position = findFirstOccurrence(matrix, row, column, number);
    if (position == -1)
        printf("O número %.2f não existe na matriz.\n", number);
    printf("Pressione qualquer tecla para continuar...");
    getchar();
}
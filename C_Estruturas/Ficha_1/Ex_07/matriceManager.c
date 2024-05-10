#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

float **createDefaultMatrix(int row, int column, float value)
{
    float **matrix = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (float *)malloc(column * sizeof(float));
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

float **createUserMatrix(int row, int column)
{
    float **matrix = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (float *)malloc(column * sizeof(float));
        for (int j = 0; j < column; j++)
        {
            clearScreen();
            printf("Insira o valor da posição [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
            fflush(stdin);
        }
    }
    return matrix;
}

int userMatrixRows()
{
    int rows;
    clearScreen();
    printf("Insira o número de linhas da matriz: ");
    scanf("%d", &rows);
    fflush(stdin);
    return rows;
}

int userMatrixColumns()
{
    int columns;
    clearScreen();
    printf("Insira o número de colunas da matriz: ");
    scanf("%d", &columns);
    fflush(stdin);
    return columns;
}

void printMatrix(float **matrix, int row, int column)
{
    clearScreen();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%.2f ", matrix[i][j]);
        printf("\n");
    }
    printf("\nPressione qualquer tecla para continuar...");
    getchar();
    fflush(stdin);
}
